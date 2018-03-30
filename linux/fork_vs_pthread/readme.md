# fork_vs_thread 빌드방법

## gtest 설치

```shell
sudo apt-get install libgtest-dev
sudo apt-get install cmake
cs /usr/src/gtest
sudo cmake CmakeLists.txt
sudo make
sudo cp *.a /usr/lib
```

## cmake 빌드

```shell
cmake CMakeLists.txt
make
```

## gtest를 통하여 thread 1000개와 process 1000개 테스트 실행해보기

```shell
./fork_vs_pthread --gtest_filter=**_1000*

Note: Google Test filter = **_1000*
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from gtest_exam
[ RUN      ] gtest_exam.pthread_1000
[       OK ] gtest_exam.pthread_1000 (55 ms)
[ RUN      ] gtest_exam.fork_1000
[       OK ] gtest_exam.fork_1000 (188 ms)
[----------] 2 tests from gtest_exam (243 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (243 ms total)
[  PASSED  ] 2 tests.
```
