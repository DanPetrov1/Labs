#include<stdio.h>
#include<stdlib.h>
typedef struct position {
	int data;
	struct position *left;
	struct position *right;
	struct position *parent;
} Pos;
void deleteAll(Pos*);
void getTree(Pos**, int, int);
Pos *GetFree(int, Pos*);
void printTree(Pos*, const char*, int);
int main() {
	system("chcp 1251>null");
	Pos *pos = NULL;
	int n;
	printf("¬ведите число: ");
	while (!scanf_s("%d", &n) || n < 1) {
		rewind(stdin);
		printf("¬ведите число: ");
	}
	getTree(&pos, n, 1);
	printTree(pos, "root", 1);
	system("pause");
	deleteAll(pos);
	return 0;
}
void deleteAll(Pos* tmp) {
	if (tmp->right)
		deleteAll(tmp->right);
	if (tmp->left)
		deleteAll(tmp->left);
	free(tmp);
}
void printTree(Pos *root, const char *dir, int level) {
	if (root) {
		printf("lvl %d %s = %d\n", level, dir, root->data);
		printTree(root->left, "left", level + 1);
		printTree(root->right, "right", level + 1);
	}
}
void getTree(Pos** pos, int n, int i) {
	if (i <= n) {
		if (i == 1) {
			*pos = GetFree(i, NULL);
			getTree(&(*pos), n, i + 1);
			getTree(&(*pos), n, i + 1);
		}
		else {
			Pos *tmp = *pos;
			tmp->left = GetFree(i, tmp);
			tmp->right = GetFree(i, tmp);
			getTree(&tmp->left, n, i + 1);
			getTree(&tmp->right, n, i + 1);
		}
	}
}
Pos *GetFree(int value, Pos*parent) {
	Pos *tmp = (Pos*)malloc(sizeof(Pos));
	tmp->left = tmp->right = NULL;
	tmp->parent = parent;
	tmp->data = value;
	return tmp;
}