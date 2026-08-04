#include <iostream>
#include "protocol/PacketDef.h"
//不写using namespace std;有函数冲突
int main(int argc,char* argv[]){
    // 打印项目启动信息
    std::cout << "========================================" << std::endl;
    std::cout << "  Video Conference Server is starting...  " << std::endl;
    std::cout << "========================================" << std::endl;
    //验证网络协议包头是否严格按照1字节对齐，如果对齐输出6Bytes
    std::cout << "[Init] MsgHeader size on network:"
              << "sizeof(vsc::protocol::MsgHeader)" << " bytes."<<std::endl;
    //TODO:初始化EpollReactor,启动循环;

}