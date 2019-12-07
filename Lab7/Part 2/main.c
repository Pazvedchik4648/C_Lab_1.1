#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_LEN 400

void print(int result);
void check(int arvc);
void check2(FILE* file_pointer);
int count_words(FILE* file_pointer);
FILE* open_file(char* argv[]);

int main(int argc, char* argv[])
{
	check(argc);
	FILE* file = open_file(argv[1]);
	check2(file);
	int result = count_words(file);
	print(result);
	fclose(file);
	return 0;
}

void check(int argc)
{
	if (argc != 2)
	{
		printf("Error. To many/few arguments\n");
		exit(1);
	}
}

void check2(FILE* file_pointer)
{
	if (file_pointer == NULL)
	{
		printf("File opening error\n");
		exit(1);
	}
}

int count_words(FILE* file_pointer)
{
	int i;
	char jk[MAX_LEN];
	char* word[MAX_LEN];

	fgets(jk, MAX_LEN, file_pointer);

	word[0] = strtok(jk, " .,");
	int length = 1;
	while (1)
	{
		word[length] = strtok(NULL, " .,");
		if (word[length] == NULL)
			break;
		length++;
	}
	return length;
}

void print(result)
{
	printf("Quantity of word = %d", result);
}

FILE* open_file(char* dot)
{
	FILE* file = fopen(dot, "r");
	return file;
}