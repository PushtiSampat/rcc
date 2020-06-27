
/*==========================================================================================**

11_j.Convert string to all upper case.

==========================================================================================**/

#include<stdio.h>

void input(char str[])
{
	printf("Enter String :");
	gets(str);
}

void display11_j(char *ptr)
{
	printf("String = ");
	while(*ptr != '\0')
	{
		printf("%c",*ptr);
		ptr++;
	}
	printf("\n");
}

void toupper(char *ptr)
{
	while(*ptr != '\0')
	{
		if(*ptr >= 97 && *ptr <=122)
		{
			*ptr = *ptr - 32;
			//*ptr++;
		}
		ptr++;
		//printf("%c",*ptr2);
	}
}

int main()
{
	char str[100];
	char *ptr;
	
	input(str);
	
	ptr = str;
	
	display11_j(ptr);
	
	printf("\nToUpper: ");
	
	toupper(ptr);
	
	display11_j(ptr);

	return 0;
}

/*==========================================================================================**

Enter String :Ajinkya
String = Ajinkya

ToUpper: String = AJINKYA

==========================================================================================**/