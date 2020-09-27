#ifndef __XMATCHTEST_H__
#define __XMATCHTEST_H__

//==================================================================================
// Includes
//==================================================================================
#include <xtl.h>
#include <xdbg.h>
#include <stdio.h>
#include <xtestlib.h>
#include <xlog.h>
#include <netsync.h>
#include <xlog.h>

#include <xonlinep.h>
#include <xnetref.h>
#include "asyncrequest.h"
#include "xmclasses.h"

//==================================================================================
// Defines
//==================================================================================
#define DEFAULT_RESULTS_LENGTH 512
#define MAX_SIMULTANEOUS_REQUESTS 5

#define GLOBALINT_ID1 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000002
#define GLOBALINT_ID2 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000003
#define GLOBALINT_ID3 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000004

#define GLOBALUSERINT_ID1 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000001
#define GLOBALUSERINT_ID2 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000002
#define GLOBALUSERINT_ID3 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000003

#define GLOBALSTR_ID1 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_STRING | 0x00000001
#define GLOBALSTR_ID2 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_STRING | 0x00000002
#define GLOBALSTR_ID3 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_STRING | 0x00000003

#define GLOBALUSERSTR_ID1 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_STRING | 0x00000001
#define GLOBALUSERSTR_ID2 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_STRING | 0x00000002
#define GLOBALUSERSTR_ID3 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_STRING | 0x00000003

#define GLOBALBLB_ID1 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000001
#define GLOBALBLB_ID2 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000002
#define GLOBALBLB_ID3 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000003

#define GLOBALUSERBLB_ID1 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000001
#define GLOBALUSERBLB_ID2 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000002
#define GLOBALUSERBLB_ID3 X_ATTRIBUTE_SCOPE_GLOBAL | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000003

#define TITLEINT_ID1 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000001
#define TITLEINT_ID2 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000002
#define TITLEINT_ID3 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000003

#define TITLEUSERINT_ID1 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000001
#define TITLEUSERINT_ID2 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000002
#define TITLEUSERINT_ID3 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_INTEGER | 0x00000003

#define TITLESTR_ID1 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_STRING | 0x00000001
#define TITLESTR_ID2 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_STRING | 0x00000002
#define TITLESTR_ID3 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_STRING | 0x00000003

#define TITLEUSERSTR_ID1 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_STRING | 0x00000001
#define TITLEUSERSTR_ID2 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_STRING | 0x00000002
#define TITLEUSERSTR_ID3 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_STRING | 0x00000003

#define TITLEBLB_ID1 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000001
#define TITLEBLB_ID2 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000002
#define TITLEBLB_ID3 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_SESSION | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000003

#define TITLEUSERBLB_ID1 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000001
#define TITLEUSERBLB_ID2 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000002
#define TITLEUSERBLB_ID3 X_ATTRIBUTE_SCOPE_TITLE_SPECIFIC | X_ATTRIBUTE_TYPE_USER | X_ATTRIBUTE_DATATYPE_BLOB | 0x00000003

#define INT1 111222333444555666
#define INT2 777888
#define INT3 999

#define STRING1 L"AAAAABBBBB"
#define STRING2 L"CCCCCDDDDDEEEEE"
#define STRING3 L"FFFFF"

#define BLOB1 "ZZZZZYYYYY"
#define BLOB2 "XXXXXWWWWWVVVVV"
#define BLOB3 "UUUUU"

#define USER1 0xFFFFFFFF00000001
#define USER2 0xFFFFFFFF00000002
#define USER3 0xFFFFFFFF00000003

#define INVALIDSP_INDEX 0xAAAAAAAA
#define NOPARAM_INDEX 0x00000000
#define INTPARAM_INDEX 0x00000001
#define STRINGPARAM_INDEX 0x00000002
#define BLOBPARAM_INDEX 0x00000003
#define GETSESSSP_INDEX 0x0000000A
#define GETSESSINT_INDEX 0x0000000B
#define GETSESSSTR_INDEX 0x0000000C
#define GETSESSBLB_INDEX 0x0000000D
#define GETSESSALL_INDEX 0x0000000E
#define GETTITLEALL_INDEX 0x0000000F
#define NOEXECPERM_INDEX 0x00000010

#define MAX_DISPLAY_RESULTS 50

#define NUM_SERVICES 1

namespace XMatchStressNamespace {

typedef enum
{
	CREATE_NO_ATTRIB_REQ,
	CREATE_INTEGER_REQ,
	CREATE_STRING_REQ,
	CREATE_BLOB_REQ,
	SEARCH_NO_PARAM_REQ,
	SEARCH_INTEGER_REQ,
	SEARCH_STRING_REQ,
	SEARCH_BLOB_REQ,
	SEARCH_RETURN_NO_PARAM_REQ,
	SEARCH_RETURN_INT_REQ,
	SEARCH_RETURN_STR_REQ,
	SEARCH_RETURN_BLB_REQ,
	DELETE_REQ,
	INVALID_REQUEST_CATEGORY
} XMATCH_REQUEST_CATEGORY;

typedef struct
{
	DWORD dwCreateNoAttrib;
	DWORD dwCreateIntAttrib;
	DWORD dwCreateStrAttrib;
	DWORD dwCreateBlobAttrib;
	DWORD dwSearchNoParam;
	DWORD dwSearchIntParam;
	DWORD dwSearchStrParam;
	DWORD dwSearchBlobParam;
	DWORD dwSearchNoAttrib;
	DWORD dwSearchIntAttrib;
	DWORD dwSearchStrAttrib;
	DWORD dwSearchBlobAttrib;
} XMATCH_STRESS_STATS, *PXMATCH_STRESS_STATS;

//==================================================================================
// Prototypes 
//==================================================================================
// Harness functions
BOOL WINAPI XMatchStressDllMain(IN HINSTANCE hInstance, IN DWORD dwReason, IN LPVOID lpContext);
VOID WINAPI XMatchStressStartTest(IN HANDLE hLog);
VOID WINAPI XMatchStressEndTest();
DWORD GetBufferLenForInt();
DWORD GetBufferLenForString(LPWSTR szString);
DWORD GetBufferLenForBlob(LPSTR szBlob);
DWORD GetBufferLenForUserInt();
DWORD GetBufferLenForUserString(LPWSTR szString);
DWORD GetBufferLenForUserBlob(LPSTR szBlob);

// Helper functions
LPVOID MemAlloc(DWORD dwSize);
BOOL MemFree(LPVOID pBuffer);

} // namespace XMatchTestNamespace

#endif // __XMATCHTEST_H__