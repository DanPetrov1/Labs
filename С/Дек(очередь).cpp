#include<stdio.h>
#include<stdlib.h>
struct pos {
	struct items *right;
	struct items *left;
	int items;
};
struct items {
	char a;
	struct items *next;
};
void deleteQ(struct pos *number);
bool getEl(char, struct pos*, int);
int main() {
	system("chcp 1251>null");
	int max, i = 0;
	char k, q;
	printf("������� ������������ ������ �������: ");
	while (!scanf_s("%d", &max) || max < 1) {
		rewind(stdin);
		printf("������� ������������ ������ �������: ");
	}
	struct items *prev = NULL;
	struct pos *number = (struct pos*)malloc(sizeof(struct pos));
	if (!number)
		return 1;
	number->items = 0;
	while (1) {
		rewind(stdin);
		printf("������� ������� �������: ");
		k = getchar();
		if (number->items != 0 && k == q)
			break;
		if (number->items >= max) {
			puts("������� �����������!");
			break;
		}
		if (getEl(k, number, i++)) {
			puts("������� ������� ��������!");
		}
		else {
			puts("������ ����������!");
		}
		q = k;
	}
	while (number->items > 0) {
		prev = number->left;
		printf("������ �������: ");
		while (prev != number->right->next) {
			printf("%c ", prev->a);
			prev = prev->next;
		}
		printf("\n");
		deleteQ(number);
	}
	system("pause");
	return 0;
}
bool getEl(char k, struct pos *number, int i) {
	struct items *prev = (struct items*)malloc(sizeof(struct items));
	if (!prev)
		return false;
	prev->a = k;
	prev->next = NULL;
	if (i % 2 == 0) {
		if (i < 2) 
			number->right = prev;
		else {
			number->right->next = prev;
			number->right = prev;
		}
	}
	else {
		if (i < 2) {
			number->left = prev;
			number->left->next = number->right;
		}
		else {
			prev->next = number->left;
			number->left = prev;
		}
	}
	number->items++;
	return true;
}
void deleteQ(struct pos *number) {
	struct items *current = number->left;
	number->left = number->left->next;
	free(current);
	number->items--;
}