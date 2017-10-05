#include <bits/stdc++.h>
 
using namespace std; 
 
typedef long long ll; 
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back 
#define sz size() 
#define mp make_pair

map<ll, ll> primeFactors(ll x)
{
    map<ll, ll> res;
    for (ll p = 2; p*p <= x; p++) {
        if (x % p == 0) {
            ll r = 0;
            while (x % p == 0) {
                x /= p;
                r++;
            }
            res[p] = r;
        }
    }
    if (x != 1) {
        res[x] = 1;
    }
    return res;
}


int main()
{
	ll n, ans, i, len;
	cin >> n;
	
	map<ll, ll> primes;
	
	primes = primeFactors(n);
	len = primes.sz;
	
	ans =  pow(2, len)-(len+1);
		
	cout << ans << endl;

	return 0;
}  
