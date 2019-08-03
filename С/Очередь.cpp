#include<stdio.h>
#include<stdlib.h>
struct pos {
	struct items *begin;
	struct items *end;
	int items;
};
struct items {
	char a;
	struct items *next;
};
void deleteQ(struct pos *number);
bool getEl(char , struct pos*);
int main() {
	system("chcp 1251>null");
	int max;
	char k, q;
	printf("Введите максимальный размер очереди: "); 
	while (!scanf_s("%d", &max) || max < 1) {
		rewind(stdin);
		printf("Введите максимальный размер очереди: ");
	}
	struct items *prev = NULL;
	struct pos *number = (struct pos*)malloc(sizeof(struct pos));
	if (!number)
		return 1;
	number->items = 0;
	while (1) {
		rewind(stdin);
		printf("Введите элемент очереди: ");
		k = getchar();
		if (number->items != 0 && k == q)
			break;
		if (number->items >= max) {
			puts("Очередь переполнена!");
			break;
		}
		if (getEl(k, number)) {
			puts("Элемент очереди добавлен!");
		}
		else {
			puts("Ошибка добавления!");
		}
		q = k;
	}
	while (number->items > 0) {
		prev = number->begin;
		printf("Данная очередь: ");
		while (prev != number->end->next) {
			printf("%c ", prev->a);
			prev = prev->next;
		}
		printf("\n");
		deleteQ(number);
	}
	system("pause");
	return 0;
}
bool getEl(char k, struct pos *number) { 
	struct items *prev = (struct items*)malloc(sizeof(struct items));
	if (!prev)
		return false;
	prev->a = k;
	prev->next = NULL;
	if (number->items == 0) {
		number->begin = prev;
	}
	else {
		number->end->next = prev;
	}
	number->end = prev;
	number->items++;
	return true;
}
void deleteQ(struct pos *number) {
	struct items *current = number->begin;
	number->begin = number->begin->next;
	free(current);
	number->items--;
}