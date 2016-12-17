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

long long freq[200001];

int main()
{
	long long n, x, number, ans = 0;

	memset(freq, 0, sizeof(freq));

	cin >> n >> x;
	
	
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		ans += freq[number^x];
		freq[number]++;
	}

	cout << ans << endl;
	
  return 0;	
}
