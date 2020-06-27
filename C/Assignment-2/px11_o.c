
/* ============================================================================================

11_o. Reverse all the characters in the string.

==========================================================================================* */


#include<stdio.h>
#include<string.h>

void reverse_string(char *str)
{
	int len , i ;
	char *start, *end, ch;

	len=strlen(str);
	//printf("count = %d",len);

	start = str;
	end = str;
	for(i = 0 ; i < len-1 ; i++)
	{ 
		end++;
	}
	//printf("end = %s",*end);
	for(i=0 ; i < len/2 ; i++)
	{
		ch = *start;
		*start = *end;
		*end = ch;
		start++;
		end--;
	}
	//printf("Reverse String = %s",*str);
}

int main()
{
	char str[100];
	
	printf("Enter String :");
	
	gets(str);	

	printf("Entered: %s",str);
	
	reverse_string(str);
	
	printf("\nReversed: %s\n",str);

	return 0;
}


/* ==========================================================================================**


Enter String :ajinkya
Entered: ajinkya
Reversed: ayknija

==========================================================================================**/