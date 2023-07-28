#ifndef DB_H
#define DB_H
#include<string>
using namespace std;

#include<mysql/mysql.h>


// 数据库操作类封装  具体操作  与具体的数据库进行连接
class MySQL
{
public:
    // 初始化数据库连接
    MySQL();
    // 释放数据库连接资源
    ~MySQL();
    // 连接数据库
    bool connect();
    // 更新操作
    bool update(string sql);
    // 查询操作
    MYSQL_RES *query(string sql);
    //获取连接
    MYSQL * getConnection();
private:
    MYSQL *_conn;
};

#endif