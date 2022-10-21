/*
4. Program the matrix multiplication using
	1) standard algorithm (class note, page 18)
	2) divide-and-conquer algorithm (class note, page 20)
	3) strassen algorithm (class note, page 28)

 - For the above cases 1), 2), 3)
	a) Compare the number of computations (multiplication, subtraction, addition)
	among 1), 2), 3) cases.

	In the matrix computation of C = A¡¿B, matrices A and B are
	filled with rand()%1000, execute srand(time(NULL)) first.
	(Note that identical values are allowed.)

 - For the case 2) and 3)
	b) Print whenever a partial matrix (except 1¡¿1) of C is constructed,
	that is, whenever a return value from a recursion is determined,
	until the completion of the matrix multiplication.

  --- Execute with the 4x4 matrix multiplication and the 8x8 matrix multiplication.
	Print matrices, A, B, and C for 4x4 and 8x8 matrices.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// standard algorithm(case 1)
int standard(int** A, int** B, int** C, int arrSize) {
	int computation = 0;

	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			for (int k = 0; k < arrSize; k++) {
				C[i][j] += A[i][k] * B[k][j]; // 1 mult 1 add
				computation += 2;
			}
		}
	}

	return computation;
}

// divide-and-conquer algorithm(case 2)
/*
int divAndConquer(int** A, int** B, int** C, int arrSize) {
	int computation = 0;
	


	return computation;
}


// strassen algorithm(case 3)
int starssen(int** A, int** B, int** C, int arrSize) {
	int computation = 0;



	return computation;
}
*/

void printMatrix(int** matrix, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		printf("[");
		for (int j = 0; j < arrSize; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("]\n");
	}
}

int main() {
	int A_4x4[4][4];
	int B_4x4[4][4];
	int C_4x4[4][4];

	int A_8x8[8][8];
	int B_8x8[8][8];
	int C_8x8[8][8];

	int standardComputation_4x4;
	int divAndConquerComputation_4x4;
	int strassenComputation_4x4;

	int standardComputation_8x8;
	int divAndConquerComputation_8x8;
	int strassenComputation_8x8;

	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			A_4x4[i][j] = rand() % 1000;
			B_4x4[i][j] = rand() % 1000;
			C_4x4[i][j] = rand() % 1000;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			A_8x8[i][j] = rand() % 1000;
			B_8x8[i][j] = rand() % 1000;
			C_8x8[i][j] = rand() % 1000;
		}
	}

	standardComputation_4x4 = standard(&A_4x4, &B_4x4, &C_4x4, 4);
	//divAndConquerComputation_4x4 = divAndConquer(A_4x4, B_4x4, C_4x4, 4);
	//strassenComputation_4x4 = strassen(A_4x4, B_4x4, C_4x4, 4);

	standardComputation_8x8 = standard(A_8x8, B_8x8, C_8x8, 8);
	//divAndConquerComputation_8x8 = divAndConquer(A_8x8, B_8x8, C_8x8, 8);
	//strassenComputation_8x8 = strassen(A_8x8, B_8x8, C_8x8, 8);

	printf("---------- Matrix A(4x4) ----------\n");
	printMatrix(&A_4x4,4);
	printf("---------- Matrix B(4x4) ----------\n");
	printMatrix(&B_4x4,4);
	printf("---------- Matrix C(4x4) ----------\n");
	printMatrix(&C_4x4,4);


	return 0;
}