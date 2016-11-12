#include <iostream>
#include <map>
#include <string>
using namespace std;

// WORKING NOW


int main(void)
{

	map<char, char> charToChar;
	string plaintext, charMap, encMessage, decMessage;
	//const string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

	// map 'em

	getline(cin, plaintext);
	getline(cin, charMap);
	getline(cin, encMessage);
	
	// char in the charmap is the key, char in plaintext is val.
	// this is cuz we need the val later on; we need the plaintext char
	// later on.
	for (int u = 0; u < charMap.length(); u++)
		charToChar[charMap[u]] = plaintext[u];
	




	for (int u = 0; u < encMessage.length(); u++)
	{

		char currChar = encMessage[u];

		// append the value (plaintext char) 
		// behind the key (key char from the 
		// charmap/encmssg) to the decoded mssg
		if (charToChar.count(currChar) == 1)
			decMessage += charToChar[currChar];
		else
			decMessage += '.';
	}


	cout << decMessage << endl;
	system("pause");

}