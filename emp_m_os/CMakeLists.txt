cmake_minimum_required(VERSION 3.19)
project(emp_m_os)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
FILE(GLOB SOURCE "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCE})