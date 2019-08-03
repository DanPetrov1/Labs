#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list {
	char* string;
	list* next;
};

list* GetList();
bool DeleteList(list*);
bool checkComparingOfLists(list*, list*);
char* getString();
int stringSize(char*);

int main() {
	list* head_of_First_list, *head_of_Second_list;
	puts("Make the first list:");
	if ((head_of_First_list = GetList()) == NULL) {
		puts("Error of making the first list!");
		return 1;
	}
	puts("Make the second list:");
	if ((head_of_Second_list = GetList()) == NULL) {
		puts("Error of making the second list!");
		return 1;
	}
	if (!checkComparingOfLists(head_of_First_list, head_of_Second_list)) {
		puts("The lists aren't compare!");
	}
	else {
		puts("the lists are the same");
	}
	if (head_of_First_list) {
		if (!DeleteList(head_of_First_list)) {
			puts("The mistake of deleting list!");
		}
	}
	if (head_of_Second_list) {
		if (!DeleteList(head_of_Second_list)) {
			puts("The mistake of deleting list!");
		}
	}
	getchar();
	return 0;
}

list* GetList() {
	list* head = NULL;
	list* current = NULL, * previous = head;
	char* input;
	while ((input = getString()) != NULL) {
		current = (list*)malloc(sizeof(list));
		if (!current) {
			puts("Error of making the element of the list!");
			break;
		}
		current->next = NULL;
		current->string = NULL;
		current->string = (char*)malloc(sizeof(char) * stringSize(input));
		if (!current->string) {
			return head;
		}
		strcpy(current->string, input);
		if (head == NULL) {
			head = current;
			previous = head;
		}
		else {
			previous->next = current;
			previous = current;
		}
	}
	return head;
}

bool checkComparingOfLists(list* head_of_First_list, list* head_of_Second_list) {
	while (head_of_First_list && head_of_Second_list) {
		if (strcmp(head_of_First_list->string, head_of_Second_list->string) != 0) {
			return false;
		}
		head_of_First_list = head_of_First_list->next;
		head_of_Second_list = head_of_Second_list->next;
	}
	return true;
}

bool DeleteList(list* head) {
	list* current = head;
	while (current) {
		head = head->next;
		free(current);
		current = head;
	}
	return true;
}

char* getString() {
	puts("Write the string and press Enter!");
	char* string = (char*)malloc(sizeof(char) * 2);
	if (!string) {
		return NULL;
	}
	int i = 0;
	char input;
	while (input = getchar() != '\n') {
		string = (char*)realloc(string, sizeof(char) * (i + 2));
		string[i] = input;
		string[++i] = '\0';
	}
	if (i == 0) {
		return NULL;
	}
	return string;
}

int stringSize(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i + 1;
}