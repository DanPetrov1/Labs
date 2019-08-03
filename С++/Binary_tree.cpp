/*#include <iostream>

using namespace std;

char menu();
int enter();*/
/*
 А. Создать сбалансированное дерево поиска, состоящее из целых чисел.
Вывести информацию на экран, используя прямой, обратный и симметричный
обход дерева. Выполнить задание, результат вывести на экран. В конце рабо-
ты освободить всю динамически выделенную память.
А4. Найти количество листов в правом поддереве.
 B. Создать сбалансированное дерево поиска, состоящее из целых чисел.
Вывести информацию на экран, используя прямой, обратный и симметричный
обход дерева. Выполнить задание, результат вывести на экран. В конце рабо-
ты освободить всю динамически выделенную память.
B4. Удалить в дереве все узлы, имеющие отрицательные ключи.*/

/*struct node {
	int data;
	node* left = nullptr;
	node* right = nullptr;
	node* parent = nullptr;
};

class tree {
public:
	node* root;
	tree() { root = nullptr; };
	~tree() = default;

	node* set_element(int value, node* parent);
	void insert(int data);
	node* search(int data);

	// DFS -- поиск в глубину (Depth-first search) 
	void preorder(node* root);  // предварительный обход
	void reverseinorder(node* root);  // симметричный обход
	void postorder(node* root); // обход в обратном порядке

	void deletenode(node* root);
	void deleteAll(node*);

	node* min(node* root);
	node* max(node* root);
	int getsize(node* root);

	// labs
	int A_4(node* root);
	void B_4(node* root);
};

int enter() {
	int n;

	while (true) {
		cin >> n;
		if (!cin) {  // == cin.fail()
			cout << "error\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	return n;
}

node* tree::min(node* root) {
	while (root->left != nullptr) root = root->left;
	return root;
}

node* tree::max(node * root) {
	if (!root) return nullptr;
	while (root->right != nullptr) root = root->right;
	return root;
}

int tree::getsize(node * root) {
	if (root == nullptr)
		return 0;
	return getsize(root->left) + getsize(root->right) + 1;
}

void tree::preorder(node* root) {  // root -- left -- right
	if (root == nullptr)
		return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void tree::reverseinorder(node * root) {  // left -- root -- right
	if (root == nullptr)
		return;

	preorder(root->left);
	cout << root->data << " ";
	preorder(root->right);
}

void tree::postorder(node * root) {  // left -- right -- root
	if (root == nullptr)
		return;

	preorder(root->left);
	preorder(root->right);
	cout << root->data << " ";
}

node* tree::set_element(int value, node* parent) {
	node* tmp = new node;
	tmp->left = tmp->right = NULL;
	tmp->parent = parent;
	tmp->data = value;
	return tmp;
}

void tree::insert(int data) {  // iterative insert
	node* tmp = root;
	if (root == nullptr) {
		root = set_element(data, nullptr);
		return;
	}
	while (tmp) {
		if (data > tmp->data) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			}
			else {
				tmp->right = set_element(data, tmp);
				return;
			}
		}
		else if (data < tmp->data) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			}
			else {
				tmp->left = set_element(data, tmp);
				return;
			}
		}
		else {
			return;
		}
	}
}

void tree::deletenode(node* tmp) {
	if (tmp->left && tmp->right) {
		node* buffer = max(tmp->left);
		tmp->data = buffer->data;
		deletenode(buffer);
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
			tmp->parent->right = nullptr;
		else
			tmp->parent->left = nullptr;
	}
	free(tmp);
}

node* tree::search(int data) {
	int d = 0;
	if (root == nullptr)
		return nullptr;

	node * curr = root;
	while (curr->data != data) {
		if (curr == nullptr) {
			cout << "there is no such data" << endl; return nullptr;
		}

		if (curr->data > data) {  // go left
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
		d++;
	}
	if (curr != nullptr)
		cout << endl << endl << curr->data << "'s depth is " << d << endl << endl;
	return curr;
}



char menu() {
	char choice;
	cout << "1. Show tree" << endl;
	cout << "2. Show tree by the symmetry tracking" << endl;
	cout << "3. Show tree by backtracking" << endl;
	cout << "4. Find the element of the tree" << endl;
	cout << "A. Выполнить задание A лабораторной работы:  " << endl;
	cout << "B. Выполнить задание B лабораторной работы:  " << endl;
	cout << "0. Exit" << endl;

	cout << endl << "Choice: ";
	cin >> choice;
	return choice;

}

int tree::A_4(node* root) {
	static int number = 0;
	if (root == nullptr) {  // на случай пустого дерева
		return number;
	}
	number++;
	A_4(root->left);
	A_4(root->right);
	return number;
}

void tree::B_4(node* tmp) {
	if (!tmp) return;
	if (tmp->data < 0) {
		deletenode(tmp);
		B_4(root);
	}
	else {
		B_4(tmp->left);
		B_4(tmp->right);
	}
}

void tree::deleteAll(node* tmp) {
	if (tmp->right)
		deleteAll(tmp->right);
	if (tmp->left)
		deleteAll(tmp->left);
	free(tmp);
}

int main() {
	int value;
	tree my_tree;
	system("chcp 1251>null");
	cout << "Write the element of the binary tree. If you want to stop - write 0" << endl;
	while (true) {
		cin >> value;
		while (!cin) {
			cout << "error\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		if (value == 0) {
			break;
		}
		else {
			my_tree.insert(value);
		}
	}
	char choice;
	do {
		choice = menu();
		switch (choice) {
		case '1': my_tree.preorder(my_tree.root); cout << endl; break;
		case '2': my_tree.reverseinorder(my_tree.root); cout << endl; break;
		case '3': my_tree.postorder(my_tree.root); cout << endl; break;
		case '4': value = enter(); my_tree.search(value); break;
		case 'A': cout << "The number of leaves in the right part " << my_tree.A_4(my_tree.root->right) << endl; break;
		case 'B': my_tree.B_4(my_tree.root); my_tree.preorder(my_tree.root); cout << endl; break;
		case '0': cout << "exit." << endl; break;
		default: cout << "Wrong choice. Try again." << endl;
		}
	} while (choice != '0');
	if (my_tree.root) {
		my_tree.deleteAll(my_tree.root);
	}
	return 0;
}*/