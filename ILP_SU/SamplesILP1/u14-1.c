#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */

/* Global prototypes */

/* Global functions */


/* Classes */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp2629;
    ILP_Object ilptmp2630;
    ilptmp2629 = ILP_Integer2ILP (33);
    ilptmp2630 = ILP_Integer2ILP (5);
    return ILP_Modulo (ilptmp2629, ilptmp2630);
  }

}

static ILP_Object
ilp_caught_program ()
{
  struct ILP_catcher *current_catcher = ILP_current_catcher;
  struct ILP_catcher new_catcher;

  if (0 == setjmp (new_catcher._jmp_buf))
    {
      ILP_establish_catcher (&new_catcher);
      return ilp_program ();
    };
  return ILP_current_exception;
}

int
main (int argc, char *argv[])
{
  ILP_START_GC;
  ILP_print (ilp_caught_program ());
  ILP_newline ();
  return EXIT_SUCCESS;
}