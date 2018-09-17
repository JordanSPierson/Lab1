//
// Jordan Pierson
// COSC2030 Lab1
// September 17, 2018

/*
Program obtains a filename, counts the total numbers in the file
and saves the first two and last two numbers read from the file
*/

#include <string>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
#include<fstream>
using std::ifstream;




int main()
{
	string filename;
	double first1(0.0),
		first2(0.0),
		last1(0.0),
		last2(0.0);
	ifstream file;
	cout << "Enter a file name:" << endl; // prompts user for filename
	getline(cin, filename); //recieves input from user

	file.open(filename); // opens file

	if (!file) // checks to see if the filename is correct
	{
		cerr << "Could not open file :" << filename <<
			".\nPlease enter a different filename:" << endl;
		getline(cin, filename);
		file.open(filename);
		while (!file) // checks if filename is correct until a "good" filename is given
		{
			cerr << "Could not open file :" << filename <<
				".\nPlease enter a different filename:" << endl;
			getline(cin, filename);
			file.open(filename);
		}
	}
	string inBuf;
	int i(0);
	double temp;
	file >> temp;
	while (!file.fail())
	{
		
		if (i == 0)
		{
			 first1 = temp;
		}
		else if (i == 1)
		{
			first2 = temp;
		}
		else
		{
			last1 = last2;
			last2 = temp;
		}
		i++;
		file >> temp;
	}
	file.close();
	cout << "The file " << filename << " contains " << i << " numbers."
		<< "\nThe first two numbers are " << first1 << ", and " << first2
		<< ".\nThe last two numbers are " << last1 << ", and " << last2 << endl;
	system("pause");
}

