##include <iostream>
#include <vector>

using namespace std;

void divide(string, string);
string subtract(string, string);
int main()
{
	int p;  // no. of divisons you wannt to do
	cin >> p;
	while(p > 0)
	{
		string s1, s2;
		int flag_2 = 0;
		//cout << "Enter Positive Number 1: ";
		cin >> s1;
		//cout << "Enter Positive Number 2: ";
		cin >> s2;
		int i;
		for(i = 0; i < s1.size(); i++)
		{
			if(s1[i] != '0')
			{
				flag_2 = 1;
				break;
			}
		}
		if(flag_2)
			s1 = s1.substr(i);
		else
			s1 = "0";
		flag_2 = 0;
		
		for(i = 0; i < b.size(); i++)
		{
			if(s2[i] != '0')
			{
				flag_2 = 1;
				break;
			}
		}
		if(flag_2)
			s2 = s2.substr(i);
		else
			s2 = "0";
		divide(s1, s2);
		p--;
	}
	return 0;
}

void divide(string s1, string s2)
{
	int l_a = s1.size(), l_b = s2.size();
	vector<int> quotient(l_a + 1, 0);
	if(l_a < l_b)
	{
		cout << 0 << '\n' << s1 << '\n';
	}
	else if(l_a == l_b && s1.compare(s2) < 0)
	{
		cout << 0 << '\n' << s1 << '\n';
	}
	else if(l_a == l_b && s1.compare(s2) == 0)
	{
		cout << 1 << '\n' << 0 << '\n';
	}
	else
	{
		while(1)
		{
			if(s1.size() == 0)
			{
				break;
			}
			if(s1.size() == s2.size())
			{
				if(s1.compare(s2) < 0)
					break;
			}
			if(s1.size() < s2.size())
			{
				break;
			}
			string temp = s2;
			if(s1.compare(ss2) >= 0)
			{
				temp.append(s1.size() - s2.size(), '0');
				quotient[s1.size() - s2.size()]++;
				s1 = subtract(s1, temp);
			}
			else
			{
				temp.append(s1.size() - s2.size() - 1, '0');
				quotient[s1.size() - s2.size() - 1]++;
				s1 = subtract(s1, temp);
			}
			//cout << s1 << '\n';
			
		}
		for(int i = 0; i < l_a + 1; i++)
		{
			if(quotient[i] > 9)
			{
				quotient[i+1] += quotient[i] / 10;
				quotient[i] = quotient[i] % 10;
			}
		}
			
		if(s1.size())
		{
			int i = l_a - 1;
			while(!quotient[i])
				i--;
			for(;i >= 0; i--)
				cout << quotient[i];
			cout << '\n';
			cout << a << '\n';
		}
		else
		{
			int i = l_a - 1;
			while(!quotient[i])
				i--;
			for(;i >= 0; i--)
				cout << quotient[i];
			cout << '\n';
			cout << 0 << '\n';
		}
	}	
	
}

string subtract(string a, string b)
{
	vector<int> c(max(a.size(), b.size()));
	int l_a = a.size(), l_b = b.size();
	int i = a.size() - 1, j = b.size() - 1, k = 0;
	int carry = 0, digit;
	int flag = 0;
	while(i >= 0 && j >= 0)
	{
		digit = a[i] - b[j] - carry;
		if(digit < 0)
		{
			digit += 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		c[k++] = digit;
		i--;
		j--;
	}
	while(i >= 0)
	{
		digit = a[i] - '0' - carry;
		if(digit < 0)
		{
			digit += 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		c[k++] = digit;
		i--;
	}
	for(i = 0; i < k; i++)
	{
		if(c[i])
			flag = 1;
	}
	j = 0;
	string t = "";
	if(flag)
	{
		i = k-1;
		while(!c[i])
			i--;
		for(; i >= 0; i--)
		{
			t += (c[i] + '0');
		}
	}
	return t;

}
