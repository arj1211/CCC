/*
ID: thejoke2
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//A=65
int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string group = "";
    fin >> group;
    string comet = "";
    fin >> comet;

    int groupnum=1, cometnum=1;

    for (int i = 0 ; i < group.length() ; i++)
    {
        groupnum*=(int(group[i])-64);
    }
    for (int i = 0 ; i < comet.length() ; i++)
    {
        cometnum*=(int(comet[i])-64);
    }

    if ( (groupnum%47) == (cometnum%47) )
    {
        fout << "GO" << endl;
    }
    else
    {
        fout << "STAY" << endl;
    }


    return 0;
}
