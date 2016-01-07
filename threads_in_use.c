#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

//Print a message about error.
void error(char* msg)
{
	fprintf(stderr,  "%s: %s\n", msg, strerror(errno));
}

//Print a message with word. Pause to skip another thread.
void* sayWord(void *a)
{
	int i = 0;
	int limit = 5;
	for (i = 0; i < limit; i++) {
		sleep(1);
		puts("Thread!");
	}

	return NULL;
}

//Print message with number. Pause to skip another thread.
void* sayNumber(void *a)
{
	int i = 0;
	int limit = 5;
	for (i = 0; i < limit; i++) {
		sleep(1);
		puts("55!");
	}

	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t first_thread;
	pthread_t second_thread;

	if (pthread_create (&first_thread, NULL, sayWord, NULL) == -1) {
		error("Can't create first_thread");
	}
	if (pthread_create (&second_thread, NULL, sayNumber, NULL) == -1) {
		error("Can't create second_thread");
	}

	//Prevent killing of threads before they'll finish to work
	void* result;
	if (pthread_join(first_thread, &result) == -1) {
		error("Can't join first_thread");
	}
	if (pthread_join(second_thread, &result) == -1) {
		error("Can't join second_thread");
	}

	return 0;

}

