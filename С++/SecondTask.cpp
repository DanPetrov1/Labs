#include<iostream>
#define MAX_SIZE 20
using namespace std;
int main() {
	int length = 0, width = 0, i, j;
	double** ms;
	cout << "enter length: ";
	while (length < 1 || length > MAX_SIZE) {
	    cin.sync();
	    rewind(stdin);
		cout << "enter length: ";
		cin >> length;
	}
	cout << "enter width: ";
	while (width < 1 || width > MAX_SIZE) {
	    cin.sync();
	    rewind(stdin);
		cout << "enter width: ";
		cin >> width;
	}
	ms = new double* [length];
	for (i = 0; i < length; i++) {
		ms[i] = new double[width];
	}


	for (i = 0; i < length; i++) {
		for (j = 0; j < width; j++) {
			cin >> ms[i][j];
		}
	}
	for (i = 0; i < length; i++) {
		for (j = 0; j < width; j++) {
			cout << ms[i][j] << " ";
		}
		cout << endl;
	}
	for (i = 0;i < length; i++) {
		for (j = 0; j < width; j++) {
			double sum = 0, number = 0;
			if (i != 0 && j != 0) {
				sum = sum + ms[i - 1][j - 1] + ms[i][j - 1] + ms[i - 1][j];
				number += 3;
			}
			if (i != 0 && j == 0) {
				sum += ms[i - 1][j];
				number += 1;
			}
			if (i == 0 && j != 0) {
				sum += ms[i][j - 1];
				number += 1;
			}
			if (i != length - 1 && j != width - 1) {
				sum = sum + ms[i + 1][j + 1] + ms[i][j + 1] + ms[i + 1][j];
				number += 3;
			}
			if (i != length - 1 && j == width - 1) {
				sum += ms[i + 1][j];
				number += 1;
			}
			if (i == length - 1 && j != width - 1) {
				sum += ms[i][j + 1];
				number += 1;
			}
			if (i != 0 && j != width - 1) {
				sum += ms[i - 1][j + 1];
				number += 1;
			}
			if (i != length - 1 && j != 0) {
				sum += ms[i + 1][j - 1];
				number += 1;
			}
			ms[i][j] = sum / number;
		}
	}
	for (i = 0; i < length; i++) {
		for (j = 0; j < width; j++) {
			cout << ms[i][j] << " ";
		}
		cout << endl;
	}
	bool flag = false;
	double maxNegative;
	int coor1, coor2;
	for (i = 0; i < length; i++) {
		for (j = 0; j < width; j++) {
			if (ms[i][j] < 0) {
				if (!flag) {
					maxNegative = ms[i][j];
					coor1 = i;
					coor2 = j;
					flag = true;
				}
				else
				{
					if (maxNegative < ms[i][j]) {
						maxNegative = ms[i][j];
						coor1 = i;
						coor2 = j;
					}
				}
			}
		}
	}
	cout << maxNegative << " " << coor1 << " " << coor2 << endl;
	return 0;
	
}  
