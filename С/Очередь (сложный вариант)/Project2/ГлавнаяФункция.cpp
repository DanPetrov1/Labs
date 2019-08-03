#include<stdio.h>
#include<stdlib.h>
#include"Заголовок.h"
int main() {
	system("chcp 1251>null");
	int i = 0, sum = 0, j;
	char *s = (char*)malloc(sizeof(char) * 100);
	if (!s)
		return 1;
	puts("Введите строку");
	gets_s(s, 100);
	char **arr = (char**)malloc(sizeof(char*)*10);
	if (!arr)
		return 1;
	for (j = 0; j < 10; j++) {
		arr[j] = (char*)malloc(sizeof(char) * 40);
		if (!arr[j]) {
			free(arr);
			return 1;
		}
	}
	search(s, arr);
	struct items *prev = NULL;
	struct pos *number = (struct pos*)malloc(sizeof(struct pos));
	if (!number)
		return 1;
	number->items = 0;
	while (arr[i][0] >= 'A' && arr[i][0] <= 'Z') {
		if (!getQ(arr[i], number))
			puts("Ошибка добавления числа в очредь!");
		i++;
	}
	prev = number->begin;
	printf("Данная очередь: \n");
	while (prev != number->end->next) {
		puts(prev->a);
		prev = prev->next;
	}
	printf("Всего элементов очереди: %d\n", number->items);
	deleteAll(number);
	system("pause");
	free(number);
	free(arr);
	free(s);
	return 0;
}