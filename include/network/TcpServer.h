#pragma once
namespace vcs{
    namespace network{
        class TcpServer{
            public:
                TcpServer(int port);
                 ~TcpServer();
                 //负责 socket bind listen;
                 bool init();
                 //临时链接
                 void startTestAccept();
            private:
                int m_port;
                int m_listen_fd;
        };
    }//namespace network
}//namespace vcs