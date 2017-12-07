#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	// This code was used to break a caesar cypher
	// for the following alphabet
	/*ALPHABET {0,1,2,3,4,5,6,7,8,9} */
	string input = "4044435476587268665877";
	string result = "";
	int checksum = 0;
	int offset = 1;

	for(int i = 0; i < input.size(); i++)
	{
		checksum += (input[i] - '0' + offset) % 10;
		result += ((input[i] - '0' + offset) % 10) + '0';
	}
	cout << result << endl;
	cout << checksum % 376 << endl;

	if(checksum % 376 == 138)
	{
		cout << "checksum passed" << endl;
	}

	cout << result << endl;

}
