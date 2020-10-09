#ifndef swap_H
#define swap_H
  
void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

#endif
