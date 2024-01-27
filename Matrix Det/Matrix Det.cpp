#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
//it works \o/
//          |
//         / \

double matrixToStep(const int* n, double* a) {
	double det = 1, m, a_i;
	for (int k = 0; k < *n - 1; k++) {
		a_i = *(a + k + 100 * k);
		for (int i = k + 1; i < *n; i++) {
			m = (*(a + k + 100 * i)) / ((a_i) * (-1));
			for (int j = 0; j < *n; j++) {
				*(a + i * 100 + j) = *(a + i * 100 + j) + (m * (*(a + j + 100 * k));
			}
		}
	}
	for (int i = 0; i < *n; i++) {
		det *= *(a + i * 100 + i);
	}
	return det;
}

void enterMatrix(const int* n, double* a) {
	printf("Do you want to enter random matrix or manual? (Random/Manual)\n");
	char s[10];
	gets_s(s);
	if (strcmp(s, "Random") == 0 or strcmp(s, 'random') == 0 or strcmp(s, "rand") == 0) {
		srand(time(NULL));
		for (int i = 0; i < *n; i++) {
			for (int j = 0; j < *n; j++) {
				*(a + 100 * i + j) = -100 + rand() % 300 + 1;
			}
		}
	}
	if (strcmp(s, "Manual") == 0 or strcmp(s, 'manual') == 0) {
		for (int i = 0; i < *n; i++) {
			for (int j = 0; j < *n; j++) {
				scanf("%lf", &(a + 100 * i + j));
			}
			puts("");
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
	puts("Output of the entered matrix");
	printMatrix(&n, *A);
	double det = matrixToStep(&n, *A);
	puts("Stepped matrix");
	printMatrix(&n, *A);
	printf("Determenant of the matrix = %lf", det);
	_getch();
}