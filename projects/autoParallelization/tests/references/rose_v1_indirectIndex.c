// A loop with array references using indirect indexing
//
// Conventional parallelization algorithms will not parallelize the loop
// since indirect indexing may result in overlapped elements being accessed,
// which in turn introduces loop carried dependencies. 
//
// However, if users can provide semantics that the indirect indexing will
// not result in overlapping elements (or unique elements), the loop can be parallelized.
//
// This is a simplified version based on code examples provided by Jeff Keasler.
//
//  Liao, 5/12/2009
#define length 100
double eps[100];
int zoneset[100];

void StressCheckEpsFail(double eps_failure_model)
{
  int i;
  int index;
  for (i = 0; i <= 99; i += 1) {
    index = zoneset[i];
    eps[index] = eps_failure_model * 1.01;
    eps[zoneset[i]] = 1.01;
  }
}
// a multi level definition chain 

void StressCheckEpsFaili2(double eps_failure_model)
{
  int i;
  int index1;
  for (i = 0; i <= 99; i += 1) {
    index1 = zoneset[i];
    int index2 = index1;
    eps[index1] = eps_failure_model * 1.01;
    eps[index2] = 1.01;
  }
}
// a multi dimensional case

void foo()
{
  int n = 100;
  int m = 100;
  double b[n][m];
  int i;
  int j;
  int index;
  int zoneset[m];
  for (i = 0; i <= n - 1; i += 1) {
    for (j = 0; j <= m - 1; j += 1) {
      index = zoneset[j];
      b[i][index] = b[i - 1][index - 1];
    }
  }
}
