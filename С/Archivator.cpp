//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct node {
//	unsigned char letter;
//	int priority;
//	node* right, * left;
//};
//
//struct queue {
//	unsigned char letter;
//	char* code;
//	queue* next;
//};
//
//int createTree(node***);
//void treeSwap(node**, node**);
//void queueInit(queue**, char, char*);
//void queueFree(queue**);
//void treeFree(node**);
//queue* setEncoding(node*, queue**, char*);
//int textCompress(queue*);
//void heapify(node**, int, int);
//void merge(node**, int);
//node* treeBuild(node**, int);
//
//int main() {
//	node** chars = (node * *)malloc(sizeof(node*) * 256);
//	int size = createTree(&chars);
//	node* tree = treeBuild(chars, size);
//	queue* encoding = NULL;
//	char* string = (char*)calloc(sizeof(char), sizeof(char));
//	encoding = setEncoding(tree, &encoding, string);
//	int result = textCompress(encoding);
//	queueFree(&encoding);
//	treeFree(&tree);
//	free(tree);
//	if (result == 0) printf("Successfully archivated!\n");
//	else printf("Error!\n");
//	system("pause");
//	return 0;
//}
//
//void heapify(node** array, int size, int index) {
//	int best = index;
//	int l = 2 * index + 1;
//	int r = 2 * index + 2;
//	if (l < size && array[l]->priority < array[best]->priority)
//		best = l;
//	if (r < size && array[r]->priority < array[best]->priority)
//		best = r;
//	if (best != index) {
//		treeSwap(&array[index], &array[best]);
//		heapify(array, size, best);
//	}
//}
//
//void merge(node** array, int size) {	//build the tree
//	while (size > 1) {
//		size--;
//		node* a = array[0];
//		treeSwap(&array[0], &array[size]);
//		heapify(array, size, 0);
//		node* b = array[0];
//		node* c = (node*)malloc(sizeof(node));
//		c->left = (node*)malloc(sizeof(node));
//		c->left = a;
//		c->right = (node*)malloc(sizeof(node));
//		c->right = b;
//		c->priority = a->priority + b->priority;
//		c->letter = '~';
//		array[0] = c;
//		heapify(array, size, 0);
//	}
//}
//
//node* treeBuild(node** array, int size) {	//build the tree
//	for (int i = size / 2 - 1; i >= 0; i--)
//		heapify(array, size, i);
//	merge(array, size);
//	return array[0];
//}
//
//int createTree(node*** array) {		//create and count the number of different letters
//	node** arr = *array;
//	for (int i = 0; i < 256; i++) {
//		arr[i] = (node*)malloc(sizeof(node));
//		arr[i]->letter = i;
//		arr[i]->priority = 0;
//		arr[i]->left = NULL;
//		arr[i]->right = NULL;
//	}
//	FILE* input;
//	fopen_s(&input, "input.txt", "r");
//	char* string = (char*)malloc(sizeof(char) * 256);
//	int size = 0;
//	while ((size = fread(string, sizeof(char), 256, input))) {
//		for (int i = 0; i < size; i++) {
//			arr[string[i]]->priority++;
//		}
//	}
//	int position = 0;
//	for (int i = 0; i < 256; i++) {
//		if (arr[i]->priority == 0) {
//			position++;
//			continue;
//		}
//		arr[i - position] = arr[i];
//	}
//	fclose(input);
//	return 256 - position;
//}
//
//void treeSwap(node * *tree1, node * *tree2) {		//change elements in tree
//	node* buffer = (*tree1);
//	(*tree1) = (*tree2);
//	(*tree2) = buffer;
//}
//
//void queueInit(queue * *my_queue, char letter, char* string) {	//initialize queue
//	(*my_queue) = (queue*)malloc(sizeof(queue));
//	(*my_queue)->letter = letter;
//	(*my_queue)->code = (char*)calloc(sizeof(char) * (strlen(string) + 1), sizeof(char) * (strlen(string) + 1));
//	strcpy((*my_queue)->code, string);
//	(*my_queue)->next = NULL;
//}
//
//void treeFree(node * *tree) {		//delete memory from the tree
//	if ((*tree)) {
//		treeFree(&((*tree)->left));
//		free(((*tree)->left));
//		treeFree(&((*tree)->right));
//		free(((*tree)->right));
//	}
//}
//
//void queueFree(queue * *my_queue) {		//delete memory from the queue
//	while ((*my_queue) != NULL) {
//		queue* buffer = (*my_queue);
//		(*my_queue) = (*my_queue)->next;
//		free(buffer);
//	}
//}
//
//queue* setEncoding(node* tree, queue** my_queue, char* string) {	//make the code of the letters
//	static queue* temp = *my_queue;
//	if (tree) {
//		if (tree->letter != '~') {
//			if ((*my_queue) == NULL) {
//				queueInit(my_queue, tree->letter, string);
//				temp = (*my_queue);
//
//			} else {
//				queueInit(&((*my_queue)->next), tree->letter, string);
//				(*my_queue) = (*my_queue)->next;
//			}
//		}
//		char* stringLeft = (char*)calloc(strlen(string) + 2, strlen(string) + 2);
//		char* stringRight = (char*)calloc(strlen(string) + 2, strlen(string) + 2);
//		strcpy(stringLeft, string);
//		strcpy(stringRight, string);
//		stringLeft[strlen(string)] = '0';
//		stringRight[strlen(string)] = '1';
//		setEncoding(tree->left, my_queue, stringLeft);
//		free(stringLeft);
//		setEncoding(tree->right, my_queue, stringRight);
//		free(stringRight);
//		return temp;
//	}
//}
//
//int textCompress(queue * encoding) {
//	FILE* input, * output;
//	fopen_s(&input, "input.txt", "r");
//	fopen_s(&output, "output.txt", "wb");	//openn both files
//	if (input == NULL) return 1;
//	queue * my_queue = encoding;
//	char symbol = '\n';
//	while (my_queue != NULL) {	//write all letters and their code into the file
//		char letter = my_queue->letter;
//		if (my_queue->letter == '\n') letter = '~';
//		fwrite(&letter, sizeof(char), sizeof(char), output);
//		fwrite(my_queue->code, sizeof(char), strlen(my_queue->code), output);
//		fwrite(&symbol, sizeof(char), sizeof(char), output);
//		my_queue = my_queue->next;
//	}
//	fwrite(&symbol, sizeof(char), sizeof(char), output);
//	int size = 0;
//	int bit = 0;
//	int index = 0;
//	symbol = '\0';
//	char* string = (char*)calloc(256, 256 * sizeof(char));
//	char* string_to_file = (char*)calloc(256, 256 * sizeof(char));
//	while ((size = fread(string, sizeof(char), 256, input))) {
//		for (int i = 0; i < size; i++) {
//			my_queue = encoding;
//			for (; my_queue->letter != string[i]; my_queue = my_queue->next);	//write the bit-code into the file
//			for (int j = 0; j < strlen(my_queue->code); j++) {
//				if (my_queue->code[j] == '1') {
//					symbol <<= 1;
//					symbol += 1;
//				} else {
//					symbol <<= 1;
//				}
//				bit++;
//				if (bit == 8) {
//					string_to_file[index++] = symbol;
//					bit = 0;
//					symbol = '\0';
//				}
//				if (index == 256) {
//					fwrite(string_to_file, sizeof(char), index, output);
//					memset(string_to_file, '\0', index);
//					index = 0;
//				}
//			}
//		}
//		memset(string, '\0', size);
//	}
//	if (bit != 0) {	//if there're some free bites in the end, we complete them
//		char number = 8 - bit + '0';
//		string_to_file[index++] = number;
//		string_to_file[index++] = symbol;
//		fwrite(string_to_file, sizeof(char), index, output);
//	}
//	fclose(input);
//	fclose(output);
//	return 0;
//}