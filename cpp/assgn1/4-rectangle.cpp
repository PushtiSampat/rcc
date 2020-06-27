

// =========================================================
// Q4: Rectangle Starts


#include<iostream>

using namespace std;

class Rectangle
{
	private :
	float width;
	float height;

	public :
	Rectangle()
	{
		width = 1.0;
		height = 1.0;

		this->width = width; 
		this->height = height; 
	}

	void getData();
	float area();
	float perimeter();
};

void Rectangle :: getData()
{
	cout << endl;
	do {
		cout << "Enter Height(0.0 - 20.00) ";
		cin >> this->height;

		cout << "Enter Width(0.0 - 20.00) ";
		cin >> this->width;

	} while(height < 0.0 || height > 20.00 || width < 0.0 || width > 20.00);
}

float Rectangle :: area()
{
	return this->width * this->height;
}

float Rectangle :: perimeter()
{
	return 2 * (this->width + this->height);
}

int main()
{
	Rectangle r;
	r.getData();
	
	cout << endl <<  "Perimeter: " << r.perimeter() << endl;
	cout << endl << "Area: " << r.area() << endl;

	return 0;
}



// Q4: Rectangle Ends
// =========================================================

