#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char letter;
	node* right = NULL, * left = NULL;
};

FILE* treeCreate(node**);
void nodeCreate(node**, char*);
void treeFree(node**);
int decryptMe(node*, FILE**);
void byteToTreeCode(unsigned char, int, char*, int*, node**, node*, FILE**);

/*Двигаемся побитово по файлу и по дереву, если наталкиваемся на лист, значит это и есть нужный символ, который мы записываем в файл
и возвращаемся снова на вершину дерева. Если бит равен 0 то двигаемся по дереву влево, бит равен 1 - двигаемся вправо*/

int main() {
	int result = -1;
	node* dictionary = (node*)calloc(1, sizeof(node)); //Корень.
	dictionary->letter = '~';
	FILE* input = treeCreate(&dictionary); //Иницилаизация дерева.
	if (input != NULL) result = decryptMe(dictionary, &input); //Дешифровка.
	treeFree(&dictionary);
	free(dictionary);
	if (result == 0) printf("Successfully decrypted!\n");
	else if (result == 1) printf("Empty tree!\n");
	else printf("We didn't find your file!\n");
	system("pause");
	return 0;
}

FILE * treeCreate(node * *main_tree) {	//read the letters and their code from the file and create the tree
	node* tree = *main_tree;
	FILE* input;
	fopen_s(&input, "output.txt", "rb");
	if (input == NULL) return NULL;
	char* symbols = (char*)calloc(256, 256 * sizeof(char));
	while (true) {
		fgets(symbols, 256, input);
		if (symbols[0] == '\n') break;
		if (feof(input)) return NULL;
		nodeCreate(&tree, symbols);
	}
	return input;
}

void nodeCreate(node * *main_tree, char* code) {	//create the element of the tree
	node* tree = *main_tree;
	char letter = code[0];
	for (int i = 1; i < strlen(code) - 1; i++) {
		if (code[i] == '1') { 
			if (tree->right == NULL) {
				tree->right = (node*)malloc(sizeof(node));
				tree->right->right = NULL;
				tree->right->left = NULL;
				tree->right->letter = '~';
			}
			tree = tree->right;
		}
		else {
			if (tree->left == NULL) {
				tree->left = (node*)malloc(sizeof(node));
				tree->left->right = NULL;
				tree->left->left = NULL;
				tree->left->letter = '~';
			}
			tree = tree->left;
		}
	}
	if (letter == '~') tree->letter = '\n';
	else tree->letter = letter;
}

void treeFree(node * *tree) {		//delete the memory
	if ((*tree)) {
		treeFree(&((*tree)->left));
		free(((*tree)->left));
		treeFree(&((*tree)->right));
		free(((*tree)->right));
	}
}

int decryptMe(node * main_tree, FILE * *input) {			//decrypt text with the help of binary tree (if there're 0 - we go left, 1 - we go right
	char symbol;									//if there aren't any leaves, we set the letter from this leaf
	char* str = (char*)malloc(sizeof(char) * 256), code, number;
	int ptr = 0, number_int;
	node* temp_tree = main_tree;
	if (main_tree == NULL) return 1;
	FILE * output;
	fopen_s(&output, "decompressed.txt", "w");
	char* string = (char*)malloc(256 * sizeof(char));
	int size = 0;
	while ((size = fread(string, sizeof(char), 256, (*input)))) {
		for (int i = 0; i < size; i++) {
			symbol = string[i];
			if (symbol >= '0' && symbol <= '8' && i == (size - 2) && size != 256) { 
				number = symbol;
				code = string[i + 1];
				number_int = number - '0';
				for (int j = 0; j < number_int; code <<= 1, j++);
				byteToTreeCode(code, 8 - number_int, str, &ptr, &temp_tree, main_tree, &output);
				fputs(str, output);
				break;
			}
			else {
				byteToTreeCode(symbol, 8, str, &ptr, &temp_tree, main_tree, &output);
			}
		}
	}
	fclose(output);
	return 0;
}

void byteToTreeCode(unsigned char symbol, int symbol_size, char* str, int* ptr, node * *temp_tree, node * main_tree, FILE * *output) {
	for (int i = 0; i < symbol_size; symbol <<= 1, ++i) {
		if (symbol >= 128) (*temp_tree) = (*temp_tree)->right;
		else (*temp_tree) = (*temp_tree)->left;
		if ((*temp_tree)->letter != '~') {			//decode char symbols
			str[(*ptr)++] = (*temp_tree)->letter;
			str[(*ptr)] = '\0';
			(*temp_tree) = main_tree;
		}
		if ((*ptr) == 255) {
			fputs(str, (*output));
			memset(str, '\0', 256);
			(*ptr) = 0;
		}
	}
}