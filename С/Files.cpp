#include <stdio.h>
#include <stdlib.h>

int columnsAndRowsCompare(FILE*);
double** getMatrixFromFile(int, FILE*);
bool showMatrix(double**, int);
double** getInverseMatrix(double**, int);
bool setMatrixInFile(double**, int, FILE*);

int main() {
	FILE *f1;
	double **matrix = NULL;
	int matrixSize, i;
	if ((fopen_s(&f1, "D:/lab3.txt", "r")) != NULL) {
		printf("Can't open file\n");
		return 1;
	}
	if (columnsAndRowsCompare(f1) == 0) {
		printf("Incorrect information in file\n");
		return 1;
	}
	else {
		matrixSize = columnsAndRowsCompare(f1);
	}
	matrix = getMatrixFromFile(matrixSize, f1);
	printf("Your standart matrix\n");
	if (!showMatrix(matrix, matrixSize)) {
		puts("The mistake of the output!");
	}
	matrix = getInverseMatrix(matrix, matrixSize);
	printf("Your inverse matrix\n");
	if (!showMatrix(matrix, matrixSize)) {
		puts("The mistake of the output!");
	}
	if (!setMatrixInFile(matrix, matrixSize, f1)) {
		puts("Error of setting matrix in the file!");
	}
	for (i = 0; i < matrixSize; i++)
		free(matrix[i]);
	free(matrix);
	system("pause");

	return 0;
}

bool showMatrix(double** matrix, int matrixSize) {
	int i, j;
	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixSize; j++) {
			printf("%lf  ", matrix[i][j]);
		}
		printf("\n");
	}
	return true;
}

double** getMatrixFromFile(int matrixSize, FILE *f1) {
	int i, j;
	double fileElement;
	double **matrix;
	rewind(f1);
	if (!(matrix = (double**)malloc(sizeof(double*)*matrixSize))) {
		matrix = (double**)realloc(matrix, matrixSize + 1);
	}
	for (i = 0; i < matrixSize; i++) {
		if (!(matrix[i] = (double*)malloc(sizeof(double)*matrixSize))) {
			matrix[i] = (double*)realloc(matrix[i], matrixSize + 1);
		}
	}
	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixSize; j++)
			if (!fscanf_s(f1, "%lf", &fileElement)) {
				puts("Eror!");
				return NULL;
			}
		matrix[i][j] = fileElement;
	}

	return matrix;
}

int columnsAndRowsCompare(FILE* f1) {
	rewind(f1);
	char symbol;
	int spaceCounter = 1, tabulationCounter = 1;
	while ((fread(&symbol, 1, 1, f1))) {
		if (symbol == '\n') {
			tabulationCounter++;
		}
		if (symbol == ' ' && tabulationCounter == 1) {
			spaceCounter++;
		}
	}
	if (tabulationCounter == spaceCounter) {
		return tabulationCounter;
	}
	else return 0;
}

double** getInverseMatrix(double** matrix, int matrixSize) {
	int k, i, j;
	double temp;
	double **E = (double**)malloc(sizeof(double*)*matrixSize);
	if (!E) {
		return matrix;
	}
	for (i = 0; i < matrixSize; i++) {
		E[i] = (double*)malloc(sizeof(double)*matrixSize);
		if (!E[i]) {
			return matrix;
		}
	}
	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixSize; j++) {
			if (i == j) {
				E[i][j] = 1;
			}
			else {
				E[i][j] = 0;
			}
		}
	}
	for (k = 0; k < matrixSize; k++)
	{
		temp = matrix[k][k];
		for (j = 0; j < matrixSize; j++)
		{
			matrix[k][j] /= temp;
			E[k][j] /= temp;
		}
		for (i = 0; i < matrixSize; i++)
		{
			temp = matrix[i][k];
			for (j = 0; j < matrixSize; j++) {
				if (i == k)
					break;
				matrix[i][j] = matrix[i][j] - matrix[k][j] * temp;
				E[i][j] = E[i][j] - E[k][j] * temp;
			}
		}
	}
	return E;
}

bool setMatrixInFile(double **matrix, int matrixSize, FILE *f1) {
	int i, j;
	rewind(f1);
	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixSize; j++) {
			if (j != matrixSize - 1) {
				fprintf(f1, "%lf ", matrix[i][j]);
			}
			else {
				fprintf(f1, "%lf", matrix[i][j]);
			}
		}
		if (i != matrixSize - 1) {
			fprintf(f1, "\n");
		}
	}
	return true;
}