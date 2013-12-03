/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* irodsFs.h - Header for for irodsFs.c */

#ifndef IRODS_FS_HPP
#define IRODS_FS_HPP

// =-=-=-=-=-=-=-
// boost includes
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>


#define FUSE_USE_VERSION 26

#include <fuse.h>
#include "rodsClient.hpp"
#include "parseCommandLine.hpp"
#include "rodsPath.hpp"

#define FILE_BLOCK_SZ	512
#define DIR_SZ    4096
#define DEF_FILE_MODE	0660
#define DEF_FILE_CREATE_MODE	0750
#define DEF_DIR_MODE	0770

#define IFUSE_CONN_TIMEOUT	120	/* 2 min connection timeout */
#define CONN_MANAGER_SLEEP_TIME 60
#define CONN_REQ_SLEEP_TIME 30

typedef struct IFuseConn {
    rcComm_t *conn;    
    boost::mutex* mutex;
    time_t actTime;	/* the last time the connection is active */
    int inuseCnt;
    int pendingCnt;
    int status;
    struct IFuseConn *next;
} iFuseConn_t;

#ifdef  __cplusplus
extern "C" {
#endif


#ifdef  __cplusplus
}
#endif

#endif	/* IRODS_FS_H */
