#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pisos {
	char FIO[40];
	int length;
	struct pisos *next;
};
int main() {
	int i = 1;
	char input[40];
	system("chcp 1251 > null");
	struct pisos *head = NULL;
	struct pisos *current, *prev = head;
	puts("Введите ФИО первого человека:");
	while (gets_s(input, 40) != NULL && input[0] != '\0') {	//Вводим элементы списка с переходом к следующему элементу
		current = (struct pisos*)malloc(sizeof(struct pisos));
		if (!current)
			return 1;
		if (head == NULL) {
			head = current;
			head->next = NULL;
		}
		else
			prev->next = current;
		current->next = NULL;
		strcpy_s(current->FIO, input);
		printf("Введите длину агрегата: ");
		while (!scanf_s("%d", &current->length)) {
			rewind(stdin);
			printf("Введите длину агрегата: ");
		}
		while (getchar() != '\n')
			continue;
		puts("Введите ФИО следующего человека:");
		prev = current;
	}
	if (head == NULL)
		puts("Данные не были введены!");
	else
		puts("Ваш список:");
	current = head;
	while (current != NULL) {
		printf("Человек №%d - %s, длина писоса - %d\n", i++, current->FIO, current->length);	//Выписываем список
		current = current->next;
	}
	current = head;
	while (current != NULL) {	//Поадресно очищаем память
		prev = current->next;
		free(current);
		current = prev;
	}
	system("pause");
	return 0;
}