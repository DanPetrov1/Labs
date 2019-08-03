/*#include<stdio.h>
#include<stdlib.h>
union height_weight {
	int height;
	double weight;
};
struct student {
	char *F, *I, *O;
	height_weight hw;
	int flag;	//We would see the type of parameter in union
};
bool showStudent(student, int);
bool showStructForTask(student*, int, int, int, int);
bool showStruct(student*, int);
student *getStruct(int*);
bool CompleteTask(char *, int, student*, int);
int main(int argc, char *argv[]) { 
	int k = 1, n;
	printf("Write the number of students: ");
	while (!scanf_s("%d", &n) || n < 1) {
		rewind(stdin);
		printf("Write the number of students: ");
	}
	student *students;
	if ((students = getStruct(&n)) == NULL) {
		puts("We can't make the massive of struct student!");
	}
	else {
		puts("The list of students was made successful!");
	}
	if (showStruct(students, n)) {					//Show a list of students
		puts("There's a list of students.\n\n\n\n");
	}
	else {
		puts("Error! You can't read the list!");
		return 0;
	}
	while (k < argc && argv[k][0]) {
		if (CompleteTask(argv[k], k, students, n)) {
			printf("The task No.%d was completed successful!\n", k);	//Show the completing tasks from the command line
		}
		else {
			printf("We can't complete the task No.%d!\n", k);
		}
		k++;
	}
	free(students);
	return 0;
}

student *getStruct(int *n) {
	rewind(stdin);
	char k;
	int i, j, l;
	student *students = (student*)malloc(sizeof(student) * (*n));
	while (!students) {
		printf("We can't make the list of %d students!\nPress 1 if you want to try to make the list of %d students or Default to close fuction.\n", *n, *n - 1);
		k = getchar();
		if (k == '1') {
			students = (student*)malloc(sizeof(student) * --(*n));
			continue;
		}
		else {
			return NULL;		//Allocate the memory
		}
	}
	for (i = 0, j = 1; i < *n; j = 1, i++) {
		rewind(stdin);
		printf("Write the surname of the student No.%d and press Enter: ", i + 1);
		if (students[i].F = (char*)malloc(sizeof(char))) {
			while ((k = getchar()) != '\n') {
				students[i].F = (char*)realloc(students[i].F, sizeof(char) * (j + 1));
				if (!students[i].F) {
					puts("Error!");
					break;
				}
				students[i].F[j - 1] = k;
				students[i].F[j++] = '\0';					//Write the information
			}
		}
		else {
			puts("You can't write the surname!");
		}
		if (j <= 1) {
			students[i].F = NULL;
			puts("You didn't write the surname!");
		}
		j = 1;
		printf("Write the name of the student No.%d and press Enter: ", i + 1);
		if (students[i].I = (char*)malloc(sizeof(char))) {
			while ((k = getchar()) != '\n') {
				students[i].I = (char*)realloc(students[i].I, sizeof(char) * (j + 1));
				if (!students[i].I) {
					puts("Error!");
					break;
				}
				students[i].I[j - 1] = k;
				students[i].I[j++] = '\0';
			}
		}
		else {
			puts("You can't write the name!");
		}
		if (j <= 1) {
			students[i].I = NULL;
			puts("You didn't write the name!");
		}
		j = 1;
		printf("Write the last name of the student No.%d and press Enter: ", i + 1);
		if (students[i].O = (char*)malloc(sizeof(char))) {
			while ((k = getchar()) != '\n') {
				students[i].O = (char*)realloc(students[i].O, sizeof(char) * (j + 1));
				if (!students[i].O) {
					puts("Error!");
					break;
				}
				students[i].O[j - 1] = k;
				students[i].O[j++] = '\0';
			}
		}
		else {
			puts("You can't write the last name!");
		}
		if (j <= 1) {
			students[i].O = NULL;
			puts("You didn't write the last name!");
		}
		printf("Choose the variant:\n1. Write the height.\n2. Write the weight.\n");			//Choose the parameter of the union
		while (!scanf_s("%d", &l) || l != 1 && l != 2) {
			rewind(stdin);
			printf("Choose the variant:\n1. Write the height.\n2. Write the weight.\n");
		}
		if (l == 1) {
			printf("Write the height: ");
			while (!scanf_s("%d", &students[i].hw.height) || students[i].hw.height < 0) {
				rewind(stdin);
				printf("Write the height: ");
			}
			students[i].flag = 1;
		}
		else {
			printf("Write the weight: ");
			while (!scanf_s("%lf", &students[i].hw.weight) || students[i].hw.weight < 0) {
				rewind(stdin);
				printf("Write the weight: ");
			}
			students[i].flag = -1;
		}
	}
	return students;
}

bool showStruct(student* students, int n) {			//Show the list of students that we've made
	int i;
	if (sizeof(students) == NULL) {
		return false;
	}
	for (i = 0; i < n; i++) {
		printf("Student No.%d\n", i + 1);
		if (students[i].F) {
			printf("Surname: %s\n", students[i].F);
		}
		if (students[i].I) {
			printf("Name: %s\n", students[i].I);
		}
		if (students[i].O) {
			printf("Last name: %s\n", students[i].O);
		}
		if (students[i].flag == 1) {
			printf("The height is %d.\n", students[i].hw.height);
		}
		else {
			printf("The weight is %lf.\n", students[i].hw.weight);
		}
	}
	return true;
}

bool showStructForTask(student*students, int flag, int flagUnion, int sum, int n) {
	int number = 0, i;
	for (i = 0; i < n; i++) {
		if (flag == 3) {					//flag == 3 -> in task we want to find the same weight/height
			if (flagUnion == 0) {				//flagUnion == 0 -> in task we want to find both weight and height
				if (students[i].flag == 1) {		//students[i].flag == 1 -> parametr of the union - height
					if (sum == students[i].hw.height) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
				else {
					if (sum == students[i].hw.weight) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
			}
			else if (flagUnion == 1) {			//flagUnion == 1 -> in task we want to find only height
				if (students[i].flag == 1) {
					if (sum == students[i].hw.height) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
			}
			else if (flagUnion == -1) {				//flagUnion == -1 -> in task we want to find only weight
				if (students[i].flag == -1) {
					if (sum == students[i].hw.weight) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
			}
		}
		if (flag == 2) {						//flag == 2 -> in task we want to find the less weight/height
			if (flagUnion == 0) {
				if (students[i].flag == 1) {
					if (sum > students[i].hw.height) {
						showStudent(students[i], i);
						number++;
					}
				}
				else {
					if (sum > students[i].hw.weight) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
			}
			else if (flagUnion == 1) {
				if (students[i].flag == 1) {
					if (sum > students[i].hw.height) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
			}
			else if (flagUnion == -1) {
				if (students[i].flag == -1) {
					if (sum > students[i].hw.weight) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
			}
		}
		if (flag == 4) {							//flag == 4 -> in task we want to find the weight/height which is more than in the task
			if (flagUnion == 0) {
				if (students[i].flag == 1) {
					if (sum < students[i].hw.height) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
				else {
					if (sum < students[i].hw.weight) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
			}
			else if (flagUnion == 1) {
				if (students[i].flag == 1) {
					if (sum < students[i].hw.height) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
			}
			else if (flagUnion == -1) {
				if (students[i].flag == -1) {
					if (sum < students[i].hw.weight) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
			}
		}
	}
	if (number <= 0) {
		return false;
	}
	return true;
}

bool showStudent(student students, int i) {
	int k = 0;
	printf("Student No.%d\n", i + 1);
	if (students.F) {
		printf("Surname: %s\n", students.F);
		k++;
	}
	if (students.I) {
		printf("Name: %s\n", students.I);
		k++;
	}
	if (students.O) {
		printf("Last name: %s\n", students.O);
		k++;
	}
	if (k <= 0) {
		puts("No information about the student! It's a mistake");
		return false;
	}
	if (students.flag == 1) {
		printf("The height is %d.\n", students.hw.height);
	}
	else {
		printf("The weight is %lf.\n", students.hw.weight);
	}
	return true;
}

bool CompleteTask(char *string, int numberTask, student* students, int n) {
	int i = 0, flag = 0, flagUnion = 0, sum = 0;
	printf("\n\n\n\n");
	while (string[i] != '\0') {
		if (string[i] == ' ') {
			i++;
			continue;
		}
		if (flag < 2) {					//find the letters, words 'more', 'less' and numbers
			flag = 1;
		}
		if ((string[i] == 'h' || string[i] == 'H') && string[i + 1] == 'e' && string[i + 2] == 'i' && string[i + 3] == 'g'
			&& string[i + 4] == 'h' && string[i + 5] == 't') {
			flagUnion = 1;
		}
		if ((string[i] == 'w' || string[i] == 'W') && string[i + 1] == 'e' && string[i + 2] == 'i' && string[i + 3] == 'g'
			&& string[i + 4] == 'h' && string[i + 5] == 't') {
			flagUnion = -1;
		}
		if (((string[i] == 'l' || string[i] == 'L') && string[i + 1] == 'e' && string[i + 2] == 's' &&
			string[i + 3] == 's') || string[i] == '<') {
			if (flag != 4 && flag != 3) {
				flag = 2;
			}
			else {
				puts("It's a mistake! You can't use both 'less' and 'more' in one task! We'll use only the first parameter!");
			}
		}
		if (((string[i] == 'm' || string[i] == 'M') && string[i + 1] == 'o' && string[i + 2] == 'r' &&
			string[i + 3] == 'e') || string[i] == '>') {
			if (flag != 2 && flag != 3) {
				flag = 4;
			}
			else {
				puts("It's a mistake! You can't use both 'less' and 'more' in one task! We'll use only the first parameter!");
			}
		}
		if (string[i] == '=') {
			if (flag != 2 && flag != 4) {
				flag = 3;
			}
			else {
				puts("It's a mistake! You can't use both 'less' and 'more' in one task! We'll use only the first parameter!");
			}
		}
		if (string[i] <= '9' && string[i] >= '0') {
			if (sum <= 0) {
				while (string[i] <= '9' && string[i] >= '0') {
					sum *= 10;
					sum = sum + string[i] - '0';
					i++;
					if (flag != 2 && flag != 4) {
						flag = 3;
					}
				}
				continue;
			}
			else {
				puts("You have too much numbers in the task! We'll use only the first number!");
			}
		}
		i++;
	}
	if (flag == 0) {
		puts("You've written nothing!");
		return false;
	}
	if (flag == 1) {
		puts("We can't understand your task!");
		return false;
	}
	if (showStructForTask(students, flag, flagUnion, sum, n)) {
		printf("There's a list of students with parameter of the task No.%d.\n", numberTask);
	}
	else {
		printf("We didn't find the students with parameter of the task No.%d or you've made a mistake.\n", numberTask);
	}
	return true;
}*/