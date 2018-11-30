
#include<stdio.h>
#include<stdlib.h>


typedef struct vertex
{
	int payload;
	char visit;
	struct vertex** vert;
	int lastVertex;
}Vertex;

void BFS(Vertex*);
void DFS(Vertex*);
Vertex* create();
void InsertVertex(Vertex*, Vertex*);

void main()
{
	Vertex** root;
	int size, i, conStart, conEnd;
	printf("Enter the number of vertex want to insert: ");
	scanf_s("%d", &size);
	root = (Vertex**)calloc(size, sizeof(Vertex));
	for (i = 0; i < size; i++)
		root[i] = create();
	for (i = 0; i < 7; i++)
	{
		printf("Enter the conncection start: ");
		scanf_s("%d", &conStart);
		printf("Enter edge end: ");
		scanf_s("%d", &conEnd);
		InsertVertex(root[conStart-1], root[conEnd-1]);
	}
	printf("\n\nDepth First Search Traversal: \n");
	for (i = 0; i < size; i++)
		DFS(root[i]);
	for (i = 0; i < size; i++) root[i]->visit = 'n'; //ReInitialize visits to no because need to do breath first Search
	printf("\n\nBreath First Search Traversal: \n");
	for (i = 0; i < size; i++) BFS(root[i]);
	printf("\n\n");
	system("pause");
}

Vertex* create()
{
	Vertex * ptr = (Vertex*)calloc(1, sizeof(Vertex));
	printf("Enter data: ");
	scanf_s("%d", &ptr->payload);
	ptr->visit = 'n';
	ptr->lastVertex = 0;
	return ptr;
}

void InsertVertex(Vertex* temp, Vertex* ptr)
{
	Vertex** tempArray = temp->vert;
	int i;
	//Creating new Array whenever going to add a new vertex
	temp->vert = (Vertex**)calloc(temp->lastVertex + 1, sizeof(Vertex));
	for (i = 0; i < temp->lastVertex; i++)
		temp->vert[i] = tempArray[i]; // Copying all vertex to the original array
	temp->vert[temp->lastVertex++] = ptr; //Inserting the vertex

	//Doing same as above but with ptr because its undirected graph
	tempArray = ptr->vert;
	ptr->vert = (Vertex**)calloc(ptr->lastVertex + 1, sizeof(Vertex));
	for (i = 0; i < ptr->lastVertex; i++)
		ptr->vert[i] = tempArray[i];
	ptr->vert[ptr->lastVertex++] = temp;
}

void DFS(Vertex* temp)
{
	int i = 0;
	if (temp == NULL)
		return;

	if (temp->visit == 'n')
	{
		printf("%d  ", temp->payload);
		temp->visit = 'y';
	}
	else
		return;

	while (i <= temp->lastVertex)
	{
		DFS(temp->vert[i]);
		i++;
	}
}

void BFS(Vertex* temp)
{
	int i = 0;
	if (!temp)
		return;
	if (temp->visit == 'n')
	{
		temp->visit = 'y';
		printf("%d  ", temp->payload);
		while (i != temp->lastVertex)
		{
			if (temp->vert[i]->visit == 'n')
			{
				printf("%d  ", temp->vert[i]->payload);
				temp->vert[i]->visit = 'y';
			}
			i++;
		}
	}
	else
		return;
}
