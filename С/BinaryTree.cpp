//#include<stdio.h>
//#include<stdlib.h>
//struct element {
//	int data;
//	struct element *left;
//	struct element *right;
//	struct element *parent;
//};
//
//struct tree {
//	element *root;
//};
//
//tree* GetTree(int);
//element *SetElement(int, element*);
//bool Insert(tree**, int);
//void PrintTree(element*, const char*, int);
//void DeleteAll(element*);
//int FindHighestLevel(element*, int);
//
//int main() {
//	int value, level;
//	tree *Tree = NULL;
//	puts("Write the numbers. When you want to stop writing - press 0");
//	do {
//		rewind(stdin);
//		while (!scanf_s("%d", &value)) {
//			rewind(stdin);
//			printf("Write the number: ");
//		}
//		if (!Insert(&Tree, value)) {
//			puts("We can't add this element!");
//		}
//	} while (value != 0);
//	puts("Your tree:");
//	PrintTree(Tree->root, "root", 1);
//	level = FindHighestLevel(Tree->root, 1);
//	printf("The highest level of the tree with positive number is %d\n", level);
//	getchar();
//	getchar();
//	DeleteAll(Tree->root);
//	free(Tree);
//	return 0;
//}
//
//element *SetElement(int value, element*parent) {
//	element *current = (element*)malloc(sizeof(element));
//	current->left = current->right = NULL;
//	current->parent = parent;
//	current->data = value;
//	return current;
//}
//
//tree* GetTree(int value) {
//	tree*current = (tree*)malloc(sizeof(tree));
//	if (!current) {
//		return NULL;
//	}
//	current->root = SetElement(value, NULL);
//	return current;
//}
//
//bool Insert(tree **Tree, int value) {
//	element *current = NULL;
//	element *another = NULL;
//	if (*Tree == NULL) {
//		if ((*Tree = GetTree(value)) == NULL) {
//			return false;
//		}
//		return true;
//	}
//	current = (*Tree)->root;
//	while (current) {
//		if (value > current->data) {
//			if (current->right) {
//				current = current->right;
//				continue;
//			}
//			else {
//				if ((current->right = SetElement(value, current)) == NULL) {
//					return false;
//				}
//				return true;
//			}
//		}
//		else if (value < current->data) {
//			if (current->left) {
//				current = current->left;
//				continue;
//			}
//			else {
//				if ((current->left = SetElement(value, current)) == NULL) {
//					return false;
//				}
//				return true;
//			}
//		}
//		else {
//			return false;
//		}
//	}
//}
//
//void PrintTree(element *current, const char *directory, int level) {
//	if (current) {
//		printf("lvl %d %s = %d\n", level, directory, current->data);
//		PrintTree(current->left, "left", level + 1);
//		PrintTree(current->right, "right", level + 1);
//	}
//}
//
//void DeleteAll(element* current) {
//	if (current->right) {
//		DeleteAll(current->right);
//	}
//	if (current->left) {
//		DeleteAll(current->left);
//	}
//	free(current);
//}
//
//int FindHighestLevel(element* current, int level) {
//	static int min = 0;
//	if (current->data > 0) {
//		if (level > min) {
//			min = level;
//		}
//	}
//	if (current->right) {
//		FindHighestLevel(current->right, level + 1);
//	}
//	if (current->left) {
//		FindHighestLevel(current->left, level + 1);
//	}
//	return min;
//}