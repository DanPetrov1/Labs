#include<stdio.h>
#include<stdlib.h>
struct bit {
	unsigned int last : 1;
};
int main() {
	system("chcp 1251>null");
	bit* point;
	int num;
	printf("Введите число: ");
	while (!scanf_s("%d", &num))
		rewind(stdin);
	point = (bit*)&num;
	if (point->last)
		puts("Остаток равен 1.");
	else
		puts("Остаток равен 0.");
	system("pause");
	return 0;
}