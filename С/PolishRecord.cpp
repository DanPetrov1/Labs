/*#include<stdio.h>
#include<stdlib.h>

struct Stack {
	struct element *down;
	struct element *up;
};
struct element {
	char symbol;
	struct element *next;
};

Stack *push(Stack*, char);
int Priority(char);
char pop(Stack*);
char *GetString();
char *PolishRecord(Stack*, char*);

int main() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (!stack) {
		return 1;
	}
	stack->down = NULL;
	stack->up = NULL;
	char *string;
	puts("Write the string to change to the Polish record");
	string = GetString();
	char *string_answer = PolishRecord(stack, string);
	puts("The answer is:");
	puts(string_answer);
	getchar();
	return 0;
}

Stack *push(Stack* stack, char symbol) {
	element*current = (element*)malloc(sizeof(element));
	if (!current) {
		return stack;
	}
	current->symbol = symbol;
	current->next = NULL;
	if (stack->up == NULL) {
		stack->up = current;
		stack->down = current;
	}
	else {
		current->next = stack->up;
		stack->up = current;
	}
	return stack;
}

char pop(Stack* stack) {
	if (!stack->up) {
		return '\0';
	}
	char symbol = stack->up->symbol;
	element *current = stack->up;
	stack->up = stack->up->next;
	if (stack->up == NULL) {
		stack->down = NULL;
	}
	free(current);
	return symbol;
}

int Priority(char input) {
	switch (input) {
	case '*':case '/':return 3;
	case '+':case '-':return 2;
	case '(': return 1;
	}
	return 0;
}

char*GetString() {
	char*string = (char*)malloc(sizeof(char) * 2);
	if (!string) {
		return NULL;
	}
	char input;
	int i = 0;
	while ((input = getchar()) != '\n') {
		string = (char*)realloc(string, sizeof(char) * (i + 2));
		if (!string) {
			break;
		}
		string[i] = input;
		string[++i] = '\0';
	}
	return string;
}

char*PolishRecord(Stack*stack, char*string) {
	int i = 0, j = 0;
	char*current_string = (char*)malloc(sizeof(char) * 1);
	if (!current_string) {
		return string;
	}
	while (string[i] != '\0' && string[i] != '=') {
		if (string[i] == ')') {
			while (stack->up && stack->up->symbol != '(') {
				current_string = (char*)realloc(current_string, sizeof(char)*(j + 2));
				if (!current_string) {
					break;
				}
				current_string[j++] = pop(stack);
			}
			pop(stack);
		}
		if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'A' && string[i] <= 'Z') {
			current_string = (char*)realloc(current_string, sizeof(char)*(j + 2));
			current_string[j++] = string[i];
		}
		if (string[i] == '(') {
			stack = push(stack, '(');
		}
		if (string[i] == '+' || string[i] == '-' || string[i] == '/' || string[i] == '*') {
			while (stack->up != NULL && Priority(stack->up->symbol) >= Priority(string[i])) {
				current_string = (char*)realloc(current_string, sizeof(char)*(j + 2));
				current_string[j++] = pop(stack);
			}
			stack = push(stack, string[i]);
		}
		i++;
	}
	while (stack->up) {
		current_string = (char*)realloc(current_string, sizeof(char)*(j + 2));
		current_string[j] = pop(stack);
		j++;
	}
	current_string[j] = '\0';
	puts(current_string);
	return current_string;
}*/