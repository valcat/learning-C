#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//This program is for sorting numbers using quick sort. Firstly it is important to pick an element called a pivot. 
//After that other elements of the array are compared with pivot and according to this comparing they are reshuffle 
//in 2 parts: less than the pivot and greater than the pivot. Next repeat the same actions for put in order smaller
//and greater values using recursion. 

void swap(int *arr, int first, int second);

int* quicksort(int* arr, int first, int last)
{
	int a = first;
	int z = last;
	int d = 0;
	int x = arr[(first + last) / 2];

	do {
		while (arr[a] < x) a++;
		while (arr[z] > x) z--;
		if (a <= z) {
			if (arr[a] > arr[z]) {
				swap(arr, a, z);
			}
			a++;
			z--;
		}
			
		
	} while (a <= z);

	if (a < last) {
		quicksort(arr, a, last);
	}

	if (first < z) {
		quicksort(arr, first, z);
	}

	return arr;
}

void swap(int *arr, int first, int second) 
{
	int d = 0;
	
	d = arr[first];
	arr[first] = arr[second];
	arr[second] = d;
}

int main(int argc, char const *argv[])
{
	int arr[50];
	int length = 0;
	int k;

	printf("Enter the length of an array:\n");
	scanf("%d", &length);
	printf("Enter %d numbers\n", length );
	for (k = 0; k < length; k++) {
		scanf("%d", &arr[k]);
	}

	quicksort(arr, 0, length - 1);
	printf("After sort\n");
	for (k = 0; k < length; k++) {
		printf("%3d,", arr[k]);
	}

	return 0;
}