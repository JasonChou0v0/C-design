#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//-------------------ȫ��------------------
	FILE*p; //����һ���ļ�ָ��
	FILE*p1; //����һ���ļ�ָ��
	FILE*p2;
#define LEN 30   //�ṹ�����ַ����ĳ���
struct caipin   //����ṹ��
{
	char name[LEN];
	
	int jiage;
	
	char add[LEN];
}cpin;
struct yuangong   //����ṹ��
{
	char name[LEN];
	
	int jiage;
	
	char add[LEN];
}cpin1;
//----------------------------------------------

int Validate()//��֤�˺�����
{
    char login_name[5],login_key[6];
    char a[6]="admin",b[7]="123456";
    printf("\t\t�������˺�����\n\t\t");
	scanf("%s",login_name);
	printf("\n\t\t");
    scanf("%s",login_key);
    if(strcmp(login_name,a)==0&&strcmp(login_key,b)==0)
    printf("\t\t��ӭ����\n");
    else
    {
        printf("\t\t�����˺������Ƿ���ȷ\n");
        Validate();//�ݹ�
    }
    return 0;
}
//========================================================
void Home()//��ȥ��ҳ��
{
	void Interface_selection();

    printf("\t\t  ��ӭ������ʯ���������ϵͳ  \n");
    printf("\t\t-----------------------------\n");
    printf("\t\t1.���ڹ���\t\t2.Ա������\n");
    printf("\t\t3.ȫ�ּ���\n");
    printf("\t\t0.�˳�����\n");
    Interface_selection();
}

void Interface_selection()//����ѡ��
{
	void Interface_selection();//��������
	void Window_management();//��������
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
        printf("\t\t���������Ƿ���ȷ\n");
        Interface_selection();
    }
}
//------------------0 ����---------------------------------
void end()
{
	printf("\t\t��л����ʹ�ã�");
}
//------------------------1------------------------------
void Window_management()//���ڹ���
{
	void Window_management();
	void Home();
	void end();
	void Juti_window1();

    int a;
	printf("\t\t1.����1\t\t2.����2\t\t3.����3\n\t\t5.����\t\t0.����\n\t\t");
	scanf("%d",&a);

    switch(a)
    {
    case 1:
        Juti_window1();break;
    case 2:
        printf("\t\t\t����2��ͣӪҵ,��ȥ�������ھͲ�\n");
		Window_management();break;
    case 3:
        printf("\t\t\t����3����������װ���У���ȥ�������ھͲ�\n");
		Window_management();break;
	case 5:
		Home();break;
	case 0:
		end();break;
    default :
        {
            printf("\t\t��ѡ��Ĵ�����δӪҵ\n");
            Window_management();
        }
    }
}
//-----------------------------------------------------
void Juti_window1()//���崰�ں���
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
	printf("\t\t1.���ݶ�ȡ\t\t2.����д��\t\t3.�����޸�\n\t\t4.����ɾ��\t\t5.����\t\t0.����\n\t\t");
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
		printf("\t\t���������Ƿ���ȷ\n");
		Juti_window1();	
	}

}
//=================���ݱ��ģ��=====================
void sj_shanchu()
{

	char name[20],name1[7]="linshi",name2[7]="caipin";
	if((p=fopen("caipin","rb"))==NULL)  //�Զ����Ƶķ�ʽ��ȡ
	{
		printf("\t\tERROR");
		exit(0);
	}
	p2=fopen("linshi","wb+");
	printf("\t\t������Ҫɾ��������\n\t\t");
	scanf("%s",name);
	while(fread(&cpin,sizeof(struct caipin),1,p)==1)
	{
		if(strcmp(cpin.name,name)!=0)//�ҵ��޸�Ŀ��
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
	printf("\t\t��������Ҫ�޸ĵ�����:\n\t\t");
	scanf("%s",name);
	p = fopen("caipin","rb+");
	while(fread(&cpin,sizeof(struct caipin),1,p)==1)
	{
		if(strcmp(cpin.name,name)==0)//�ҵ��޸�Ŀ��
		{ 
			printf("\t\t%s\t%d\t%s",cpin.name,cpin.jiage,cpin.add);
			printf("\n");
			printf("\t\t�������µ���Ϣ:\n\t\t");
			scanf("%s%d%s",name,&jiage,add);
			strcpy(cpin.name,name);//cpin.name = name;//�޸ı���cpin��name
			cpin.jiage = jiage;//strcpy(cpin.jiage,jiage);
			strcpy(cpin.add,add);//cpin.add = add;
			fseek(p,-sizeof(struct caipin),SEEK_CUR);//ָ�������޸�Ŀ��ǰ 
			fwrite(&cpin,sizeof(struct caipin),1,p);//д���µ�cpin����ԭdata 
			printf("\t\t\t�޸ĳɹ�\n"); 
			break;
		}
	}
	fclose(p); 

	puts("\t\t��ʼ��ȡ..."); 
	sj_duqu();//���ݶ�ȡ
} 
//------------------------------------------------------------------------
void sj_xieru()//����д��

{
	if((p=fopen("caipin","ab"))==NULL)  //����һ����caipin���ļ��Զ�������ʽ���д򿪽���д�������
	{
		printf("ERROR");
		
		exit(0);
	}
	
	printf("\t\t����������\n\t\t");
	scanf("%s%d%s",&cpin.name,&cpin.jiage,&cpin.add);//����������Ϣ
	
	if(fwrite(&cpin,sizeof(struct caipin),1,p)!=1)//ÿ��дһ���ṹ�������ռ���ֽڣ������������д���ļ�
	{
		printf("write error");
	}

	fclose(p);	//�ر��ļ�
}
//------------------------------------------------
void sj_duqu()//���ݶ�ȡ
{
	if((p=fopen("caipin","rb"))==NULL)  //�Զ����Ƶķ�ʽ��ȡ
	{
		printf("\t\tERROR");
		exit(0);
	}
	{
		printf("\t\t����\t\t�۸�\tԭ��\n");
		while(fread(&cpin,sizeof(struct caipin),1,p) == 1)
		{
			printf("\t\t%s\t%d\t%s",cpin.name,cpin.jiage,cpin.add);
			printf("\n");
		}
	}
	fclose(p);	//�ر��ļ�
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
	printf("\t\t1.���ݶ�ȡ\t\t2.����д��\t\t3.�����޸�\n\t\t4.����ɾ��\t\t5.����\t\t0.����\n\t\t");
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
		printf("\t\t���������Ƿ���ȷ\n");
		Juti_window1();	
	}

}
//---------------------------  3  ---------------------------
//----------------------------------------------------------------------
void yg_duqu()
{
	if((p1=fopen("yuangong","rb"))==NULL)  //�Զ����Ƶķ�ʽ��ȡ
	{
		printf("ERROR");
		exit(0);
	}
	{
		printf("���� ���� ��Ϣ\n");
		while(fread(&cpin1,sizeof(struct yuangong),1,p1) == 1)
		{
			printf("%s,%d,%s",cpin1.name,cpin1.jiage,cpin1.add);
			printf("\n");
		}
	}
	fclose(p1);	//�ر��ļ�
}
//-----------------------------------------------------------------
void yg_xieru()
{
	if((p1=fopen("yuangong","ab"))==NULL)  //����һ����caipin���ļ��Զ�������ʽ���д򿪽���д�������
	{
		printf("ERROR");
		
		exit(0);
	}
	
	printf("����������\n");
	scanf("%s%d%s",&cpin1.name,&cpin1.jiage,&cpin1.add);//����������Ϣ
	
	if(fwrite(&cpin1,sizeof(struct yuangong),1,p1)!=1)//ÿ��дһ���ṹ�������ռ���ֽڣ������������д���ļ�
	{
		printf("write error");
	}

	fclose(p1);	//�ر��ļ�
}
//----------------------------------
void yg_xiugai()
{
	void sj_duqu();

	char name[100],add[100];
	int jiage;
	printf("\t\t��������Ҫ�޸ĵ�����:\n\t\t");
	scanf("%s",name);
	p = fopen("yuangong","rb+");
	while(fread(&cpin1,sizeof(struct yuangong),1,p1)==1)
	{
		if(strcmp(cpin1.name,name)==0)//�ҵ��޸�Ŀ��
		{ 
			printf("\t\t%s\t%d\t%s",cpin1.name,cpin1.jiage,cpin1.add);
			printf("\n");
			printf("\t\t�������µ���Ϣ:\n\t\t");
			scanf("%s%d%s",name,&jiage,add);
			strcpy(cpin1.name,name);//cpin.name = name;//�޸ı���cpin��name
			cpin1.jiage = jiage;//strcpy(cpin.jiage,jiage);
			strcpy(cpin1.add,add);//cpin.add = add;
			fseek(p,-sizeof(struct yuangong),SEEK_CUR);//ָ�������޸�Ŀ��ǰ 
			fwrite(&cpin1,sizeof(struct yuangong),1,p1);//д���µ�cpin����ԭdata 
			printf("\t\t\t�޸ĳɹ�\n"); 
			break;
		}
	}
	fclose(p1); 

	puts("\t\t��ʼ��ȡ..."); 
	yg_duqu();//���ݶ�ȡ
}
//========================  4  ============================================

