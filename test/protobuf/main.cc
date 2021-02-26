/*
 * @Description: 请输入....
 * @Author: 何林桐
 * @Date: 2020-06-01 08:35:09
 * @LastEditTime: 2020-06-01 23:35:44
 * @LastEditors: 何林桐
 */ 
#include "test.pb.h"
#include <iostream>
#include <string>
using namespace fixbug;

int main()
{
    // LoginResponse rsp; //声明 LoginResponse类
    // ResultCode *rc = rsp.mutable_result(); //mutable不可改变的
    // rc->set_errcode(1); // 指向errcode对象
    // rc->set_errmsg("登录处理失败了");
    
    GetFriendListsResponse rsp; // 声明GetFriendListsResponse类
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(0);

    User *user1 = rsp.add_friend_list(); // 注意protobuf中变量名为friend_list,声明它为list所以自带add方法
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User *user2 = rsp.add_friend_list();
    user2->set_name("li si");
    user2->set_age(22);
    user2->set_sex(User::MAN);

    std::cout << rsp.friend_list_size() << std::endl; // 获得好友列表的个数

    return 0;
}

int main1()
{
    // 封装了login请求对象的数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    // 对象数据序列化 =》 char*
    std::string send_str;
    if (req.SerializeToString(&send_str)) // 序列化到字符串中
    {
        std::cout << send_str.c_str() << std::endl;
    }

    // 从send_str反序列化一个login请求对象
    LoginRequest reqB;
    if (reqB.ParseFromString(send_str))
    {
        std::cout << reqB.name() << std::endl;
        std::cout << reqB.pwd() << std::endl;
    }

    return 0;
}