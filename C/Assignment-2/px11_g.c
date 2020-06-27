
/* ==========================================================================================**

11_g. Copy one string to another string.

==========================================================================================**/

#include<stdio.h>

void get_input(char str1[])
{
	printf("Enter String =");
	gets(str1);
}


void display(char *ptr)
{
	while(*ptr != '\0')
	{
		printf("%c",*ptr);
		ptr++;
	}
	printf("\n");
}


void copy(char str2[],char *ptr)
{
	char *ptr2;
	ptr2 = str2;
	while(*ptr != '\0'){
		*ptr2 = *ptr;
		printf("\n%c: %c",(*ptr),(*ptr2));
		ptr2++;
		ptr++;
	}
	*ptr2 = '\0';
}

int main()
{
	char str1[50],str2[50];
	char *ptr;
	
	get_input(str1);
	
	ptr = str1;
	
	display(ptr);
	
	printf("Copied String: ");
	copy(str2,ptr);

	printf("\n\nString :");
	display(str2);

	return 0;
}

/* ==========================================================================================**
output:
	Enter String =Ajinkya
	Ajinkya
	Copied String:
	A: A
	j: j
	i: i
	n: n
	k: k
	y: y
	a: a

	String :Ajinkya
==========================================================================================**/

