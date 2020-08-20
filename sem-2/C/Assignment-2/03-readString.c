
/* ==================================================================
Read String Using Pointers
================================================================== */

#include<stdio.h>
#include<string.h>

char strupr(char *str)
{

  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = toupper((unsigned char)*p);
      p++;
  }

}

int filterString(char string1[])
{
	char *cptr;
	int vowels = 0, consonants = 0, numbers = 0, whitespaces = 0, special_characters = 0;

	// string1 = strupr(string1);

	cptr = string1;

	while(*cptr != '\0') {

		// Vowels should always come before consonants, else consonants will always be increased
		if(*cptr == 65 || *cptr == 69 || *cptr == 73 || *cptr == 79 || *cptr == 85) {
			printf("Vowel: %c is stored at %d \n", *cptr, cptr);
			vowels++;
		}
		
		else if (*cptr > 47 && *cptr < 58) {
			printf("Number: %c is stored at %d \n", *cptr, cptr);
			numbers++;
		}

		else if(*cptr == 9 || *cptr == 32) {
			printf("Whitespace: %c is stored at %d \n", *cptr, cptr);
			whitespaces++;
		}

		else if(*cptr > 64 && *cptr < 91){
			printf("Consonant: %c is stored at %d \n", *cptr, cptr);
			consonants++;
		}
		
		else {
			printf("Special Character: %c is stored at %d \n", *cptr, cptr);
			special_characters++;
		}

		cptr++;
	}

	printf("\n Vowels: %d\n", vowels);
	printf("\n Numbers: %d\n", numbers);
	printf("\n Whitespaces: %d\n", whitespaces);
	printf("\n Consonants: %d\n", consonants);
	printf("\n Special Characters: %d\n", special_characters);

	return 0;
}


int main()
{
	char string1[50];
	
	printf("Enter String\n");
	scanf("%[^\n]",string1);
	
	strupr(string1);

	filterString(string1);

	printf("\n");

	return 0;
}



/* ==================================================================
================================================================== */


