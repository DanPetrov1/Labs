/*#include<stdio.h>
#include<stdlib.h>

struct string {
	char* current_string;
	string* next;
};

struct queue {
	string* first;
	string* last;
	int number;
};

char* getString();
queue* getQueue(char*);
bool isAlpha(char);
bool isUpper(char);
bool DeleteQueue(queue*);
bool showQueue(queue*);

int main() {
	char* string = NULL;
	if ((string = getString()) == NULL) {
		return 1;
	}
	queue* Queue = NULL;
	if ((Queue = getQueue(string)) == NULL) {
		printf("Error of making queue!");
		return 1;
	}
	if (!showQueue(Queue)) {
		puts("Error of showing!");
	}
	free(string);
	if (Queue) {
		if (!DeleteQueue(Queue)) {
			puts("The mistake of deleting!");
		}
		else {
			free(Queue);
		}
	}
	return 0;
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
	return string;
}

queue* getQueue(char* String) {
	int i = 0;
	queue* Queue = (queue*)malloc(sizeof(queue));
	if (!Queue)
	{
		return NULL;
	}
	struct string *current = NULL;
	Queue->first = NULL;
	Queue->last = NULL;
	Queue->number = 0;
	while (String[i] != '\0') {
		if (isUpper(String[i]) && i != 0 && String[i - 2] != '.' && String[i - 2] != '?' && String[i - 2] != '!') {
			int index = 0;
			current = (struct string*)malloc(sizeof(struct string));
			if (!current) {
				puts("Error of making the element of the queue!");
				break;
			}
			current->next = NULL;
			current->current_string = (char*)malloc(sizeof(char) * 2);
			if (!current->current_string) {
				puts("Error of making the string!");
				break;
			}
			if (Queue->first == NULL) {
				Queue->first = current;
				Queue->last = current;
				Queue->number++;
			}
			else {
				Queue->last->next = current;
				Queue->number++;
				Queue->last = current;
			}
			while (isAlpha(String[i])) {
				current->current_string = (char*)realloc(current->current_string, sizeof(char) * (index + 2));
				current->current_string[index++] = String[i];
				current->current_string[index] = '\0';
				i++;
			}
		}
	}
	return Queue;
}

bool isAlpha(char a) {
	if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}

bool isUpper(char a) {
	if (a >= 'A' && a <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}

bool DeleteQueue(queue* Queue) {
	string* current, * previous = Queue->first;
	while (previous != Queue->last) {
		current = previous->next;
		free(previous);
		previous = current;
	}
	free(previous);
	return true;
}

bool showQueue(queue* Queue) {
	printf("The number of elements of the queue is %d\n", Queue->number);
	string* current = Queue->first;
	while (current) {
		puts(current->current_string);
		current = current->next;
	}
	return true;
}*/