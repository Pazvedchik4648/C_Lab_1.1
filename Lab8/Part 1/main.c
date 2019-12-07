#define  _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE* open_file();
void read_from_file(FILE* file);
int digit_check(char* str);

typedef struct
{
	int id;
	int mark;
}Student;

int main()
{
	FILE* file = open_file();
	read_from_file(file);
	fclose(file);
	return 0;
}

FILE* open_file()
{
	FILE* file_pointer = fopen("C:\\GitHub\\rating.txt", "r");

	if (file_pointer == NULL)
	{
		printf("File no open\n");
		exit(5);
	}

	return file_pointer;
}

void read_from_file(FILE* file)
{
	char value[MAX_LENGTH];
	fgets(value, 256, file);

	char* words[MAX_LENGTH];
	words[0] = strtok(value, " ");

	int students_num = 0;
	int marks[MAX_LENGTH];
	if (digit_check(words[0]) != 0)
	{
		marks[0] = atoi(words[0]);
		students_num = 1;
	}

	while (1)
	{
		words[students_num] = strtok(NULL, " ");
		if (words[students_num] == NULL)
			break;
		if (digit_check(words[students_num]) != 0)
		{
			marks[students_num] = atoi(words[students_num]);
			students_num++;
		}
	}

	Student* students = (Student*)malloc(sizeof(Student) * MAX_LENGTH);

	for (int i = 0; i < students_num; i++)
	{
		students[i].mark = marks[i];
		students[i].id = i + 1;
	}

	for (int i = 0; i < students_num; i++)
	{
		if (students[i].mark <= 100 && students[i].mark >= 88)
			printf("Student number %d have a %d mark and point 5\n", students[i].id, students[i].mark);
		else if (students[i].mark < 88 && students[i].mark >= 71)
			printf("Student number %d have a %d mark and point 4\n", students[i].id, students[i].mark);
		else if (students[i].mark < 71 && students[i].mark >= 51)
			printf("Student number %d have a %d mark and point 3\n", students[i].id, students[i].mark);
		else
			printf("Student number %d have a %d mark and point 2\n", students[i].id, students[i].mark);
	}
}

int digit_check(char* str)
{
	int flag = 1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != '\n')
		{
			if (isdigit(str[i]) == 0)
			{
				flag = 0;
				break;
			}
		}
	}

	return flag;
}