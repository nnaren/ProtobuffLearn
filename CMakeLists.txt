cmake_minimum_required(VERSION 3.10)
project(ProtobuffLearn)

set(CMAKE_CXX_STANDARD 11)
link_libraries("/usr/lib/x86_64-linux-gnu/libprotobuf.a")
add_executable(ProtobuffLearn src/TestProtoBuffer.cpp src/test.pb.cc)