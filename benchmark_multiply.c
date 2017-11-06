#include<time.h> /* for random number generator (filling of matrix column/row array elements),
				    and clock functions */
#include<stdio.h>
#include<stdlib.h> /* for malloc (memory allocation) of dynamic arrays*/

#define N 2 //dimension for rows and columns of square-matrices

const int ROW_SIZE = N;
const int COL_SIZE = N;

void printArray(double **a); //print to screen function for testing/debugging
void deallocate(double **a, int n); // memory deallocation

int main()
{
	int a, b, c, i, j, k, l, p, q,s, t, v; // for-loop counters
	double ** matrixA;
	double ** matrixB;
	double ** matrixC;
	
	srand(time(NULL));
		
	// allocate memory for matrix A rows
	matrixA = malloc(ROW_SIZE*sizeof(double*));
	//allocate memory for matrix A columns
	for(a=0; a<ROW_SIZE;a++)
	{
		matrixA[a] = malloc(COL_SIZE*sizeof(double*));
	}
		
	// allocate memory for matrix B rows	
	matrixB = malloc(ROW_SIZE*sizeof(double*));
	//allocate memory for matrix B columns
	for(b=0; b<ROW_SIZE;b++)
	{
		matrixB[b] = malloc(COL_SIZE*sizeof(double*));
	}
	
	// allocate memory for matrix C rows	
	matrixC = malloc(ROW_SIZE*sizeof(double*));
	//allocate memory for matrix C columns
	for(c=0; c<ROW_SIZE;c++)
	{
		matrixC[c] = malloc(COL_SIZE*sizeof(double*));
	}

	
	//fill matrixA multidimensional array with random numbers
		for(i=0; i<ROW_SIZE; i++)
		{	
			for(j=0; j<COL_SIZE; j++)
			{
				matrixA[i][j] = rand() % 100;
			
			}
		}
		
	printf("matrix A array :\n\n");			// used in testing/debugging 
	printArray(matrixA);					// used in testing/debugging 
	
	system("PAUSE");						// used in testing/debugging 
	system("cls");							// used in testing/debugging 
	
	srand(time(NULL));
	
	//fill matrixB multidimensional array with random numbers
		for(k=0; k<ROW_SIZE; k++)
		{	
			for(l=0; l<COL_SIZE; l++)
			{
				matrixB[k][l] = rand() % 100;
			
			}
		}
	
	printf("\n");						// used in testing/debugging 
	printf("matrix B array :\n\n");		// used in testing/debugging 
	printArray(matrixB);				// used in testing/debugging 
	
	system("PAUSE");					// used in testing/debugging 
	system("cls");						// used in testing/debugging 
	
	// fill matrixC with 0s (clear all junk values for forthcoming additions and multiplications)
	for(p=0; p<ROW_SIZE; p++)
	{	
		for(q=0; q<COL_SIZE; q++)
		{
			matrixC[p][q] = 0;
			
		}
	}
	
    // fill matrixC with results of matrixA * matrixB (matrix multiplication)
	for( s=0; s<ROW_SIZE; s++)
	{
		for( t = 0; t<ROW_SIZE; t++)
		{
			for( v = 0; v < ROW_SIZE; v++)
			{
				matrixC[s][t] += matrixA[s][v] * matrixB[v][t];
			}
		}			
	}
	
	printArray(matrixC); // used in testing/debugging 
	
	//clean up
	deallocate(matrixA, ROW_SIZE);
	deallocate(matrixB, ROW_SIZE);
	deallocate(matrixC, ROW_SIZE);
		
} // end main

/**************************************************************
* prints matrix to screen for testing/debugging purposes only *
**************************************************************/
void printArray(double** a)
{
	int m, n;
	for (m=0; m<ROW_SIZE;m++ )
	{
		for (n = 0; n <= COL_SIZE-1; n++)
		{
			printf("%.2lf ", a[m][n]);
		}
		
		printf("\n");
	}
}

/*********************************
* 		memory deallocation		 *
*********************************/	
void deallocate(double **a, int n)
{
	int x;
	for ( x = 0; x < n; x++)
	{
		free(a[x]);
	}
	free(a);
}

