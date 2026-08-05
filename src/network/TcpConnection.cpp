#include "network/TcpConnection.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>

namespace vcs{
    namespace network{
        TcpConnection::TcpConnection(int client_fd):m_fd(client_fd){}
        TcpConnection::~TcpConnection(){
            close(m_fd);
        }

        void TcpConnection::testReadHeader(){
            char buffer[1024] = {0};
            //读消息头的六个字节
            ssize_t bytes_read = recv(m_fd,buffer,6,0);
            if(bytes_read > 0){
                std::cout<<"[Success] received "<<bytes_read<<" bytes."<<std::endl;
                std::cout<<"[Data] Content: "<< buffer <<std::endl;
            }
        }
    }//namespace network
}//namespace vcs