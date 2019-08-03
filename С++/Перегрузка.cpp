#include<iostream>
using namespace std;
void f(int);
void f(double);
void f(int, int);
int main() {
	f(1);
	f(1.);
	f(2.3);
	f(3, 4);
	getchar();
	return 0;
}
void f(int a) {
	cout << 1 / a << endl;
}
void f(double a) {
	cout << a * 3.14 << endl;
}
void f(int a, int b) {
	cout << a + b << endl;
}