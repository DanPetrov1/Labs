#include <stdio.h>
#include <stdlib.h>
struct bites {
	unsigned int bit32 : 1, bit31 : 1, bit30 : 1, bit29 : 1, bit28 : 1, bit27 : 1, bit26 : 1, bit25 : 1, bit24 : 1, bit23 : 1,
		bit22 : 1, bit21 : 1, bit20 : 1, bit19 : 1, bit18 : 1, bit17 : 1, bit16 : 1, bit15 : 1, bit14 : 1, bit13 : 1,
		bit12 : 1, bit11 : 1, bit10 : 1, bit9 : 1, bit8 : 1, bit7 : 1, bit6 : 1, bit5 : 1, bit4 : 1, bit3 : 1, bit2 : 1, bit1 : 1;
};
char * GetString();
int GetNumberFromString(char*);
int main() {
	char* string = GetString();
	int number = GetNumberFromString(string);
	bites*pointer;
	pointer = (bites*)&number;
	printf("The addictive code of the number is\n%d %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
		pointer->bit1, pointer->bit2, pointer->bit3, pointer->bit4, pointer->bit5, pointer->bit6, pointer->bit7, pointer->bit8, pointer->bit9, pointer->bit10,
		pointer->bit11, pointer->bit12, pointer->bit13, pointer->bit14, pointer->bit15, pointer->bit16, pointer->bit17, pointer->bit18, pointer->bit19, pointer->bit20,
		pointer->bit21, pointer->bit22, pointer->bit23, pointer->bit24, pointer->bit25, pointer->bit26, pointer->bit27, pointer->bit28, pointer->bit29, pointer->bit30,
		pointer->bit31, pointer->bit32);
	system("pause");
	free(string);
	return 0;
}
char *GetString() {
	int i = 1;
	char k;
	char *string = (char*)malloc(sizeof(char) * 1);
	if (!string) {
		puts("Error!");
		return NULL;
	}
	puts("Write your number and press Enter or another letter:");
	while ((k = getchar()) >= '0' && k <= '9' || k == '-') {
		string = (char*)realloc(string, ++i);
		if (!string) {
			puts("Error of allocating!");
			break;
		}
		string[i - 2] = k;
		string[i - 1] = '\0';
	}
	return string;
}
int GetNumberFromString(char*string) {
	int number = 0, i;
	bool flag = 0;
	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] == '-') {
			flag = true;
			continue;
		}
		number *= 10;
		number += string[i] - '0';
	}
	if (flag) {
		return (-1 * number);
	}
	else {
		return number;
	}
}