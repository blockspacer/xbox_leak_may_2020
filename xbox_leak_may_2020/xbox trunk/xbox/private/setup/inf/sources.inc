MAJORCOMP=setup
MINORCOMP=inf

TARGETNAME=XDKSetup
TARGETPATH=$(_OBJ_DIR)

TARGETTYPE=LIBRARY

C_DEFINES = $(C_DEFINES) -DSKIP_XBOXVERP_PRAGMA

SOURCES=

NTTARGETFILE0=\
    $(_OBJ_DIR)\$(TARGET_DIRECTORY)\xdk.inf \
    $(_OBJ_DIR)\$(TARGET_DIRECTORY)\xdk.sed \
    $(_OBJ_DIR)\$(TARGET_DIRECTORY)\$(TARGETNAME).exe \
