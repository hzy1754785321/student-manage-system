#include <stdio.h>
#include <string.h>
#include "student.h"
#include "teacher.h"


struct Teacher teachers[1000];

static int tnum=0;
void teacher_insert()
{
		int i;
		while(1)
		{
				printf("请输入教员序号:");
				scanf("%d",&teachers[tnum].id);
				for(i=0;i<tnum;i++)
				{
						if(teachers[tnum].id==teachers[i].id)
						{
								printf("该序号已存在!\n");
								return ;
						}
				}
				printf("请输入教员姓名:");
				scanf("%s",teachers[tnum].name);
				getchar();
				printf("请输入所在班级:");
				scanf("%d",&teachers[tnum].class);
				strcpy(teachers[tnum].passwd,"?");
				tnum++;
				printf("添加成功!\n");
				printf("是否继续?(y/n)");
				getchar();
				if((getchar())=='n')
						break;
		}
}

int teacher_findid(int id)
{
		int i;
		for(i=0;i<tnum;i++)
		{
				if(teachers[i].id==id)
						return i;
		}
		return -1;
}


int teacher_search(int id)
{
		int i;
		for(i=0;i<tnum;i++)
		{
				if(teachers[i].id==id)
						return 1;
		}
		return 0;
}


void teacher_delete()
{
		int id,x,i;
		while(1)
		{
				printf("请输入要删除的教师的序号:");
				scanf("%d",&id);
				x=teacher_findid(id);
				if(x==-1)
						printf("该教师不存在!");
				else
				{
						printf("是否确定删除?(y/n)");
						if((getchar())=='n')
								break;
						else
								for(i=x;i<tnum-1;i++)
										teachers[i]=teachers[i+1];
						printf("删除成功!\n");
						printf("是否继续?(y/n)");
						getchar();
						if((getchar())=='n')
								break;
				}
		}
}
						
void teacher_change()
{
		int i,j,id,x;
		while(1)
		{
				printf("请输入要修改的教师的序号:");
				scanf("%d",&id);
				x=teacher_findid(id);
				if(x==-1)
						printf("该教师不存在!");
				else
				{
				       printf("请输入教员序号:");
				       scanf("%d",&teachers[x].id);
				       for(i=0;i<tnum;i++)
				       {
						   if(teachers[tnum].id==teachers[i].id)
						   {
								printf("该序号已存在!\n");
								return ;
						   } 
			           }
				       printf("请输入教员姓名:");
				       scanf("%s",teachers[x].name);
				       getchar();
				       printf("请输入所在班级:");
				       scanf("%d",&teachers[x].class);
				       tnum++;
				       printf("修改成功!\n");
				       printf("是否继续?(y/n)");
					   getchar();
				       if((getchar())=='n')
					      	break;
				}
		}
}

void teacher_changeus(int id)
{
		int x;
		x=teacher_findid(id);
		printf("请输入教员姓名:");
		scanf("%s",teachers[x].name);
		getchar();
		printf("请输入所在班级:");
		scanf("%d",&teachers[x].class);
		printf("修改成功!\n");
}	

void teacher_passwd(int id)
{
		int x;
		x=teacher_findid(id);
		printf("请设置新的密码:");
		scanf("%s",teachers[x].passwd);
		getchar();
		printf("设置成功!\n");
}

void teacher_display(int tn)
{
		printf("教师序号:%d\n姓名:%s\n班级:%d\n",teachers[tn].id,teachers[tn].name,teachers[tn].class);
}

int teacher_findname(char name1[128])
{
		int i;
		for(i=0;i<tnum;i++)
		{
				if(strcmp(teachers[i].name,name1)==0)
						return i;
		}
		return -1;
}

void teacher_displayclass(int class1)
{
		int i,b[100],j=0;
		for(i=0;i<tnum;i++)
		{
				if(teachers[i].class==class1)
						b[j++]=i;
		}
				if(j==0)
						printf("没有该班级!");
				for(i=0;i<j;i++)
		                printf("教师序号:%d\n姓名:%s\n班级:%d\n",teachers[i].id,teachers[i].name,teachers[i].class);
}


void teacher_find()
{
		char flag,name1[128];
		int i,x,id,class1;
		printf("a) 按序号查找\n");
		printf("b) 按姓名查找\n");
		printf("c) 按班级查找\n");
		printf("请选择查找方式:");
		getchar();
		scanf("%c",&flag);
		switch(flag)
		{
				case 'a':{
								 printf("请输入教师序号:");
								 scanf("%d",&id);
								 x=teacher_findid(id);
								 if(x==-1)
										 printf("该教师不存在!");
								 else
										 teacher_display(x);
								 break;
						 }
				case 'b':{
								 printf("请输入教师姓名:");
								 scanf("%s",name1);
								 x=teacher_findname(name1);
								 if(x==-1)
										 printf("该教师不存在!");
								 else
								
								 teacher_display(x);
								 break;
						 }
				case 'c':{
								 printf("请输入班级:");
								 scanf("%d",&class1);
								 teacher_displayclass(class1);
								 break;
						 }
		}
}
								 
void teacher_displayall()
{
		int i;
		for(i=0;i<tnum;i++)
		       printf("教师序号:%d\n姓名:%s\n班级:%d\n\n",teachers[i].id,teachers[i].name,teachers[i].class);
}

void teacher_sort()
{
		int i,flag,j;
		struct Teacher teach;
		printf("1) 显示所有教师\n");
		printf("2) 按教师序号进行显示\n");
		printf("请选择功能:");
		scanf("%d",&flag);
		switch(flag)
		{
				case 1:{
							   teacher_displayall();
							   break;
					   }
				case 2:{
							   for(i=0;i<tnum-1;i++)
									   for(j=0;j<tnum-i;j++)
											   if(teachers[j].id>teachers[j+1].id)
											   {
													   teach=teachers[j];
													   teachers[j]=teachers[j+1];
													   teachers[j+1]=teach;
											   }
							   teacher_displayall();
							   break;
					   }
		}
}
void teacher_readfile()
{
		FILE *fp;
		int i;
		if((fp=fopen("teacher","r+"))==NULL)
		{
				printf("不能打开文件!\n");
				for(i=0;i<tnum;i++)
						strcpy(teachers[i].passwd,"?");
				return ;
		}
		        fread(&tnum,sizeof(int),1,fp);
				for(i=0;i<tnum;i++)
				{
						fread(&teachers[i],sizeof(struct Teacher),1,fp);
				}
		fclose(fp);
}

void teacher_writefile()
{
		FILE *fp;
		int i;
		if((fp=fopen("teacher","w+"))==NULL)
		{
				printf("不能打开文件!\n");
				return ;
		}
		if(fwrite(&tnum,sizeof(int),1,fp)!=1)
		{
				printf("写入文件错误!");
		}
		else
				fread(&tnum,sizeof(int),1,fp);
				for(i=0;i<tnum;i++)
				{
						fwrite(&teachers[i],sizeof(struct Teacher),1,fp);
				}
		printf("写入成功!\n");
		fclose(fp);
}






