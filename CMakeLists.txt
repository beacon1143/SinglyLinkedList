cmake_minimum_required(VERSION 3.10)

project(SinglyLinkedList)
set(SINGLY_LINKED_LIST_SRC main.cpp SinglyLinkedList.cpp)
set(SINGLY_LINKED_LIST_HDR SinglyLinkedList.hpp)
add_executable(${PROJECT_NAME} ${SINGLY_LINKED_LIST_SRC} ${SINGLY_LINKED_LIST_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data.dat
#     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
