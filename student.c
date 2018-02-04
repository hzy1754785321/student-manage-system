#include <stdio.h>
#include <string.h>
#include "student.h"
#include "login.h"

 struct Student students[1000];

struct Student students1[1000];
static int num=0;
void insert()  //插入学生信息 
{
		int i;
		while(1)
		{
				printf("请输入学号:");
				scanf("%d",&students[num].id);
				for(i=0;i<num;i++)
				{
						if(students[num].id==students[i].id)
						{
								printf("该学号已存在!\n");
								return ;
						}
				}
				printf("请输入姓名:");
				scanf("%s",students[num].name);
				getchar();
				printf("请输入年龄:");
				scanf("%d",&students[num].age);
				printf("请输入班级:");
				scanf("%d",&students[num].class);
				printf("请输入语文成绩:");
				scanf("%f",&students[num].chinese);
				printf("请输入数学成绩:");
				scanf("%f",&students[num].math);
				printf("请输入C语言成绩:");
				scanf("%f",&students[num].C);
				students[num].ave=average(students[num]);   // 求平均分
				students[num].rand=rank(students[num].id);
                student_display(num);
				strcpy(students[num].passwd,"?");
				printf("num=%d\n",num);
				num++;
				printf("是否继续?(y/n)\n");
				getchar();
				if(getchar()=='n')
						break;
		}
}
int search(int id)
{
		int i;
		for(i=0;i<num;i++)
		{
				if(students[i].id==id)
						return 1;
		}
		return 0;
}

int rank(int id)
{
		int i,j;
		for(i=0;i<num;i++)
		students1[i]=students[i];
		struct Student st;
				 for(i=0;i<num-1;i++)
						 for(j=0;j<num-i;j++)
								 if(students1[j].ave>students1[j+1].ave)
								 {
										 st=students1[j];
										 students1[j]=students1[j+1];
										 students1[j+1]=st;
								 }
	  for(i=0;i<num;i++)
	  {
			  if(students1[i].id==id)
					  return i;
	  }
}

int student_login(int x)
{
		if(strcmp(students[x].passwd,"?")==0)
				return 1;
		else
				return 0;
}

void student_loginpasswd(int x)
{
		scanf("%s",students[x].passwd);
}


void student_changeus(int x)
{
	    printf("请输入新数据!\n");
		printf("请输入姓名:");
	    scanf("%s",students[x].name);
		getchar();
		printf("请输入年龄:");
		scanf("%d",&students[x].age);
		printf("请输入班级:");
		scanf("%d",&students[x].class);
}

void student_passwd(int x)
{
		printf("请输入新的密码:");
		scanf("%s",students[x].passwd);
		printf("设置成功!");
		printf("mima:%s\n",students[x].passwd);
}

float average(struct Student avg)  //三门课程平均分，通过这个进行排序
{
		return ((avg.chinese+avg.math+avg.C)/3.0);
}


void student_display(int num)   //显示单个学生信息
{
		printf("\n学号:%d\n姓名:%s\n年龄:%d\n班级:%d\n语文成绩:%.2f\n数学成绩:%.2f\nC语言成绩:%.2f\n平均成绩:%.2f\n",students[num].id,students[num].name,students[num].age,students[num].class,students[num].chinese,students[num].math,students[num].C,students[num].ave);
}



int student_findname(char name[])  //通过姓名查找
{
		int i;
		for(i=0;i<num;i++)
		{
				if(strcmp(students[i].name,name))
								return i;
		}
		return -1;
}

int student_findid(int id)   //通过id查询
{
        int i;
		for(i=0;i<num;i++)
		{
		        if(students[i].id==id)
				          		return i;
		}
}

