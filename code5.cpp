#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

std::vector<char> v;

int main(int argc, char const *argv[])
{
	vector<char> s1;
	
	cin>>s1;

	vector<char> a;
	a='2';

	num=subtract(power(a,s1),'2');

	if(div(s1,num)=='0')
	{
		cout<<"the number is prime";
	}			

	else
		cout<<"the number is not prime";
	return 0;
}

vector<char> power(std::vector<char> s1;std::vector<char> s2;)
{
	if(s2=='0')
		return '1';
	else if (div(s2,'2')=='0')
		return multiply(s1,multiply(power(s1,div(s2,'2')),power(s1,div(s2,'2'))))
	else
		return multiply(power(s1,div(s2,'2')),power(s1,div(s2,'2')))
}

vector<char> subtract(vector<char> s1, std::vector<char> s2;)
{
	
	

	int sign =s1.compare(s2);
	if(sign<0) swap(s1,s2);

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
	
	
	

	

	return s3;
}

vector<char> multiply(std::vector<char> s1;std::vector<char> s2;)
{
	


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

	
	return result;
}
