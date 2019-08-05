#include <iostream>

#include <string>
#include<algorithm>
#include<vector>
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
{
int number;
	cin>>number;//tests
while(number>0)	
{	string s1,s2;
	cin>>s1>>s2;
	
	int value1=zero_testing(s1);
	int value2=zero_testing(s2);

	if(value1!=0)s1=remove_front_zeros(s1);
	if(value2!=0)s2=remove_front_zeros(s2);
	
	
	if(s2.length()>s1.length())
		swap(s1,s2);
	
	if(s2.length()==s1.length())
	{
	if(s1<s2) 
		swap(s1,s2);  
	}

	int n1=s1.length(),n2=s2.length();

	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());

	int carry=0;
	int p;
	std::vector<char> s3;
	auto q=s3.begin();

	

	
	

	for(int i=0;i<n2;i++)
	{
		p=s1[i]+s2[i]+carry-2*'0';
		carry=p/10;
		char t=p%10+'0';
		s3.push_back(t);

	}

	

	for(int i=n2;i<n1;i++)
	{
		p=s1[i]+carry-'0';
		carry=p/10;
		char t=p%10+'0';
		s3.push_back(t);
	}

	if(carry!=0) s3.push_back(carry+'0');

	reverse(s3.begin(),s3.end());

	int value3=zero_testing_v(s3);

	if(value3!=0) s3=remove_zeros(s3);
	
	
	for(auto ir=s3.cbegin();ir!=s3.cend();ir++)
	{
		cout<<*ir;
	}
number--;
}
	return 0;
}
