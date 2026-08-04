#pragma once
#include<cstdint>

namespace vc {
    namespace protocol{
        //强制编译器按一字节对齐
        //防止编译器自动做内存对齐补齐填充字节，确保结构体在网络上刚好是6字节
        #pragma pack(push,1)

        struct MsgHeader{
            //消息体长度，不包含包头本身的6字节
            uint32_t body_len;
            //命令字两字节
            uint16_t cmd_id;
        };//Struct MsgHeader

        #pragma pack(pop)
        
        //定义基础的命令字
        enum CommandId:uint16_t{
            CMD_HEARTBEAT = 1000,//心跳包
            CMD_USER_LOGIN = 1001,//用户登录
            CMD_CREATE_ROOM = 1002,//创建房间
            CMD_JOIN_ROOM = 1003 //加入房间
        };

    }//namespace protocol
}//namespace vc