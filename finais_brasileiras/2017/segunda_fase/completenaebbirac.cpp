#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back
#define sz size()
#define mp make_pair

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second > b.second)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, x, diff;
    set<int> used;
    int freq[1001] = {0};
    vector<pair<int, int> > vf;

    cin >> k >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        used.insert(x);
        freq[x]++;
    }

    for(set<int>::iterator it = used.begin(); it != used.end(); it++)
        vf.pb(mp(*it, freq[*it]));

    sort(vf.begin(), vf.end(), cmp);

    diff = vf[0].second-vf[vf.sz-1].second;

    if (diff > 2 or k-used.sz > 1)
    {
		cout << "*" << endl;
    }
    else
    {
		if(diff == 0)
		{		
			if(vf[0].second > 2)
			{
				cout << "*" << endl;
				return 0;
			}
			for(int i = 1; i <= k; i++)
			{
				if(used.find(i) == used.end())
				{
					cout << "+" << i << endl;
					return 0;
				}
			}
		}
		else
		{
			if (diff == 1)
			{
				if(used.sz < k && vf[0].second == 2)
				{					
					cout << "-" <<  vf[0].first;
					for(int i = 1; i <= k; i++)
					{
						if(used.find(i) == used.end())
						{
							cout << " +" << i << endl;
							break;
						}
					}
				}
				else{
					if(vf[0].second == vf[1].second)
						if(vf[vf.sz-1].second != vf[vf.sz-2].second)
							cout << "+" <<  vf[vf.sz-1].first   << endl;
						else
							cout << "*" << endl;	
					else{
						if(used.sz == k)
							cout << "-" <<  vf[0].first  << endl;
						else
							cout << "*" << endl;
					}
				}
			}
			else
			{
				if(vf[0].second != vf[1].second && vf[vf.sz-2].second != vf[vf.sz-1].second)
					cout << "-" <<  vf[0].first   << " +" <<   vf[vf.sz-1].first   << endl;
				else
					cout << "*" << endl;
			}
		}
    }
   
    return 0;
}
