//Back to the Future

#include <bits/stdc++.h>
 
using namespace std; 
 
typedef long long ll; 
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back 
#define sz size() 
#define mp make_pair

#define REP(i,a,b) for(int i=a;i<b;i++)

int dg[100000];
vector<int> graph[100000];
stack<int> pilha;
set<int> n_vert;

void restricoes(int v, int a, int b)
{
	int w;
	if (n_vert.find(v) != n_vert.end())
	{
		if (!(dg[v] >= a && (n_vert.sz-dg[v]-1) >=b))
		{
			n_vert.erase(v);
			
			for (int i = 0; i < graph[v].sz; i++)
			{
				w = (graph[v])[i];
				dg[w]--;
				if (n_vert.find(w) != n_vert.end())
					pilha.push(w);
			}
			graph[v].clear();
		}
	}
}

int main()
{	
	
	int n, m, a, b, x, y, v;

	cin >> n >> m >> a >> b;

	for (int i = 0; i < n; i++)
	{
		n_vert.insert(i);
		dg[i] = 0;
	}
	
	
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		graph[x-1].pb(y-1);
		graph[y-1].pb(x-1);

		dg[x-1]++;
		dg[y-1]++;
	}

	while(true)
	{
		for (int i = 0; i < n; i++)
		{

			while (pilha.sz > 0)
			{
				v = pilha.top();
				pilha.pop();
				restricoes(v, a, b);
			}
			restricoes(i, a, b);
			while (pilha.sz > 0)
			{
				v = pilha.top();
				pilha.pop();
				restricoes(v, a, b);
			}
		}

	for (int k = 0; k < n; k++)
	{
		restricoes(k, a, b);
	}
	if(pilha.sz == 0)
		break;
}	
	cout << n_vert.sz << endl;
	return 0;
}
