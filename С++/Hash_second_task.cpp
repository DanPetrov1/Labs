/*#include <iostream>
#include<string>

using namespace std;

struct student {
	string surname;
	string address;
	long int phone_number;
};

struct hash_element {
	student value;
	hash_element* next;
};

hash_element** create_table(const int M) {
	hash_element** table = new hash_element * [M];
	for (int i = 0; i < M; i++) {
		table[i] = NULL;
	}
	return table;
}

int enter() {
	long int n;

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

void add_number(hash_element **table, student Student, const int M) {
	hash_element* tmp = new hash_element;
	tmp->next = NULL;
	tmp->value = Student;
	if (table[Student.phone_number % M] == NULL) {
		table[Student.phone_number % M] = tmp;
		tmp = table[Student.phone_number % M];
	}
	else {
		tmp->next = table[Student.phone_number % M];
		table[Student.phone_number % M] = tmp;
	}
}

void remove(hash_element * element) {
	if (element->next) {
		remove(element->next);
	}
	delete element;
}

void table_delete(hash_element **table, const int M) {
	for (int i = 0; i < M; i++) {
		if (table[i]) {
			remove(table[i]);
		}
	}
}

student* find_element(hash_element **table, int phone_number, const int M) {
	if (table[phone_number % M]) {
		hash_element* tmp = table[phone_number % M];
		while (tmp)
		{
			if (tmp->value.phone_number == phone_number) {
				return &tmp->value;
			}
			else {
				tmp = tmp->next;
			}
		}
		return nullptr;
	}
	else {
		return nullptr;
	}
}

int main() {
	const int n = 9, M = 10;
	int i;
	student Student;
	student *found;
	long int choose;
	hash_element** table = create_table(M);
	cout << "Write information about " << n << " students to add in a hash table" << endl;
	for (i = 0; i < n; i++) {
		cout << "Student No" << i + 1 << ":\nPhone number: ";
		Student.phone_number = enter();
		cout << "Surname: "; cin >> Student.surname;
		cout << "Address: "; cin >> Student.address;
		add_number(table, Student, M);
	}
	do {
		cout << "Write the phone number to find, or write -1 to exit." << endl;
		choose = enter();
		if (choose != -1) {
			if (!(found = find_element(table, choose, M))) {
				cout << "No such student!" << endl;
			}
			else {
				cout << "Surname - " << found->surname << " , address - " << found->address << " , phone number - " << found->phone_number << endl;
			}
		}
	} while (choose != -1);
	table_delete(table, M);
	return 0;
}*/