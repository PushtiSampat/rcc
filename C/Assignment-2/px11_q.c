/* ==========================================================================================**
11_q.	(q) Compare two strings S1 and S2. The function should return -1, 0 or 1 if S1 < S2, S1 = S2 and S1 > S2 respectively.
	Ignore case.	

==========================================================================================**/

#include<stdio.h>
#include<string.h>

int str_icompare(char s1[],char s2[])
{
	char *sp1,*sp2;
	int i=0;

	sp1=s1;
	sp2=s2;

	while(*(sp1+i) != '\0' && *(sp2+i) != '\0')
	{
		if(*(sp1+i) < *(sp2+i))
		{
			if( *(sp1+i) < *(sp2+i)-32)
			return -1;
		}
		else if(*(sp1+i) > *(sp2+i))
		{
			if( *(sp1+i) < *(sp2+i)+32)
			return 1;
		}
		i++;
	}

	if(*(sp1+i) != '\0' && *(sp2+i) == '\0')
	{
		return 1;
	}
	else if(*(sp1+i) == '\0' && *(sp2+i) != '\0')
	{
		return -1;
	}
	else
		return 0;

}

int main()
{
	char s1[30],s2[30];
	int result;
	
	printf("Enter string1: ");
	gets(s1);
	
	printf("Enter string 2: ");
	gets(s2);

	result=str_icompare(s1,s2);
	
	printf("result is %d",result);

	return 0;
}


/*==========================================================================================**
output1:

Enter string1: AJIN
Enter string 2: ajin
result is 0

==========================================================================================**/


