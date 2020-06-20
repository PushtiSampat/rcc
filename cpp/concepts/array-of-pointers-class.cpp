#include<iostream>

class Matrix 
{
    private :
        int **p;
        int rows, cols;

    public :
        Matrix (int, int);

        void getElement(int, int, int);
        void putElement(int, int);
};


Matrix :: Matrix (int rows, int cols)
{
    this -> rows = rows;
    this -> cols = cols;

    p = new int*[rows];
    for (int i = 0; i < rows; i++) {
        p[i] = new int [cols];
        std :: cout << p[i] << std :: endl;
    }
}

void Matrix :: getElement (int i, int j, int value)
{
    // this -> p[i][j] = value; 
    *(*(p + i) + j) = value;
}
 
void Matrix :: putElement (int i, int j)
{
    //std :: cout << p[i][j] << std :: endl;
    std :: cout << *(*(p + i) + j) << std :: endl;
}

int main ()
{
    const int x = 2, y = 2, z = 2;
    std :: cout << x << y << z << std :: endl;

    int rows, cols, element;
    std :: cout << "Enter Rows" << std :: endl;
    std :: cin >> rows;

    std :: cout << "Enter Cols" << std :: endl;
    std :: cin >> cols;

    Matrix M (rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std :: cout << "Enter Element: ";
            std :: cin >> element;

            M.getElement(i, j, element);
        } 
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            M.putElement(i, j);
        } 
    }

    return 0;
}
