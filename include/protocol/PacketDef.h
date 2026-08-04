//防止头文件重复包含
#pragma once
/*
cstdint库 网络传输需要严格限制包大小 传统的int可能会因为系统位数不同导致int占字节不同
所以引入cstdint库 库中的uint32_t uint16_t都是标准的四字节以及两字节的int类型，所引引入此库
*/
#include<cstdint>

//命名空间 工程化规范，vcs代表此项目video_conference_server
//这样做是防止命名冲突 如果调用可以写vcs::protocol::MsgHeader 区别其他的MsgHeader
namespace vcs {
    namespace protocol{
        //强制编译器按一字节对齐
        //防止编译器自动做内存对齐补齐填充字节，确保结构体在网络上刚好是6字节
        //正常编译器会进行内存对齐，编译器会自动向4的整数倍对齐，所以临时把对其数改成一个字节
        #pragma pack(push,1)

        struct MsgHeader{
            //消息体长度，不包含包头本身的6字节
            uint32_t body_len;
            //命令字两字节
            uint16_t cmd_id;
        };//Struct MsgHeader
        //将对齐规则复原
        #pragma pack(pop)
        
        //定义基础的命令字
        enum CommandId:uint16_t{
            CMD_HEARTBEAT = 1000,//心跳包
            CMD_USER_LOGIN = 1001,//用户登录
            CMD_CREATE_ROOM = 1002,//创建房间
            CMD_JOIN_ROOM = 1003 //加入房间
        };

    }//namespace protocol
}//namespace vcs