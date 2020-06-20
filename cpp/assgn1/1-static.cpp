#include<iostream>
#include<iomanip>

using namespace std;

class Static_count 
{
	private :
		static int count;

	public :
		Static_count()
		{
			count++;
		}

		void countObj();

};

void Static_count :: countObj()
{
	cout << "Static int count: " << count << endl;
}

int Static_count :: count;

// Driver Program
int main()
{
	Static_count sc1;
	sc1.countObj();

	Static_count sc2;
	sc2.countObj();

	Static_count sc3;
	sc3.countObj();

	return 0;
}
