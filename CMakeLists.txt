# CMake把这份配置文件翻译成MakeFile，然后Linux才能用make命令去编译C++代码

#基础信息声明部分
#告诉系统,跑这个工程的CMake版本不能低于3.10，防止太古老了CMake编译此工程出错
cmake_minimum_required(VERSION 3.10)
# 项目名称 执行这行会生成一个隐藏变量${PROJECT_NAME}值是video_conference_server
project(video_conference_server)

# 指定使用C++17标准,方便后续使用智能指针,std::function等现代特性
# 此语句强制要求例如g++编译器使用C++17标准
set(CMAKE_CXX_STANDARD 17)
# 这句是如果编译器太老，不支持C++17 就直接报错
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 告诉编译器去哪里找头文件
# ${PROJECT_SOURCE_DIR}这一句是CMake自动生成的绝对路径变量，就指向CMakeLists.txt所在的根目录
# 有了这个我可以直接 #include"protocol/PacketDef.h" 编译器会自动去include去找头文件
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party)

# 把编译出来的.exe文件都放到bin里
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 自动查找src目录下所有的.cpp文件
# 递归扫描src文件夹，把所有以.cpp结尾的文件路径都搜集起来,放到SOURCE这个变量里
file(GLOB_RECURSE SOURCE "src/*.cpp")

# 生成可执行文件
# 用上一步SOURCE里的源码,编译生成一个叫第一步中设置的项目名字的可执行程序 video_conference_server
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接多线程库
# 线程库比较特殊需要手动去链接，例如在Linux上 如果使用了pthread_create的时候 编译需要加-lpthread
# find_package 是去linux系统找Thread这个库
find_package(Threads REQUIRED)
# 负责把找到的库和刚刚生成的video_conference_server链接在一起
target_link_libraries(${PROJECT_NAME} Threads::Threads)