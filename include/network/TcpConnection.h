#pragma once

namespace vcs{
    namespace network{
        class TcpConnection{
            public:
                TcpConnection(int client_fd);
                ~TcpConnection();

                void testReadHeader();
            private:
                int m_fd;
        };   
    }//namespace network
}//namespace vcs