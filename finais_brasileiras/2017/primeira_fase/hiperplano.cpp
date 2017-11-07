#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back
#define sz size()
#define mp make_pair

vector<pair<pair<int, int> ,int> > dp;

//https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
bool intpoint_inside_trigon(float s[2], float a[2], float b[2], float c[2])
{
    int as_x = s[0]-a[0];
    int as_y = s[1]-a[1];

    bool s_ab = (b[0]-a[0])*as_y-(b[1]-a[1])*as_x > 0;

    if((c[0]-a[0])*as_y-(c[1]-a[1])*as_x > 0 == s_ab) return false;

    if((c[0]-b[0])*(s[1]-b[1])-(c[1]-b[1])*(s[0]-b[0]) > 0 != s_ab) return false;

    return true;
}

int solve(vector<pair<int, int> > current_set, int a, int b, pii pt)
{
    int ans = 0;
    int n = current_set.sz;
    double w[3], u[3], v[3], prod, area1, area2, area3, area, l, l1, l2, l3;
    pii best_pt;
    int maior_n_pontos, n_pts;
    vector<pair<int, int> > set_sizes;
		float pa[2], pb[2], pc[2],pp[2];

    vector<pair<int, int> > set_pts, best_set, sub_best;

    if (current_set.sz == 0)
       return 0;
		

		bool flag_ = false;
		int k;
		pair< pair<int, int>, int> elem;
		for (k = 0; k < dp.sz; k++)
		{
			elem = dp[k];
			if (elem.first.first == pt.first && elem.first.second == pt.second)
			{
				flag_ = true;
				break;
			}
		}

		if (flag_)
			return elem.second;
   
    for (int i = 0; i < current_set.sz; i++)
    {
        set_pts.clear();
        n_pts = 0;
        for (int j = 0; j < current_set.sz; j++)
        {
            if (i != j)
            {
								pa[0] = a; pa[1] = a; pb[0] = b; pb[1] = 0;
								pc[0] = current_set[i].first; pc[1] = current_set[i].second;
								pp[0] = current_set[j].first; pp[1] = current_set[j].second; 
								if (intpoint_inside_trigon(pp, pa, pb, pc))
								{
									set_pts.pb(mp(current_set[j].first, current_set[j].second));
								}
            }
        }
			
				pii pt(current_set[i].first, current_set[i].second);
				int ans_ = solve(set_pts, a, b, pt);
				ans = max(ans, ans_+1);
    }

    dp.pb(mp(mp(pt.first, pt.second), ans));
    return ans;
}

int main()
{
  	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n, a, b, x, y, n_pts, ans = 0;
    vector<pair<int, int> > p;
    vector<pair<int, int> > set_pts, best_set, current_set;

    cin >> n >> a >> b;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        p.pb(mp(x, y));
    }   
    current_set = p;

	  pii pt(-1, -1);

    ans = solve(current_set, a, b, pt);
    cout << ans << endl;
  return 0;
}


//maneira de declarar uma matriz usando vector nice
// The dynamic programming:
// vector<vector<long> > f(n + 1, vector<long>(k+1) );
//como acessar  f[n+1][k+1];

/*
 string expression = "222 + 33 - 2 + 0";
string computeExpression(string exp)
{
    int number, sum;
    char op;
    stringstream ss, iss;

    iss.str(exp);
    iss >> number;
    sum = number;
    while (iss >> op >> number)
    {
        op == '+' ? sum+=number : sum-=number;
    }
    ss << sum;

    return ss.str();
}
*/
