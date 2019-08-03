#include<stdio.h>
#include<stdlib.h>
void del(struct ints*);
struct ints {
	int a;
	struct ints *next;
};
int main() {
	int n, i;
	while (!scanf_s("%d", &n) || n < 1)
		rewind(stdin);
	int *ms = (int*)malloc(sizeof(int)*n);
	struct ints *head = NULL, *current, *prev = head;
	if (!ms)
		return 1;
	for (i = 0; i < n; i++) {
		while (!scanf_s("%d", &ms[i]))
			rewind(stdin);
		current = (struct ints*)malloc(sizeof(struct ints));
		if (!current)
			return 1;
		if (i == 0) {
			head = current;
			current->a = ms[i];
			current->next = NULL;
			prev = current;
		}
		else if (i != 0 && i != n - 1) {
			prev->next = current;
			current->a = ms[i];
			current->next = NULL;
			prev = current;
		}
		else {
			prev->next = current;
			current->a = ms[i];
			current->next = NULL;
			prev = current;
		}
	}
	current = head;
	struct ints *buffer = (struct ints*)malloc(sizeof(struct ints));
	while (current != NULL) {
		if (current->a == 0)
			del(current);
		else
			current = current->next;
	}
	current = head;
	while (current) {
		printf("%d ", current->a);
		current = current->next;
	}
	current = head;
	while (current != NULL) {	//Поадресно очищаем память
		prev = current->next;
		free(current);
		current = prev;
	}
	system("pause");
	free(ms);
	return 0;
}
void del(struct ints *s) {
	struct ints *temp = (struct ints*)malloc(sizeof(struct ints));
	*temp = *s;
	*s = *s->next;
	free(temp);
}