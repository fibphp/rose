#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PTR_SIZE 100
#define PTR2_SIZE 10
#define PTR3_SIZE 10
#define OUT_OF_BOUNDS_EXCESS 1


#if 1
struct GStruct{
  int* ptr2obj;

};
#endif

typedef struct GStruct IntStruct;

int main()
{
  IntStruct ptr;
  IntStruct ptr2;
  ptr.ptr2obj = (int*)malloc(PTR_SIZE*sizeof(int));
  ptr2.ptr2obj = (int*)malloc(PTR2_SIZE*sizeof(int));

  IntStruct start_ptr = ptr;
  IntStruct start_ptr2 = ptr2;

  start_ptr.ptr2obj[PTR_SIZE-1] = 0; // out of bounds access
  start_ptr.ptr2obj[0] = 0; // out of bounds access

  free(ptr.ptr2obj);
  free(ptr2.ptr2obj);
  return 0;
}
