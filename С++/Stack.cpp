#include <iostream>

using namespace std;

/*
	А. Создать стек, состоящий из n целых чисел. Выполнить задание, результат вывести на экран.
В конце работы освободить всю динамически выделенную память.

	А4. Найти произведение нечётных элементов стека.

	В. Создать стек, состоящий из n целых чисел. Выполнить задание. Информационную
часть в оперативной памяти не перемещать. Результат вывести на экран.
В конце работы освободить всю динамически выделенную память.

	В4. Поменять местами второй и предпоследний элементы стека.
*/

char menu();

struct node {
	int value;
	node* next = nullptr;
};

class stack {
private:
	node* head;
public:
	stack() { head = nullptr; }
	~stack() = default;
	void push(int);
	int pop();
	void clear();
	int get_value(node* tmp) { return tmp->value; }
	void set_value(node* tmp, int value) { tmp->value = value; }
	bool is_empty() { return head == nullptr; };
	void show();
	void taskA();
	void taskB();
};

void stack::push(int value) {	// добавить элемент в стек
	node* tmp = new node;  // (struct node*)malloc(sizeof(struct node));
	tmp->value = value;

	if (head == nullptr) {
		head = tmp;
		return;
	}
	else {
		tmp->next = head;
		head = tmp;
	}
}

int stack::pop() {  // удалить последний элемент стека
	if (this->is_empty())
		return 0;
	int value;
	node* tmp = head;
	head = head->next;
	value = tmp->value;
	delete tmp;
	return value;
}

void stack::clear() {
	if (this->is_empty()) {
		cout << "Stack is already empty" << endl; return;
	}
	while (head != nullptr) {
		node* old = head;
		head = head->next;
		delete old;
	}

	cout << "Stack is emptyed" << endl;
}

void stack::show() {
	node* tmp = head;
	while (tmp) {
		cout << tmp->value << endl;
		tmp = tmp->next;
	}
}

char menu() {
	char choice;
	cout << "1. Show your stack" << endl;
	cout << "2. Clear your stack" << endl;
	cout << "A. Выполнить задание A лабораторной работы:  " << endl;
	cout << "B. Выполнить задание B лабораторной работы:  " << endl;
	cout << "0. Exit" << endl;

	cout << endl << "Choice: ";
	cin >> choice;
	return choice;

}

void stack::taskA() {
	if(this->is_empty()) {
		cout << "The stack is empty!" << endl;
		return;
	}
	bool flag = false;
	int mul;
	node* tmp = head;
	while (tmp) {
		if ((tmp->value % 2) != 0) {
			if (!flag) {
				flag = true;
				mul = tmp->value;
			}
			else {
				mul *= tmp->value;
			}
		}
		tmp = tmp->next;
	}
	if (!flag) {
		cout << "There are 0 odd numbers" << endl;
	}
	else {
		cout << "The composition is " << mul << endl;
	}
	cout << "The task A completed!" << endl;
}

void stack::taskB() {
	if (this->is_empty()) {
		cout << "The stack is empty!" << endl;
		return;
	}
	node* tmp = head;
	node* second = tmp->next;
	while (tmp->next->next) {
		tmp = tmp->next;
	}
	node* pre_last = tmp;
	if (second && pre_last) {
		int buffer = second->value;
		second->value = pre_last->value;
		pre_last->value = buffer;
	}
	cout << "The task B completed!" << endl;
}

int main() {
	int value;
	stack stk;
	system("chcp 1251>null");
	cout << "Write the element of the stack. If you want to stop - write 0" << endl;
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
			stk.push(value);
		}
	}
	char choice;
	do {
		choice = menu();
		switch (choice) {
		case '1': stk.show(); break;
		case '2': stk.clear(); break;
		case 'A': stk.taskA(); break;
		case 'B': stk.taskB(); stk.show(); break;
		case '0': cout << "exit." << endl; break;
		default: cout << "Wrong choice. Try again." << endl;
		}
	} while (choice != '0');
	stk.clear();
	return 0;
}