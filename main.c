#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include "teacher.h"
#include "tooler.h"
#include "login.h"
#include "menu.h"



int main()
{
		int n,pass,status,x,flag1;
		char flag;
		printf("\t\t0:学生\n");
		printf("\t\t1:老师\n");
		printf("\t\t2:管理员\n");
		printf("请选择你的身份：");
		scanf("%d",&n);
		switch(n)
		{
				case 0:{
							   readfile();
							   pass=login(n);
							   x=student_findid(pass);
							   if(pass==-1)
							   {
									   printf("学号错误!\n");
									   break;
							   }
							   if(pass==0)
							   {
									   printf("密码错误!\n");
									   break;
							   }
							   else
									   while(1)
									   {
							            meanu(n);
									    printf("请选择功能:");
									    scanf("%c",&flag);
									       switch(flag)
									       {
											   case '1':		  student_display(x);
															  break;

											   case '2':		  student_changeus(x);
															  break;
													  
											   case '3':		  student_passwd(x);
															  break;
													  
											   case '4':		  writefile();
															  break;
													  
											   case '5':		  printf("bye!\n");
													          exit(0);
															  break;
											   default:
															  printf("选择错误!\n");
															  break;
										   }
									  }
					   }

				case 1:{
							   teacher_readfile();
							   readfile();
							   pass=login(n);
				               x=teacher_findid(pass);
							   if(pass==-1)
							   {
									   printf("序号错误!\n");
									   break;
							   }
							   if(pass==0)
							   {
									   printf("密码错误!\n");
										break;
							   }
							   else 
									   while(1)
									   {
									      meanu(n);
							              printf("请选择功能:");
							              scanf("%c",&flag); 
							              switch(flag)
									      {
											   case '1':insert();
													  break;
											   case '2':teacher_display(x);
													  break;
											   case '3':teacher_changeus(pass);
													  break;
											   case '4':teacher_passwd(pass);
													  break;
											   case '5':sort();
													  break;
											   case '6':student_find();
													  break;
											   case '7':student_change();
													  break;
											   case '8':writefile();
													  teacher_writefile();
													  break;
											   case '9':printf("bye!\n");
													  exit(0);
													  break;
											   default:
															  printf("选择错误!\n");
															  break;
									   }
					   }
				case 2:{
							   tooler_readfile();
							   pass=login(n);
							   if(pass==0)
							   {
									   printf("密码错误!\n");
									   break;
							   }
							   else
									  {
									    
							            readfile();
									    teacher_readfile();
										while(1)
										{
										 meanu(n);
									     printf("请选择功能:");
									     scanf("%c",&flag);
									     switch(flag)
									     {
											    case '1':{
															  toolermeanu();
													          scanf("%d",&flag1);
															  if(flag1==1)
															  {
																	  insert();
															          break;
															  }
															  if(flag1==2)
															  {
																	  teacher_insert();
																	  break;
															  }
													   }
											    case '2':{
															  toolermeanu();
															  scanf("%d",&flag1);
															  if(flag1==1)
															  {
																	  sort();
																	  break;
															  }
															  if(flag1==2)
															  {
																	  teacher_sort();
																	  break;
															  }
												   	   }
											    case '3':{
															  toolermeanu();
															  scanf("%d",&flag1);
															  if(flag1==1)
															  {
																	  student_change();
																	  break;
															  }
															  if(flag1==2)
															  {
																	  teacher_change();
																	  break;
															  }
													   }
												case '4':{
															   toolermeanu();
															   scanf("%d",&flag1);
															   if(flag1==1)
															   {
																	   student_find();
																	   break;
															   }
															   if(flag==2)
															   {
																	   teacher_find();
																	   break;
															   }
													   }
												case '5':{
															   toolermeanu();
															   scanf("%d",&flag1);
															   if(flag1==1)
															   {
																	   student_delete();
																	   break;
															   }
															   if(flag1==2)
															   {
																	   teacher_delete();
																	   break;
															   }
													   }
												case '6':{
															   tooler_passwd();
															   break;
													   }
												case '7':{
															   writefile();
															   teacher_writefile();
															   tooler_writefile();
															   break;
													   }
											    case '8':{
															   printf("bye!\n");
															   exit(0);
															   break;
													   }
											   default:
															  printf("选择错误!\n");
															  break;
									   }
					   }
					   }
	}
				default:
					   printf("选择错误!\n");
					   break;
					   }
		}
}
