//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct string {
//	char *String;
//	string* next;
//	string* previous;
//};
//
//struct doubly_linked_list {
//	int size = 0;
//	string *first;
//	string *last;
//};
//
//doubly_linked_list *GetList();
//bool DeleteList(doubly_linked_list *);
//bool ShowList(doubly_linked_list*);
//doubly_linked_list* AddElemenetToTheBeginOfList(doubly_linked_list*);
//doubly_linked_list* AddElemenetToTheEndOfList(doubly_linked_list*);
//char * GetString();
//bool IsListEmpty(doubly_linked_list*);
//int SizeOfList(doubly_linked_list*);
//bool DeleteFirstElemetOfList(doubly_linked_list*);
//bool DeleteLastElementOfList(doubly_linked_list*);
//bool FindSameElementOfList(doubly_linked_list*, char*);
//int DeleteSameElementOfList(doubly_linked_list*, char*);
//doubly_linked_list* ChangeSameElementOfList(doubly_linked_list*, char*, char*);
//bool CheckTheSymmetryOfList(doubly_linked_list*);
//
//int main() {
//	doubly_linked_list *List;
//	if ((List = GetList()) == NULL) {
//		puts("Error of making list!");
//		return 0;
//	}
//	else {
//		puts("The list was made successfully!");
//	}
//	int input;
//	char *string, *string_to_change;
//	do {
//		rewind(stdin);
//		printf("Choose the variant:\n1. Add elemet to the begin of the list\n2. Add element to the end of the list\n3. Show the list\n4. Delete the list\n5. Check the size of the list\n");
//		printf("6. Check the list\n7. Delete the first element of the list\n8. Delete the last element of the list\n9. Find the same element in the list\n");
//		printf("10. Delete the same elements in the list\n11. Change the same elements of the list\n12. Check the symmetry of the list\n13. Exit\n");
//		while (!scanf_s("%d", &input)) {
//			rewind(stdin);
//		}
//		switch (input) {
//		case 1:
//			if ((List = AddElemenetToTheBeginOfList(List)) == NULL) {
//				printf("Error!\n");
//			}
//			else {
//				List->size++;
//				puts("The task was completed successfully!");
//			}
//			break;
//		case 2:
//			if ((List = AddElemenetToTheEndOfList(List)) == NULL) {
//				printf("Error!\n");
//			}
//			else {
//				List->size++;
//				puts("The task was completed successfully!");
//			}
//			break;
//		case 3:
//			if (!ShowList(List)) {
//				printf("Error!\n");
//			}
//			else {
//				puts("The task was completed successfully!");
//			}
//			break;
//		case 4:
//			if (!DeleteList(List)) {
//				printf("Error!\n");
//			}
//			else {
//				puts("The task was completed successfully!");
//				List->size = 0;
//			}
//			break;
//		case 5:
//			printf("The size of the list is %d\n", SizeOfList(List));
//			break;
//		case 6:
//			if (IsListEmpty(List)) {
//				printf("The list is empty!\n");
//			}
//			else {
//				puts("The list isn't empty!");
//			}
//			break;
//		case 7:
//			if (!DeleteFirstElemetOfList(List)) {
//				printf("Error!\n");
//			}
//			else {
//				puts("The task was completed successfully!");
//				List->size--;
//			}
//			break;
//		case 8:
//			if (!DeleteLastElementOfList(List)) {
//				printf("Error!\n");
//			}
//			else {
//				puts("The task was completed successfully!");
//				List->size--;
//			}
//			break;
//		case 9:
//			puts("Write the string to find");
//			string = GetString();
//			if (!FindSameElementOfList(List, string)) {
//				printf("The aren't the same strings!\n");
//			}
//			else {
//				printf("We've found the same string in the list!\n");
//			}
//			break;
//		case 10:
//			puts("Write the string to find and delete");
//			string = GetString();
//			if (List->size = DeleteSameElementOfList(List, string) == -1) {
//				printf("Error of deleting!\n");
//			}
//			else {
//				puts("The task was completed successfully!");
//			}
//			break;
//		case 11:
//			puts("Write the string to find");
//			string = GetString();
//			puts("Write the string to change");
//			string_to_change = GetString();
//			if ((List = ChangeSameElementOfList(List, string, string_to_change)) == NULL) {
//				puts("Error of changing!");
//			}
//			break;
//		case 12:
//			if (!CheckTheSymmetryOfList(List)) {
//				puts("The list isn't symmetry!");
//			}
//			else {
//				puts("The list is symmetry!");
//			}
//			break;
//		default:
//			if (input != 13) {
//				puts("Write the correct number!");
//			}
//			break;
//		}
//	} while (input != 13);
//	if (List) {
//		if (!DeleteList(List)) {
//			puts("The mistake of deleting list!");
//		}
//	}
//	getchar();
//	getchar();
//	return 0;
//}
//
//doubly_linked_list* GetList() {
//	doubly_linked_list *List = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
//	if (!List) {
//		return NULL;
//	}
//	List->first = NULL;
//	List->size = 0;
//	List->last = NULL;
//	string *current = NULL;
//	char previous_input = '0', input;
//	int i = 0;
//	printf("Write the strings. Every string is an element of list. If you want to stop writing, press Enter twice.\n");
//	while ((input = getchar()) != '\n' || previous_input != '\n') {
//		previous_input = input;
//		if (input == '\n') {
//			i = 0;
//			continue;
//		}
//		if (i == 0) {
//			current = (string*)malloc(sizeof(string));
//			if (!current) {
//				puts("Error of making the element of the list!");
//				break;
//			}
//			current->next = NULL;
//			current->previous = NULL;
//			current->String = (char*)malloc(sizeof(char) * 2);
//			if (!current->String) {
//				puts("Error of making the string!");
//				break;
//			}
//			if (List->size == 0) {
//				List->first = current;
//				List->last = current;
//				List->size++;
//			}
//			else {
//				List->last->next = current;
//				List->size++;
//				current->previous = List->last;
//				List->last = current;
//			}
//		}
//		else {
//			current->String = (char*)realloc(current->String, sizeof(char) * (i + 2));
//			if (!current->String) {
//				puts("Error!");
//				break;
//			}
//		}
//		current->String[i++] = input;
//		current->String[i] = '\0';
//	}
//	return List;
//}
//
//bool DeleteList(doubly_linked_list*List) {
//	string *current = List->first, *another;
//	while (current) {
//		another = current->next;
//		free(current);
//		current = another;
//	}
//	return true;
//}
//
//bool ShowList(doubly_linked_list*List) {
//	string *current = List->first;
//	while (current) {
//		puts(current->String);
//		current = current->next;
//	}
//	return true;
//}
//
//doubly_linked_list* AddElemenetToTheBeginOfList(doubly_linked_list* List) {
//	string *current = (string*)malloc(sizeof(string));
//	if (!current) {
//		return List;
//	}
//	current->String = GetString();
//	current->previous = NULL;
//	current->next = List->first;
//	List->first->previous = current;
//	List->first = current;
//	return List;
//}
//
//char *GetString() {
//	char*string = (char*)malloc(sizeof(char) * 2);
//	if (!string) {
//		return NULL;
//	}
//	char input;
//	int i = 0;
//	rewind(stdin);
//	while (input = getchar() != '\n') {
//		string = (char*)realloc(string, sizeof(char) * (i + 2));
//		if (!string) {
//			break;
//		}
//		string[i] = input;
//		string[++i] = '\0';
//	}
//	return string;
//}
//
//doubly_linked_list* AddElemenetToTheEndOfList(doubly_linked_list* List) {
//	string *current = (string*)malloc(sizeof(string));
//	if (!current) {
//		return List;
//	}
//	current->String = GetString();
//	current->next = NULL;
//	current->previous = List->last;
//	List->last->next = current;
//	List->last = current;
//	return List;
//}
//
//bool IsListEmpty(doubly_linked_list* List) {
//	if (List->size < 1) {
//		return false;
//	}
//	return true;
//}
//
//int SizeOfList(doubly_linked_list*List) {
//	return List->size;
//}
//
//bool DeleteFirstElemetOfList(doubly_linked_list*List) {
//	string*current = List->first;
//	List->first = List->first->next;
//	free(current);
//	List->first->previous = NULL;
//	return true;
//}
//
//bool DeleteLastElementOfList(doubly_linked_list*List) {
//	string*current = List->last;
//	List->last = List->last->previous;
//	free(current);
//	List->last->next = NULL;
//	return true;
//}
//
//bool FindSameElementOfList(doubly_linked_list* List, char*current_string) {
//	for (string*current = List->first; current != NULL; current = current->next) {
//		if (strcmp(current->String, current_string) == 0) {
//			return true;
//		}
//	}
//	return false;
//}
//
//int DeleteSameElementOfList(doubly_linked_list*List, char*current_string) {
//	for (string*current = List->first; current != NULL; current = current->next) {
//		if (strcmp(current->String,current_string)==0) {
//			if (current == List->first) {
//				DeleteFirstElemetOfList(List);
//				List->size--;
//			}
//			else if (current == List->last) {
//				DeleteLastElementOfList(List);
//				List->size--;
//			}
//			else {
//				string*toDelete = current;
//				current = current->previous;
//				current->next = toDelete->next;
//				current->next->previous = current;
//				free(toDelete);
//				List->size--;
//			}
//		}
//	}
//	return List->size;
//}
//
//doubly_linked_list* ChangeSameElementOfList(doubly_linked_list*List, char*current_string, char *string_for_change) {
//	for (string*current = List->first; current != NULL; current = current->next) {
//		if (strcmp(current->String, current_string) == 0) {
//			strcpy(current->String, string_for_change);
//		}
//	}
//	return List;
//}
//
//bool CheckTheSymmetryOfList(doubly_linked_list*List) {
//	string*one = List->first;
//	string*two = List->last;
//	while (one != two) {
//		if (strcmp(one->String, two->String) != 0) {
//			return false;
//		}
//		one = one->next;
//		if (one == two) {
//			break;
//		}
//		two = two->previous;
//	}
//	return true;
//}