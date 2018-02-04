#ifndef _TOOLER_H_
#define _TOOLER_H_
#endif
struct Tooler
{
		char name[128];
		char passwd[32];
};

struct Tooler tooler[10];
static int tonum=0;
void tooler_passwd();
void tooler_readfile();
void tooler_writefile();
