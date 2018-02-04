#include <stdio.h>
#include <string.h>
#include "tooler.h"
#include "student.h"
#include "teacher.h"

//struct Tooler tooler[10]={"admin","?"};

//int tonum=0;

void tooler_passwd()
{
		printf("请输入新的密码:");
		scanf("%s",tooler[tonum].passwd);
		printf("修改成功!");
}
		
void tooler_readfile()
{
		FILE *fp;
		if((fp=fopen("tooler","r+"))==NULL)
		{
				printf("不能打开文件!\n");
				strcpy(tooler[0].name,"admin");
				strcpy(tooler[0].passwd,"?");;
				return ;
		}
		if(fread(&tonum,sizeof(int),1,fp)!=1)
		{
				tonum=-1;
		}
		else
				fread(&tooler[tonum],sizeof(struct Tooler),1,fp);
		fclose(fp);
}

void tooler_writefile()
{
		FILE *fp;
		if((fp=fopen("tooler","w+"))==NULL)
		{
				printf("不能打开文件!\n");
				return ;
		}
		if(fwrite(&tonum,sizeof(int),1,fp)!=1)
		{
				printf("写入错误!\n");
		}
		else
				fwrite(&tooler[tonum],sizeof(struct Tooler),1,fp);
		fclose(fp);
}






