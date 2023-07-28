#ifndef GROUPUSER_H
#define GROUPUSER_H

#include"user.hpp"

//群组用户信息，多一个role角色，从User类直接继承，复用User的其他信息
class GroupUser : public User
{
public:
    void setRole(string role){this->role = role;}
    string getRole(){return this->role;}

private:
    string role;
};


#endif