
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int temp,counter = 0;
vector<int> m(10,0);
vector<int> cur(1,0);
vector<int> what(10,0);
vector<int> wanted(10,0);
vector<int> answer;
bool found = false;

void solve( void )
{
    for ( m[9] = 0; m[9] <= 3;m[9]++ ){
        for ( m[8] = 0; m[8] <= 3; m[8]++){
            for ( m[7] = 0; m[7] <= 3; m[7]++){
                for ( m[6] = 0; m[6] <= 3; m[6]++){
                    for ( m[5] = 0; m[5] <= 3; m[5]++){
                        for ( m[4] = 0; m[4] <= 3; m[4]++){
                            for ( m[3] = 0; m[3] <= 3; m[3]++){
                                for ( m[2] = 0; m[2] <= 3; m[2]++){
                                    for (m[1] = 0; m[1] <= 3; m[1]++){
                                        if (found)
                                            break;

                                        what[1] = ( cur[1] + m[1] + m[2] + m[4]) % 4;
                                        what[2] = ( cur[2] + m[1] + m[2] + m[3] + m[5] ) % 4;
                                        what[3] = ( cur[3] + m[2] + m[3] + m[6] ) % 4;
                                        what[4] = ( cur[4] + m[1] + m[4] + m[5] + m[7]) % 4;
                                        what[5] = ( cur[5] + m[1] + m[3] + m[5] + m[7] + m[9] ) % 4;
                                        what[6] = ( cur[6] + m[3] + m[5] + m[6] + m[9]) % 4;
                                        what[7] = ( cur[7] + m[4] + m[7] + m[8]) % 4;
                                        what[8] = ( cur[8] + m[5] + m[7] + m[8] + m[9]) % 4;
                                        what[9] = ( cur[9] + m[6] + m[8] + m[9]) % 4;
                                        if (what == wanted){
                                            found = true;
                                            for (int i = 1; i <= 9;i++){
                                                while (m[i] > 0){
                                                    answer.push_back(i);
                                                    m[i]--;
                                                }
                                            }
                                        }


                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{

	ifstream in("clocks.in");
	ofstream out("clocks.out");

    for (int i = 0; i < 9;i++){
        cin >> temp;
        cur.push_back(temp/3);
    }
    solve();
    for (int i = 0; i < answer.size()-1;i++)
        cout << answer[i] << " ";
    cout << answer[answer.size()-1] << "\n";
}


