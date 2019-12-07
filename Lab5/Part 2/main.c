#include <stdio.h>
#include <string.h>

typedef struct result
{
	int string_length;
	char* string;
}Result;

Result delete_all_entries(char* string, char* substring);

int main()
{
	char string1[100], string2[100];

	printf("Please enter a two string:\n");

	fgets(string1, 100, stdin);
	fgets(string2, 100, stdin);

	Result returned = delete_all_entries(string1, string2);

	for (int i = 0; i < returned.string_length; i++)
		printf("%c", returned.string[i]);
}

Result delete_all_entries(char string[], char substring[])
{
	int string_len = strlen(string) - 1;
	int substring_len = strlen(substring) - 1;

	int j = 0;
	for (int i = 0; ; i++)
	{
		if (string[i] == substring[j])
			j++;
		else
			j = 0;

		if (j == substring_len)
		{
			for (int m = 0; m < substring_len; m++)
			{
				for (int k = i - substring_len + 1; k < string_len - 1; k++)
					string[k] = string[k + 1];
			}

			i = -1;
			string_len -= substring_len;
			j = 0;
		}
	}

	Result result = { string_len, string };

	return result;
}
