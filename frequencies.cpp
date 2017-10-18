#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	char nextChar;
	int asciiVal;
	unsigned char unChar;
	map<int, int> freqTable;

	while(cin.get(nextChar))
	{
		unChar = nextChar;
		asciiVal = int(unChar); 
		freqTable[asciiVal] += 1;

	}
	map<int, int>::iterator itr;
	for(itr = freqTable.begin(); itr != freqTable.end(); itr++)
	{
		  cout << itr->first <<  '\t' << itr->second << '\n';
	}

	return 0;
}