


// =================================================================
// Q16
// Command Line Find Word In current Directory


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

int findWordIn(char search_this_word[], char d_name[])
{
	int i = 0, length = 0, count = 0, finding = 0, first_occurance = 0;
	char c, search;
	FILE *f = fopen (d_name, "r"); 

    // printf("\nWorking on File: %s \n", d_name);

	length = strlen (search_this_word);

	if (f) {
		if(!length) {
			exit(0);
		}

		search = search_this_word[0];

		while((c = fgetc(f)) != EOF){
			if (count == 0) {
				first_occurance++;
			}

			if (search == c) {
				finding = 1;

				if(length == i + 1) {

					i = finding = 0;
					count++;
					search = search_this_word[i];
				}

				else {
					search = search_this_word[++i];
				}

			}
			else {
				finding = 0;
			}
		}

		if (count > 0) {
            // printf ("\"%s\" found 1st time at %d position \n", search_this_word, first_occurance - length + 1);
            // printf ("\"%s\" found %d times\n", search_this_word, count);
			return first_occurance - length + 1;
		}
		else {
            // printf ("\"%s\" not found\n", search_this_word);
			return -1;
		}
	}
	else {
        // puts ("Cannot open file to read");
		return -1;
	} 
	return -1;
}

int* findWordInDirectory(int argc, char **argv, int *arr)
{
	int count = 0;
	DIR *d;
	char wordToFind[50];
	struct dirent *dir;

	if(argc != 2) {
		printf("Enter one word to find\n");
		exit(1);
	}
	d = opendir(".");
	strcpy(wordToFind, argv[1]);

	if(d) {
		while((dir = readdir(d)) != NULL) {
			arr[count] = findWordIn(wordToFind, dir -> d_name);
			count += 1;
		}
		closedir(d);
	}
	return arr;

}

int main(int argc, char **argv)
{
    // Assuming max 50 files in directory 
	int arr[50], count = 0;

	int *ptr = findWordInDirectory(argc, argv, arr);
    // Return Position where Word was found, else returns -1

	DIR *d;
	struct dirent *dir;

	d = opendir(".");

	if (d) {
		printf("Position   Filename\n");
		while ((dir = readdir(d)) != NULL){

			if(ptr[count] != -1) {
				printf("%8d   %s\n", ptr[count], dir->d_name);
			}
			count += 1;
		}
		closedir(d);
	}

	return 0;
}

/* =================================================

ajinzrathod@ajinz:~/Documents/Assgn/cla$ ./objectFile Rollwala

Position   Filename
     606   01-alternate.c
     746   02-copy-line-by-line.c
     216   03-find-word.c
     545   04-sort-merge.c
     549   05-repeated-characters.c
     231   06-count-characters-whitespaces.c
    1055   07-remove-occurences.c
     967   08-remove-blank-lines.c
    1020   09-remove-comments.c
     884   10-telephone.c
     788   16-cla-check-executable.c
    1877   16-cla-find-word-in-directory.c

 ================================================= */

