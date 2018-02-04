#include <stdio.h>
#include <string.h>
#include "student.h"
#include "teacher.h"
#include "tooler.h"
#include "login.h"

int login(int flag)
{
		int i,id,x,j=0,f1,y;
		char pass[32],toolerid[128];
		switch(flag)
		{
				case 0:{
							   printf("请输入你的学号进行登录:");
							   scanf("%d",&id);
							   y=search(id);
							   if(y==0)
									   return -1;
							   else
							   x=student_findid(id);
							   if(strcmp(students[x].passwd,"?")==0)
							   {
									   printf("你还未设置密码，请设置新的密码:");
									   scanf("%s",students[x].passwd);
									   getchar();
									   printf("密码:%s\n",students[x].passwd);
									   printf("设置成功!\n");
									   printf("欢迎%s同学登录!\n",students[x].name);
									   writefile();
									   return id;
							   }
							   else
							   {
									   while(1)
									   {
											   printf("请输入你的密码:");
									           scanf("%s",pass);
									           getchar();
									           if(strcmp(students[x].passwd,pass)==0)
									           {
											       printf("登录成功!\n");
											       printf("欢迎%s同学登录!\n",students[x].name);
											       return id;
									           }
									           else if(j==2)
													   return 0; //错误三次，跳出循环

											       j++;
									   }
							   }
							   break;
					   }
				case 1:{
							   printf("请输入你的教师序号进行登录:");
							   scanf("%d",&id);
							   y=teacher_search(id);
							   if(y==0)
									   return -1;
							   x=teacher_findid(id);
							   if(strcmp(teachers[x].passwd,"?")==0)
							   {
									   printf("你还未设置密码，请设置新的密码:");
									   scanf("%s",teachers[x].passwd);
									   getchar();
									   printf("设置成功!\n");
									   printf("欢迎%s老师登录!\n",teachers[x].name);
									   return id;
							   }
							   else
							   {
									   while(1)
									   {
											   printf("请输入你的密码:");
									           scanf("%s",pass);
									           getchar();
									           if(strcmp(teachers[x].passwd,pass)==0)
									           {
											       printf("登录成功!\n");
											       printf("欢迎%s老师登录!\n",teachers[x].name);
											       return id;
									           }
									           else if(j==2)
													   return 0; //错误三次，跳出循环

											       j++;
									   }
							   }
					    }

				case 2:{
							   printf("请输入管理员帐号:");
							   scanf("%s",toolerid);
							   getchar();
							   if(strcmp(toolerid,"admin")==0)
							  {
							     if(strcmp(tooler[0].passwd,"?")==0)
							      {
									   printf("你还未设置密码，请设置新的密码:");
									   scanf("%s",tooler[0].passwd);
									   getchar();
									   printf("设置成功!\n");
									   printf("欢迎管理员登录!\n");
									   return 1;
								  }
								  else
									   while(1)
									   {
											   printf("请输入管理员密码:");
									           scanf("%s",pass);
									           getchar();
									           if(strcmp(tooler[0].passwd,pass)==0)
									           {
													   printf("登录成功!\n");
											           printf("欢迎管理员登录!\n");
											           return 1;
									           }
									            else if(j==2)
														return 0;
									             j++;
									   }
							   }
							   else
							   {
									   printf("帐号错误!");
							   }
							   break;
					   }

		}
}

