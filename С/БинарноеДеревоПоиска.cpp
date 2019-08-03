#include<stdio.h>
#include<stdlib.h>
typedef struct position {
	int data;
	struct position *left;
	struct position *right;
	struct position *parent;
} Pos;
typedef struct tree {
	Pos *root;
} Tree;
int Sum(Pos*);
int bin_search(Tree *, int);
Pos *GetFree(int, Pos*);
void insert(Pos**, int);
Pos *getByValue(Pos*, int);
void remove(Pos*);
Pos* findMax(Pos*);
bool deleteValue(Pos*, int);
void printTree(Pos*, const char*, int);
void deleteAll(Pos*);
int main() {
	char a;
	int value, sum = 0;
	Pos *pos = NULL;
	Pos *current;
	system("chcp 1251>null");
	do {
		rewind(stdin);
		printf("�������� �������:\na. �������� ������� � ������.\nb. ������� ������� ������� � ������.\nc. ������� ������� ������ �� ��������.\nd. ����� �������.\ne. ������� ������ �� �����.\ns. ������� ����� ���������\nf. ��������� ���������\n");
		a = getchar();
		switch (a) {
		case 'a':
			printf("������� �����: ");
			while (!scanf_s("%d", &value)) {
				rewind(stdin);
				printf("������� �����: ");
			}
			insert(&pos, value);
			break;
		case 'b':
			remove(pos);
			break;
		case 'c':
			printf("������� �����: ");
			while (!scanf_s("%d", &value)) {
				rewind(stdin);
				printf("������� �����: ");
			}
			if(!deleteValue(pos, value))
				puts("������ �������� ��� � ������!");
			break;
		case 'd':
			printf("������� �����: ");
			while (!scanf_s("%d", &value)) {
				rewind(stdin);
				printf("������� �����: ");
			}
			if (current = getByValue(pos, value))
				printf("������ ����� - %d\n", current->data);
			else
				puts("������� ����� ��� � ������!");
			break;
		case 'e':
			printTree(pos, "root", 1);
			break;
		case 's':
			sum = Sum(pos);
			printf("����� ���� ��������� ����� %d\n", sum);
			break;
		default:
			puts("������� ���������� ������!");
			break;
		}
	} while (a != 'f');
	deleteAll(pos);
	return 0;
}
int bin_search(Tree *search_tree, int item) {
	Pos *search_node = search_tree->root;
	for (;;) {
		if (search_node == NULL) return 0;
		else if (item == search_node->data) return 1;
		else if (item > search_node->data) search_node = search_node->right;
		else search_node = search_node->left;
	}
}
Pos *GetFree(int value, Pos*parent) {
	Pos *tmp = (Pos*)malloc(sizeof(Pos));
	tmp->left = tmp->right = NULL;
	tmp->parent = parent;
	tmp->data = value;
	return tmp;
}

void insert(Pos **head, int value) {
	Pos *tmp = NULL;
	Pos *ins = NULL;
	if (*head == NULL) {
		*head = GetFree(value, NULL);
		return;
	}
	tmp = *head;
	while (tmp) {
		if (value > tmp->data) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			}
			else {
				tmp->right = GetFree(value, tmp);
				return;
			}
		}
		else if (value < tmp->data) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			}
			else {
				tmp->left = GetFree(value, tmp);
				return;
			}
		}
		else {
			return;
		}
	}
}
Pos *getByValue(Pos *root, int value) {
	while (root) {
		if (root->data > value) {
			root = root->left;
			continue;
		}
		else if (root->data < value) {
			root = root->right;
			continue;
		}
		else {
			return root;
		}
	}
	return NULL;
}
void remove(Pos*tmp) {
	if (tmp->left && tmp->right) {
		Pos *buffer = findMax(tmp->left);
		tmp->data = buffer->data;
		remove(buffer);
		return;
	}
	else if (tmp->left) {
		if (tmp == tmp->parent->left)
			tmp->parent->left = tmp->left;
		else
			tmp->parent->right = tmp->left;
	}
	else if (tmp->right) {
		if (tmp == tmp->parent->right)
			tmp->parent->right = tmp->right;
		else
			tmp->parent->left = tmp->right;
	}
	else {
		if (tmp->parent->right == tmp)
			tmp->parent->right = NULL;
		else
			tmp->parent->left = NULL;
	}
	free(tmp);
}
Pos *findMax(Pos *tmp) {
	while (tmp->right)
		tmp = tmp->right;
	return tmp;
}
bool deleteValue(Pos *root, int value) {
	Pos* tmp = getByValue(root, value);
	if (!tmp)
		return false;
	remove(tmp);
	return true;
}
void printTree(Pos *root, const char *dir, int level) {
	if (root) {
		printf("lvl %d %s = %d\n", level, dir, root->data);
		printTree(root->left, "left", level + 1);
		printTree(root->right, "right", level + 1);
	}
}
int Sum(Pos *pos) {
	static int sum = 0;
	if (pos) {
		sum += pos->data;
		Sum(pos->left);
		Sum(pos->right);
	}
	return sum;
}
void deleteAll(Pos* tmp) {
	if (tmp->right)
		deleteAll(tmp->right);
	if (tmp->left)
		deleteAll(tmp->left);
	free(tmp);
}