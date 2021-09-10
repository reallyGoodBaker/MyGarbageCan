#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#define clrscr() system("cls") /*清屏*/

typedef struct
{
	char a[20];
	char b[40];
}XYZ;

XYZ xyz[50];
void init() /*初始化函数*/
{
	int i;
	FILE *fp;
	for (i=0;i<50;i++)
	{
		memset(xyz[i].a,'\0',20); /*清空磁道*/
		memset(xyz[i].b,'\0',40);
	}
	fp=fopen("c:\\my.txt","w"); /*在 C 盘新建一个 TXT 文件*/
	fp=fopen("c:\\my.txt","r"); /*将新建的 TXT 文件打开*/
	i=0;
	while( fscanf(fp,"%s %s\n",xyz[i].a,xyz[i].b)!=EOF) /*由文件向结构体数组中写数锯*/
		i++;
	fclose(fp);
}
void find() /*单词查询函数*/
{
	int i;
	char temp[20];
	clrscr();
	printf("please input a word:");
	scanf("%s",temp);
	for (i=0;i<50;i++)
	if(strcmp(temp,xyz[i].a)==0) /*通过比较字符查询*/
	{
		printf ("\n\n%s : %s",xyz[i].a,xyz[i].b);
		printf ("\n\npress y to redo or other keys to return");
		if(getch() == 'y') find();
		return;
	}
	printf ("\n\nnot found");
	getch();
	return;
}
void add() /*词条录入函数*/
{
	int i,j;
	char temp[20];
	char temp1[40];
	clrscr();
	for (i=0;i<50;i++)
	{
		if(!(*xyz[i].a)) /*找到空位*/
		{
			printf("\n\nplease input the word:");
			scanf("%s",temp);
			for (j=0;j<50;j++)
			if(strcmp(temp,xyz[j].a)==0) /*找到相同字符*/
			{
				printf ("\n\nthe word is already store\n\n");
				getch();
				return;
			}
			printf("\n\nplease input the mean:");
			scanf("%s",temp1);
			strcpy(xyz[i].a,temp); /*复制*/
			strcpy(xyz[i].b,temp1);
			printf ("press y to redo or other keys to return");
			if(getch() == 'y') add();
			return;
		}
	}
	printf("\n\nsorry,the data is full");
}
void del() /*词条删除函数*/
{
	int i;
	char temp[20];
	clrscr();
	printf("\n\nplease input the word:");
	scanf("%s",temp);
	for (i=0;i<50;i++)
	if(strcmp(temp,xyz[i].a)==0) /*比较*/
	{
		memset(xyz[i].a,'\0',20); /*清空该结构体*/
		memset(xyz[i].b,'\0',40);
		printf ("\n\nsuccess,press y to redo or other keys to return");
		if(getch() == 'y') del();
		return;
	}
	printf ("\n\nnot found");
	getch();
	return;
}
void modify() /*词条修改函数*/
{
	int i;
	char temp[20];
	char temp1[40];
	clrscr();
	printf("\n\nplease input the word:");
	scanf("%s",temp);
	for (i=0;i<50;i++)
	if(strcmp(temp,xyz[i].a)==0)
	{
		printf ("\n\nfound\n\n");
			printf("%s : %s\n\n",xyz[i].a,xyz[i].b); /*显示原有单词和意思*/
		printf ("\n\nplease input the new mean:");
		scanf("%s",temp1);
		strcpy(xyz[i].b,temp1); /* 从 temp1 复制结构体中*/
		printf ("\n\nsuccess,press y to redo or other keys to return");
		if(getch() == 'y') modify();
		return;
	}
	printf ("\n\nnot found");
	getch();
	return;
}
void view() /*信息显示函数*/
{
	int i,j;
	clrscr();
	for (i=0,j=0;i<50;i++)
	{
	if(*xyz[i].a!='\0') /*如果不是空位*/
		{
			j++;
			printf("%s : %s\n",xyz[i].a,xyz[i].b);
		if(j==20) /*分页显示， 一次显示 20 页*/
			{
				j=0;
				printf ("\nprease any key to page down");
				getch();
				clrscr();
			}
		}
	}
	printf("\n\nthat's all");
	getch();
}
void store() /*信息保存函数*/
{
	int i;
	FILE *fp;
	fp=fopen("c:\\my.txt","w"); /*以读的方式再新建 my.txt 文档*/
	if(fp==NULL) /*没建成显示 wrong!*/
	printf("wrong!");
	getchar();
	for (i=0;i<50;i++)
		fprintf(fp,"%s %s\n",xyz[i].a,xyz[i].b); /*将结构体中的数剧保存到 my.txt 文档*/
		fclose(fp);
	printf ("\n\nstore success");
	getch();
	return;
}
int main(void) /*主函数*/
{
	char key;
	init();
	while(1)
	{
		clrscr();
		printf("\n\n\n 电子英汉词典\n\n");
		printf("*********************\n");
		printf("*   1. 单 词 查 询  * \n");
		printf("*   2. 词 条 录 入  * \n");
		printf("*   3. 词 条 删 除  * \n");
		printf("*   4. 词 条 修 改  * \n");
		printf("*   5. 信 息 显 示  * \n");
		printf("*   6. 信 息 保 存  * \n");
		printf("*   7. 退 出 系 统  * \n");
		printf("*********************\n\n");
		printf("请按下键盘上对应数字(1-7)\n\n");
		key=getch();
		switch(key)
		{
			case '1':find();break;
			case '2':add();break;
			case '3':del();break;
			case '4':modify();break;
			case '5':view();break;
			case '6':store();break;
			case '7': return 0;
		}
	}
	return 0;
}
