#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//-------------------全局------------------
	FILE*p; //设置一个文件指针
	FILE*p1; //设置一个文件指针
	FILE*p2;
#define LEN 30   //结构体中字符串的长度
struct caipin   //定义结构体
{
	char name[LEN];
	
	int jiage;
	
	char add[LEN];
}cpin;
struct yuangong   //定义结构体
{
	char name[LEN];
	
	int jiage;
	
	char add[LEN];
}cpin1;
//----------------------------------------------

int Validate()//验证账号密码
{
    char login_name[5],login_key[6];
    char a[6]="admin",b[7]="123456";
    printf("\t\t请输入账号密码\n\t\t");
	scanf("%s",login_name);
	printf("\n\t\t");
    scanf("%s",login_key);
    if(strcmp(login_name,a)==0&&strcmp(login_key,b)==0)
    printf("\t\t欢迎回来\n");
    else
    {
        printf("\t\t请检查账号密码是否正确\n");
        Validate();//递归
    }
    return 0;
}
//========================================================
void Home()//进去主页面
{
	void Interface_selection();

    printf("\t\t  欢迎来到西石大餐厅管理系统  \n");
    printf("\t\t-----------------------------\n");
    printf("\t\t1.窗口管理\t\t2.员工管理\n");
    printf("\t\t3.全局检索\n");
    printf("\t\t0.退出程序\n");
    Interface_selection();
}

void Interface_selection()//界面选择
{
	void Interface_selection();//函数声明
	void Window_management();//函数声明
	void yg_management();
	void search();
	void end();
    int sequence_number;
	printf("\n\t\t");
    scanf("%d",&sequence_number);
    if(sequence_number == 1)

        Window_management();

    else if(sequence_number == 2)
	{
        yg_management();
	}

    else if(sequence_number == 3)

        search();

    else if(sequence_number == 0)

        end();

    else
    {
        printf("\t\t请检查输入是否正确\n");
        Interface_selection();
    }
}
//------------------0 结束---------------------------------
void end()
{
	printf("\t\t感谢您的使用！");
}
//------------------------1------------------------------
void Window_management()//窗口管理
{
	void Window_management();
	void Home();
	void end();
	void Juti_window1();

    int a;
	printf("\t\t1.窗口1\t\t2.窗口2\t\t3.窗口3\n\t\t5.返回\t\t0.结束\n\t\t");
	scanf("%d",&a);

    switch(a)
    {
    case 1:
        Juti_window1();break;
    case 2:
        printf("\t\t\t窗口2暂停营业,请去其他窗口就餐\n");
		Window_management();break;
    case 3:
        printf("\t\t\t窗口3售罄，紧急装修中，请去其他窗口就餐\n");
		Window_management();break;
	case 5:
		Home();break;
	case 0:
		end();break;
    default :
        {
            printf("\t\t您选择的窗口暂未营业\n");
            Window_management();
        }
    }
}
//-----------------------------------------------------
void Juti_window1()//具体窗口函数
{
	void Juti_window1();
	void Window_management();
	void sj_xieru();
	void sj_duqu();
	void sj_xiugai();
	void sj_shanchu();
	void yg_xieru();
	void yg_duqu();
	int a;
	printf("\t\t1.数据读取\t\t2.数据写入\t\t3.数据修改\n\t\t4.数据删除\t\t5.返回\t\t0.结束\n\t\t");
	scanf("%d",&a);
	if(a == 1) 
	{
		sj_duqu();
		Juti_window1();
	}
	else if(a == 2) 
	{
		sj_xieru();
		Juti_window1();
	}
	else if(a == 3)
	{
		sj_xiugai();
		Juti_window1();
	}
	else if(a == 4)
	{
		sj_shanchu();
		Juti_window1();
	}
	else if(a == 5)
	{
		Window_management();
	}
	else if(a == 0)
	{
		end();
	}
	else
	{
		printf("\t\t请检查输入是否正确\n");
		Juti_window1();	
	}

}
//=================数据变更模块=====================
void sj_shanchu()
{

	char name[20],name1[7]="linshi",name2[7]="caipin";
	if((p=fopen("caipin","rb"))==NULL)  //以二进制的方式读取
	{
		printf("\t\tERROR");
		exit(0);
	}
	p2=fopen("linshi","wb+");
	printf("\t\t请输入要删除的姓名\n\t\t");
	scanf("%s",name);
	while(fread(&cpin,sizeof(struct caipin),1,p)==1)
	{
		if(strcmp(cpin.name,name)!=0)//找到修改目标
		{
			fwrite(&cpin,sizeof(struct caipin),1,p2);
		}
	}
	fclose(p);
	fclose(p2);
	
	remove("caipin");
	rename(name1,name2);
}
//------------------------------------------------------
void sj_xiugai()
{
	void sj_duqu();

	char name[100],add[100];
	int jiage;
	printf("\t\t请输入想要修改的名称:\n\t\t");
	scanf("%s",name);
	p = fopen("caipin","rb+");
	while(fread(&cpin,sizeof(struct caipin),1,p)==1)
	{
		if(strcmp(cpin.name,name)==0)//找到修改目标
		{ 
			printf("\t\t%s\t%d\t%s",cpin.name,cpin.jiage,cpin.add);
			printf("\n");
			printf("\t\t请输入新的信息:\n\t\t");
			scanf("%s%d%s",name,&jiage,add);
			strcpy(cpin.name,name);//cpin.name = name;//修改变量cpin的name
			cpin.jiage = jiage;//strcpy(cpin.jiage,jiage);
			strcpy(cpin.add,add);//cpin.add = add;
			fseek(p,-sizeof(struct caipin),SEEK_CUR);//指针移至修改目标前 
			fwrite(&cpin,sizeof(struct caipin),1,p);//写入新的cpin覆盖原data 
			printf("\t\t\t修改成功\n"); 
			break;
		}
	}
	fclose(p); 

	puts("\t\t开始读取..."); 
	sj_duqu();//数据读取
} 
//------------------------------------------------------------------------
void sj_xieru()//数据写入