void search()
{
	void search();
	void Home();
	void end();
	char name[30];
	int i,j;
	printf("\t\t1.��ѯԱ��\t\t2.��ѯ��Ʒ\t\t5.����\t\t0.����\n\t\t");
	scanf("%d",&i);
	if(i == 1)
	{
			printf("\t\t��������Ҫ������Ա������:\n\t\t");
			scanf("%s",name);
			p1 = fopen("yuangong","rb");
			while(fread(&cpin1,sizeof(struct yuangong),1,p1)==1)
			{
				if(strcmp(cpin1.name,name)==0)//�ҵ��޸�Ŀ��
				{ 
					printf("\t\t%s\t%d\t%s",cpin1.name,cpin1.jiage,cpin1.add);
					printf("\n");
				}
			}
			fclose(p1);
			search();

	}//�ر��ļ�

	else if(i == 2)
	{
		printf("\t\t��������Ҫ�����Ĳ�Ʒ����:\n\t\t");
		scanf("%s",name);
		p = fopen("caipin","rb");
		while(fread(&cpin,sizeof(struct caipin),1,p)==1)
		{
			if(strcmp(cpin.name,name)==0)//�ҵ��޸�Ŀ��
			{ 
				printf("\t\t %s\t%d\t%s",cpin.name,cpin.jiage,cpin.add);
				printf("\n");
			}
		}
		fclose(p);
		search();
	}//�ر��ļ�
	else if(i == 5)
		Home();
	else if(i == 0)
		end();
	else
	{
		printf("\t\t���������Ƿ���ȷ");
		search();
	}
}



int main()
{
	Validate();//��֤�˺�����
    Home();//������ҳ����
    return 0;
}
