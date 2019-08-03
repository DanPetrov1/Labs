/*#include <iostream>

using namespace std;

struct hash_element {
	int value;
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

void add_number(hash_element** table, int value, const int M) {
	hash_element* tmp = new hash_element;
	tmp->next = NULL;
	tmp->value = value;
	if (table[value % M] == NULL) {
		table[value % M] = tmp;
		tmp = table[value % M];
	}
	else {
		tmp->next = table[value % M];
		table[value % M] = tmp;
	}
}

void remove(hash_element* element) {
	if (element->next) {
		remove(element->next);
	}
	delete element;
}

void table_delete(hash_element** table, const int M) {
	for (int i = 0; i < M; i++) {
		if (table[i]) {
			remove(table[i]);
		}
	}
}

bool find_element(hash_element** table, int number, const int M) {
	if (table[number % M]) {
		hash_element* tmp = table[number % M];
		while (tmp)
		{
			if (tmp->value == number) {
				return true;
			}
			else {
				tmp = tmp->next;
			}
		}
		return false;
	}
	else {
		return false;
	}
}

int main() {
	const int n = 9, M = 10;
	int i, value;
	int choose;
	hash_element** table = create_table(M);
	cout << "Write " << n << " numbers to add in a hash table" << endl;
	for (i = 0; i < n; i++) {
		cout << "Number No" << i + 1 << ":";
		value = enter();
		add_number(table, value, M);
	}
	do {
		cout << "Write the number to find, or write -1 to exit." << endl;
		choose = enter();
		if (choose != -1) {
			if (!find_element(table, choose, M)) {
				cout << "No such number!" << endl;
			}
			else {
				cout << "Number " << choose << " with the key " << choose % M << endl;
			}
		}
	} while (choose != -1);
	table_delete(table, M);
	return 0;
}*/