#include<stdio.h>
#include<stdlib.h>

union bodyparameter {
	int height;
	double weight;
};

struct student {
	char *surname,
		 *name,
		 *lastname;
	bodyparameter BodyParametr;
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
	if (CompleteTask(argv[argc], k, students, n)) {
		printf("The task was completed successful!\n");	//Show the completing tasks from the command line
	}
	else {
		printf("We can't complete the task!\n");
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
		if (students[i].surname = (char*)malloc(sizeof(char))) {
			while ((k = getchar()) != '\n') {
				students[i].surname = (char*)realloc(students[i].surname, sizeof(char) * (j + 1));
				if (!students[i].surname) {
					puts("Error!");
					break;
				}
				students[i].surname[j - 1] = k;
				students[i].surname[j++] = '\0';					//Write the information
			}
		}
		else {
			puts("You can't write the surname!");
		}
		if (j <= 1) {
			students[i].surname = NULL;
			puts("You didn't write the surname!");
		}
		j = 1;
		printf("Write the name of the student No.%d and press Enter: ", i + 1);
		if (students[i].name = (char*)malloc(sizeof(char))) {
			while ((k = getchar()) != '\n') {
				students[i].name = (char*)realloc(students[i].name, sizeof(char) * (j + 1));
				if (!students[i].name) {
					puts("Error!");
					break;
				}
				students[i].name[j - 1] = k;
				students[i].name[j++] = '\0';
			}
		}
		else {
			puts("You can't write the name!");
		}
		if (j <= 1) {
			students[i].name = NULL;
			puts("You didn't write the name!");
		}
		j = 1;
		printf("Write the last name of the student No.%d and press Enter: ", i + 1);
		if (students[i].lastname = (char*)malloc(sizeof(char))) {
			while ((k = getchar()) != '\n') {
				students[i].lastname = (char*)realloc(students[i].lastname, sizeof(char) * (j + 1));
				if (!students[i].lastname) {
					puts("Error!");
					break;
				}
				students[i].lastname[j - 1] = k;
				students[i].lastname[j++] = '\0';
			}
		}
		else {
			puts("You can't write the last name!");
		}
		if (j <= 1) {
			students[i].lastname = NULL;
			puts("You didn't write the last name!");
		}
		printf("Choose the variant:\n1. Write the height.\n2. Write the weight.\n");			//Choose the parameter of the union
		while (!scanf_s("%d", &l) || l != 1 && l != 2) {
			rewind(stdin);
			printf("Choose the variant:\n1. Write the height.\n2. Write the weight.\n");
		}
		if (l == 1) {
			printf("Write the height: ");
			while (!scanf_s("%d", &students[i].BodyParametr.height) || students[i].BodyParametr.height < 0) {
				rewind(stdin);
				printf("Write the height: ");
			}
			students[i].flag = 1;
		}
		else {
			printf("Write the weight: ");
			while (!scanf_s("%lf", &students[i].BodyParametr.weight) || students[i].BodyParametr.weight < 0) {
				rewind(stdin);
				printf("Write the weight: ");
			}
			students[i].flag = 0;
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
		if (students[i].surname) {
			printf("Surname: %s\n", students[i].surname);
		}
		if (students[i].name) {
			printf("Name: %s\n", students[i].name);
		}
		if (students[i].lastname) {
			printf("Last name: %s\n", students[i].lastname);
		}
		if (students[i].flag == 1) {
			printf("The height is %d.\n", students[i].BodyParametr.height);
		}
		else {
			printf("The weight is %lf.\n", students[i].BodyParametr.weight);
		}
	}

	return true;
}

bool showStructForTask(student*students, int flag, int flagUnion, int sum, int n) {
	int number = 0, i;
	for (i = 0; i < n; i++) {
		if (flag == 3) {					//flag == 3 -> in task we want to find the same weight/height
			if (flagUnion == 0) {				//flagUnion == 0 -> in task we want to find both weight and height
				if (students[i].flag) {		//students[i].flag == 1 -> parametr of the union - height
					if (sum == students[i].BodyParametr.height) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
				else {
					if (sum == students[i].BodyParametr.weight) {
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
				if (students[i].flag) {
					if (sum == students[i].BodyParametr.height) {
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
				if (!students[i].flag) {
					if (sum == students[i].BodyParametr.weight) {
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
				if (students[i].flag) {
					if (sum > students[i].BodyParametr.height) {
						showStudent(students[i], i);
						number++;
					}
				}
				else {
					if (sum > students[i].BodyParametr.weight) {
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
				if (students[i].flag) {
					if (sum > students[i].BodyParametr.height) {
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
				if (!students[i].flag) {
					if (sum > students[i].BodyParametr.weight) {
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
				if (students[i].flag) {
					if (sum < students[i].BodyParametr.height) {
						if (showStudent(students[i], i)) {
							number++;
						}
						else {
							puts("We can't show information about the student!");
						}
					}
				}
				else {
					if (sum < students[i].BodyParametr.weight) {
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
				if (students[i].flag) {
					if (sum < students[i].BodyParametr.height) {
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
				if (!students[i].flag) {
					if (sum < students[i].BodyParametr.weight) {
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
}

bool showStudent(student Student, int a) {
	if (Student.surname) {
		printf("%s ", Student.surname);
	}if (Student.name) {
		printf("%s ", Student.name);
	}if (Student.lastname) {
		printf("%s. ", Student.lastname);
	}
	if (Student.flag == 1) {
		printf("The height is %d.\n", Student.BodyParametr.height);
	}
	else {
		printf("The weight is %lf.\n", Student.BodyParametr.weight);
	}
	return true;
}