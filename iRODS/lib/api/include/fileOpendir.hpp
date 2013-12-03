/* -*- mode: c++; fill-column: 132; c-basic-offset: 4; indent-tabs-mode: nil -*- */

/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* fileOpendir.h - This file may be generated by a program or script
 */

#ifndef FILE_OPENDIR_HPP
#define FILE_OPENDIR_HPP

/* This is a low level file type API call */

#include "rods.hpp"
#include "rcMisc.hpp"
#include "procApiRequest.hpp"
#include "apiNumber.hpp"
#include "initServer.hpp"

#include "fileDriver.hpp"

typedef struct {
    char resc_name_[MAX_NAME_LEN];
    char resc_hier_[MAX_NAME_LEN];
    char objPath[MAX_NAME_LEN];
    
    rodsHostAddr_t addr;
    char dirName[MAX_NAME_LEN];
} fileOpendirInp_t;
    
#define fileOpendirInp_PI "str resc_name_[MAX_NAME_LEN]; str resc_hier_[MAX_NAME_LEN]; str objPath[MAX_NAME_LEN]; struct RHostAddr_PI; str dirName[MAX_NAME_LEN];" 

#if defined(RODS_SERVER)
#define RS_FILE_OPENDIR rsFileOpendir
/* prototype for the server handler */
int
rsFileOpendir (rsComm_t *rsComm, fileOpendirInp_t *fileOpendirInp);
int
_rsFileOpendir (rsComm_t *rsComm, fileOpendirInp_t *fileOpendirInp,
                void **dirPtr);
int
remoteFileOpendir (rsComm_t *rsComm, fileOpendirInp_t *fileOpendirInp,
                   rodsServerHost_t *rodsServerHost);
#else
#define RS_FILE_OPENDIR NULL
#endif

/* prototype for the client call */
int
rcFileOpendir (rcComm_t *conn, fileOpendirInp_t *fileOpendirInp);

#endif  /* FILE_OPENDIR_H */
