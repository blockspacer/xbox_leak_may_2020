/*******************************************************************************

Copyright (c) 2000 Microsoft Corporation.  All rights reserved.

File Name:

    brick1_6.bmp.cpp

Description

    Data file for the resource brick1_6.bmp.

*******************************************************************************/

#include "d3dlocus.h"

static BYTE g_brick1_6[] = {

   0x42, 0x4D, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 
   0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x0E, 0x00, 0x00, 0xC3, 0x0E, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xF4, 0xF6, 0xFA, 0x63, 0x78, 0x9F, 0x5E, 
   0x70, 0x99, 0xF5, 0xF6, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xF4, 0xF6, 0xF8, 0x53, 0x64, 0x86, 0x56, 0x67, 0x87, 0xF5, 0xF7, 0xF8, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF5, 0xF5, 0xF9, 0x63, 0x7D, 0x99, 0x58, 
   0x72, 0x8F, 0xF5, 0xF4, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xF5, 0xF6, 0xF8, 0x3C, 0xB7, 0xC7, 0x3B, 0xB8, 0xC7, 0xF5, 0xF8, 0xF9, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xFD, 0xFD, 0x2A, 0xCF, 0xDB, 0x34, 
   0xAE, 0xC4, 0xF4, 0xF5, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xF5, 0xF3, 0xF5, 0x3F, 0x8F, 0xA5, 0x4B, 0x9C, 0xB5, 0xF9, 0xF7, 0xFA, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF6, 0xF8, 0xF8, 0x5D, 0x69, 0x83, 0x62, 
   0x70, 0x91, 0xF7, 0xF9, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xF7, 0xF9, 0xFA, 0x65, 0x7D, 0x94, 0x5E, 0x73, 0x8D, 0xF5, 0xF7, 0xF8, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 
};

static RESOURCEDATA g_rd_brick1_6(TEXT(MODULE_STRING), TEXT("brick1_6.bmp"), g_brick1_6, sizeof(g_brick1_6));

extern "C" LPVOID PREPEND_MODULE(_brick1_6) = (LPVOID)&g_rd_brick1_6;