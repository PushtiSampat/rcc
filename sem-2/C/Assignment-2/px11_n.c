/* ==========================================================================================**
11_n.	Append at most n characters of one string S2 to another string S1.	

==========================================================================================**/ 


#include<stdio.h>
#include<string.h>

void append_n(char str1[],char str2[],int n)
{
	int len1,len2,i;
	char *sptr1,*sptr2;

	sptr1=str1;
	sptr2=str2;
	len1=strlen(sptr1);
	len2=strlen(sptr2);
	*(sptr1+len1)=' ';
	for(i=0;i<n;i++)
	{
		*(sptr1+len1+i+1)=*(sptr2+i);
	}

	*(sptr1+len1+i+1)='\0';

}

int main()
{
	int n;
	char str1[30],str2[30];
	
	printf("Enter first string: ");
	gets(str1);
	
	printf("Enter second string: ");
	gets(str2);
	
	printf("Enetr how many characters you want to append: ");
	scanf("%d",&n);
	
	append_n(str1,str2,n);

	printf("After appending %d characters: ",n);
	puts(str1);
	
	return 0;
}


/* ==========================================================================================**

output:

Enter first string: ajinkya
Enter second string: rathod
Enetr how many characters you want to append: 5
After appending 5 characters: ajinkya ratho

==========================================================================================* */


