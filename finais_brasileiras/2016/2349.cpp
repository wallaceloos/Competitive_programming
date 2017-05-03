//Farm Robot
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
	
int main()
{

	int n, c, s, x, ans, estacao;
	
	cin >> n >> c >> s;
	
	s--;
	ans = 0;
	estacao = 0;
	
	if (estacao == s)
		ans++;
	for (int i = 0; i < c; i++)
	{
		cin >> x;
		if (x == 1)
		{
			estacao++;
			estacao %= n;
		}
		else
		{
			if (estacao-1 < 0)
				estacao = n-1;
			else	
				estacao--;
		}
		
		if (estacao == s)
			ans++;
		
	}
	cout << ans << endl;
	return 0;
}
