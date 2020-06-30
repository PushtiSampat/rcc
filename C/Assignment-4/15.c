
// =================================================================
// Q15

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void Insert(char *fname,int n)
{
	char str[100];
	int i;
	FILE *fp;
	fp=fopen(fname,"w");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}

	for(i=0;i<=n;i++)
	{
		fgets(str,sizeof(str),stdin);
		fputs(str,fp);
	}
	fclose(fp);
}

void get_line(char *fname,int n,int lno)
{
	char str[100];
	int i,cnt=0;
	FILE *fp;
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}

	for(i=0;i<=n;i++)
	{
		fgets(str,sizeof(str),fp);
		if(i==lno)
		{
			fputs(str,stdout);
			cnt++;
		}
	}
	fclose(fp);
	//printf("\n cnt is:%d",cnt);
}


void Insert_line_at_k(char *fname,int n,int k)
{
	char str[100],str2[100],ch;
	int i,cnt=0,n2;
	FILE *fp,*fptr;
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}
	
	fptr=fopen("temp.txt","w");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}

	for(i=0;i<=n;i++)
	{
		fgets(str,sizeof(str),fp);
		fputs(str,fptr);
		if(i==k)
		{
			printf("\n Enter Number of line:");
			scanf("%d",&n2);

			for(int j=0;j<=n2;j++)
			{
				fgets(str2,sizeof(str2),stdin);
				if(j!=0)
				{
					fputs(str2,fptr);
				}
			}
		
			cnt++;
		}
		
	}
	fclose(fp);
	fclose(fptr);


	fp=fopen(fname,"w");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}

	fptr=fopen("temp.txt","r");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}
	
	while((ch=getc(fptr))!=EOF)
	{
		fprintf(fp,"%c",ch);
	}
	fclose(fp);
	fclose(fptr);

}


void Delete_line_at_k(char *fname,int n,int k)
{
	char str[100],str2[100],ch;
	int i,cnt=0,n2;
	FILE *fp,*fptr;
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}
	
	fptr=fopen("temp.txt","w");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}

	for(i=0;i<=n;i++)
	{
		fgets(str,sizeof(str),fp);
		fputs(str,stdout);
		fputs(str,fptr);
		if(i==k)
		{
			printf("\n Enter Number of line:");
			scanf("%d",&n2);

			for(int j=0;j<n2;j++)
			{
				fgets(str,sizeof(str),fp);
				i++;
			}
		
		}
		
	}
	fclose(fp);
	fclose(fptr);


	fp=fopen(fname,"w");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}

	fptr=fopen("temp.txt","r");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}
	
	while((ch=getc(fptr))!=EOF)
	{
		fprintf(fp,"%c",ch);
	}
	fclose(fp);
	fclose(fptr);

}


void display(char *fname,int n)
{
	int i;
	FILE *fp;
	char ch;

	fp=fopen(fname,"r");
	fseek(fp,0L,0);
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	ch = fgetc(fp);
	while(ch != EOF)
	{
			printf("%c", ch);
			ch = fgetc(fp);
	}
	fclose(fp);
}

void main()
{
	int n,res,lno;
	char file_name[80],choice='n',name[20],tele[10],ch[10],ch2;
	static int cnt=0;

	printf("\n Enter File name:");
	scanf("%s",&file_name);
	printf("\n --------------------");
	printf("\n 1.$E-Enter new text ");
	printf("\n 2.$L-list the entire block of text");
	printf("\n 3.$Fk-find(retrieve)line number k ");
	printf("\n 4.$In-insert n lines after line number k ");
	printf("\n 5.$Dn-delete n lines after line number k ");
	printf("\n 6.$S-save the edited block of text and end the computation");
	printf("\n --------------------");
	do
	{
		printf("\n Enter Your choice:");
		scanf("%s",&ch);
		switch(ch[0])
		{
			case 69:printf("\n Input the number of lines to be written : ");
					scanf("%d", &n);
					cnt=cnt+n;
					Insert(file_name,cnt);
					break;
			case 76:
					printf("\n----------------");
					printf("\n Display Files");
					printf("\n----------------");
					display(file_name,cnt);
					break;
			case 70:
					ch2=ch[1]-'0';
					lno=ch2;
					if(lno>cnt)
						printf("\n Invalid line number");
					else
						get_line(file_name,cnt,lno);
					break;
			case 73:
					ch2=ch[1]-'0';
					lno=ch2;
					if(lno>cnt)
						printf("\n Invalid line number");
					else
						Insert_line_at_k(file_name,cnt,lno);
					break;

			case 68:
					ch2=ch[1]-'0';
					lno=ch2;
					if(lno>cnt)
						printf("\n Invalid line number");
					else
						Delete_line_at_k(file_name,cnt,lno);					
					break;	
			case 83:
					exit(0);
					break;
			default :
					printf("\n Invalid Choice");
					break;
		}	
		printf("\n Do You want to continue:");
		scanf("%s",&choice);

	}while(choice=='y' || choice=='Y');
	
	getch();
}




// =================================================================