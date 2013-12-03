/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* rcFileRead.c - Client API call for fileRead. Part of the 
 * reoutine may be generated by a script
 */
#include "fileRead.hpp"

int
rcFileRead (rcComm_t *conn, fileReadInp_t *fileReadInp,
bytesBuf_t *fileReadOutBBuf)
{
    int status;

    status = procApiRequest (conn, FILE_READ_AN, fileReadInp, 
      NULL, (void **) NULL, fileReadOutBBuf);

    return (status);
}