{
	if((p=fopen("caipin","ab"))==NULL)  //建立一个叫caipin的文件以二进制形式进行打开进行写入操作，
	{
		printf("ERROR");
		
		exit(0);
	}
	
	printf("\t\t请输入数据\n\t\t");
	scanf("%s%d%s",&cpin.name,&cpin.jiage,&cpin.add);//输入数据信息
	
	if(fwrite(&cpin,sizeof(struct caipin),1,p)!=1)//每次写一个结构体变量所占的字节，将输入的数据写入文件
	{
		printf("write error");
	}

	fclose(p);	//关闭文件
}
//------------------------------------------------
void sj_duqu()//数据读取
{
	if((p=fopen("caipin","rb"))==NULL)  //以二进制的方式读取
	{
		printf("\t\tERROR");
		exit(0);
	}
	{
		printf("\t\t名称\t\t价格\t原料\n");
		while(fread(&cpin,sizeof(struct caipin),1,p) == 1)
		{
			printf("\t\t%s\t%d\t%s",cpin.name,cpin.jiage,cpin.add);
			printf("\n");
		}
	}
	fclose(p);	//关闭文件
}
//---------------------------------------------------------------------
//=========================  2  ========================================
void yg_management()
{
	void yg_duqu();
	void yg_xieru();
	void yg_xiugai();
	void yg_shanchu();
	int a;
	printf("\t\t1.数据读取\t\t2.数据写入\t\t3.数据修改\n\t\t4.数据删除\t\t5.返回\t\t0.结束\n\t\t");
	scanf("%d",&a);
	if(a == 1) 
	{
		yg_duqu();
		yg_management();
	}
	else if(a == 2) 
	{
		yg_xieru();
		yg_management();
	}
	else if(a == 3)
	{
		yg_xiugai();
		yg_management();
	}
	else if(a == 5)
	{
		Home();
	}
	else if(a == 0)
	{
		end();
	}
	else
	{
		printf("\t\t请检查输入是否正确\n");
		Juti_window1();	
	}

}
//---------------------------  3  ---------------------------
//----------------------------------------------------------------------
void yg_duqu()
{
	if((p1=fopen("yuangong","rb"))==NULL)  //以二进制的方式读取
	{
		printf("ERROR");
		exit(0);
	}
	{
		printf("姓名 年龄 信息\n");
		while(fread(&cpin1,sizeof(struct yuangong),1,p1) == 1)
		{
			printf("%s,%d,%s",cpin1.name,cpin1.jiage,cpin1.add);
			printf("\n");
		}
	}
	fclose(p1);	//关闭文件
}
//-----------------------------------------------------------------
void yg_xieru()
{
	if((p1=fopen("yuangong","ab"))==NULL)  //建立一个叫caipin的文件以二进制形式进行打开进行写入操作，
	{
		printf("ERROR");
		
		exit(0);
	}
	
	printf("请输入数据\n");
	scanf("%s%d%s",&cpin1.name,&cpin1.jiage,&cpin1.add);//输入数据信息
	
	if(fwrite(&cpin1,sizeof(struct yuangong),1,p1)!=1)//每次写一个结构体变量所占的字节，将输入的数据写入文件
	{
		printf("write error");
	}

	fclose(p1);	//关闭文件
}
//----------------------------------
void yg_xiugai()
{
	void sj_duqu();

	char name[100],add[100];
	int jiage;
	printf("\t\t请输入想要修改的名称:\n\t\t");
	scanf("%s",name);
	p = fopen("yuangong","rb+");
	while(fread(&cpin1,sizeof(struct yuangong),1,p1)==1)
	{
		if(strcmp(cpin1.name,name)==0)//找到修改目标
		{ 
			printf("\t\t%s\t%d\t%s",cpin1.name,cpin1.jiage,cpin1.add);
			printf("\n");
			printf("\t\t请输入新的信息:\n\t\t");
			scanf("%s%d%s",name,&jiage,add);
			strcpy(cpin1.name,name);//cpin.name = name;//修改变量cpin的name
			cpin1.jiage = jiage;//strcpy(cpin.jiage,jiage);
			strcpy(cpin1.add,add);//cpin.add = add;
			fseek(p,-sizeof(struct yuangong),SEEK_CUR);//指针移至修改目标前 
			fwrite(&cpin1,sizeof(struct yuangong),1,p1);//写入新的cpin覆盖原data 
			printf("\t\t\t修改成功\n"); 
			break;
		}
	}
	fclose(p1); 

	puts("\t\t开始读取..."); 
	yg_duqu();//数据读取
}
//========================  4  ============================================

