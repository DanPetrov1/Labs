#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct service {
	int number;
	char mark[20];
	double run;
	char FIOm[30];
	double sum;
};
void get(struct service *, int);
void sortmark(struct service *, int);
void sortsum(struct service *, int);
void sort(struct service *, int);
void del(struct service *, int);
int main() {
	system("chcp 1251>null");
	int n = 0, i, k, filecount;
	struct service clients[100];
	FILE *autos;
	if (fopen_s(&autos, "autoservice.pdf", "a+b") != NULL) {
		puts("Ошибка открытия файла");
		exit(1);
	}
	rewind(autos);
	while (n < 100 && fread(&clients[n], sizeof(struct service), 1, autos) == 1) {
		if (n == 0)
			puts("База данных клиентов:");
		printf("Клиент №%d - %d, марки %s, %.2lf километров пробежки, мастер - %s,\nсумма к оплате - %.2lf\n", n + 1, clients[n].number, clients[n].mark, clients[n].run, clients[n].FIOm, clients[n].sum);
		n++;
	}
	filecount = n;
	if (n == 100) {
		fputs("Файл заполнен!", stderr);
		exit(2);
	}
	if (n == 0) {
		printf("Введите количество клиентов: ");
		while (!scanf_s("%d", &i) || i < 0) {
			rewind(stdin);
			printf("Введите количество клиентов: ");
		}
		printf("Введите информацию о клиентах:\n");
		for (;n < i ; n++) {
			get(clients, n);
		}
		sort(clients, n);
	}
	do {
		system("CLS");
		if (n > 0) {
			puts("База данных клиентов:");
			for (i = 0; i < n; i++)
				printf("Клиент №%d - %d, марки %s, %.2lf километров пробежки, мастер - %s,\nсумма к оплате - %.2lf\n", i + 1, clients[i].number, clients[i].mark, clients[i].run, clients[i].FIOm, clients[i].sum);
			fwrite(&clients[filecount], sizeof(struct service), n - filecount, autos);
		}
		else {
			puts("База клиентов пуста!");
		}
		printf("\nВыберите вариант работы с базой клиентов:\n1. Отсортировать по сумме оплаты\n2. Отсортировать по маркам\n3. Отсортировать по регистрационному номеру\n4. Добавить клиента\n5. Выход из программы\n");
		while (!scanf_s("%d", &k) || k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6) {
			rewind(stdin);
		}
		switch (k) {
		case 1:
			sortsum(clients, n);
			break;
		case 2:
			sortmark(clients, n);
			break;
		case 3:
			sort(clients, n);
			break;
		case 4:
			get(clients, n);
			filecount = n++;
			break;
		}
	} while (k != 5);
	fclose(autos);
	return 0;
}
void sort(struct service * clients, int n) {
	int i, j;
	struct service buffer;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (clients[j - 1].number > clients[j].number) {
				buffer = clients[j];
				clients[j] = clients[j - 1];
				clients[j - 1] = buffer;
			}
		}
	}
}
void sortmark(struct service * clients, int n) {
	int i, j;
	struct service buffer;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (strcmp(clients[j - 1].mark, clients[j].mark) > 0) {
				buffer = clients[j];
				clients[j] = clients[j - 1];
				clients[j - 1] = buffer;
			}
		}
	}
}
void sortsum(struct service * clients, int n) {
	int i, j;
	struct service buffer;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (clients[j - 1].sum > clients[j].sum) {
				buffer = clients[j];
				clients[j] = clients[j - 1];
				clients[j - 1] = buffer;
			}
		}
	}
}
void get(struct service *clients, int i) {
	rewind(stdin);
	printf("Введите регистрационный номер автомобиля клиента №%d: ", i + 1);
	while (!scanf_s("%d", &(clients[i].number)) || (clients[i].number) < 1) {
		rewind(stdin);
		printf("Введите регистрационный номер автомобиля №%d: ", i + 1);
	}
	rewind(stdin);
	printf("Введите марку автомобиля клиента №%d: ", i + 1);
	gets_s(clients[i].mark, 20);
	printf("Введите пробежку автомобиля клиента №%d: ", i + 1);
	while (!scanf_s("%lf", &clients[i].run) || clients[i].run <= 0) {
		rewind(stdin);
		printf("Введите пробежку автомобиля клиента №%d: ", i + 1);
	}
	rewind(stdin);
	printf("Введите ФИО мастера, выполнившего ремонт автомобиля: ");
	gets_s(clients[i].FIOm, 30);
	printf("Введите сумму за ремонт $: ");
	while (!scanf_s("%lf", &clients[i].sum) || clients[i].sum < 0) {
		rewind(stdin);
		printf("Введите сумму за ремонт $: ");
	}
}