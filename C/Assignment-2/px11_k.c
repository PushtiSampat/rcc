/*==========================================================================================**

11_k.Convert string to all Lower case.

==========================================================================================**/


#include<stdio.h>
#include<conio.h>
void inputk(char str[])
{
	printf("Enter String: ");
	gets(str);
}

void display11_k(char *ptr)
{
	printf("String = ");
	while(*ptr != '\0')
	{
		printf("%c",*ptr);
		ptr++;
	}
	printf("\n");
}

void tolower(char *ptr)
{
	while(*ptr != '\0')
	{
		if(*ptr >= 65 && *ptr <=90)
			*ptr = *ptr + 32;
		ptr++;
	}
}

int main()
{
	char str[100];
	char *ptr;

	inputk(str);

	ptr = str;

	display11_k(ptr);

	printf("\nAfter Converting ToLower Case\n ");

	tolower(ptr);

	display11_k(ptr);

	return 0;
}


/*==========================================================================================**
output:
Enter String :Ajinkya
String = Ajinkya

After Converting ToLower Case:
ajinkya

==========================================================================================**/


