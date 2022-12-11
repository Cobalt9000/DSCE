#include<stdio.h>

/* Define a structure for a sparse matrix entry */
struct Entry 
{
  int row;
  int col;
  int value;
};

/* Define a structure for a sparse matrix */
struct SparseMatrix 
{
  int numRows;
  int numCols;
  int numNonZero;
  struct Entry entries[];
};

/* Function to create a sparse matrix */
struct SparseMatrix createSparseMatrix(int numRows, int numCols, int numNonZero) 
{
  /* Allocate memory for the sparse matrix */
  struct SparseMatrix sm;
  sm.numRows = numRows;
  sm.numCols = numCols;
  sm.numNonZero = numNonZero;
  sm.entries = malloc(numNonZero * sizeof(struct Entry));

  /* Read in the entries for the sparse matrix */
  for (int i = 0; i < numNonZero; i++) 
  {
    scanf("%d%d%d", &sm.entries[i].row, &sm.entries[i].col, &sm.entries[i].value);
  }

  return sm;
}

/* Function to print a sparse matrix */
void printSparseMatrix(struct SparseMatrix sm) 
{
  printf("Number of rows: %d\n", sm.numRows);
  printf("Number of columns: %d\n", sm.numCols);
  printf("Number of non-zero entries: %d\n", sm.numNonZero);
  printf("Entries:\n");
  for (int i = 0; i < sm.numNonZero; i++) 
  {
    printf("%d %d %d\n", sm.entries[i].row, sm.entries[i].col, sm.entries[i].value);
  }
}

int main() 
{
  /* Create a sparse matrix */
  struct SparseMatrix sm = createSparseMatrix(3, 4, 6);

  /* Print the sparse matrix */
  printSparseMatrix(sm);

  return 0;
}
