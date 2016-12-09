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

class SortingSubsets
{
	public:
	int getMinimalSize(vector <int> a)
	{
		pair<int, int> pos;
		vector<int> ordered(a);
		int ans = 0;

		sort(ordered.begin(), ordered.end());

		for (int i = 0; i < a.sz; i++)
		{
			if (a[i] != ordered[i])
			{
				ans++;
			}
		}

		return ans;
	}

};
