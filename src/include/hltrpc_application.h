#pragma once

// hltrpc框架的基础类，负责框架的一些初始化操作,单例模式
class HltrpcApplication
{
public:
    static void Init(int argc, char **argv);
    static HltrpcApplication& GetInstance();// 专门获取实例的方法
private:

    HltrpcApplication(){}
    HltrpcApplication(const HltrpcApplication&) = delete;
    HltrpcApplication(HltrpcApplication&&) = delete;
};