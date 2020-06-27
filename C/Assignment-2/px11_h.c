
/* ============================================================================================

11_h.Copy n characters of one string to another string.

==========================================================================================**/ 

#include<stdio.h>

void input11_h(char str[])
{
	printf("Enter String :");
	gets(str);
}


void disp11_h(char *ptr)
{
	printf("String = ");
	while(*ptr != '\0')
	{
		printf("%c",*ptr);
		ptr++;
	}
	printf("\n");
}

void copych (char *ptr,char *cptr,int n)
{
	int i = 0;
	for(i = 0; i<n ; i++)
	{
		//printf("asd");
		*cptr = *ptr;
		cptr++;
		ptr++;
	}
	*cptr = '\0';
}

int main()
{
	char str[50],cstr[50];
	char *ptr,*cptr;
	int n;//i = 0;

	input11_h(str);

	ptr = str;

	disp11_h(ptr);

	printf("Enter How Many Characters You want to Copy: ");
	scanf("%d",&n);
	
	cptr = cstr;
	printf("Cloned String: ");

	copych(ptr,cptr,n);
	disp11_h(cptr);

	return 0;
}

/* ==========================================================================================**


Enter String :aaajjiinnkkyyaa
String = aaajjiinnkkyyaa
Enter How Many Characters You want to Copy: 7
Cloned String: String = aaajjii


==========================================================================================**/

