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
	
	int n, k, ans, last, x;

	cin >> n >> k;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.rbegin(), v.rend());
	ans = k;
	last = v[k-1];

	for (int i = k; i < n; i++)
	{
		if (last == v[i])
			ans++;
		else
			break;
	}

	cout << ans << endl;
	
  return 0;
}

