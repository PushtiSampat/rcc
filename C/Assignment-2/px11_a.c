
/* ==========================================================================================**

11_a. Find the first occurrence of a character in the given string. The function should return the
position in the string.

==========================================================================================**/

#include<stdio.h>
#include<conio.h>
void disp_str(char *ptr)
{
	//char *ptr;
	//ptr=str;
	printf("String = ");
	while(*ptr != '\0')
	{
		printf("%c",*ptr);
		ptr++;
	}
}

int search_char(char *ptr, char ch)
{
	int i,val = -1;
	//char *ptr;
	//ptr = str;
	for(i = 0 ; *ptr != '\0' ; i++)
	{
		if(*ptr == ch)
		{
			val = i;
			break;
		}
		ptr++;
	}
	return val;
}


int main()
{
	char str[50],ch,*ptr;
	int search_val;
	
	printf("Enter String :");
	gets(str);
	
	ptr = str;
	
	disp_str(ptr);
	
	printf("\nWhich Character You Find :");
	scanf("%c",&ch);
	
	search_val = search_char(ptr,ch);
	
	if (search_val == -1)
		printf("\nCharacter %c is not found..",ch);
	
	else
		printf("Character %c is found at %d",ch,search_val);
	
	return 0;
}

/* ==========================================================================================**

Enter String :Ajinkya
String = Ajinkya
Which Character You Find :k
Character k is found at 4

==========================================================================================**/


