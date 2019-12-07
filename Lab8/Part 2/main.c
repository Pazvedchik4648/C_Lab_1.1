#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_LEN 512

typedef struct node
{
	char group_name[MAX_LEN];
	char executor[MAX_LEN];
	char album_name[MAX_LEN];
	char genre[MAX_LEN];
	int year;
	struct node* next;
} node;

node* create_node();
void add_node();
void search_node();
void display();
void modificate();
void delete_node();
void sort();

node* head = NULL;
int list_length = 0;
char trash;
char trash_array[MAX_LEN];

int main(void)
{
	while (1)
	{
		printf("1 - add new node\n");
		printf("2 - search node by field\n");
		printf("3 - display list from beginning\n");
		printf("4 - modificate value by field\n");
		printf("5 - delete node\n");
		printf("6 - sort by field\n");
		printf("7 - exit from the program\n\n");

		int choice;
		printf("Enter your choice: ");
		fflush(stdin);
		while (scanf("%d", &choice) != 1)
		{
			printf("Input error. Try again\n");
			fgets(trash_array, MAX_LEN, stdin);
		}

		switch (choice)
		{
		case 1:
		{
			add_node();
			break;
		}
		case 2:
		{
			search_node();
			break;
		}
		case 3:
		{
			display();
			break;
		}
		case 4:
		{
			modificate();
			break;
		}
		case 5:
		{
			delete_node();
			break;
		}
		case 6:
		{
			/*sort();*/
			break;
		}
		case 7:
			exit(0);
		default:
		{
			printf("Incorrect input. Try again\n");
			break;
		}
		}
	}
}

node* create_node()
{
	trash = getchar();
	node* new_node = (node*)malloc(sizeof(node));
	new_node->next = NULL;

	printf("Please, enter a name of group: ");
	fgets(new_node->group_name, MAX_LEN, stdin);

	printf("Please, enter an executor: ");
	fgets(new_node->executor, MAX_LEN, stdin);

	printf("Please, enter an album name: ");
	fgets(new_node->album_name, MAX_LEN, stdin);

	printf("Please, enter a genre: ");
	fgets(new_node->genre, MAX_LEN, stdin);

	printf("Please, enter a year: ");
	while (scanf("%d", &new_node->year) != 1)
	{
		printf("Input error. Try again\n");
		fgets(trash_array, MAX_LEN, stdin);
	}

	printf("\n");
	return new_node;
}

void add_node()
{
	node* new_node = create_node();

	if (head == NULL)
	{
		head = new_node;
		head->next = NULL;
	}
	else
	{
		node* crawler = head;
		while (crawler->next != NULL)
			crawler = crawler->next;
		crawler->next = new_node;
		new_node->next = NULL;
	}

	list_length++;
}

