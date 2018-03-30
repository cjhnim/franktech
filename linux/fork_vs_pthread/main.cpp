#include <cstdio>
#include <gtest/gtest.h>
#include <iostream>
#include <pthread.h>

using namespace std;

namespace {
	class gtest_exam : public testing::Test {
	protected:

		virtual void SetUp() {

		}

		virtual void TearDown() {

		}
	public:
		static const int value = 100;

		static int calc(int count)
		{
			int i;
			int result;

			for (i = 0; i < count; i++)
			{
				result = i*value;
				//printf("%d\n", i*a);
			}
			return i * value;
		}

		static void* testThread(void *data)
		{
			int count = *(int *)data;
			return (void *)(intptr_t)calc(count);
		}

		static void runThread(int thread_num, int count) {
			pthread_t *thread_t = (pthread_t*)malloc(sizeof thread_t*thread_num);
			memset(thread_t, 0, sizeof thread_t*thread_num);

			int *status = (int*)malloc(sizeof status*thread_num);
			memset(status, 0, sizeof status*thread_num);


			for (int i = 0; i< thread_num; i++) {
				int result = pthread_create(&thread_t[i], NULL, testThread, (void *)&count);
				EXPECT_EQ(result, 0);
			}

			for (int i = 0; i < thread_num; i++) {
				pthread_join(thread_t[i], (void **)&status[i]);
				//printf("Thread End %d\n", status[i]);
				EXPECT_EQ(status[i], value * count);
			}

			free(thread_t);
			free(status);
		}

		static void runProcess(int process_num, int count) {
			//printf("fork test start\n");

			for (int i = 0; i < process_num; i++) {
				int current_pid;
				if ((current_pid = fork()) == 0) {
					//printf("child[%d] start: %d\n", i, getpid());
					testThread((void*)&count);
					//printf("child[%d] end: %d\n", i, getpid());
					exit(0);
				}
				else {
					EXPECT_GE(current_pid, 0);
				}
			}

			//printf("==> parent after fork: %d\n", getpid());
			int child_pid;
			while ((child_pid = wait(NULL)) >= 0) {
				//printf("child signal: %d\n", child_pid);
			}
			//printf("<== parent exit: %d, wait:%d\n", getpid(), child_pid);
		}
	};

	TEST_F(gtest_exam, first) {
		EXPECT_EQ(1,1);
	}

	TEST_F(gtest_exam, pthread_1) {
		int count = 10;
		static const int num = 1;
		runThread(num, count);
	}

	TEST_F(gtest_exam, pthread_2) {
		int count = 10;
		static const int num = 2;
		runThread(num, count);
	}

	TEST_F(gtest_exam, pthread_1000) {
		int count = 10;
		static const int num = 1000;
		runThread(num, count);
	}

	TEST_F(gtest_exam, fork_1) {
		int count = 10;
		int num = 1;
		runProcess(num, count);
	}

	TEST_F(gtest_exam, fork_2) {
		int count = 10;
		int num = 2;
		runProcess(num, count);
	}

	TEST_F(gtest_exam, fork_1000) {
		int count = 10;
		int num = 1000;
		runProcess(num, count);
	}

}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}