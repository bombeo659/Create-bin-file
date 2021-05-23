#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int a[] = { 23, 78, 45, 8, 32, 56, 129, 100, 200, 169};
	int b[10];																//Used to re-check when read

	fstream f;

	f.open("INT10.BIN", ios::out | ios::binary);							//Write to file INT10.BIN

	if (f) {																//Check write
		f.write(reinterpret_cast<char*>(a), 10 * sizeof(int));
		f.close();
	}
	else {
		cout << "Error opening file for writing \n";
		exit(1);
	}

	f.open("INT10.BIN", ios::in | ios::binary);								//Read to check

	if (f) {																//Check read
		f.read(reinterpret_cast<char*>(b), 10 * sizeof(int));
		f.close();
	}
	else {
		cout << "Error opening file for reading \n";
		exit(2);
	}

	for (int i = 0; i < 10; i++) cout << b[i] << " ";						//Re-check in c++
	cout << endl;
	return 0;

}
