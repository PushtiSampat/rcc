

/*==========================================================================================**
11_f.	Delete all occurrences of a string from another string. Ignore Case.
==========================================================================================**/


#include<stdio.h>
#include<string.h>

void remove_str(char str1[],char str2[])
{
	int i,j,k,found=1,index,itemp,len1,len2;
	char *sptr1,*sptr2;
	len1=strlen(str1);
	len2=strlen(str2);
	sptr1=str1;
	sptr2=str2;

	for(i=0; i<len1; i++)
	{
		if(*(sptr1+i) == *(sptr2)|| *(sptr1+i) == *(sptr2)-32 ||*(sptr1+i) == *(sptr2)+32)				
		{
			index=i;												
			itemp=i;
			itemp++;
			for(j=1;j<len2;j++,itemp++)			
			{

				if(*(sptr2+j) != *(sptr1+itemp) && *(sptr2+j) != *(sptr1+itemp)-32 && *(sptr2+j) != *(sptr1+itemp)+32)					
				{
					found=0;
					break;
				}
			}
			if(found)
			{
				for(k=0;k<len1;k++)									
				{
					*(sptr1+index+k)=*(sptr1+index+len2+k);	
				}
				len1-=len2;											
				*(str1+len1)='\0';
				i--;
			}
			found=1;
		}
	}
}


int main()
{
	char str1[50],str2[50];
	int index;
	
	printf("Enter first string: ");
	gets(str1);
	
	printf("Enter second string: ");
	gets(str2);
	
	remove_str(str1,str2);
	
	printf("After removing second string: \n");
	puts(str1);														
	
	return 0;
}


/* ============================================================
	
	Output:
	Enter first string: Ajinkya
	Enter second string: AJi
	After removing second string:
	nkya

 ============================================================ */
