#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct clients {
	char FIO[40];
	int length;
	struct clients *next;
};
int main() {
	int i = 1, buffer;
	char input[40];
	system("chcp 1251 > null");
	struct clients *head = NULL;
	struct clients *current, *prev = head;
	puts("Введите ФИО первого человека:");
	while (gets_s(input, 40) != NULL && input[0] != '\0') {	//Вводим элементы списка с переходом к следующему элементу
		current = (struct clients*)malloc(sizeof(struct clients));
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
		printf("Введите сумму оплаты : $");
		while (!scanf_s("%d", &current->length)) {
			rewind(stdin);
			printf("Введите сумму оплаты: $");
		}
		while (getchar() != '\n')
			continue;
		puts("Введите ФИО следующего человека:");
		prev = current;
	}
	if (head == NULL || head->next->next->next->next == NULL)
		puts("Данные элементы списка не были введены!");
	current = head;	//Обозначаем указатель на первый элемент списка
	prev = head->next->next->next->next;	//Обозначаем указатель на пятый элемент списка
	strcpy_s(input, current->FIO);	//копируем в буферную переменную 1 элемент структуры
	strcpy_s(current->FIO, prev->FIO);	//и просто обмениваем значениями
	strcpy_s(prev->FIO, input);
	buffer = current->length;
	current->length = prev->length;	//Так же поступаем с интовым значением (обмениваем всё, кроме указателя на следующий элемент)
	prev->length = buffer;
	puts("Ваш список:");
	current = head;
	while (current != NULL) {
		printf("Человек №%d - %s, сумма оплаты - $%d\n", i++, current->FIO, current->length);	//Выписываем список
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