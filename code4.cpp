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

std::vector<char> make_vector(string , int);
std::vector<char> multiply(string s1,string s2);
std::vector<char> subtract(std::vector<char>  s1,std::vector<char>  s2);
vector<char> remove_zeros(vector<char> s);
string remove_front_zeros(string );

int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;

	s1=remove_front_zeros(s1);// for strings
	s2=remove_front_zeros(s2);

	std::vector<char> s3; // quotient
	std::vector<char> s4;//remainder

	if(s1.length()==s2.length())
	{
		if(s2.compare(s1)>0) cout<<"answer is quotient is 0 remainder is"<<s1;
	}

	if(s1.length()<s2.length())
	{
		cout<<"answer is quotient is 0 remainder is"<<s1;
	}

	else
	{
		if(s1.compare(s2)>0)
		{
		
			int k=s2.length(); // for tracking the number of digits which is being brought down to continue division
			std::vector<char> temp=make_vector(s1,k);

			int i;
			string j;
		
		
			for(i=0;;i=i+1)
			{
			
				j=to_string(i);
				std::vector<char> p=subtract(temp,multiply(s2,j));
				if(p[0]=='-') break;
			}

		

			if(i-1==0)
			{
				temp=make_vector(s1,k++);

		 	
		
				for(i=0;i<11;i=i+1)
				{	
					j=to_string(i);
					std::vector<char> p=subtract(temp,multiply(s2,j));
					if(p[0]=='-') break;
				}

			}

			j=to_string(i-1);
			s3.push_back(j[0]);
			s4=subtract(temp,multiply(s2,j));

		

			for(;k<=s1.length()-s2.length();k++)
			{
				s4.push_back(s1[k]);
				temp=s4;
				for(i=0;i<11;i++)
				{	
					j=to_string(i);
					std::vector<char> p=subtract(temp,multiply(s2,j));
					if(p[0]=='-') break;	
				}
			
				j=to_string(i-1);
				s3.push_back(j[0]);
				s4=subtract(temp,multiply(s2,j));
			}

			s3=remove_zeros(s3);
			s4=remove_zeros(s4);

			for(auto ir=s3.cbegin();ir!=s3.cend();ir++)
			{
				cout<<*ir;
			}

			for(auto ir=s4.cbegin();ir!=s4.cend();ir++)
			{
				cout<<*ir;
			}

		}

		else 

		{	
			if (s1.compare(s2)==0)
			{
				cout<<"the answer is 1";
				/* code */
			}
		}
	}

	return 0;	
}


std::vector<char> multiply(string s1,string s2)
{	


	int value1=zero_testing(s1);
	int value2=zero_testing(s2);
	if(value1==0||value2==0)
	{
		
		std::vector<char> v(1,'0');
		return v;
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

	int value3=zero_testing_v(result);
	if(value3!=0)result=remove_zeros(result);

	
	return result;
}


std::vector<char> subtract(std::vector<char>  k1,std::vector<char>  k2)
{
	string s1(k1.begin(),k1.end());
	string s2(k2.begin(),k2.end());
	
	int value1=zero_testing(s1);
	int value2=zero_testing(s2);

	int sign;

	if(value1!=0)s1=remove_front_zeros(s1);
	if(value2!=0)s2=remove_front_zeros(s2);

	if(s1.length()<s2.length())
	{
		swap(s1,s2);
		sign=-1;
	}
	if(s1.length()==s2.length())
	{
		sign =s1.compare(s2);
		if(sign<0) swap(s1,s2);
	}

	int n1=s1.length(),n2=s2.length();
	

	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());

	int carry=0;
	int p;
	std::vector<char> s3;
	

	
	for(int i=0;i<n2;i++)
	{
		
		if(s1[i]+carry>=s2[i])
		{
			p=s1[i]+carry-s2[i]+'0';
			carry=0;;
			
		}
		
		else
		{
			p=carry+10+s1[i]-s2[i]+'0';

			carry=-1;

		}
		
		s3.push_back(p);

	}

	

	for(int i=n2;i<n1;i++)
	{
		if(s1[i]+carry>='0')
		{
			p=s1[i]+carry;
			carry=0;
		}
		
		else
		{
			p=carry+10+s1[i];
			carry=-1;
		}
		
		s3.push_back(p);
	}

	if(sign<0) s3.push_back('-');
	
	reverse(s3.begin(),s3.end());
	int value3=zero_testing_v(s3);

	if(value3!=0) s3=remove_zeros(s3);
	
	

	return s3;
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

std::vector<char> make_vector(string s , int i)
{
	std::vector<char> v;
	for(int j=0;j<i;j++)
	{
		v.push_back(s[i]);
	}

	return v;
}