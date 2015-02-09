/***********************************************************************
 * blower - functions to blow fuses
 *
 *-- system includes ------------------------------------------------------
 *   */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 *-- module include -------------------------------------------------------
 */

#include "tpi_c.h"
#include "adiUserI.h"
#include "ci_types.h"
#include "libcicpi.h"



/************************************************************************
 *
 *  ---------------------------------------------------------------------
 *
 *  Valid Return Codes:
 *
 *  CI_CALL_PASS    = 0  function completed successfully
 *  CI_TEST_PASS    = 0  test passed 
 *  CI_TEST_FAIL    = 1  test failed
 *  CI_CALL_ERROR   = 2  function call failed
 *  CI_CALL_BREAKD  = 3  break
 *
 *  Constants used:
 *
 *  CI_CI_MAX_COMMENT_LEN = 45000 bytes
 *
 *  ---------------------------------------------------------------------
 *
 *  Very Important: always restrict the length of comment_out. If strncat
 *  is used then a terminating '\0' is automatically  placed at the end
 *  of the string, even if the full CI_MAX_COMMENT_LEN bytes are written
 *
 *  ----------------------------------------------------------------------
 *  INPUTS:  char *parm_list_input   input parameter string pointer
 *           int   parmcount         No. of tokens in *parm_list_input
 *
 *  OUTPUTS: char *comment_out       output/result buffer
 *           int  *comlen            length (in bytes) of comment data 
 *           int  *state_out         success state of the function call
 *
 *=======================================================================
 ***************************************************************************/

bool session_blessed = false;

/*** bless ***/
void
bless (char *parm_list_input,
		int parmcount, char *comment_out, int *comlen, int *state_out)
{


  *state_out = CI_CALL_ERROR;

  if(session_blessed)
  {
    *state_out = CI_CALL_PASS;
  }
  else if(system("cd ..; blessings/bless") == 0)
  {
    session_blessed = true;
    *state_out = CI_CALL_PASS;
  }
}


