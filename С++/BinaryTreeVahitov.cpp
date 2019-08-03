//#include <iostream>
//
//using namespace std;
//
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
//	cout << "Write the numbers. When you want to stop writing - press 0" << endl;
//	while (true) {
//		cin >> value;
//		while (!cin) {
//			cout << "error\n";
//			cin.clear();
//			while (cin.get() != '\n');
//		}
//		if (value == 0) {
//			break;
//		}
//		else {
//			if (!Insert(&Tree, value)) cout << "Error!\n";
//		}
//	}
//	cout << "Your tree:" << endl;
//	PrintTree(Tree->root, "root", 1);
//	level = FindHighestLevel(Tree->root, 1);
//	printf("The highest level of the treeis %d\n", level);
//	system("pause");
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
//void PrintTree(element *current, const char *dir, int level) {
//	if (current) {
//		printf("lvl %d %s = %d\n", level, dir, current->data);
//		PrintTree(current->left, "left", level + 1);
//		PrintTree(current->right, "right", level + 1);
//	}
//}
//
//void DeleteAll(element* current) {
//	if (current->right)
//		DeleteAll(current->right);
//	if (current->left)
//		DeleteAll(current->left);
//	free(current);
//}
//
//int FindHighestLevel(element* current, int level) {
//	static int min = 0;
//	if (level > min) {
//		min = level;
//	}
//	if (current->right) {
//		FindHighestLevel(current->right, level + 1);
//	}
//	if (current->left) {
//		FindHighestLevel(current->left, level + 1);
//	}
//	return min;
//}