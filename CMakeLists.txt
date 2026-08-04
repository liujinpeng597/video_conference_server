cmake_minimum_required(VERSION 3.10)
# 项目名称
project(video_conference_server)

# 指定使用C++17标准,方便后续使用智能指针,std::function等现代特性
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 告诉编译器去哪里找头文件
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party)

# 把编译出来的.exe文件都放到bin里
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 自动查找src目录下所有的.cpp文件
file(GLOB_RECURSE SOURCE "src/*.cpp")

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接多线程库
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)