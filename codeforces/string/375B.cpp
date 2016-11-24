#include <bits/stdc++.h>

using namespace std; 
 
typedef long long ll; 
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back 
#define sz size() 
#define mp make_pair

#define f(i,a,b) for(i=a;i<b;i++)

	
int main()
{
	int n;
	int open = 0, i, j, longest = 0, words = 0;
	string ss, a;
	
	cin >> n >> ss;
	
	a = "";
	for (i = 0; i < n; i++)
	{
		if (ss[i] != '_' && ss[i] != '(' && ss[i] != ')')
		{
			a += ss[i];
		}
		else
		{			
			if (a.sz > 0)
			{
				if (open)
				{
					words++;
				}
				else
				{
					longest = max<int>(longest, a.sz);
				}
				a.clear();
			}
			
			if (ss[i] == '(')
			{
				open++;
			}
			else
			{
				if (ss[i] == ')')
					open--;
			}
		}
	}
	
	if (a.sz > 0)
	{
		if (open)
		{
			words++;
		}
		else
		{
			longest = max<int>(longest, a.sz);
		}
		a.clear();
	}

	cout << longest << " " << words << endl;
	
	return 0;
}
