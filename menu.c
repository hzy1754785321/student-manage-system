#include <stdio.h>
#include "tooler.h"
void meanu(int n)
{
		if(n==0)
		{
      			printf("\t\t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("\t\t\t\t\t\t\t       学  生  管  理  系  统      \n\n");
				printf("\t\t\t\t\t\t\t**********************************\n");
				printf("\t\t\t\t\t\t\t**********************************\n");
				printf("\t\t\t\t\t\t\t*****1:   查 看 本 人 信 息  *****\n\n");
				printf("\t\t\t\t\t\t\t*****2:   修 改 本 人 信 息  *****\n\n");
				printf("\t\t\t\t\t\t\t*****3:   修 改 帐 号 密 码  *****\n\n");
				printf("\t\t\t\t\t\t\t*****4:   保 存 修 改        *****\n\n");
				printf("\t\t\t\t\t\t\t*****5:   退 出 系 统        *****\n\n");
				printf("\t\t\t\t\t\t\t**********************************\n");
				printf("\t\t\t\t\t\t\t**********************************\n\n\n");
				printf("\t\t\t\t\t\t\t\t\t                     作者：何朝阳\n\n");
				printf("\t\t\t\t\t\t\t\t\t                     student ver\n");
		}
		if(n==1)
		{
      			printf("\t\t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("\t\t\t\t\t\t\t        学  生  管  理  系  统      \n\n");
				printf("\t\t\t\t\t\t\t***************************************\n");
				printf("\t\t\t\t\t\t\t***************************************\n");
				printf("\t\t\t\t\t\t\t******1:  学  生  信  息  录  入 ******\n\n");
				printf("\t\t\t\t\t\t\t******2:  查  看  本  人  信  息 ******\n\n");
		        printf("\t\t\t\t\t\t\t******3:  修  改  本  人  信  息 ******\n\n");
				printf("\t\t\t\t\t\t\t******4:  修  改  帐  号  密  码 ******\n\n");
				printf("\t\t\t\t\t\t\t******5:  查  看  学  生  信  息 ******\n\n");
				printf("\t\t\t\t\t\t\t******6:  查  找  学  生  数  据 ******\n\n");
				printf("\t\t\t\t\t\t\t******7:  修  改  学  生  成  绩 ******\n\n");
				printf("\t\t\t\t\t\t\t******8:  保  存  修  改         ******\n\n");
				printf("\t\t\t\t\t\t\t******9:  退  出  系  统         ******\n\n");
				printf("\t\t\t\t\t\t\t***************************************\n");
				printf("\t\t\t\t\t\t\t***************************************\n\n\n");
				printf("\t\t\t\t\t\t\t\t\t                     作者：何朝阳\n\n");
				printf("\t\t\t\t\t\t\t\t\t                     teacher ver\n");
		}
		if(n==2)
		{
      			printf("\t\t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("\t\t\t\t\t\t\t    学  生  管  理  系  统      \n\n");
				printf("\t\t\t\t\t\t\t******************************\n");
				printf("\t\t\t\t\t\t\t******************************\n");
				printf("\t\t\t\t\t\t\t*****1:   信 息 录 入    *****\n\n");
				printf("\t\t\t\t\t\t\t*****2:   查 看 信 息    *****\n\n");
				printf("\t\t\t\t\t\t\t*****3:   修 改 信 息    *****\n\n");
				printf("\t\t\t\t\t\t\t*****4:   查 找 数 据    *****\n\n");
				printf("\t\t\t\t\t\t\t*****5:   删 除 数 据    *****\n\n");
				printf("\t\t\t\t\t\t\t*****6:   修 改 密 码    *****\n\n");
				printf("\t\t\t\t\t\t\t*****7:   保 存 修 改    *****\n\n");
				printf("\t\t\t\t\t\t\t*****8:   退 出 系 统    *****\n\n");
				printf("\t\t\t\t\t\t\t******************************\n");
				printf("\t\t\t\t\t\t\t******************************\n\n\n");
				printf("\t\t\t\t\t\t\t\t\t                     作者：何朝阳\n\n");
				printf("\t\t\t\t\t\t\t\t\t                     admin  ver\n");
		}
}

void toolermeanu()
{
		printf("1) 学生\n");
		printf("2) 老师\n");
		printf("请选择对象:");
}
