#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "function.h"
#include "stack.h"

int main()
{
	int adjMatrix[9][9] = {
   //0   1  2  3  4  5  6  7  8
	 {0, 1, 0, 1, 1, 0, 0, 0, 0}, //0
	 {0, 0, 1, 0, 1, 0, 0, 0, 0}, //1
	 {0, 0, 0, 0, 0, 1, 0, 0, 0}, //2
	 {0, 0, 0, 0, 1, 0, 1, 0, 0}, //3
	 {0, 0, 0, 0, 0, 1, 0, 0, 0}, //4
	 {0, 0, 0, 0, 0, 0, 0, 0, 0}, //5
	 {0, 0, 0, 0, 1, 0, 0, 1, 0}, //6
	 {0, 0, 0, 0, 0, 1, 0, 0, 1}, //7
	 {0, 0, 0, 0, 0, 0, 0, 0, 0},  //8
	 };


	int **arr = (int **)malloc(sizeof(int *)*9);

	for(int i=0; i<9; i++)
	{
		arr[i] = (int *)malloc(sizeof(int)*9);
	}

	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			arr[i][j] = adjMatrix[i][j];
		}
	}

	printf("bfs = ");
	bfs(arr, 9, 6);

	printf("\ndft = ");
	dft(arr, 9, 0);



}


