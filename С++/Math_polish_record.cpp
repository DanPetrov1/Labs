/*#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct stack
{
	double inf;
	stack* next;
};

stack* AddStack(stack* sp, double inf)
{
	stack* spt = new stack;
	spt->inf = inf;
	spt->next = sp;
	return spt;
}

stack* ReadStack(stack* sp, double& inf)
{
	stack* spt = sp;
	inf = spt->inf;
	sp = sp->next;
	delete spt;
	return sp;
}

int priority(char ch)
{
	switch (ch)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	default: return -1;
	}
}

void AddPostFix(char* strin, char* strout)
{
	stack* sp = NULL;
	int n = 0;
	char ch;
	double inf;
	for (unsigned int i = 0; i < strlen(strin); i++)
	{
		ch = strin[i];
		if (ch == '^')
		{
			int pr = priority(ch);
			while (sp != NULL && priority((char)sp->inf) >= pr)
			{
				sp = ReadStack(sp, inf);
				strout[n++] = (char)inf;
			}
			sp = AddStack(sp, ch);
			continue;
		}
		if (ch >= 'A')
		{
			strout[n++] = ch;
			continue;
		}
		if (sp == NULL || ch == '(')
		{
			sp = AddStack(sp, ch);
			continue;
		}
		if (ch == ')')
		{
			while (sp->inf != '(')
			{
				sp = ReadStack(sp, inf);
				strout[n++] = (char)inf;
			}
			sp = ReadStack(sp, inf); 
			continue;
		}
		int pr = priority(ch);
		while (sp != NULL && priority((char)sp->inf) >= pr)
		{
			sp = ReadStack(sp, inf);
			strout[n++] = (char)inf;
		}
		sp = AddStack(sp, ch);
	}
	while (sp != NULL)
	{
		sp = ReadStack(sp, inf);
		strout[n++] = (char)inf;
	}
	strout[n++] = '\0';
}

int main()
{
	system("chcp 1251>null");
	char str[100], strp[100], strArguments[100];
	cout << "Ввод выражения: "; cin >> str;
	int i = 1;
	int arg = 0;
	bool b = true;
	if (str[0] == '*' || str[0] == '/' || str[0] == '^') {
		b = false;
	}
	else if (str[strlen(str) - 1] == '+' || str[strlen(str) - 1] == '-' || str[strlen(str) - 1] == '*' || str[strlen(str) - 1] == '/' || str[strlen(str) - 1] == '^') {
		b = false;
	}
	else {
		int counter1 = 0, counter2 = 0;
		if (str[0] == '(') counter1++;
		else if (str[0] == ')') b = false;
		if (str[0] >= 'a' && str[0] <= 'z') {
			strArguments[arg] = str[0];
			arg++;
		}
		if ((str[0] < 'a' || str[0] > 'z') && str[0] != '(') {
			b = false;
		}
		if (b) {
			for (i; i < strlen(str); i++) {
				if ((str[i] < 'a' || str[i] > 'z') && str[i] != '(' && str[i] != ')' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '^') {
					b = false;
					break;
				}
				if (str[i] == '0' && str[i - 1] == '/') {
					b = false;
					break;
				}
				if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] >= 'a' && str[i - 1] <= 'z') {
					b = false;
					break;
				}
				if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '^')) {
					b = false;
					break;
				}
				if (str[i] == '(') counter1++;
				if (str[i] == ')') counter2++;
				if (counter2 > counter1) {
					b = false;
					break;
				}
				if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') && str[i - 1] == '(') {
					b = false;
					break;
				}
				if (str[i] == ')' && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '^')) {
					b = false;
					break;
				}
				if (str[i] == ')' && (str[i - 1] < 'a' || str[i - 1] > 'z')) {
					b = false;
					break;
				}
				if (str[i - 1] == ')' && (str[i] >= 'a' && str[i] <= 'z')) {
					b = false;
					break;
				}
				if (str[i] >= 'a' && str[i] <= 'z') {
					strArguments[arg] = str[i];
					arg++;
				}
			}
			if (b) {
				if (str[strlen(str) - 1] == '(') {
					b = false;
				}
				else if (counter1 != counter2) b = false;
			}
		}
	}
	if (b) {
		cout << endl;
		for (int j = 0; j < arg; j++) {
			cout << strArguments[j] << " ";
		}
		AddPostFix(str, strp);
		cout << endl << strp;
		return 0;
	}
	else {
		cout << "Ошибка выражения!!" << endl;
		return 0;
	}
}*/