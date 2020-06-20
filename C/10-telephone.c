#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct telephone
{
    int id;
    char tel[13];
    char name[50];
};

int askN()
{
    int n;
    printf ("Enter no of record you want to enter: ");
    scanf ("%d",&n);
    return n;
}

// Function for -> Creating Strcut
struct telephone *createStruct()
{
	struct telephone *new_struct;

	// Sufficient memory not available
	if((new_struct = (struct telephone *) malloc(sizeof(struct telephone))) == NULL) {
		perror("\n ** Sufficient Memory Not Available ** \n");
		exit(1);
	}

	return new_struct;
}

void enterRecords(int n)
{
    int i = 0, seek_me;
    struct telephone *p =  createStruct();
    FILE *f1= fopen("tel_records.txt", "wb");

    while (n) {
        printf("Id: %d \n", ++i);
        p->id = i;

        printf ("Enter name: ");
        scanf ("%s",p->name);

        printf ("Enter  telephone no: ");
        scanf ("%s",p->tel);

        fprintf (f1, "%03d ",p->id);
        fprintf (f1, "%s ",p->tel);
        fprintf (f1, "%s\n",p->name);

        seek_me = ((sizeof (struct telephone)) + 3) * (i - 1);
        fseek (f1, seek_me,SEEK_SET);
        n--;
    }
    fclose(f1);
}

void deleteRecord(int n)
{
    int id = 1, max_size, seek_me;
    FILE *f1 = fopen ("tel_records.txt", "rb");

    // 2 spaces and 1 \n (+3)
    max_size = ((sizeof (struct telephone)) + 3) * (n - 1);
    seek_me = ((sizeof (struct telephone)) + 3) * (id - 1);

    if (seek_me > max_size) {
        printf ("Max Limit Reached");
        return;
    }

    printf("%ld \n", sizeof (struct telephone));
    printf("%d", seek_me);

    fseek (f1, seek_me ,SEEK_SET);
    fprintf(f1, "*");
    fclose (f1);

}
int main ()
{
    int n;
    n = askN();
    enterRecords(n);
    deleteRecord(n);

    return 0;
}
