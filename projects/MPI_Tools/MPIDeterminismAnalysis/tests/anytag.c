#include <mpi.h>
#include <stdlib.h>

int SOURCE_DETERMINISM = 1;
int TAG_DETERMINISM = 0;
int FUNCTION_DETERMINISM = 1;

int main(int argc, char **argv) {
  int a;
  MPI_Recv(&a, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, NULL);

  return 0;
}
