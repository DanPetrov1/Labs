#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct service {
	int number;
	char mark[20], FIOm[30];
	double run, sum;
};
void get(struct service *, int);
void sortmark(struct service *, int);
void sortsum(struct service *, int);
void sort(struct service *, int);
void del(struct service *, int);
int main() {
	system("chcp 1251>null");
	int n, i, k;
	struct service *clients;
	fputs("Введите количество клиентов, принявших наши услуги: ", stdout);
	while (!fscanf_s(stdin, "%d", &n) || n < 1) {
		rewind(stdin);
		fputs("Введите количество клиентов, принявших наши услуги: ", stdout);
	}
	clients = (struct service*)malloc(sizeof(struct service)*n);
	if (!clients)
		return 1;
	fputs("Введите информацию о клиентах:\n", stdout);
	for (i = 0; i < n; i++) {
		get(clients, i);
	}
	sort(clients, n);
	do {
		system("CLS");
		fputs("База данных клиентов:\n", stdout);
		for (i = 0; i < n; i++) {
			fprintf(stdout, "Клиент №%d - %d, марки %s, %.2lf километров пробежки, мастер - %s,\nсумма к оплате - %.2lf\n", i + 1, clients[i].number, clients[i].mark, clients[i].run, clients[i].FIOm, clients[i].sum);
		}
		fprintf(stdout, "\nВыберите вариант работы с базой клиентов:\n1. Отсортировать по сумме оплаты\n2. Отсортировать по маркам\n3. Отсортировать по регистрационному номеру\n4. Добавить клиента\n5. Удалить клиента\n6. Выход из программы\n");
		while (!fscanf_s(stdin, "%d", &k) || k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6) {
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
			clients = (struct service*)realloc(clients, sizeof(struct service)* ++n);
			if (!clients)
				return 1;
			get(clients, n - 1);
			break;
		case 5:
			del(clients, n);
			n--;
			break;
		}
	} while (k != 6);
	system("pause");
	free(clients);
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
void del(struct service * clients, int n) {
	int i;
	fprintf(stdout, "Введите номер клиента, который следует удалить: ");
	while (!fscanf_s(stdin, "%d", &i) || i > n || i < 1) {
		rewind(stdin);
		fprintf(stdout, "Введите номер клиента, который следует удалить: ");
	}
	for (; i < n; i++) {
		clients[i - 1] = clients[i];
	}
	clients = (struct service*)realloc(clients, sizeof(struct service)* --n);
	if (!clients)
		return;
}
void get(struct service *clients, int i) {
	rewind(stdin);
	fprintf(stdout, "Введите регистрационный номер автомобиля клиента №%d: ", i + 1);
	while (!fscanf_s(stdin, "%d", &(clients[i].number)) || (clients[i].number) < 1) {
		rewind(stdin);
		fprintf(stdout, "Введите регистрационный номер автомобиля №%d: ", i + 1);
	}
	rewind(stdin);
	fprintf(stdout, "Введите марку автомобиля клиента №%d: ", i + 1);
	gets_s(clients[i].mark, 20);
	fprintf(stdout, "Введите пробежку автомобиля клиента №%d: ", i + 1);
	while (!fscanf_s(stdin, "%lf", &clients[i].run) || clients[i].run <= 0) {
		rewind(stdin);
		fprintf(stdout, "Введите пробежку автомобиля клиента №%d: ", i + 1);
	}
	rewind(stdin);
	fprintf(stdout, "Введите ФИО мастера, выполнившего ремонт автомобиля: ");
	gets_s(clients[i].FIOm, 30);
	fprintf(stdout, "Введите сумму за ремонт $: ");
	while (!fscanf_s(stdin, "%lf", &clients[i].sum) || clients[i].sum < 0) {
		rewind(stdin);
		fprintf(stdout, "Введите сумму за ремонт $: ");
	}
}