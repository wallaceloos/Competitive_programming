#include <bits/stdc++.h>
 
using namespace std; 
 
typedef long long ll; 
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back 
#define sz size() 
#define mp make_pair

class TCPhoneHomeEasy
{
	public:
	int validNumbers(int digits, vector <string> specialPrefixes)
	{
		int ans = pow(10, digits);
		string number;

		for (int i = 0; i < specialPrefixes.sz; i++)
		{
			number = specialPrefixes[i];
			ans -=  pow(10, digits - number.sz);
		}
		return ans;
	}
};

