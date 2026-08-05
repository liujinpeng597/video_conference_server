#include "network/TcpServer.h"
#include "network/TcpConnection.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

namespace vcs{
    namespace network{
        TcpServer::TcpServer(int port):m_port(port),m_listen_fd(-1){}

        TcpServer::~TcpServer(){
            if(m_listen_fd != -1){
                close(m_listen_fd);
                std::cout<<"[TcpServer] Closed listen socket."<<std::endl;
            }
        }

        //初始化网络,绑定ip与port
        bool TcpServer::init(){
            //1.创建套接字
            m_listen_fd = socket(AF_INET,SOCK_STREAM,0);
            if(m_listen_fd == -1)return false;

            //开启端口复用
            int opt = 1;
            setsockopt(m_listen_fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

            //2.绑定ip和端口
            sockaddr_in server_addr{};
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = INADDR_ANY;
            server_addr.sin_port = htons(m_port); //host to network

            if(bind(m_listen_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
                std::cerr<<"[Error] Bind failed on port "<<m_port<<std::endl;
                return false;
            }

            //3.监听
            if(listen(m_listen_fd,128)<0){
                std::cerr<<"[Error] Listen failed."<<std::endl;
                return false;
            }

            std::cout<<"[Init] TcpServer successfully listening on port "<<m_port<<std::endl;
            return true;
        }

        //启动阻塞连接
        void TcpServer::startTestAccept(){
            std::cout<<"[Network] Waiting for clients on port "<<m_port <<"..."<<std::endl;

            sockaddr_in client_addr{};
            socklen_t client_len = sizeof(client_addr);

            //阻塞等待客户端连接
            while(true){
                int client_fd = accept(m_listen_fd,(struct sockaddr*)&client_addr,&client_len);
                if(client_fd >= 0){
                std::cout<<"[NetWork] Clinet connected! FD: "<<client_fd<<std::endl;
                //TcpServer接到连接 转给处理连接的类
                TcpConnection conn(client_fd);
                conn.testReadHeader();
                }
            }
        }
    }//namespace network
}//namespace vcs
