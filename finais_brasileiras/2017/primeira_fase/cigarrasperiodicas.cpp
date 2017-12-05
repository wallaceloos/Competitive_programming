#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back
#define sz size()
#define mp make_pair

unsigned long gcd(unsigned long a, unsigned long b)
{
	int64_t dividendo = max(a, b);
	int64_t divisor = min(a,b);
	int64_t resto = dividendo%divisor;

	if (resto == 0)
		return divisor;

	while (resto > 0)
	{
		dividendo = divisor;
		divisor = resto;
		resto = dividendo%divisor;
	}
	return divisor;
}

int64_t lcm(int64_t a, int64_t b)
{
    return a * (b / gcd(a, b));
}

int64_t lcm(vector<int64_t> &c)
{
    int64_t result = c[0];
    for(int i = 1; i < c.sz; i++) 
			result = lcm(result, c[i]);
    return result;
}


int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int64_t n, l, maior_temp, maior_iter = 0, maior_x = -1, ans = 1;
	cin >> n >> l;

	vector<int64_t> c(n);

	for (int i = 0; i < n; i++)
	{	
		cin >> c[i];
	}

	int64_t mmc = lcm(c);
	
	for (int64_t k = 1; k <= l; k++)
	{
	  maior_temp = lcm(k, mmc);
		if (maior_iter < maior_temp && maior_temp <= l)
		{
			ans = k;
			maior_iter = maior_temp;
		}
	}

	cout << ans << endl;
  return 0;
}
