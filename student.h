#include <stdio.h>
#ifndef _STUDENT_H_
#define _STUDENT_H_
#endif
struct Student{
		int id;
		char name[128];
		char passwd[32];
		int age;
		int class;
		float math;
		float C;
		float chinese;
		float ave;
		int rand;
};
extern struct Student students[1000];
//int num=0;
void insert();
int rank(int id);
float average(struct Student avg);
void student_display(int num);
int student_findname(char name[]);
int student_findid(int id);
void student_displayclass(int class);
void student_find();
void student_delete();
void display_all();
void student_change();
void sortsubject(int n);
void sort();
void readfile();
void writefile();
void student_changeus(int x);
void student_passwd(int x);
int search(int id);
//int student_login(int x);
//void student_loginpasswd(int x);

