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


    	map<int, string> codeTable;

		int value;
		string code;

		while(codeFile >> value)
    	{ 		
        	codeFile >> code;

			codeTable[value] = code;
			
		}


		char nextChar;
		int asciiVal;
		unsigned char unChar;
		string fullNumText = "";

		while(cin.get(nextChar))
		{
			unChar = nextChar;
			asciiVal = int(unChar); 
			fullNumText += codeTable[asciiVal];

		}

		string endCount = to_string(fullNumText.length()) + " ";
		cout << endCount;

		int addEnd = 8 - (fullNumText.length() % 8);
		
		for(; addEnd < 8 && addEnd > 0; addEnd--)
		{
			fullNumText+="0";
		}

		//cout << fullNumText;
		string piece;
		unsigned char byte;

		for(int x = 0; x < fullNumText.length(); x+=8)
		{
			piece = fullNumText.substr(x, 8);
			byte = 0;
				for( int i = 0; i < 8; ++i )
		   			if( piece[i] == '1' ) 
		  			{
		    			byte |= 1 << (7-i);
					}
			cout << byte;
		}

    }

  }


    return 0;
}