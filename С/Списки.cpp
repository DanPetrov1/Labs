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
	puts("������� ��� ������� ��������:");
	while (gets_s(input, 40) != NULL && input[0] != '\0') {	//������ �������� ������ � ��������� � ���������� ��������
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
		printf("������� ����� ��������: ");
		while (!scanf_s("%d", &current->length)) {
			rewind(stdin);
			printf("������� ����� ��������: ");
		}
		while (getchar() != '\n')
			continue;
		puts("������� ��� ���������� ��������:");
		prev = current;
	}
	if (head == NULL)
		puts("������ �� ���� �������!");
	else
		puts("��� ������:");
	current = head;
	while (current != NULL) {
		printf("������� �%d - %s, ����� ������ - %d\n", i++, current->FIO, current->length);	//���������� ������
		current = current->next;
	}
	current = head;
	while (current != NULL) {	//��������� ������� ������
		prev = current->next;
		free(current);
		current = prev;
	}
	system("pause");
	return 0;
}