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

class GridSort
{
	public:
	string sort(int n, int m, vector <int> grid)
	{
		int count = 0;
		vector<int> tmp(grid);
		vector<int> pos[51];
		set<int> c;
		int found = 0, ind = 0;
		bool ok = false;
		int number = 0;

		if (n == 1 or m== 1)
			return "Possible";

		std::sort(tmp.begin(), tmp.end());

		while (count < (n*m))
		{
			c.clear();
			ok = false;
			
			for (int i = count; i < (count+m); i++)
					c.insert(tmp[i]);
		
			for (int i = 0; i < n && !ok; i++)
			{
				found = 0;
				for (int j = 0; j < m; j++)
				{
					if (c.find(grid[i*m+j]) != c.end())
					{
						found++;
					}
				}
				if (found == m)
				{
					ok = true;
					for (int j = 0; j < m; j++)
					{
						number = grid[i*m+j];
						for (int jj = 0; jj < m; jj++)
						{
							if (number == tmp[count+jj])
							{
								pos[ind].pb(jj);
							}
						}
					}
				}
			}
			if (!ok)
				return "Impossible";
			ind++;
			count+=m;
		}
		
		for (int j = 0; j < m; j++)
		{
			for (int i = 0; i < ind-1; i++)
			{		
				if ((pos[i])[j] != (pos[i+1])[j])
					return "Impossible";
			}
		}

		return "Possible";
	}
};
	
int main()
{


	return 0;
}
