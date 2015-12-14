#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Program sorts array using method bubble sort. It swaps 2 elements if first one is larger than second. After all changes we have sorted array.
void swap(int *a, int index1, int index2);

int* bubble_sort(int a[], int length)
{
	int i, j, b, k;
	bool flag = true;
	printf("\nBefore sort:");
	for (k = 0; k < length; k++) {
        printf("%3d", a[k]);
    }

	for (i = 0; i < length; i++) {
		flag = true;
		for (j = 0; j < length - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a, j, j + 1);
				flag = false;
			}
		} 

		if (flag == true) {
			return a;
		}
	}

	return a;
}

void swap(int *a, int index1, int index2) 
{
	int b;
	b = a[index1];
	a[index1] = a[index2];
	a[index2] = b;
}

int main()
{
	int array[30];
	int length;
	int i;
	printf("\nEnter length of the array:");
	scanf("%d", &length);

	printf("\nEnter numbers:");
	for (i = 0; i < length; i++) {
		scanf("%d", &array[i]);
	}

	int* ar = bubble_sort(array, length);
	printf("\nAfter sort");
	for (i = 0; i < length; i++) {
		printf("%2d", ar[i]);
	}
	
	return 0;
}