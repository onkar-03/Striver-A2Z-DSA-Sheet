#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter Number of Rows: " << endl;
	cin >> n;
	// Rows
	for (int i = 0; i < n; i++)
	{
		// Columns
		for (int j = 0; j < n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
