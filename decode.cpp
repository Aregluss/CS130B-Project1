#include <string>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;


int main(int argc, char* argv[])
{
	
  if ( argc > 2 ) 
  {
  		cout << "Usage: " << argv[0] << " <filename>\n";
  } else {

	ifstream codeFile (argv[1]);

    if (!codeFile.is_open())
    {
		cout<<"Could not open file\n";
     	return 0;
    } else {

    	map<string, int> valueTable; //use 01 to find ascii
    	map<string,int>::iterator it;

		int value;
		string code;

		while(codeFile >> value)
    	{ 		
        	codeFile >> code;

			valueTable[code] = value;
		}


		int realBits;
    	cin >> realBits;
    	char waste;
    	cin.get(waste);

		char nextChar;
		int asciiVal;
		unsigned char unChar;

		string currentText = "";

		int endingBitCount = 8 - (realBits - ((realBits)/8)*8);

		//for(int i = 0; i < (realBits+7)/8; i++)
		while(cin.get(nextChar))   /////////// i++ cuz i have /8
		{
			unChar = nextChar;
			for (int x=0; x<8;++x)
			{
				currentText += to_string((unChar >>(7-x)) &1);
				
			}
		}


		string readPoint = "";

		for(int j = 0; j < currentText.length() - endingBitCount; j++)
			{
				readPoint += currentText[j];
				it = valueTable.find(readPoint);

				if (it != valueTable.end())  //THIS GOES INSIDE IF IT FOUND AND IS LEGIT
	  			{
	  				asciiVal = valueTable[readPoint];
	  				cout << (char)asciiVal;
	  				//currentText = currentText.substr(j+1);
	  				readPoint = "";
	  			}
			}

    }

  }


    return 0;
}