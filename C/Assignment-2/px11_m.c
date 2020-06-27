/* ==========================================================================================**
11_m.	(m)Append one string to another string.	

==========================================================================================* */


#include<stdio.h>
#include<string.h>

void append(char str1[],char str2[])
{
	int len1,len2,i;
	char *sptr1,*sptr2;

	sptr1=str1;
	sptr2=str2;
	len1=strlen(sptr1);
	len2=strlen(sptr2);
	*(sptr1+len1)=' ';
	for(i=0;i<len2;i++)
	{
		*(sptr1+len1+i+1)=*(sptr2+i);
	}

	*(sptr1+len1+i+1)='\0';

}

int main()
{
	char str1[30],str2[30];
	
	printf("Enter first string: ");
	gets(str1);

	printf("Enter second string: ");
	gets(str2);
	
	append(str1,str2);
	
	printf("String after appending: ");
	puts(str1);
	

	return 0;
}



/* ==========================================================================================**

output:
Enter first string: Rollwala
Enter second string: Computer Center
String after appending: Rollwala Computer Center


==========================================================================================* */


