#include "inputmoveDeclarationToInnermostScope_test2015_16.h"

#if 0
extern "C" {
extern void __assert_fail (__const char *__assertion, __const char *__file,
      unsigned int __line, __const char *__function)
     throw () __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, __const char *__file,
      unsigned int __line,
      __const char *__function)
     throw () __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     throw () __attribute__ ((__noreturn__));
}
#endif

  void foo()
     {
       int x;
       if (1)
          {
            x = 4;
          }
     }
