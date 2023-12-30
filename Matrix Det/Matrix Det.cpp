#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

void matrixToStep(const int* n, double* a) {
	double m = *(a + 0);
	for (int i = 0; i < *n; i++) {
		*(a + i) = (*(a + i)) / m;
	}
	for (int i = 1; i < *n; i++) {
		for (int j = 1; j < *n; j++) {
			*(a + 100 * i + j) -= (*(a + 0 + j)) * (*(a + 100 * i + 0));
		}
	}

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
			printf("%6.2lf ", *(a + (100) * i + j));
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
	matrixToStep(&n, *A);
	puts("Stepped matrix");
	printMatrix(&n, *A);
	_getch();
}