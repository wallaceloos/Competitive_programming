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
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a1, a2, a3, ans;

	cin >> a1 >> a2 >> a3;

	ans = INF;
	ans = min((a2*2 + a3*4), ans);
	ans = min((a1*2 + a3*2), ans);
	ans = min((a1*4 + a2*2), ans);

	cout << ans << endl;
	
  return 0;
}

