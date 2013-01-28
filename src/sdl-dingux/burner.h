// FB Alpha - Emulator for MC68000/Z80 based arcade games
//            Refer to the "license.txt" file for more info

#ifndef _BURNER_H_
#define _BURNER_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tchar.h"

#define BZIP_MAX (8)								// Maximum zip files to search through
#define DIRS_MAX (8)								// Maximum number of directories to search

#include "burn.h"

#ifndef MAX_PATH
#define	MAX_PATH 256
#endif

// drv.cpp
extern char szAppRomPaths[DIRS_MAX][MAX_PATH];
int DrvInitCallback(); // needed for StatedLoad/StatedSave

// state.cpp
int BurnStateLoadEmbed(FILE* fp, int nOffset, int bAll, int (*pLoadGame)());
int BurnStateLoad(const char * szName, int bAll, int (*pLoadGame)());
int BurnStateSaveEmbed(FILE* fp, int nOffset, int bAll);
int BurnStateSave(const char * szName, int bAll);

// statec.cpp
int BurnStateCompress(unsigned char** pDef, int* pnDefLen, int bAll);
int BurnStateDecompress(unsigned char* Def, int nDefLen, int bAll);

// stated.cpp
extern int nSavestateSlot;
int StatedAuto(int bSave);
int StatedLoad(int nSlot);
int StatedSave(int nSlot);

// zipfn.cpp
struct ZipEntry { char* szName;	unsigned int nLen; unsigned int nCrc; };

int ZipOpen(char* szZip);
int ZipClose();
int ZipGetList(struct ZipEntry** pList, int* pnListCount);
int ZipLoadFile(unsigned char* Dest, int nLen, int* pnWrote, int nEntry);

// bzip.cpp

#define BZIP_STATUS_OK		(0)
#define BZIP_STATUS_BADDATA	(1)
#define BZIP_STATUS_ERROR	(2)

int BzipOpen(bool);
int BzipClose();
int BzipInit();
int BzipExit();
int BzipStatus();

#endif // _BURNER_H_


