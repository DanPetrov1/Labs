#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Заголовок.h"
bool getQ(char item[40], struct pos *number) {
	struct items *prev = (struct items*)malloc(sizeof(struct items));
	if (!prev)
		return false;
	strcpy_s(prev->a, item);
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
void deleteAll(struct pos *number) {
	while (number->items > 0)
		deleteQ(number);
}
void deleteQ(struct pos *number) {
	struct items *current = number->begin;
	number->begin = number->begin->next;
	free(current);
	number->items--;
}
void search(char *s, char **arr) {
	int i = 0, l = 0, number = 0, j = 0;
	while (s[i] != '\0') {
		int flag = 0;
		while (!(s[i] >= 'A' && s[i] <= 'Z') && s[i] != '\0')	//Ищем конец числа
			i++;
		if (s[i] == '\0')
			break;
		l = 0;
		while (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
			arr[j][l] = s[i];	//Записываем число по разрядно
			i++;
			l++;
		}
		arr[j][l] = '\0';
		j++;
		i++;
	}
}