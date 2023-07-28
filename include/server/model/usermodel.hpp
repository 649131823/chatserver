#ifndef USERMODEL_H
#define USERMODEL_H

#include"user.hpp"

//User表的数据操作类:针对表的增删改查  与db和user连接的桥梁  
//相当于将User的数据通过usermodel写入到db的数据库内
class UserModel
{
public:
    //User表的增加方法
    bool insert(User &user);
    //根据用户号码查询用户信息
    User query(int id);
    //更新用户的状态信息
    bool updateState(User user);
    //重置用户的状态信息
    void resetState();

};


#endif