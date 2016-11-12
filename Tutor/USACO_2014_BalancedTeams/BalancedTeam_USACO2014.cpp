#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>

//WORKING
using namespace std;
#define debug(x) cout << #x<<' '<< (x) << endl;
#define debug2(x,y) cout << <<#x<<' '<< (x) << " " << #y << ' '<<(y) << endl;
#define debug3(x,y,z) cout << #x<<' '<<(x) << " " << #y<<' '<<(y) << " " << #z<<' '<<(z) <<  endl;
#define debug4(x,y,z,q) cout << (x) << " " << (y) << " " << (z) << " " << (q) <<  endl;
#define fast_input ios::sync_with_stdio(0);cin.tie(0)
#define pause system("pause")
#define pbb push_back
#define printvec(vec) for(auto i:vec){ cout<<i<<" ";}cout<<endl;
#define printvec2(vec2) for(auto i:vec2)for(auto k: i){ cout<<(k)<<" ";}cout<<endl;
#define printpair(p) cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
#define printmap(m) for (auto i : m){cout<<"{"<<i.first<<", "<<i.second<<"}"<<endl;}
#define vI vector<int>
#define v(x) vector<x >
#define vVI vector<vector<int> >
#define vV(x) vector<vector<x > >
#define pI pair<int,int>
#define p(x) pair<x,x >
#define vpI vector<pair<int,int> >
#define vp(x) vector<pair<x,x> >
#define lenn length()
#define newln debug("")
#define max(x,y) (x)>(y)?(x):(y)


vI skillLevels;
vI playerAvail(12,1);
int minPossible=1000001;

void team(int currTeam, int maxSkillTeam, int minSkillTeam)
{

	int diff=maxSkillTeam-minSkillTeam;
	
	if (diff>=minPossible) return;

	if (currTeam==4)
	{
		if (diff<minPossible)minPossible=diff;
		debug3(maxSkillTeam,minSkillTeam,diff);
		return;
	}

	for (int i=0;i<12;i++)
		if (playerAvail[i])
			for (int j=i+1;j<12;j++)
				if (playerAvail[j])
					for (int k=j+1;k<12;k++)
						if (playerAvail[k])
						{
							//this is a possible team
							playerAvail[i]=0;
							playerAvail[j]=0;
							playerAvail[k]=0;

							int currSkill = skillLevels[i]+skillLevels[j]+skillLevels[k];

							team(currTeam+1,max(maxSkillTeam,currSkill),min(minSkillTeam,currSkill));

							playerAvail[i]=1;
							playerAvail[j]=1;
							playerAvail[k]=1;
						}
}



int main()
{

	int y=12;
	while (y--)
	{
		int lev;
		cin>>lev;
		skillLevels.pbb(lev);
	}
	team(0,0,1000000);
	cout<<minPossible<<endl;

	return 0;

}