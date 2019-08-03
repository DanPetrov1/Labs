#include<stdio.h>
#include<stdlib.h>
typedef struct pos {
	struct stack *down;
	struct stack *up;
	int items;
} Pos;
typedef struct stack {
	int k;
	struct stack *next;
} Stack;
bool getS(Pos *);
bool deleteS(Pos *);
void showS(Pos *);
void deleteAll(Pos *);
int main() {
	int n;
	system("chcp 1251>null");
	Pos *number = (Pos*)malloc(sizeof(Pos));
	if (!number)
		return 1;
	number->items = 0;
	do {
		printf("�������� �������:\n1. �������� ������� � ����.\n2. ������� ������� �� �����.\n3. ������� ���� �� �����.\n4. ����� �� ���������.\n");
		while (!scanf_s("%d", &n))
			rewind(stdin);
		switch (n) {
		case 1:
			if (getS(number))
				puts("������� �������� � ����!");
			else
				puts("������ ����������!");
			break;
		case 2:
			if (deleteS(number))
				puts("������� ������� ����� �����!");
			else
				puts("���� ����!");
			break;
		case 3:
			showS(number);
			break;
		}
	} while (n != 4);
	if (number->items > 0)
		deleteAll(number);
	return 0;
}
bool getS(Pos *number) {
	Stack *prev = (Stack*)malloc(sizeof(Stack));
	if (!prev)
		return false;
	while (!scanf_s("%d", &prev->k))
		rewind(stdin);
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
	return true;
}
bool deleteS(Pos *number) {
	if (number->items > 0) {
		Stack *prev = number->up;
		number->up = number->up->next;
		free(prev);
		number->items--;
		return true;
	}
	else
		return false;
}
void showS(Pos *number) {
	Stack *prev = number->up;
	if (number->items > 0) {
		printf("�������� �����: ");
		while (prev) {
			printf("%d ", prev->k);
			prev = prev->next;
		}
	}
	else
		puts("���� ����!");
}
void deleteAll(Pos * number) {
	while (number->up) {
		Stack *prev = number->up;
		number->up = number->up->next;
		free(prev);
		number->items--;
	}
}