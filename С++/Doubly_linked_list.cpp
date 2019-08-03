#include <iostream>

using namespace std;

char menu();
int enter();

struct node {
	int value;
	node* next = nullptr;
	node* prev = nullptr;
};

class double_linked_list {
private:
	node* head, * tail;
public:
	double_linked_list() { head = nullptr; tail = nullptr; } // конструктор
	~double_linked_list() = default; // деструктор

	void add(int);  // добавление в конец
	void insert_before(int); //в начало

	void clear();
	void del(node*);

	void show();
	void task();

	bool is_empty() { return head == nullptr; };
};


void double_linked_list::add(int value) {
	node* tmp = new node;  // (struct node*)malloc(sizeof(struct node));
	tmp->value = value;
	tmp->next = nullptr;
	if (head == nullptr) {
		head = tmp; tail = tmp; tmp->prev = nullptr;
		return;
	}
	else {
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}
}

void double_linked_list::show() {
	node* tmp = head;
	while (tmp) {
		cout << tmp->value << endl;
		tmp = tmp->next;
	}
}

void double_linked_list::clear() {
	if (this->is_empty()) {
		cout << "List is already empty" << endl; return;
	}
	while (head != nullptr) {
		node* old = head;
		head = head->prev;
		delete old;
	}

	cout << "List is emptyed" << endl;
}

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

void double_linked_list::insert_before(int value) {
	node* tmp = new node;
	tmp->prev = nullptr;
	tmp->value = value;
	if (is_empty()) {
		head = tmp;
		tail = tmp;
		tmp->next = nullptr;
	}
	else {
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}
}

char menu() {
	char choice;
	cout << "1. Add the element in the begin of the list" << endl;
	cout << "2. Add the element in the end of the list" << endl;
	cout << "3. Show your list" << endl;
	cout << "4. Clear your list" << endl;
	cout << "5. Выполнить задание лабораторной работы:  " << endl;
	cout << "0. Exit" << endl;

	cout << endl << "Choice: ";
	cin >> choice;
	return choice;

}

void double_linked_list::del(node* element) {
	if (!element->prev) {
		head = element->next;
		head->prev = nullptr;
	}
	if (!element->next) {
		tail = element->prev;
		tail->next = nullptr;
	}
	if (element->next && element->prev) {
		element->prev->next = element->next;
		element->next->prev = element->prev;
	}
	delete element;
}

void double_linked_list::task() {
	if (this->is_empty()) {
		cout << "The list is empty!" << endl;
		return;
	}
	int buffer = head->value;
	head->value = tail->value;
	tail->value = buffer;
	cout << "The task completed!" << endl;
}

int main() {
	int value;
	double_linked_list lst, second_list;
	system("chcp 1251>null");
	cout << "Write the element of the list. If you want to stop - write 0" << endl;
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
			lst.add(value);
		}
	}
	char choice;
	do {
		choice = menu();
		switch (choice) {
		case '1': cout << "Write the value: "; value = enter(); lst.add(value); break;
		case '2': cout << "Write the value: "; value = enter(); lst.insert_before(value); break;
		case '3': lst.show(); break;
		case '4': lst.clear(); break;
		case '5': lst.task(); cout << "The list:" << endl;  lst.show(); break;
		case '0': cout << "exit." << endl; break;
		default: cout << "Wrong choice. Try again." << endl;
		}
	} while (choice != '0');
	lst.clear();
	return 0;
}