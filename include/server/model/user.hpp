#ifndef USER_H
#define USER_H

#include<string>
using namespace std;

//与之前定义四张表一一对应
//User表的ORM类   ORM 对象关系映射  相当于给的数据，各数据段都是什么
class User
{
public:
    User(int id = -1,string name = "",string pwd = "",string state = "offline")
    {
        this->id = id;
        this->name = name;
        this->password = pwd;
        this->state  = state;
    }

    //为外部提供接口访问内部私有变量
    void setId(int id){this->id = id;}
    void setName(string name){this->name = name;}
    void setPwd(string pwd){this->password = pwd;}
    void setState(string state){this->state = state;}

    int getId(){return this->id;}
    string getName(){return this->name;}
    string getPwd(){return this->password;}
    string getState(){return this->state;}
private:
    int id;
    string name;
    string password;
    string state;
};



#endif