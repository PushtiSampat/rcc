
/* ==========================================================================================**

11_c. Delete all occurrences of a character from a string.

==========================================================================================**/

#include<stdio.h>
#include<conio.h>
void input_data(char str[])
{
	printf("Enter String =");
	gets(str);
}
void display11_c(char *ptr)
{
	printf("\nString = ");
	while(*ptr != '\0')
	{
		printf("%c",*ptr);
		ptr++;
	}
	printf("\n");
}
void delete_char(char *ptr,char ch,char str2[])
{
	char *ptr2;
	ptr2 = str2;
	while(*ptr != '\0')
	{
		//printf("aer");
		if(*ptr != ch)
		{
			*ptr2 = *ptr;
			ptr2++;
		}
		ptr++;
	}
	*ptr2 = '\0';
}

int main()
{	
	char str[50],str2[50],ch;
	char *ptr;
	
	input_data(str);
	
	ptr = str;
	
	display11_c(ptr);
	
	printf("\nEnter Which Character You want to delete :");
	scanf("%c",&ch);
	
	delete_char(ptr,ch,str2);
	
	printf("\nAfter Deleting Character:");
	display11_c(str2);

	return 0;
}

/*==========================================================================================**

Enter String =ajinkya

String = ajinkya

Enter Which Character You want to delete :a

After Deleting Character:
String = jinky

==========================================================================================**/

