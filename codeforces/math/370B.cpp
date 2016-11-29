
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
	int up = 0, down = 0, left = 0, right = 0, ans;
	string s;

	cin >> s;

	ans = -1;
	
	if (s.sz%2 != 0)
		cout << ans << endl;
	else
	{
		for (int i = 0; i < s.sz; i++)
			{
				if (s[i] == 'U')
						up++;
				if (s[i] == 'D')
						down++;
				if (s[i] == 'L')
						left++;
				if (s[i] == 'R')
						right++;
			}		

		if (up == down && left == right)
				cout << "0" << endl;
		else
		{
			if (abs(up-down) > abs(left-right))
			{
				ans = abs(left-right);
				if (up > down)
						up -= abs(left-right);
				else
						down -= abs(left-right);
				ans += abs(up-down)/2;
			}
			else
			{
				ans = abs(up-down);
				if (left > right)
						left -= abs(up-down);
				else
						right -= abs(up-down);
				ans += abs(left-right)/2;
			}
			cout << ans << endl;
		}
	}

return 0;
}
