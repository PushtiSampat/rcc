
/* ==========================================================================================**

11_i. Find length of the string and toggle the characters of the string.

==========================================================================================* */

#include<stdio.h>

void input11_i(char str[])
{
	printf("Enter String :");
	gets(str);
}
void disp(char *ptr)
{
	printf("\nString = ");
	while(*ptr != '\0')
	{
		printf("%c",*ptr);
		ptr++;
	}
	printf("\n");
}
void toggle(char *ptr)
{
	while(*ptr != '\0')
	{
		if(*ptr >= 65 && *ptr <= 90)
		{
			*ptr = *ptr + 32;
		}
		else if(*ptr >= 97 && *ptr <= 122)
		{
			*ptr = *ptr - 32;
		}
		else
		{
			
		}
		ptr++;
	}
}

int main()
{
	char str[50];
	char *ptr;
	
	input11_i(str);
	
	ptr = str;
	
	disp(ptr);	
	
	toggle(ptr);
	
	disp(ptr);

	return 0;
}

/* ==========================================================================================**
	Enter String :ajink

	String = ajink

	String = AJINK
==========================================================================================**/