void search_node()
{
	if (head == NULL)
	{
		printf("Error, list is empty");
		return;
	}

	printf("What field do you want to use in searching?\n");
	printf("1 - group name\n");
	printf("2 - executor\n");
	printf("3 - album name\n");
	printf("4 - genre\n");
	printf("5 - year\n\n");

	int choice;
	printf("Enter your choice\n");
	trash = getchar();
	while (scanf("%d", &choice) != 1)
	{
		printf("Input error. Try again\n");
		fgets(trash_array, MAX_LEN, stdin);
	}

	switch (choice)
	{
	case 1:
	{
		char group_name[MAX_LEN];
		printf("Enter a group name: ");
		trash = getchar();
		fgets(group_name, MAX_LEN, stdin);
		int flag = 0;

		int i = 0;
		for (node* crawler = head; i < list_length; crawler = crawler->next, i++)
		{
			if (strcmp(crawler->group_name, group_name) == 0)
				flag = 1;
		}

		if (flag == 1)
			printf("Name group is found\n\n");
		else
			printf("Not found\n\n");

		break;
	}
	case 2:
	{
		char executor[MAX_LEN];
		printf("Enter a executor: ");
		trash = getchar();
		fgets(executor, MAX_LEN, stdin);
		int flag = 0;

		int i = 0;
		for (node* crawler = head; i < list_length; crawler = crawler->next, i++)
		{
			if (strcmp(crawler->executor, executor) == 0)
				flag = 1;
		}

		if (flag == 1)
			printf("Executor is found\n\n");
		else
			printf("Not found\n\n");

		break;
	}
	case 3:
	{
		char album_name[MAX_LEN];
		printf("Enter a album name: ");
		trash = getchar();
		fgets(album_name, MAX_LEN, stdin);

		int flag = 0;
		int i = 0;
		for (node* crawler = head; i < list_length; crawler = crawler->next, i++)
		{
			if (strcmp(crawler->album_name, album_name) == 0)
				flag = 1;
		}

		if (flag == 1)
			printf("Album name is found\n\n");
		else
			printf("Not found\n\n");

		break;
	}
	case 4:
	{
		char genre[MAX_LEN];
		printf("Enter a genre: ");
		trash = getchar();
		fgets(genre, MAX_LEN, stdin);
		int flag = 0;

		int i = 0;
		for (node* crawler = head; i < list_length; crawler = crawler->next, i++)
		{
			if (strcmp(crawler->genre, genre) == 0)
				flag = 1;
		}

		if (flag == 1)
			printf("Genre is found\n\n");
		else
			printf("Not found\n\n");

		break;
	}
	case 5:
	{
		int year;
		printf("Enter a year: ");
		trash = getchar();
		while (scanf("%d", &year) != 1)
		{
			printf("Input error. Try again\n");
			fgets(trash_array, MAX_LEN, stdin);
		}
		int flag = 0;
		int i = 0;
		for (node* crawler = head; i < list_length; crawler = crawler->next, i++)
		{
			if (crawler->year == year)
				flag = 1;
		}

		if (flag == 1)
			printf("Album name is found\n\n");
		else
			printf("Not found\n\n");

		break;
	}
	default:
	{
		printf("Incorrect input. Try again\n\n");
		break;
	}
	}
}

void display()
{
	if (head == NULL)
	{
		printf("Error, list is empty\n\n");
		return;
	}

	int i = 0;
	for (node* crawler = head; i < list_length; crawler = crawler->next, i++)
	{
		printf("Group name: %s", crawler->group_name);
		printf("Executor: %s", crawler->executor);
		printf("Album name: %s", crawler->album_name);
		printf("Genre: %s", crawler->genre);
		printf("Year: %d\n\n", crawler->year);
	}
}

void modificate()
{
	if (head == NULL)
	{
		printf("List is empty\n\n");
		return;
	}

	int index;
	printf("Enter an index of element, that you want to change: ");
	while (scanf("%d", &index) != 1)
	{
		printf("Input error. Try again\n");
		fgets(trash_array, MAX_LEN, stdin);
	}

	if (index < 0 && index >= list_length)
	{
		printf("Incorrect index\n");
		return;
	}

	int i = 0;
	for (node* crawler = head; i < list_length; crawler = crawler->next, i++)
	{
		if (i == index)
		{
			printf("Please, enter a name of group: ");
			trash = getchar();
			fgets(crawler->group_name, MAX_LEN, stdin);

			printf("Please, enter an executor: ");
			trash = getchar();
			fgets(crawler->executor, MAX_LEN, stdin);

			printf("Please, enter an album name: ");
			trash = getchar();
			fgets(crawler->album_name, MAX_LEN, stdin);

			printf("Please, enter a genre: ");
			trash = getchar();
			fgets(crawler->genre, MAX_LEN, stdin);

			printf("Please, enter a year: ");
			trash = getchar();
			while (scanf("%d", &crawler->year) != 1)
			{
				printf("Input error. Try again\n");
				fgets(trash_array, MAX_LEN, stdin);
			}

			printf("\n");
			break;
		}
	}
}

void delete_node()
{
	int index;
	printf("Enter an index of element, that you want to delete: ");
	while (scanf("%d", &index) != 1)
	{
		printf("Input error. Try again\n");
		fgets(trash_array, MAX_LEN, stdin);
	}

	if (index < 0 && index >= list_length)
	{
		printf("Incorrect index\n");
		return;
	}

	int i = 0;
	for (node* crawler = head; i < list_length; crawler = crawler->next, i++)
	{
		if (list_length == 1)
		{
			head = NULL;
			list_length--;
		}

		if (i == index - 1)
		{
			node* deleted = crawler->next;

			if (deleted->next == NULL)
				crawler->next = NULL;
			else
				crawler->next = deleted->next;

			list_length--;
			free(deleted);
			break;
		}
	}

	printf("Completed successfully\n\n");
}
