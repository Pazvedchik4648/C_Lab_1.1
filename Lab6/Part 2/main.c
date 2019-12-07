#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_LEN 128

char** swap(char** string_array, int index1, int index2);
char** bubble_sort(char** string_array, int length);

int main()
{
	char* words[MAX_LEN];
	printf("Type the sentence. Press 'ENTER' at the end:\n");

	char sentence[MAX_LEN];
	fgets(sentence, MAX_LEN, stdin);
	printf("\n");

	words[0] = strtok(sentence, " ,.");
	int length = 1;

	while (1)
	{
		words[length] = strtok(NULL, " ,.");

		if (words[length] == NULL)
			break;

		length++;
	}

	char** result = bubble_sort(words, length);

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < strlen(words[i]); j++)
		{
			if (result[i][j] != '\n')
				printf("%c", result[i][j]);
		}
		printf("\n");
	}
}

char** swap(char** string_array, int index1, int index2)
{
	char* temp = string_array[index2];
	string_array[index2] = string_array[index1];
	string_array[index1] = temp;

	return string_array;
}

char** bubble_sort(char** string_array, int length)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = 0; j < length - i; j++)
		{
			if (strcmp(string_array[j], string_array[j + 1]) > 0)
			{
				string_array = swap(string_array, j, j + 1);
			}
		}
	}

	return string_array;
}
