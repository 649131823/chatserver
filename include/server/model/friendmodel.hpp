#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include<vector>
#include"user.hpp"
using namespace std;

//维护好友信息的操作接口方法
class FriendModel
{
public:
    //添加好友信息
    void insert(int userid,int friendid);

    //返回用户的好友列表  通过用户的好友id返回好友的用户信息
    vector<User> query(int userid);
};



#endif