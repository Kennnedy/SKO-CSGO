/*
Syn's AyyWare Framework 2015
*/

// Credits to Valve and Shad0w

#pragma once

//uncomment me if you wish to dump netvars
//#define DUMP_NETVARS_TO_FILE 

#include "CommonIncludes.h"

struct netvar_info_s
{
#ifdef DUMP_NETVARS_TO_FILE
	char szTableName[128];
	char szPropName[128];
#endif
	DWORD_PTR dwCRC32;
	DWORD_PTR dwOffset;
};

struct RecvTable;

class CNetVar
{
public:
	void RetrieveClasses();
	void LogNetVar(RecvTable *table, int align);
	DWORD_PTR GetNetVar(DWORD_PTR dwCRC32);
	void HookProxies();
private:
	std::vector<netvar_info_s>vars;
};

#ifdef DUMP_NETVARS_TO_FILE
#define NETVAR_FILENAME "netvars.txt"
#endif

extern CNetVar NetVar;

