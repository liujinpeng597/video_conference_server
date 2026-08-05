#pragma once
#include <sys/epoll.h>

namespace vcs{
    namespace network{
        class EpollReactor{
            public:
                EpollReactor();
                ~EpollReactor();

                //核心骨架 只管epoll的增删改查和事件循环
                bool init();
                void addFd(int fd,uint32_t events);
                void loop();
            private:
                int m_epoll_fd;
        };
    }//namespace EpollReactor
}//namespace vcs