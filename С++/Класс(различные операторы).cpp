#include<iostream>
using namespace std;
struct Vector {
	double D;
	double C;
};
class Complex {
	struct Vector first;
	struct Vector second;
public:
	Complex();
	void operator+(Complex ob);
	void operator-(Complex ob);
	void operator*(Complex ob);
	Complex operator=(Complex *ob);
};
Complex::Complex() {
	cout << "������� ������������ ����� ������� �����: ", cin >> first.D;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> first.D;
	}
	cout << "������� ������ ����� ������� �����: ", cin >> first.C;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> first.C;
	}
	cout << "������� ������������ ����� ������� �����: ", cin >> second.D;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> second.D;
	}
	cout << "������� ������ ����� ������� �����: ", cin >> second.C;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> second.C;
	}
}
void Complex::operator+(Complex ob) {
	struct Vector *three = (struct Vector*)calloc(1, sizeof(struct Vector));
	if (!three)
		return;
	three->D = ob.first.D + ob.second.D;
	three->C = ob.first.C + ob.second.C;
	cout << "����� ����� " << three->D << "+(" << three->C << ")i" << endl;
	free(three);
}
void Complex::operator-(Complex ob) {
	struct Vector *three = (struct Vector*)calloc(1, sizeof(struct Vector));
	if (!three)
		return;
	three->D = ob.first.D - ob.second.D;
	three->C = ob.first.C - ob.second.C;
	cout << "�������� ����� " << three->D << "+(" << three->C << ")i" << endl;
	free(three);
}
void Complex::operator*(Complex ob) {
	struct Vector *three = (struct Vector*)calloc(1, sizeof(struct Vector));
	if (!three)
		return;
	three->D = ob.first.D * ob.second.D - ob.first.C * ob.second.C;
	three->C = ob.first.D * ob.second.C + ob.first.C * ob.second.D;
	cout << "������������ ����� " << three->D << "+(" << three->C << ")i" << endl;
	free(three);
}
Complex Complex::operator=(Complex *ob) {
	int k;
	struct Vector *three = (struct Vector*)calloc(1, sizeof(struct Vector));
	if (!three)
		return *ob;
	cout << "�������� �������:\n1. �������� ������ ����������� �����.\n2. �������� ������ ����������� �����.\n3. �������� ��� �����.\n", cin >> k;
	while (!cin || k != 1 && k != 2 && k != 3) {
		cin.clear();
		cin.get();
		cin >> k;
	}
	if (k == 1) {
		cout << "������� ������������ ����� ������� �����: ", cin >> three->D;
		while (!cin) {
			cin.clear();
			cin.get();
			cin >> three->D;
		}
		cout << "������� ������ ����� ������� �����: ", cin >> three->C;
		while (!cin) {
			cin.clear();
			cin.get();
			cin >> three->C;
		}
		(*ob).second.D = three->D, ob->second.C = three->C;
		return *ob;
	}
	else if (k == 2) {
		cout << "������� ������������ ����� ������� �����: ", cin >> three->D;
		while (!cin) {
			cin.clear();
			cin.get();
			cin >> three->D;
		}
		cout << "������� ������ ����� ������� �����: ", cin >> three->C;
		while (!cin) {
			cin.clear();
			cin.get();
			cin >> three->C;
		}
		ob->first.D = three->D, ob->first.C = three->C;
		return *ob;
	}
	else if (k == 3) {
		Complex d;
		*ob = d;
		return *ob;
	}
}
int main() {
	system("chcp 1251 > null");
	int k;
	Complex aq;
	do {
		rewind(stdin);
		cout << "�������� �������:\n1. �������� ����������� �����.\n2. ��������� ����������� �����.\n3. ��������� ����������� �����.\n4. ������ ������������ �����/�����.\n5. ����� �� ��������.\n", cin >> k;
		while (!cin || k != 1 && k != 2 && k != 3 && k != 4 && k != 5) {
			cin.clear();
			cin.get();
			cin >> k;
		}
		switch (k) {
		case 1:
			aq.operator+(aq);
			break;
		case 2:
			aq.operator-(aq);
			break;
		case 3:
			aq.operator*(aq);
			break;
		case 4:
			aq.operator=(&aq);
			break;
		}
	} while (k != 5);
	return 0;
}