#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
//not working for matrix bigger then 2x2 at the moment

double matrixToStep(const int* n, double* a) {
	double mult = 1, m, a_i;
	for (int k = 0; k < *n - 1; k++) {
		m = *(a + k*100 + k);
		mult = mult / m;
		
		for (int i = k; i < *n; i++) {
			*(a + 100*(k) + i) = (*(a + 100 * (k) + i)) / m;
		}
		for (int i = k + 1; i < *n; i++) {
			a_i = *(a + 100 * i + k);
			for (int j = 0; j < *n; j++) {
				*(a + (100) * i + j) = (*(a + (100) * i + j)) - a_i * (*(a + (100) * k + j));
			}
		}

	}
	return mult;
}

void enterMatrix(const int* n, double* a) {
	srand(time(NULL));
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n; j++) {
			*(a + (100) * i + j) = -100 + rand() % 300 + 1;
		}
	}
}

void printMatrix(const int* n, const double* a) {
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n; j++) {
			printf("%8.2lf ", *(a + (100) * i + j));
		}
		puts("");
	}
}

int main() {
	puts("Enter size of matrix");
	int n;
	double A[100][100];
	scanf_s("%d", &n);
	enterMatrix(&n, *A);
	puts("Output of the obtained matrix");
	printMatrix(&n, *A);
	double det = matrixToStep(&n, *A);
	for (int i = 0; i < n; i++) {
		det *= A[i][i];
	}
	puts("Stepped matrix");
	printMatrix(&n, *A);
	printf("Determenant of the matrix = %lf", det);
	_getch();
}
