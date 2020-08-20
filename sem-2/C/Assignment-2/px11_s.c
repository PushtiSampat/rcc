/* ==========================================================================================**
11_s.	Compare at most n characters of two strings S1 and S2. The function should return -1, 0 or 1 if	S1 < S2, S1 = S2 and
	S1 > S2 respectively.Ignore case.	

==========================================================================================* */


#include<stdio.h>
#include<string.h>

int str_incompare(char s1[],char s2[],int n)
{
	char *sp1,*sp2;
	int i=0;

	sp1=s1;
	sp2=s2;

	while((*(sp1+i) != '\0' && *(sp2+i) != '\0') && i<n)
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

	if(*(sp1+i) != '\0' && *(sp2+i) == '\0' && i<n)
	{
		return 1;
	}
	else if(*(sp1+i) == '\0' && *(sp2+i) != '\0' && i<n)
	{
		return -1;
	}
	else
		return 0;

}

void main()
{
	char s1[30],s2[30];
	int result,n;
	
	printf("Enter string1: ");
	gets(s1);
	printf("Enter string 2: ");
	gets(s2);
	printf("Enter how many characters you want to compare: ");
	scanf("%d",&n);
	result=str_incompare(s1,s2,n);
	printf("result is %d",result);

	getch();
}


/* ==========================================================================================**
output:
Enter string1: Ajinkya
Enter string 2: ajinkya12345
Enter how many characters you want to compare: 6
result is 0

==========================================================================================**/