void search()
{
	void search();
	void Home();
	void end();
	char name[30];
	int i,j;
	printf("\t\t1.查询员工\t\t2.查询菜品\t\t5.返回\t\t0.结束\n\t\t");
	scanf("%d",&i);
	if(i == 1)
	{
			printf("\t\t请输入想要搜索的员工名称:\n\t\t");
			scanf("%s",name);
			p1 = fopen("yuangong","rb");
			while(fread(&cpin1,sizeof(struct yuangong),1,p1)==1)
			{
				if(strcmp(cpin1.name,name)==0)//找到修改目标
				{ 
					printf("\t\t%s\t%d\t%s",cpin1.name,cpin1.jiage,cpin1.add);
					printf("\n");
				}
			}
			fclose(p1);
			search();

	}//关闭文件

	else if(i == 2)
	{
		printf("\t\t请输入想要搜索的菜品名称:\n\t\t");
		scanf("%s",name);
		p = fopen("caipin","rb");
		while(fread(&cpin,sizeof(struct caipin),1,p)==1)
		{
			if(strcmp(cpin.name,name)==0)//找到修改目标
			{ 
				printf("\t\t %s\t%d\t%s",cpin.name,cpin.jiage,cpin.add);
				printf("\n");
			}
		}
		fclose(p);
		search();
	}//关闭文件
	else if(i == 5)
		Home();
	else if(i == 0)
		end();
	else
	{
		printf("\t\t请检查输入是否正确");
		search();
	}
}



int main()
{
	Validate();//验证账号密码
    Home();//进入主页面面
    return 0;
}
