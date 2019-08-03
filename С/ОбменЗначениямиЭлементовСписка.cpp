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
	puts("������� ��� ������� ��������:");
	while (gets_s(input, 40) != NULL && input[0] != '\0') {	//������ �������� ������ � ��������� � ���������� ��������
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
		printf("������� ����� ������ : $");
		while (!scanf_s("%d", &current->length)) {
			rewind(stdin);
			printf("������� ����� ������: $");
		}
		while (getchar() != '\n')
			continue;
		puts("������� ��� ���������� ��������:");
		prev = current;
	}
	if (head == NULL || head->next->next->next->next == NULL)
		puts("������ �������� ������ �� ���� �������!");
	current = head;	//���������� ��������� �� ������ ������� ������
	prev = head->next->next->next->next;	//���������� ��������� �� ����� ������� ������
	strcpy_s(input, current->FIO);	//�������� � �������� ���������� 1 ������� ���������
	strcpy_s(current->FIO, prev->FIO);	//� ������ ���������� ����������
	strcpy_s(prev->FIO, input);
	buffer = current->length;
	current->length = prev->length;	//��� �� ��������� � ������� ��������� (���������� ��, ����� ��������� �� ��������� �������)
	prev->length = buffer;
	puts("��� ������:");
	current = head;
	while (current != NULL) {
		printf("������� �%d - %s, ����� ������ - $%d\n", i++, current->FIO, current->length);	//���������� ������
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