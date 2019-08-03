#define _CRT_SECURE_NO_WARNINGS
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list {
	char *string;
	list *next;
};

list *GetList();
bool CheckSort(list*);
bool DeleteList(list *);
bool SortList(list*);
bool ShowList(list*);

int main() {
	list *head;
	char q;
	if ((head = GetList()) == NULL) {
		puts("Error of making list!");
	}
	else {
		puts("The list was made successfully!");
	}
	if (CheckSort(head)) {
		puts("Everything sorted alphabetically");
	}
	else {
		puts("This list hasn't sorted yet!\nDo you want to sort it? (Y/y = Yes)");
		q = getchar();
		if (q == 'Y' || q == 'y') {
			if (!SortList(head)) {
				puts("Error of sorting list!");
			}
			else {
				if (!ShowList(head)) {
					puts("Error of showing list!");
				}
			}
		}
	}
	if (head) {
		if (!DeleteList(head)) {
			puts("The mistake of deleting list!");
		}
	}
	getchar();
	getchar();
	return 0;
}

list* GetList() {
	list *head = NULL;
	list *current = NULL, *previous = head;
	char previous_input = '0', input;
	int i = 0;
	printf("Write the strings. Every string is an element of list. If you want to stop writing, press Enter twice.\n");
	while ((input = getchar()) != '\n' || previous_input != '\n') {
		previous_input = input;
		if (input == '\n') {
			i = 0;
			continue;
		}
		if (i == 0) {
			current = (list*)malloc(sizeof(list));
			if (!current) {
				puts("Error of making the element of the list!");
				break;
			}
			current->next = NULL;
			current->string = (char*)malloc(sizeof(char) * 2);
			if (!current->string) {
				puts("Error of making the string!");
				break;
			}
			if (head == NULL) {
				head = current;
				previous = head;
			}
			else {
				previous->next = current;
				previous = current;
			}
		}
		else {
			current->string = (char*)realloc(current->string, sizeof(char) * (i + 2));
			if (!current->string) {
				puts("Error!");
				break;
			}
		}
		current->string[i++] = input;
		current->string[i] = '\0';
	}
	return head;
}

bool CheckSort(list *head) {
	list *current, *another;
	int i = 0;
	for (current = head; current->next->next != NULL; current = current->next, i = 0) {
		another = current->next;
		while (current->string[i] == another->string[i] && current->string[i] != '\0' && another->string[i] != '\0') {
			i++;
		}
		if (current->string[i] < another->string[i] || current->string[i] == '\0') {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

bool DeleteList(list *head) {
	list *current = head;
	while (current) {
		head = head->next;
		free(current);
		current = head;
	}
	return true;
}

bool SortList(list *head) {
	char *buffer = (char*)malloc(sizeof(char));
	if (!buffer) {
		return false;
	}
	list *current, *another;
	int i = 0;
	for (current = head; current; current = current->next, i = 0) {
		for (another = current->next; another; another = another->next, i = 0) {
			while (current->string[i] == another->string[i] && current->string[i] != '\0' && another->string[i] != '\0') {
				i++;
			}
			if (current->string[i] <= another->string[i] || current->string[i] == '\0') {
				continue;
			}
			else {
				strcpy(buffer, current->string);
				strcpy(current->string, another->string);
				strcpy(another->string, buffer);
			}
		}
	}
	return true;
}

bool ShowList(list*head) {
	list *current = head;
	while (current) {
		puts(current->string);
		current = current->next;
	}
	return true;
}*/