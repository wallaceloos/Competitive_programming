#include <bits/stdc++.h>
 
using namespace std; 
 
typedef long long ll; 
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back 
#define sz size() 
#define mp make_pair

int main()
{
	int sum = 0;
	string s;
	
	cin >> s;
	
	for (int i = 0; i < s.sz; i++)
		sum += s[i]-'0';
	
	if (sum%3 == 0)
	{
		cout << "0" << endl;
	}
	else
	{
		sum = sum%3;
		cout << sum << endl;
	}

	return 0;
}
