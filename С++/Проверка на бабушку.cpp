#include <iostream>
#include <string>

using namespace std;

int input()
{
	int temp;
	try
	{
		cin.sync();
		cin.clear();
		rewind(stdin);
		cin >> temp;
		if (!cin || cin.peek() != '\n')
		{
			throw 1;
		}
	}
	catch (int i)
	{
		cout << "Err" << endl;
		cin.sync();
		cin.clear();
		rewind(stdin);
		return input();
	}
	return temp;
}

int main()
{
	int n;
	n = input();
	cout << n << endl;
	system("pause>nul");
}