#include<iostream>
using namespace std;
class Help {
private:
	double x;
public:
	inline double f() {
		return 1 / x;
	}
	Help(int i);
	~Help();
};
Help::Help(int i) {
	x = i;
}
Help::~Help() {
	cout << "Ce pizdec\n";
}
int main() {
	Help t1(2);
	Help t2(3);
	cout << t1.f() << endl << t2.f() << endl;
	getchar();
	return 0;
}