

/* ==========================================================================================**
11_e.	Delete all occurrences of a character from a string. Ignore Case.

==========================================================================================**/

#include<stdio.h>
#include<string.h>

void delete_char(char str[],char ch)
{
	char *sptr=str;
	int i,j,length,index;
	length=strlen(str);

	for(i=0;i<length;i++)
	{
		if(*(sptr+i) == ch ||*(sptr+i) == ch-32 || *(sptr+i) == ch+32  )
		{
			j=i;
			while(j<length-1)
			{
				*(sptr+j)=*(sptr+j+1);
				j++;
			}
			*(sptr+length-1)='\0';
			length--;
			i--;
		}
	}
}

int main()
{
	char str[10],ch;

	printf("Enter string: ");
	gets(str);
	
	printf("Enter character to delete its all occurrences: ");
	scanf("%c",&ch);
	
	delete_char(str,ch);
	
	printf("Result: ");
	puts(str);

	return 0;

}


/* ==========================================================================================**
Enter string: aajjiinnkkyyaa
Enter character to delete its all occurrences: i
Result: aajjnnkkyyaa
==========================================================================================**/


