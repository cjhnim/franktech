project (fork_vs_pthread)
add_executable(fork_vs_pthread main.cpp fork_vs_pthread.cpp)
target_link_libraries(fork_vs_pthread gtest gtest_main pthread)