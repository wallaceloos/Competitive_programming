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

	int n;
  unsigned long long k, pi, r, x, pc, ans;

	cin >> n >> k;

	if (n == 1)
		ans = 1;
	else
	{
		pc = (pow(2,n)-1)/2;
		if (pc+1 == k)
			ans = n;
		else
		{
			k--;
			for (long long i = 1; i < n; i++)
			{
				pi = pow(2, i-1)-1;
				r = pow(2,i);
				x = (k-pi)%r;

				if (!x)
				{
					ans = i;
					break;
				}
			}
		}
	}
	
	cout << ans << endl;
	
  return 0;	
}
