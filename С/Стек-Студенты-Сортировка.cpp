#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct pos {
	struct stack *down;
	struct stack *up;
	int items;
} Pos;
typedef struct stack {
	char FIO[40];
	char faculty[10];
	int birthday;
	struct stack *next;
} Stack;
void sort(Pos*);
void getS(Pos *, char*);
void showS(Pos *);
void deleteAll(Pos *);
int main() {
	int n;
	char a[40];
	system("chcp 1251>null");
	Pos *number = (Pos*)malloc(sizeof(Pos));
	if (!number)
		return 1;
	printf("Введите максимальный размер стека: ");
	while (!scanf_s("%d", &n) || n < 1) {
		rewind(stdin);
		printf("Введите максимальный размер стека: ");
	}
	number->items = 0;
	puts("Вводите информацию о студентах, если хотите прекратить ввод - нажмите Enter:");
	while (number->items < n) {
		rewind(stdin);
		printf("Введите ФИО студента: ");
		if (!gets_s(a, 40) || a[0] == '\0') {
			break;
		}
		getS(number, a);
		if (number->items == n)
			puts("Стек заполнен!");
	}
	sort(number);
	showS(number);
	if (number->items > 0)
		deleteAll(number);
	system("pause");
	return 0;
}
void getS(Pos *number, char *a) {
	Stack *prev = (Stack*)malloc(sizeof(Stack));
	if (!prev)
		return;
	printf("Введите факультет: ");
	gets_s(prev->faculty, 10);
	printf("Введите год рождения студента: ");
	while (!scanf_s("%d", &prev->birthday) || prev->birthday < 1) {
		rewind(stdin);
		printf("Введите год рождения студента: ");
	}
	strcpy_s(prev->FIO, a);
	prev->next = NULL;
	if (number->items == 0) {
		number->down = prev;
		number->up = prev;
	}
	else {
		prev->next = number->up;
		number->up = prev;
	}
	number->items++;
}
void showS(Pos *number) {
	Stack *prev = number->up;
	if (number->items > 0) {
		printf("Элементы стека: ");
		while (prev) {
			printf("Студент %s, %d года рождения, факультет %s\n", prev->FIO, prev->birthday, prev->faculty);
			prev = prev->next;
		}
	}
	else
		puts("Стек пуст!");
}
void deleteAll(Pos * number) {
	while (number->up) {
		Stack *prev = number->up;
		number->up = number->up->next;
		free(prev);
		number->items--;
	}
}
void sort(Pos *number) {
	Stack *buffer, *min, *s = number->up;
	char a[10], b[40];
	int k;
	for (; s->next; s = s->next) {
		min = s;
		for (buffer = s; buffer; buffer=buffer->next)
			if (min->birthday > buffer->birthday) {
				strcpy_s(a, min->faculty);
				strcpy_s(min->faculty, buffer->faculty);
				strcpy_s(buffer->faculty, a);
				strcpy_s(b, min->FIO);
				strcpy_s(min->FIO, buffer->FIO);
				strcpy_s(buffer->FIO, b);
				k = min->birthday;
				min->birthday = buffer->birthday;
				buffer->birthday = k;
			}
	}
}