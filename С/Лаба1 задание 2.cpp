/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct perimetr {
	double p;
	char color[15];
};
struct figure {
	char *name;
	double area;
	perimetr* per;
};
void get(figure*, int);
void deleteS(figure*, int);
void show(figure*, int);
int main() {
	int n, i, k;
	figure*str;
	system("chcp 1251>null");
	printf("Введите количество элементов структуры: ");
	while (!scanf_s("%d", &n) || n < 1)
		rewind(stdin);
	while (!(str = (figure*)malloc(sizeof(figure)*n)))
		figure *str = (figure*)malloc(sizeof(figure)*n);
	for (i = 0; i < n; i++) {
		while (!(str[i].per = (perimetr*)malloc(sizeof(perimetr))))
			str[i].per = (perimetr*)malloc(sizeof(perimetr));
	}
	get(str, n);
	do {
		printf("Выберите вариант:\n1. Вывести фигуры с площадью меньше заданной.\n2. Удалить фигуры по названию.\n3. Выход из программы.\n");
		while (!scanf_s("%d", &k) || k != 1 && k != 2 && k != 3)
			rewind(stdin);
		switch (k) {
		case 1:
			show(str, n);
			break;
		case 2:
			deleteS(str, n--);
			break;
		}
	} while (k != 3);
	system("pause");
	free(str);
	return 0;
}
void get(figure* str, int n) {
	printf("Введите элементы структуры:\n");
	for (int i = 0; i < n; i++) {
		printf("Введите информацию о фигуре №%d:\n", i + 1);
		rewind(stdin);
		while (!(str[i].name = (char*)malloc(sizeof(char) * 15)))
			str[i].name = (char*)malloc(sizeof(char) * 15);
		printf("Введите название: ");
		gets_s(str[i].name, 15);
		printf("Введите её площадь: ");
		while (!scanf_s("%lf", &str[i].area) || str[i].area < 0)
			rewind(stdin);
		printf("Введите её периметр: ");
		while (!scanf_s("%lf", &str[i].per->p) || str[i].per->p < 0)
			rewind(stdin);
		rewind(stdin);
		printf("Введите цвет фигуры: ");
		gets_s(str[i].per->color, 15);
	}
}
void deleteS(figure* str, int n) {
	char *s, k;
	int j, flag, q, l;
	rewind(stdin);
	printf("Введите название фигуры которую хотите удалить: ");
	while (!(s = (char*)malloc(sizeof(char) * 15)))
		s = (char*)malloc(sizeof(char) * 15);
	gets_s(s, 15);
	for (j = 0; j < n; j++) {
		for (flag = 0, q = 0; q < 15; q++) {
			if (str[j].name[q] != s[q])
				flag = 1;
		}
		if (flag == 0) {
			for (l = j; l < n - 1; l++) {
				str[l] = str[l + 1];
			}
			str = (figure*)realloc(str, sizeof(figure) * --n);
			j--;
		}
	}
}
void show(figure* str, int n) {
	double value;
	int flag = 0, i;
	printf("Введите площадь: ");
	while (!scanf_s("%lf", &value))
		rewind(stdin);
	for (i = 0; i < n; i++) {
		if (str[i].area < value) {
			flag = 1;
			printf("Фигура %s: площадь %lf, периметр - %lf цвета %s.\n", str[i].name, str[i].area, str[i].per->p, str[i].per->color);
		}
	}
	if (flag == 0)
		printf("Фигур с меньшей площадью нет!\n");
}*/