/*#include<stdio.h>
#include<stdlib.h>

struct string {
	char *current_string;
	string *next;
};

struct queue {
	string *first;
	string *last;
	int number;
};

queue *GetQueue();
bool SymmetryCheck(queue*);
bool DeleteQueue(queue*);

int main() {
	queue *Queue;
	if ((Queue = GetQueue()) == NULL) {
		puts("Error of making the queue!");
		return 1;
	}
	else {
		puts("The queue was made successfully!");
	}
	if (SymmetryCheck(Queue)) {
		puts("There're all palindromes.");
	}
	else {
		puts("There're no palindromes!");
	}
	if (Queue) {
		if (!DeleteQueue(Queue)) {
			puts("The mistake of deleting!");
		}
		else {
			free(Queue);
		}
	}
	getchar();
	return 0;
}

queue *GetQueue() {
	queue *Queue = (queue*)malloc(sizeof(queue));
	string *current = NULL;
	if (!Queue) {
		return NULL;
	}
	Queue->first = NULL;
	Queue->last = NULL;
	Queue->number = 0;
	char previous_input = '0', input;
	int i = 0;
	printf("Write the strings. Every string is an element of queue. If you want to stop writing, press Enter twice.\n");
	while ((input = getchar()) != '\n' || previous_input != '\n') {
		previous_input = input;
		if (input == '\n') {
			i = 0;
			continue;
		}
		if (i == 0) {
			current = (string*)malloc(sizeof(string));
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
		}
		else {
			current->current_string = (char*)realloc(current->current_string, sizeof(char) * (i + 2));
			if (!current->current_string) {
				puts("Error!");
				break;
			}
		}
		current->current_string[i++] = input;
		current->current_string[i] = '\0';
	}
	return Queue;
}

bool SymmetryCheck(queue *Queue) {
	int i = 0, number = 0, first_half, second_half;
	bool FlagOfSymmetry = 0;
	string *current;
	for (current = Queue->first; current->next != NULL; current = current->next, i = 0, FlagOfSymmetry = 0) {
		while (current->current_string[i] != '\0') {
			i++;
		}
		if (i % 2 == 0) {
			first_half = i / 2 - 1;
			second_half = first_half + 1;
		}
		else {
			first_half = (i - 1) / 2 - 1;
			second_half = first_half + 2;
		}
		while (first_half >= 0) {
			if (current->current_string[first_half] != current->current_string[second_half]) {
				FlagOfSymmetry = 1;
			}
			first_half--;
			second_half++;
		}
		if (!FlagOfSymmetry) {
			puts(current->current_string);
			number++;
		}
	}
	if (number == 0) {
		return false;
	}
	else {
		return true;
	}
}

bool DeleteQueue(queue* Queue) {
	string *current, *previous = Queue->first;
	while (previous != Queue->last) {
		current = previous->next;
		free(previous);
		previous = current;
	}
	free(previous);
	return true;
}*/