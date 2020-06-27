

/*==========================================================================================**
11_b.	Find the first occurrence of a string in another string. The function should return the position in the string.

==========================================================================================**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int search(char str1[],char str2[])
{
	int i,j,found=1,index,itemp;
	char *sptr1,*sptr2;
	sptr1=str1;
	sptr2=str2;

	for(i=0; *(sptr1+i) != '\0'; i++)
	{
		if(*(sptr1+i) == *(sptr2))
		{
			index=i;
			itemp=i;
			itemp++;
			for(j=1;*(sptr2+j) != '\0';j++,itemp++)
			{
				if(*(sptr2+j) != *(sptr1+itemp))
				{
					found=0;
					break;
				}
			}
			if(found)
			{
				return index;
			}
			found=1;
		}
	}
	
	return -1;
}

void main()
{
	char str1[10],str2[10];
	int index;
	printf("Enter first string: ");
	gets(str1);
	printf("Enter second string: ");
	gets(str2);

	index=search(str1,str2);
	if(index == -1)
	{
		printf("Second string not found in first string!!");
	}
	else
	{
		printf("Second string found at index %d in first string",index);
	}
	getch();
}


/*==========================================================================================**
Enter first string: Ajinkya
Enter second string: ink
Second string found at index 2 in first string
==========================================================================================**/


