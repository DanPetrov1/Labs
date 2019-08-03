#include<iostream>
#include<stdlib.h>
using namespace std;

template<typename T>
class stack {
	T *stackPtr;
	int size = 10;
	int top = 0;
public:
	int GetSize() { return size; }
	T GetTop() { return top; }
	T GetPtr(int i) { return stackPtr[i]; }
	void SetPtr(int k, T i) { stackPtr[k] = i; }
	T* GetPTR() { return stackPtr; }
	stack();
	stack(int);
	stack(int, int);
	~stack();
	void Show();
	void Show(int);
	bool push(const T);
	bool pop();
};
void thirdTask();
void forthTask();
template<typename T>
stack<T>::stack(int max) {
	size = max;
	top = 0;
	stackPtr = new T[size];
	for (; top < size; top++) {
		cout << "������� �������� ��������: ", cin >> stackPtr[top];
		while (!cin || top != 0 && stackPtr[top - 1] > stackPtr[top]) {
			cin.clear();
			cin.get();
			cin >> stackPtr[top];
		}
	}
}
template<typename T>
stack<T>::~stack() {
	delete[]stackPtr;
}
template<typename T>
void stack<T>::Show() {
	for (int i = size - 1; i >= 0; i--)
		cout << "|" << stackPtr[i] << "\n";
}
template<typename T>
void stack<T>::Show(int) {
	for (int i = 0; i < size; i--)
		cout << "|" << stackPtr[i] << "\n";
}
template<typename T>
bool stack<T>::push(const T value) {
	if (top > size - 1)
		return false;
	else {
		stackPtr[top] = value;
		top++;
		return true;
	}
}
template<typename T>
bool stack<T>::pop() {
	if(top <= 0)
		return false;
	stackPtr[top] = 0;
	top--;
	return true;
}
void firstTask();
void secondTask();
template<typename T>
void sort(stack<T>&);
template<typename T>
stack<T>::stack() {
	int i;
	cout << "�������� ������� ����� �����:\n1. ������������� (����. 10).\nDefault. ������ ���� �����\n", cin >> i;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> i;
	}
	if (i != 1) {
		cout << "������� ������ �����: ", cin >> size;
		while (!cin) {
			cin.clear();
			cin.get();
			cin >> size;
		}
	}
	stackPtr = new T[size];
	for (int i = 0; i < size; i++) {
		stackPtr[i] = 0;
	}
	cout << "������� ������ ������� �����: ", cin >> stackPtr[0];
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> stackPtr[0];
	}
	top++;
}
int main() {
	int i;
	system("Chcp 1251>null");
	do {
		rewind(stdin);
		cout << "�������� �������:\n1. ������� ����� ��� ������ �� ������. ������� ����� � �������������� �����. ��������� ����� ��� ������ ������������\n",
			cout << "����� ������������������ �������������� �����: a) � �������� �������; �) � ��� �� �������(����� � �������������\n",
			cout << "������������������ ������������ �����).\n2. ��������� ����� ��� ������ �� ������. ������� ����� � ����� ",
			cout << "�����. ������ ��� ����������� ������������������ �����\n� ��� �����. ������������ ������ ���� ��� ������� ����",
			cout << "������������������� � ���� �����������.\n3. ������� ����� ��� ������ �� ������. ������� ����� � ������.",
			cout << "������������ ��� �����, ���������� ������������������\n��������. ���������� ����� ����� ��������� � ������,",
			cout << "������������� �������������� �� ��������� ������������.\n4. ������� ����� ��� ������ �� ������. ������� �����",
			cout << "� ������. ������������ ���� ��� �������� ������������\n����������� ������ ���� �����(�������, ���������� �",
			cout << "��������) � ���������.\n5. ����� �� ���������.\n", cin >> i;
		while (!cin) {
			cin.clear();
			cin.get();
			cin >> i;
		}
		switch (i) {
		case 1:
			firstTask();
			break;
		case 2:
			secondTask();
			break;
		case 3:
			thirdTask();
			break;
		case 4:
			forthTask();
			break;
		default:
			cout << "�������� ���������� �������!\n";
			break;
		}
	} while (i != 5);
	return 0;
}
void firstTask() {
	stack<double> k;
	int i;
	double value;
	do {
		rewind(stdin);
		cout << "�������� �������:\n1. �������� ������� �����.\n2. ������� ������� �����.\n3. ������� ���� �� �����.\n4. ��������� �������.\n5. ����� �� ���������� �������.\n", cin >> i;
		while (!cin) {
			cin.clear();
			cin.get();
			cin >> i;
		}
		switch (i) {
		case 1:
			cout << "������� ��������: ", cin >> value;
			while (!cin) {
				cin.clear();
				cin.get();
				cin >> value;
			}
			if (k.push(value))
				cout << "������� ��������!" << endl;
			else
				cout << "������ ����������!" << endl;
			break;
		case 2:
			if (k.pop())
				cout << "������� �����!" << endl;
			else
				cout << "������ ��������!" << endl;
			break;
		case 3:
			k.Show();
			break;
		case 4:
			sort(k);
			break;
		default:
			cout << "�������� �������: ";
			break;
		}
	} while (i != 5);
}
template<typename T>
void sort(stack<T>& k) {
	int i, j, choose;
	T buffer;
	cout << "�������� ������� ����������:\n1. �� �����������.\n2. �� ��������.\n", cin >> choose;
	while (choose != 1 && choose != 2) {
		cin.clear();
		cin.get();
		cin >> choose;
	}
	for (i = 0; i < k.GetTop(); i++) {
		for (j = k.GetTop() - 1; j > i; j--) {
			if (choose == 1) {
				if (k.GetPtr(i) > k.GetPtr(j)) {
					buffer = k.GetPtr(i);
					k.SetPtr(i, k.GetPtr(j));
					k.SetPtr(j, buffer);
				}
			}
			else {
				if (k.GetPtr(i) < k.GetPtr(j)) {
					buffer = k.GetPtr(i);
					k.SetPtr(i, k.GetPtr(j));
					k.SetPtr(j, buffer);
				}
			}
		}
	}
}

