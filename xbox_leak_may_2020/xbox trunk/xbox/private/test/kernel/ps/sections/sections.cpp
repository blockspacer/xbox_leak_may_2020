/*

Copyright (C) Microsoft Corporation.  All rights reserved.

Module Name:

    sections.cpp

Abstract:

    The DLL exports two of the mandatory APIs: StartTest and EndTest.
    TESTINI.INI must be modified correctly so that the
    harness will load and call StartTest/EndTest.

    Please see "x-box test harness.doc" for more information.

Author:

    jpoley

Environment:

    XBox

Revision History:

*/


#include "stdafx.h"
#include <xlog.h>
#include "sections.h"
#include "commontest.h"
#include "utils.h"
#include "xtestlib.h"

//
// Thread ID in multiple-thread configuration (not a Win32 thread ID)
//
// You can specify how many threads you want to run your test by
// setting the key NumberOfThreads=n under your DLL section. The
// default is only one thread.
//

static ULONG ThreadID = 0;


//
// Heap handle from HeapCreate
//
HANDLE XESECTIONSHeapHandle;


BOOL WINAPI XESECTIONSDllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpReserved)
    {
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(lpReserved);

    if(fdwReason == DLL_PROCESS_ATTACH)
        {
        XESECTIONSHeapHandle = HeapCreate(0, 0, 0);

        if(!XESECTIONSHeapHandle)
            {
            OutputDebugString(L"XESECTIONS: Unable to create heap\n");
            }
        }
    else if(fdwReason == DLL_PROCESS_DETACH)
        {
        if(XESECTIONSHeapHandle)
            {
            HeapDestroy(XESECTIONSHeapHandle);
            }
        }

    return TRUE;
    }

static bool wcistrstr(WCHAR *string, WCHAR *substr, size_t len=0)
    {
    if(!string || ! substr) return false;
    if(!*string) return false;
    if(!len) len = wcslen(substr);
    if(_wcsnicmp(string, substr, len) == 0) return true;

    return wcistrstr(string+1, substr, len);
    }


/*

Routine Description:


Arguments:

    HANDLE hLog - to the logging object
    DWORD threadNumber - sequential number of the thread
    DWORD loops - # of times to run test
    WCHAR* testname - specific name of a test to run

Return Value:

    DWORD

*/
namespace XESECTIONS {

DWORD stressMode = 0;


static DWORD RunAll(HANDLE hLog, DWORD threadNumber, DWORD loops, WCHAR *testname)
    {
    Sleep(threadNumber*200); // stagger the thread's execution a bit

    struct APIFUNCT
        {
        APITEST_FUNC f;
        WCHAR *name;
        };
    #define BUILTAPISTRUCT(n) { n , L#n }

    // Define all the API tests
    APIFUNCT testlist[] =
        {
        /*
        */
        BUILTAPISTRUCT(XESECTIONS::XLoadSection_Test),
        /*
        */
        };

    bool runAll = _wcsicmp(testname, L"(all)") == 0 ? true : false;

    // Run the suite of tests
    for(DWORD i=0; i<loops; i++)
        {
        // run each test
        for(unsigned j=0; j<ARRAYSIZE(testlist); j++)
            {
            if(runAll || wcistrstr(testlist[j].name, testname))
                {
                xLog(hLog, XLL_INFO, "%ws() ******************************************", testlist[j].name);
                LogResourceStatus(hLog, false);
                DebugPrint("XESECTIONS(%d): Entering %ws()\n", threadNumber, testlist[j].name);
                testlist[j].f(hLog, threadNumber);
                }
            }
        }

    return 0;
    }
    } // namespace XESECTIONS

/*

Routine Description:

    This is your test entry point. It returns only when all tests have
    completed. If you create threads, you must wait until all threads have
    completed. You also have to create your own heap using HeapAlloc, do not
    use GlobalAlloc or LocalAlloc.

    Please see "x-box test harness.doc" for more information

Arguments:

    hLog - Handle used to call logging APIs. Please see "logging.doc"
        for more information regarding logging APIs

Return Value:

    None

*/
VOID WINAPI XESECTIONSStartTest(HANDLE hLog)
    {
    DWORD ID = 0;

    //
    // One way to run multiple threads without creating threads is to
    // set NumberOfThreads=n under the section [sample]. Everytime
    // the harness calls StartTest, ThreadID will get increment by one
    // after InterlockedIncrement call below. If no NumberOfThreads
    // specified, only RunTest1 will be run
    //

    ID = InterlockedIncrement((LPLONG) &ThreadID);


    // test settings
    const int buffLen = 1024;
    WCHAR testname[buffLen];
    DWORD loops;


    // Pull out internal INI file settings
    GetProfileString(L"sections", L"testname", L"(all)", testname, buffLen);
    loops = GetProfileInt(L"sections", L"loops", 1);
    XESECTIONS::stressMode = GetProfileInt(L"GeneralSettings", L"StressTestMode", 0);


    xSetOwnerAlias(hLog, "jpoley");
    xSetComponent(hLog, "XAPI", "Loader");
    DebugPrint("XESECTIONS(%d): **************************************************************\n", ID);
    DebugPrint("XESECTIONS(%d): Entering StartTest()\n", ID);
    DebugPrint("XESECTIONS(%d): Internal INI Settings:\n", ID);
    DebugPrint("  loops=%lu\n", loops);
    DebugPrint("  testname=%ws\n", testname);


    switch(ID)
        {
        case 0:
        case 1:
        default:
            XESECTIONS::RunAll(hLog, ID, loops, testname);
            break;
        }


    DebugPrint("XESECTIONS(%d): Leaving StartTest()\n", ID);
    DebugPrint("FILEIO(%d): **************************************************************\n", ID);
    xSetOwnerAlias(hLog, NULL);
    }


/*

Routine Description:

    This is your test clean up routine. It will be called only ONCE after
    all threads have done. This will allow you to do last chance clean up.
    Do not put any per-thread clean up code here. It will be called only
    once after you have finished your StartTest.

Arguments:

    None

Return Value:

    None

*/
VOID WINAPI XESECTIONSEndTest(void)
    {
    ThreadID = 0;
    }


//
// Export function pointers of StartTest and EndTest
//

#pragma data_seg( EXPORT_SECTION_NAME )
DECLARE_EXPORT_DIRECTORY( sections )
#pragma data_seg()

BEGIN_EXPORT_TABLE( sections )
    EXPORT_TABLE_ENTRY( "StartTest", XESECTIONSStartTest )
    EXPORT_TABLE_ENTRY( "EndTest", XESECTIONSEndTest )
    EXPORT_TABLE_ENTRY( "DllMain", XESECTIONSDllMain )
END_EXPORT_TABLE( sections )