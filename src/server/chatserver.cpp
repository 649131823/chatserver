#include "chatserver.hpp"
#include<functional>
#include<string>
#include"json.hpp"
#include"chatservice.hpp"
using namespace std;
using namespace placeholders;
using json = nlohmann::json;

ChatServer::ChatServer(EventLoop *loop,               //事件循环
               const InetAddress &listenAddr, //muduo封装好的，绑定IP+Port
               const string &nameArg)
               :_server(loop,listenAddr,nameArg),_loop(loop)
{
    //注册链接回调
    _server.setConnectionCallback(std::bind(&ChatServer::onConnection,this,_1));

    _server.setMessageCallback(std::bind(&ChatServer::onMessage,this,_1,_2,_3));

    //设置线程数量
    _server.setThreadNum(4);  
}

  //启动服务
void ChatServer:: start()
{
    _server.start();
}

    //上报链接相关信息的回调函数
void ChatServer:: onConnection(const TcpConnectionPtr & conn)
{
    //客户端断开连接
    if(!conn->connected())
    {
        ChatService::instance()->clientCloseException(conn);
        conn->shutdown();  
    }
}
    //上报读写信息的回调函数
void ChatServer:: onMessage(const TcpConnectionPtr &conn,Buffer*buffer,Timestamp time)
{
    string buf = buffer->retrieveAllAsString();
    //数据的反序列化
    json js = json::parse(buf);
    //完全解耦网络模块和业务模块的代码
    //通过js["msgid"]获取业务handler >>conn js time
    auto msgHandler = ChatService::instance()->getHandler(js["msgid"].get<int>());
    //回调消息绑定好的事件处理器，来处理相应的业务处理
    msgHandler(conn,js,time);
}