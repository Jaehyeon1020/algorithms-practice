#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* num1, int* num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//descending order selection sort
int selectionSort(int arr[], int arrLength)
{
	int comparison = 0;
	for (int i = 0; i <= arrLength- 2; i++)
	{
		int maxIndex = i;
		for (int j = i+1; j <= arrLength - 1; j++)
		{
			comparison++;
			if (arr[maxIndex] < arr[j])
				maxIndex = j;
		}
		swap(&arr[maxIndex], &arr[i]);
	}
	return comparison;
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
	int comparison;
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

	comparison = selectionSort(A, sizeof(A)/sizeof(int));

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

	comparison = selectionSort(A, sizeof(A) / sizeof(int));

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

	comparison = selectionSort(A, sizeof(A) / sizeof(int));

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