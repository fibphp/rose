#include <vector>
void foo ()
{
  int i;
  std::vector <int> v1(100);
  for (i=0; i< v1.size(); i++)
    v1[i] = v1[i-1] +1; 
}
