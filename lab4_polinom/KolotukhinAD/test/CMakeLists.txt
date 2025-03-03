set(target list_test)

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp" "../include/list.cpp")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest)