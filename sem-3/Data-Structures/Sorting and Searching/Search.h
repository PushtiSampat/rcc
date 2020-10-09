int linearSearch(int data, int *array, int size)
{
    for(int i = 0; i < size; i++)
        if(array[i] == data)
            return i;
    return -1;
}

int binarySearch(int data, int *array, int size)
{
    int lb = 0, ub = size;

    while(lb <= ub){
        int middle =  (lb + ub) / 2;

        if(data == array[middle])
            return middle;

        else if(data > array[middle])
            lb = middle + 1;
        
        else if(data < array[middle])
            ub = middle - 1;
    }
    return -1;
}
