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

	long dp[2][100001], t, m, n, ind;
	long ans = 0;
	
	cin >> t >> m >> n;
	
	ind = 0;
	for (int i = m; i <= n; i++)
	{
		dp[0][i] = 1;		
	}
	
	for (int i = 2; i <= t; i++)
	{
		for (int j = m; j <= n; j++)
		{
			dp[1-ind][j] = 0;
			if (j-1 >= m)
				dp[1-ind][j]+=dp[ind][j-1];
			
			dp[1-ind][j]%=MOD;
			
			if (j+1 <= n)
				dp[1-ind][j]+=dp[ind][j+1];
		
			dp[1-ind][j]%=MOD;
		}
		ind = 1-ind;
	}
	
	for (int i = m; i <= n; i++)
	{
		ans += dp[ind][i];
		ans%=MOD;
	}
	
	cout << ans << endl;
	
	return 0;
}  
