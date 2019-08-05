#include <iostream>

#include <string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int zero_testing(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='0') return 1;
	}

	return 0;
}

int zero_testing_v(vector<char> s)
{
	for(auto i=s.begin();i!=s.end();i++)
	{
		if(*i!='0') return 1;
	}

	return 0;
}

string remove_front_zeros(string s)
{
	int i;
	string result;
	
	for(i=0;i<s.length();i++)
	{
		if(s[i]!='0') break;
	}
	
	for(;i<s.length();i++)
	{
		result.push_back(s[i]);
	}

	return result;
}

vector<char> remove_zeros(vector<char> s)
{
	auto i=s.begin();
	vector<char> result;
	
	for(;i!=s.end();i++)
	{
		if(*i!='0') break;
	}
	
	for(;i!=s.end();i++)
	{
		result.push_back(*i);
	}

	return result;
}

int main(int argc, char const *argv[])
{int number=0;
 cin>>number;
 while(number>0)
 {	string s1,s2;
	cin>>s1>>s2;

	int value1=zero_testing(s1);
	int value2=zero_testing(s2);
	if(value1==0||value2==0)
	{
		cout<< "0";
		return 0;
	}

	s1=remove_front_zeros(s1);
	s2=remove_front_zeros(s2);

	int result_size=s1.length()+s2.length();

	vector<char> result(result_size,'0'); // storage of final result

	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());



	int i_n1=0; // the character of 1st string with whom multiplication is being done in the current iteration
	
	

	int carry=0;

	for(int i=0;i<s1.length();i++)
	{
		int n1=s1[i]-'0'; 

		int i_n2=0;  // the character of 2nd string with whom multiplication is being done in the current iteration

		for(int j=0;j<s2.length();j++)
		{	
			int n2=s2[j]-'0';

			int p=n1*n2+result.at(i_n2+i_n1)-'0'+carry;// here result[n1+n2] term accounts for the shifting required in normal multiplication


			char t=p%10+'0';
			result[i_n1+i_n2]=t;
		
			carry=p/10;

			i_n2++;

		}

		i_n1++;

		
	}

		result[result_size-1]=carry+'0';



	reverse(result.begin(),result.end());

	result=remove_zeros(result);

	for(int i=0;i<result_size;i++)
	{
		cout<<result[i];
	}
 number--;
 }
	return 0;
}


