#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int comparison = 0;

void merge(int arr[], int low, int middle, int high)
{
	int* sortedArr = (int*)malloc(sizeof(int) * (high-low+1));

	int sortedArrIndex = 0;
	int leftArrIndex = low;
	int rightArrIndex = middle + 1;

	while (leftArrIndex <= middle && rightArrIndex <= high)
	{
		if (arr[leftArrIndex] <= arr[rightArrIndex])
			sortedArr[sortedArrIndex++] = arr[leftArrIndex++];
		else
			sortedArr[sortedArrIndex++] = arr[rightArrIndex++];
		comparison++;
	}
	while (leftArrIndex <= middle)
		sortedArr[sortedArrIndex++] = arr[leftArrIndex++];
	while (rightArrIndex <= high)
		sortedArr[sortedArrIndex++] = arr[rightArrIndex++];
	sortedArrIndex--;

	for (int i = high; i >= low; i--)
		arr[i] = sortedArr[sortedArrIndex--];

	free(sortedArr);
}

void mergeSort(int arr[], int low, int high)
{
	int middle = (low + high) / 2;
	if (low < high)
	{
		mergeSort(arr, low, middle);
		mergeSort(arr, middle + 1, high);
		merge(arr, low, middle, high);
	}
}

void fillArraySorted(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = arrSize - i;
	}
}

void fillArrayReverseSorted(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = i + 1;
	}
}

int main()
{
	int A[100];
	srand(time(NULL));

	//<----------Test case 1---------->
	for (int i = 0; i < 100; i++)
	{
		A[i] = rand() % 1000;
		for (int j = 0; j < i; j++)
		{
			if (A[i] == A[j])
			{
				i--;
				break;
			}
		}
	}

	printf("<----------Test case 1---------->\n");
	printf("Before sorting : [");
	for (int i = 0; i < 100; i++)
	{
		if (i == 99)
			printf("%d", A[i]);
		else
			printf("%d, ", A[i]);
	}
	printf("]\n\n"); // for printing the array before sorting

	mergeSort(A, 0, 99);

	printf("After sorting : [");
	for (int i = 0; i < 100; i++)
	{
		if (i == 99)
			printf("%d", A[i]);
		else
			printf("%d, ", A[i]);
	}
	printf("]\n\n"); // for printing the array after sorting
	printf("The number of comparison : %d\n\n", comparison);
	comparison = 0;
	//<----------Test case 1 END---------->

	//<----------Test case 2---------->
	fillArraySorted(A, sizeof(A) / sizeof(int)); // Function that fills the array already sorted
	printf("<----------Test case 2---------->\n");
	printf("Before sorting : [");
	for (int i = 0; i < 100; i++)
	{
		if (i == 99)
			printf("%d", A[i]);
		else
			printf("%d, ", A[i]);
	}
	printf("]\n\n"); // for printing the array before sorting

	mergeSort(A, 0, 99);

	printf("After sorting : [");
	for (int i = 0; i < 100; i++)
	{
		if (i == 99)
			printf("%d", A[i]);
		else
			printf("%d, ", A[i]);
	}
	printf("]\n\n"); // for printing the array after sorting
	printf("The number of comparison : %d\n\n", comparison);
	comparison = 0;
	//<----------Test case 2 END---------->

	//<----------Test case 3---------->
	fillArrayReverseSorted(A, sizeof(A) / sizeof(int));
	printf("<----------Test case 3---------->\n");
	printf("Before sorting : [");
	for (int i = 0; i < 100; i++)
	{
		if (i == 99)
			printf("%d", A[i]);
		else
			printf("%d, ", A[i]);
	}
	printf("]\n\n"); // for printing the array before sorting

	mergeSort(A, 0, 99);

	printf("After sorting : [");
	for (int i = 0; i < 100; i++)
	{
		if (i == 99)
			printf("%d", A[i]);
		else
			printf("%d, ", A[i]);
	}
	printf("]\n\n"); // for printing the array after sorting
	printf("The number of comparison : %d\n", comparison);
	//<----------Test case 3 END---------->

	return 0;
}