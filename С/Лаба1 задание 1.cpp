#include<stdio.h>
#include<stdlib.h>
struct bit {
	unsigned int last : 1;
};
int main() {
	system("chcp 1251>null");
	bit* point;
	int num;
	printf("������� �����: ");
	while (!scanf_s("%d", &num))
		rewind(stdin);
	point = (bit*)&num;
	if (point->last)
		puts("������� ����� 1.");
	else
		puts("������� ����� 0.");
	system("pause");
	return 0;
}