void secondTask() {
	stack<int> third(0, 0);
}
template<typename T>
stack<T>::stack(int , int) {
	int s, f;
	cout << "������� ������ ������� �����: ", cin >> f;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> f;
	}
	stack<int> first(f);
	cout << "������� ������ ������� �����: ", cin >> s;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> s;
	}
	stack<int> second(s);
	size = first.top + second.top;
	int *stackPtr = new int[size];
	int i = 0, j = 0;
	for (top = 0; top < first.size; top++) {
		stackPtr[top] = first.stackPtr[top];
	}
	for (top = first.size; top < first.size + second.size; top++) {
		stackPtr[top] = second.stackPtr[top - first.size];
	}
	for (i = 0; i < first.size + second.size; i++) {
		for (j = first.size + second.size - 1; j > i; j--) {
			if (stackPtr[i] > stackPtr[j]) {
				int buffer = stackPtr[i];
				stackPtr[i] = stackPtr[j];
				stackPtr[j] = buffer;
			}
		}
	}
	for (i = first.size + second.size - 1; i >= 0; i--)
		cout << "|" << stackPtr[i] << endl;
}

void thirdTask() {
	stack<char> first;
	int i;
	char k;
	for (i = 1; i < first.GetSize(); i++) {
		cout << "������� ������: ", cin >> k;
		first.push(k);
	}
	stack<char> second;
	for (i = 1; i < second.GetSize(); i++) {
		cout << "������� ������: ", cin >> k;
		second.push(k);
	}
	cout << "������ ����:" << endl;
	first.Show();
	cout << "������ ����:" << endl;
	second.Show();
	cout << "�� ����� ������ - " << first.GetSize() + second.GetSize() << endl;
}

void forthTask() {
	int i, openF = 0, closeF = 0, openS = 0, closeS = 0, openT = 0, closeT = 0, flag = 0;
	char k;
	stack<char> one;
	for (i = 1; i < one.GetSize(); i++) {
		cout << "������� ������: ", cin >> k;
		one.push(k);
	}
	for (i = 0; i < one.GetSize(); i++) {
		if (one.GetPtr(i) == '[')
			openF++;
		if (one.GetPtr(i) == '{')
			openS++;
		if (one.GetPtr(i) == '(')
			openT++;
		if (one.GetPtr(i) == ']')
			closeF++;
		if (one.GetPtr(i) == '}')
			closeS++;
		if (one.GetPtr(i) == ')')
			closeT++;
		if (closeF > openF || closeS > openS || closeT > openT) {
			flag = 1;
			break;
		}
	}
	one.Show();
	if (closeF != openF || closeS != openS || closeT != openT || flag == 1)
		cout << "�������� ������������ ������!\n";
	else
		cout << "������ ���������!\n";
}