void student_displayclass(int class)  //显示班级学生的特殊函数
{
		int i,a[100],j=0;
		for(i=0;i<num;i++)
		if(students[i].class==class)
				a[j++]=i;
		if(j==0)
		{
				printf("班级不存在!");
				return ;
		}
		for(i=0;i<j;i++)      //循环输出所有该班级的学生
	         	printf("\n学号:%d\n姓名:%s\n年龄:%d\n班级:%d\n语文成绩:%.2f\n数学成绩:%.2f\nC语言成绩:%.2f\n平均成绩:%.2f\n",students[a[i]].id,students[a[i]].name,students[a[i]].age,students[a[i]].class,students[a[i]].chinese,students[a[i]].math,students[a[i]].C,students[a[i]].ave);
}


void student_find ()  //寻找学生信息
{
		char a,name[30];
		int x,id,class;
		printf("a) 根据姓名查找\n");
		printf("b) 根据学号查找\n");
		printf("c) 根据班级查找\n");
		printf("请选择查找方式:");
		getchar();
		scanf("%c",&a);
		while(1)
		{
		  switch(a)
	     	{
				case 'a':{
				                printf("请输入要查找的姓名:");
						        scanf("%s",name);
						        getchar();
						        x=student_findname(name);
						           if(x==-1)
								            printf("该学生不存在!");
						           else
								            student_display(x);
						            break;
						 }
			    case 'b':{
								printf("请输入要查找的学号:");
								scanf("%d",&id);
								x=student_findid(id);
									if(x==-1)
											printf("该学生不存在!");
									else
											student_display(x);
									break;
						 }
			    case 'c':{
								 printf("请输入要查找的班级:");
								 scanf("%d",&class);
								 student_displayclass(class);
								 break;
						 }
			}
		  printf("是否继续?(y/n)");
		  getchar();
		  if((getchar())=='n')
						  break;
		}
}

void student_delete()        //删除学生信息
{
		int i,id,x;
		while(1)
		{
				printf("请输入要删除的学生的学号:");
				scanf("%d",&id);
				x=student_findid(id);
				if(x==-1)
				{
						printf("该学生不存在!");
						break;
				}
				else
				{
						printf("确定要删除?(y/n)");
						getchar();
						if((getchar())=='n')
								break;
						else
						{
								for(i=x;i<num-1;i++)
								{
										students[i]=students[i+1];
								}
								num--;    //总数减一
						}
						printf("是否继续?(y/n))");
						getchar();
						if((getchar())=='n')
								break;
				}
		}
}

void display_all()
{
		int i;
		printf("num=%d\n",num);
		for(i=0;i<num;i++)
	         	printf("\n学号:%d\n姓名:%s\n年龄:%d\n班级:%d\n语文成绩:%.2f\n数学成绩:%.2f\nC语言成绩:%.2f\n平均成绩:%.2f\n",students[i].id,students[i].name,students[i].age,students[i].class,students[i].chinese,students[i].math,students[i].C,students[i].ave);
}

void student_change()   //修改学生数据
{
		int i,id,x;
		while(1)
		{
				printf("请输入要修改的学生的学号:");
				scanf("%d",&id);
				x=student_findid(id);
				if(x==-1)
						printf("该学生不存在!");
				else
				{
						printf("请输入新数据!\n");
						printf("请输入学号:");
						scanf("%d",&students[x].id);
				        for(i=0;i<num;i++)
				        {
						    if(students[num].id==students[i].id)
						    {
								printf("该学号已存在!\n");
								return ;
					     	}
				        }
						printf("请输入姓名:");
						scanf("%s",students[x].name);
						getchar();
						printf("请输入年龄:");
						scanf("%d",&students[x].age);
						printf("请输入班级:");
						scanf("%d",&students[x].class);
						printf("请输入语文成绩:");
						scanf("%f",&students[x].chinese);
						printf("请输入数学成绩:");
						scanf("%f",&students[x].math);
						printf("请输入C语言成绩:");
						scanf("%f",&students[x].C);
				}
				printf("是否继续?(y/n)");
				getchar();
				if((getchar())=='n')
						break;
		}
}

