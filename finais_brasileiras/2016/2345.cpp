//Assigning Teams

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
	int a, ans;
	vector<int> v;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		v.pb(a);
	}
	
	sort(v.begin(), v.end());
	
	ans = (v[0]+v[3]) - (v[1]+v[2]);
	ans = abs(ans);
	
	cout << ans << endl;
	
	return 0;
}
