//#include <iostream>
//
//using namespace std;
//
//struct node {
//	int value;
//	node* next = nullptr;
//};
//
//class stack {
//private:
//	node* head;
//public:
//	stack() { head = nullptr; }
//	~stack() = default;
//	void push(int);
//	int pop();
//	void clear();
//	bool is_empty() { return head == nullptr; };
//	void show();
//	stack task();
//};
//
//void stack::push(int value) {	// добавить элемент в стек
//	node* tmp = new node;  // (struct node*)malloc(sizeof(struct node));
//	tmp->value = value;
//
//	if (head == nullptr) {
//		head = tmp;
//		return;
//	}
//	else {
//		tmp->next = head;
//		head = tmp;
//	}
//}
//
//int stack::pop() {  // удалить последний элемент стека
//	if (this->is_empty())
//		return 0;
//	int value;
//	node* tmp = head;
//	head = head->next;
//	value = tmp->value;
//	delete tmp;
//	return value;
//}
//
//void stack::clear() {
//	if (this->is_empty()) {
//		cout << "Stack is already empty" << endl; return;
//	}
//	while (head != nullptr) {
//		node* old = head;
//		head = head->next;
//		delete old;
//	}
//
//	cout << "Stack is emptyed" << endl;
//}
//
//void stack::show() {
//	node* tmp = head;
//	while (tmp) {
//		cout << tmp->value << endl;
//		tmp = tmp->next;
//	}
//}
//
//stack stack::task() {
//	stack new_stack;
//	while (!this->is_empty()) {
//		int k = pop();
//		if (k % 10 != 5) {
//			new_stack.push(k);
//		}
//	}
//	return new_stack;
//}
//
//int main() {
//	int value;
//	stack stk;
//	system("chcp 1251>null");
//	cout << "Write the element of the stack. If you want to stop - write 0" << endl;
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
//			stk.push(value);
//		}
//	}
//	stk = stk.task();
//	stk.show();
//	system("pause");
//	stk.clear();
//	return 0;
//}