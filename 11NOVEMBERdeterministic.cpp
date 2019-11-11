#include<bits/stdc++.h>
using namespace std;

int main()
{
	set<string> s;
	int z;
	cin>>z;
	int n=z;
	bool found=false;
	while(n>0)
	{
		string word;
		cin>>word;
		string z=word;
		reverse(word.begin(),word.end());
		if(z!=word)
		{
			if(s.find(word)==s.end())
				s.insert(z);
			else
			{
				found=true;
				break;
			}
			
		}
		n--;
	}

	if(found)
		cout<<"YES";
	else
		cout<<"NO";
	


}