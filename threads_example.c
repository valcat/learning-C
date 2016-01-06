#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

//Global variables.
int GiftCount = 26000;
pthread_mutex_t GiftCount_lock = PTHREAD_MUTEX_INITIALIZER;

//Decrease number of gifts by subtract 1.
void* bring_gifts(void* box)
{
	int i = 0;
	int limit = 1000;
	for (; i < limit; i++) {
		//Lock the sourse when the process starts to use it. Don't let other processes can take it.
		pthread_mutex_lock(&GiftCount_lock);
		GiftCount -= 1;
		//Unlock the sourse after using.
		pthread_mutex_unlock(&GiftCount_lock);
	}
	printf("Gifts - %i\n", GiftCount);
	
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t threads[20];
	int t = 0;
	int limit = 20;
	printf("%i gifts are in the shop.\n", GiftCount);

	for (; t < limit; t++) {
		pthread_create(&threads[t], NULL, bring_gifts, NULL);
	}
	t = 0;

	//Prevent killing of threads before they'll finish to work.
	void* result;
	for(; t < limit; t++) {
		pthread_join(threads[t], &result);
	}

	printf("Many customers buy boxes with gifts.\nNow there are just %i gifts in the shop.\n", GiftCount);
	
	return 0;
}