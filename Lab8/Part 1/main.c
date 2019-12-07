#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

FILE* open_file();
void record_from_file(FILE* file);

typedef struct
{
	int id;
	int mark;
}Student;

int main()
{
	FILE* file = open_file();
	record_from_file(file);
	fclose(file);
	return 0;
}

FILE* open_file()
{
	FILE* file_pointer = fopen("ratin.txt", "r");
	if (file_pointer == NULL);
	{
		printf("File no open");
		exit(5);
	}
	return file_pointer;
}

void record_from_file(FILE* file)
{
	Student st1 = { 1 };
	Student st2 = { 2 };
	Student st3 = { 3 };
	Student st4 = { 4 };
	Student st5 = { 5 };
	Student st6 = { 6 };
	Student st7 = { 7 };
	Student st8 = { 8 };
	Student st9 = { 9 };
	Student st10 = { 10 };

	char value[256];
	fgets(value, 256, file);

	char* words[256];
	words[0] = strtok(file, " ");

	int lenght = 1;
	while (1)
	{
		words[lenght] = strtok(NULL, " ");
		if (words[lenght] = NULL)
			break;
		lenght++;
	}

	int num[40];

	for (int i = 0;; i++)
	{
		if (words[i] == 0)
			break;
		num[i] = atoi(words[i]);
	}
	st1.mark = num[0];
	st2.mark = num[1];
	st3.mark = num[2];
	st4.mark = num[3];
	st5.mark = num[4];
	st6.mark = num[5];
	st7.mark = num[6];
	st8.mark = num[7];
	st9.mark = num[8];
	st10.mark = num[9];

	for (int j = 0; j <= 10; ++j)
	{
		if (num[j] <= 100 && num[j] >= 88)
			printf("Student number %d have a %d mark and point 5", j, num[j]);

		else if (num[j] < 88 && num[j] >= 71)
			printf("Student number %d have a %d mark and point: 4", j, num[j]);
		else if (num[j] < 71 && num[j] >= 51)
			printf("Student number %d have a %d mark and point:: 3", j, num[j]);
		else (num[j] < 50);
		printf("Student number %d have a %d mark and point: 2", j, num[j]);
		if (num[j] == 0)
			break;
	}