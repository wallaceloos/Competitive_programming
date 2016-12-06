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

struct node{
	int v;
	long w;
};

struct node2{
	int u;
	int v;
	long w;
};

vector<node> g[100001];
vector<int> check[100001];

int main()
{
	int n, m, k, u, v;
	long w, ans = 1000000001;
	node p;
	node2 p2;
	vector<int> storage;
	set<int> check;

	cin >> n >> m >> k;


	for (int i = 0; i < m; i++)
	{
			cin >> u >> v >> w;
			p.v = v;
			p.w = w;
			g[u].pb(p);

			p.v = u;
			p.w = w;
			g[v].pb(p);
	}

	for (int i = 0; i < k; i++)
	{
		cin >> u;
		check.insert(u);
		storage.pb(u);
	}

	if (k == 0 || k >= n)
	{
		cout << "-1" << endl;
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < g[storage[i]].sz; j++)
			{
				p =  (g[storage[i]])[j];
				if (check.find(p.v) == check.end())
					ans = min(ans, p.w);
			}
		}

		if (ans != 1000000001)
			cout << ans << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}
