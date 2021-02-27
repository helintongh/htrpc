#include "hltrpc_application.h"

void HltrpcApplication::Init(int argc, char **argv)
{

}

HltrpcApplication& HltrpcApplication::GetInstance()
{
    static HltrpcApplication app;
    return app;
}