void sortsubject(int n)
{
		int i;
		float sum=0;
		if(1==n)
		{
				for(i=0;i<num;i++)
						sum=sum+students[i].chinese;
				printf("语文平均分为%.2f\n",sum/num);
		}
		if(2==n)
		{
				for(i=0;i<num;i++)
						sum=sum+students[i].math;
				printf("数学平均分为%.2f\n",sum/num);
		}
		if(3==n)
		{
				for(i=0;i<num;i++)
						sum=sum+students[i].C;
				printf("C语言平均分为%.2f\n",sum/num);
		}
}

void sort()   //按给定条件排序
{
		char temp;
		int i,j,flag;
		struct Student st;
		printf("a) 按学号顺序显示\n");
		printf("b) 按名次顺序显示\n");
		printf("c) 按课程成绩顺序显示\n");
		printf("请选择排序方法:");
		getchar();
		scanf("%c",&temp);
		switch(temp)
		{
				case 'a':{
								 for(i=0;i<num-1;i++)
										 for(j=0;j<num-i-1;j++)
												 if(students[j].id>students[j+1].id)
												 {
														 st=students[j];
														 students[j]=students[j+1];
														 students[j+1]=st;
												 }
								 display_all();
								 break;
						 }
				case 'b':{
								 for(i=0;i<num-1;i++)
										 for(j=0;j<num-i-1;j++)
												 if(students[j].rand>students[j+1].rand)
												 {
														 st=students[j];
														 students[j]=students[j+1];
														 students[j+1]=st;
												 }
								 display_all();
								 break;
						 }
				case 'c':{
								 printf("1) 语文\n ");
								 printf("2) 数学\n ");
								 printf("3) C语言\n");
								 printf("请选择按哪门课程排序:");
								 scanf("%d",&flag);
								 switch(flag)
								 {
										 case 1:{
												        for(i=0;i<num-1;i++)
														          for(j=0;j<num-i-1;j++)
																         if(students[j].chinese>students[j+1].chinese)
																         {
																		        st=students[j];
														                        students[j]=students[j+1];
														                        students[j+1]=st;
												                         }
												        display_all();
														sortsubject(1);   //调用函数求单个科目的平均成绩
												        break;
												}
								         case 2:{
														for(i=0;i<num-1;i++)
										                          for(j=0;j<num-i-1;j++)
												                          if(students[j].math>students[j+1].math)
												                          { 
														                        st=students[j];
														                        students[j]=students[j+1];
														                        students[j+1]=st;
												                          }
												        display_all();
														sortsubject(2);
												        break;
												}
									     case 3:{
								                        for(i=0;i<num-1;i++)
										                           for(j=0;j<num-i-1;j++)
												                          if(students[j].C>students[j+1].C)
												                          {
														                         st=students[j];
														                         students[j]=students[j+1];
													                         	 students[j+1]=st;
												                          }
														display_all();
														sortsubject(3);
														break;
												}
								 }
								 break;
						 }
		}
}


void readfile()
{
		FILE *fp;
		int i;
		int fnum;
	        if((fp=fopen("students","r+"))==NULL)
		{
				printf("不能打开文件!\n");
				for(i=0;i<num;i++)
				{
						strcpy(students[i].passwd,"?");
				}
				return ;
		}
		        fread(&num,sizeof(int),1,fp);
				for(i=0;i<num;i++)
				{
						fread(&students[i],sizeof(struct Student),1,fp);
				}
		fclose(fp);
}

void writefile()    //文件写入
{
		FILE *fp;
		int i;
	            if((fp=fopen("students","w+"))==NULL)  // 如果文件不存在创建一个新的,存在指向尾部
		{
				printf("不能打开文件!\n");
				return ;
		}
		
		     fwrite(&num,sizeof(int),1,fp);
			      for(i=0;i<num;i++)
				{
						fwrite(&students[i],sizeof(struct Student),1,fp);
				}
		printf("写入成功!\n");
		fclose(fp);
}




