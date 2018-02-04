#ifndef _TEACHER_H_
#define _TEACHER_H_
#endif

struct Teacher
{
		int id;
		char name[128];
		char passwd[32];
		int class;
};

extern struct Teacher teachers[1000];
void teacher_insert();
int teacher_findid(int id);
void teacher_delete();
void teacher_change();
void teacher_display(int tn);
int teacher_findname(char name1[128]);
void teacher_displayclass(int class1);
void teacher_find();
void teacher_displayall();
void teacher_sort();
void teacher_readfile();
void teacher_writefile();
void teacher_changeus(int id);
void teacher_passwd(int id);
int teacher_search(int id);

