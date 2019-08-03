#include<stdio.h>
#include<stdlib.h>
typedef struct pos {
	struct stack *down;
	struct stack *up;
	int items;
} Pos;
typedef struct stack {
	char k;
	struct stack *next;
} Stack;
bool getS(Pos *, char);
void showS(Pos *);
void deleteAll(Pos *);
int main() {
	int n;
	char a;
	system("chcp 1251>null");
	Pos *number = (Pos*)malloc(sizeof(Pos));
	if (!number)
		return 1;
	printf("¬ведите максимальный размер стека: ");
	while (!scanf_s("%d", &n) || n < 1) {
		rewind(stdin);
		printf("¬ведите максимальный размер стека: ");
	}
	number->items = 0;
	puts("¬водите элементы:");
	while (number->items < n) {
		rewind(stdin);
		a = getchar();
		if (number->items != 0 && a == number->up->k) {
			printf("¬ведЄн повторный элемент %c\n", a);
			break;
		}
		getS(number, a);
	}
	showS(number);
	if (number->items > 0)
		deleteAll(number);
	system("pause");
	return 0;
}
bool getS(Pos *number, char a) {
	Stack *prev = (Stack*)malloc(sizeof(Stack));
	if (!prev)
		return false;
	prev->k = a;
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
void showS(Pos *number) {
	Stack *prev = number->up;
	if (number->items > 0) {
		printf("Ёлементы стека: ");
		while (prev) {
			printf("%c ", prev->k);
			prev = prev->next;
		}
	}
	else
		puts("—тек пуст!");
}
void deleteAll(Pos * number) {
	while (number->up) {
		Stack *prev = number->up;
		number->up = number->up->next;
		free(prev);
		number->items--;
	}
}