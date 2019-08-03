/*10. Создать производный класс «МИНОР» для базового класса
«МАТРИЦА» размерности n×m. Переопределить для производного
класса операции и методы (см. лаб. работу № 2, задание № 4). 
4. Определить класс «Квадратная матрица» – Matrix. Класс должен содержать несколько конструкторов, в том числе конструктор копирования. 
Реализовать методы для сложения, вычитания, умножения
матриц; вычисления нормы матрицы. Перегрузить операции сложения, вычитания, умножения и присваивания для данного класса. Создать массив 
объектов класса Matrix и передать его в функцию, которая изменяет i -ю матрицу путем возведения ее в квадрат. В головной
программе вывести результат*/
#include <iostream>

class Matrix {
private:
	int n, m;
	int **ms;
public:
	Matrix(int, int);
	Matrix();
	int GetMatrix(int i, int j) { return ms[i][j]; };
	int GetN() { return n; }
	int GetM() { return m; }
};

class Minor:public Matrix {
private:
	int minor = 0, k, l;
	int **min;
public:
	Minor();
	void operator+(Minor);
	void operator-(Minor);
	void operator=(Minor);
	void operator*(Minor);
};

Matrix::Matrix() {
	int i, j;
	std::cout << "Введите размер: ", std::cin >> n;
	while (!std::cin) {
		std::cin.clear();
		std::cin.get();
		std::cin >> n;
	}
	std::cout << "Введите размер: ", std::cin >> m;
	while (!std::cin) {
		std::cin.clear();
		std::cin.get();
		std::cin >> m;
	}
	ms = new int*[n];
	for (i = 0; i < n; i++) {
		ms[i] = new int[m];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			std::cin >> ms[i][j];
			while (!std::cin) {
				std::cin.clear();
				std::cin.get();
				std::cin >> ms[i][j];
			}
		}
	}
}

Matrix::Matrix(int a, int b) {
	int i, j;
	n = a, m = b;
	ms = new int*[n];
	for (i = 0; i < n; i++) {
		ms[i] = new int[m];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			std::cin >> ms[i][j];
			while (!std::cin) {
				std::cin.clear();
				std::cin.get();
				std::cin >> ms[i][j];
			}
		}
	}
}

Minor::Minor():Matrix(){
	int i, j, mult, flagI = 0, flagJ = 0;
	std::cout << "Введите первую координату: ", std::cin >> l;
	while (!std::cin || l > GetN() - 1 && l < 0) {
		std::cin.clear();
		std::cin.get();
		std::cin >> l;
	}
	std::cout << "Введите вторую координату: ", std::cin >> k;
	while (!std::cin || k > GetM() - 1 && k < 0) {
		std::cin.clear();
		std::cin.get();
		std::cin >> k;
	}
	min = new int*[GetN() - 1];
	for (i = 0; i < GetN() - 1; i++)
		min[i] = new int[GetM() - 1];
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0, flagJ = 0; j < GetM() - 1; j++) {
			if (j == k)
				flagJ = 1;
			else if (i == l)
				flagI = 1;
			min[i][j] = GetMatrix(i + flagI, j + flagJ);
		}
	}
	for (int q = 0; q < GetM() - 1; q++) {
		for (i = 0, mult = 1, j = q; i < GetN() - 1; i++, j++) {
			if (j >= GetM() - 1)
				j = 0;
			mult *= min[i][j];
		}
		minor += mult;
	}
	std::cout << minor << std::endl;
}

void Minor::operator+(Minor ms1) {
	int i, j;
	Matrix ms2(ms1.GetN() - 1, ms1.GetM() - 1);
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetM() - 1; j++) {
			ms1.min[i][j] += ms2.GetMatrix(i, j);
		}
	}
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetM() - 1; j++) {
			std::cout << ms1.min[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Minor::operator-(Minor ms1) {
	int i, j;
	Matrix ms2(ms1.GetN() - 1, ms1.GetM() - 1);
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetM() - 1; j++) {
			ms1.min[i][j] -= ms2.GetMatrix(i, j);
		}
	}
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetM() - 1; j++) {
			std::cout << ms1.min[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Minor::operator=(Minor ms1) {
	int i, j;
	Matrix ms2(ms1.GetN() - 1, ms1.GetM() - 1);
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetM() - 1; j++) {
			ms1.min[i][j] = ms2.GetMatrix(i, j);
		}
	}
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetM() - 1; j++) {
			std::cout << ms1.min[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Minor::operator*(Minor ms1) {
	int i, j, k;
	int **ms3 = new int*[ms1.GetN() - 1];
	for (i = 0; i < ms1.GetN() - 1; i++)
		ms3[i] = new int[ms1.GetN() - 1];
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetN() - 1; j++) {
			ms3[i][j] = 0;
		}
	}
	Matrix ms2(ms1.GetM() - 1, ms1.GetN() - 1);
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetM() - 1; j++) {
			for (k = 0; k < ms1.GetN() - 1; k++)
				ms3[i][j] += ms1.min[k][j] * ms2.GetMatrix(i, k);
		}
	}
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetM() - 1; j++) {
			ms1.min[i][j] = ms3[i][j];
		}
	}
	for (i = 0; i < GetN() - 1; i++) {
		for (j = 0; j < GetN() - 1; j++) {
			std::cout << ms1.min[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	system("chcp 1251>null");
	Minor a;
	a * a;
	system("pause");
	return 0;
}