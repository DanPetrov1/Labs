#include<iostream>
using namespace std;
struct marks {
	int Math, Physics, OAiP, KPiYP;
};
class Abiturient {
	char F[10], I[10], O[15];
	char adress[20];
	struct marks marks;
	int sum;
public:
	Abiturient();
	void show();
	char *getF();
	int sumM();
	int mMaths();
	int mKPiYP();
	int mOAiP();
	int mPhysics();
};
void Abiturient::show() {
		cout << F << ' ' << I << ' ' << O << " , общий балл - " << sum << endl;
}
void BestHalf(Abiturient*, int);
void badMarks(Abiturient *, int);
void nearMark(Abiturient *, int, int);
int main() {
	system("chcp 1251>null");
	int n, i, k, mark;
	cout << "Введите количество студентов: ", cin >> n;
	Abiturient *list = new Abiturient[n];
	for (i = 0; i < n; i++) {
		list[i].show();
	}
	do {
		rewind(stdin);
		cout << "Выберите вариант:\n1. Вывести список абитуриентов, имеющих неудовлетворительные оценки.\n2. Вывести список абитуриентов, сумма баллов у которых не меньше заданной.\n3. Вывести абитуриентов, имеющих самую высокую сумму баллов, и список абитуриентов, имеющих полупроходной балл.\n4. Выход из программы.\n";
		cin >> k;
		while (!cin) {
			cin.clear();
			cin.get();
			cin >> k;
		}
		switch (k) {
		case 1:
			badMarks(list, n);
			break;
		case 2:
			cout << "Введите сумму баллов для поиска: ", cin >> mark;
			while (!cin) {
			cin.clear();
			cin.get();
			cin >> mark;
		}
			nearMark(list, mark, n);
			break;
		case 3:
			BestHalf(list, n);
			break;
		}
	} while (k != 4);
	delete []list;
	return 0;
}
Abiturient::Abiturient() {
	cout << "Введите фамилию ", cin >> F;
	cout << "Введите имя ", cin >> I;
	cout << "Введите отчество ", cin >> O;
	cout << "Введите адрес абитуриента ", cin >> adress;
	rewind(stdin);
	cout << "Введите оценку по математике: ", cin >> marks.Math;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> marks.Math;
	}
	cout << "Введите оценку по физике: ", cin >> marks.Physics;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> marks.Physics;
	}
	cout << "Введите оценку по алгоритмизации: ", cin >> marks.OAiP;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> marks.OAiP;
	}
	cout << "Введите оценку по программированию: ", cin >> marks.KPiYP;
	while (!cin) {
		cin.clear();
		cin.get();
		cin >> marks.KPiYP;
	}
	sum = marks.KPiYP + marks.Math + marks.OAiP + marks.Physics;
	cout << "Общий балл: " << sum << endl;
}
void badMarks(Abiturient *list, int n) {
	int i = 0, badMark = 20;
	cout << "Список абитуриентов с неудолетворительными оценками:\n";
	while (i < n) {
		if (list[i].sumM() < badMark || list[i].mKPiYP() < 4 || list[i].mMaths() < 4 || list[i].mOAiP() < 4 || list[i].mPhysics() < 4)
			list[i].show();
		i++;
	}
}
char * Abiturient::getF() {
	return F;
}
int Abiturient::sumM() {
	return sum;
}
int Abiturient::mMaths() {
	return marks.Math;
}
int Abiturient::mKPiYP() {
	return marks.KPiYP;
}
int Abiturient::mPhysics() {
	return marks.Physics;
}
int Abiturient::mOAiP() {
	return marks.OAiP;
}
void nearMark(Abiturient *list, int mark, int n) {
	int i = 0;
	cout << "Список абитуриентов с более высоким баллом:\n";
	while (i < n) {
		if (list[i].sumM() >= mark )
			list[i].show();
		i++;
	}
}
void BestHalf(Abiturient *list, int n) {
	int i = 0, best = 34, half = 26;
	cout << "Список абитуриентов с идеальным баллом:\n";
	while (i < n) {
		if (list[i].sumM() >= best)
			list[i].show();
		i++;
	}
	i = 0;
	cout << "Список абитуриентов с полупроходным баллом:\n";
	while (i < n) {
		if (list[i].sumM() <= half + 1 && list[i].sumM() >= half - 1)
			list[i].show();
		i++;
	}
}