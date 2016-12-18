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

void boundaries(char mtx[50][50], int n, int m, int &T, int &B, int &L, int &R)
{
	T = n;
	L = m;
	B = R = 0;
	for (int j = 0;  j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (mtx[i][j] == 'O')
			{
				if (i < T)
					T = i;

				if (i > B)
					B = i;

				if (j < L)
  				L = j;

				if (j > R)
					R = j;
			}
		}
	}
}


class XMarksTheSpot
{
	public:
	int countArea(vector <string> board)
	{
		int ans = 0, n, m, n_k = 0;
		int rr, ll, tt, bb, t_, b_, r_, l_;
		vector<pair<int, int> > pos_k;
		pair<int, int> p;
		vector<int> mask;
		char mtx[50][50];
		string s;

		n = board.sz;
		m = (board[0]).sz;
		for (int i = 0; i < board.sz; i++)
		{
			s = board[i];
			for (int j = 0; j < s.sz; j++)
			{
					mtx[i][j] = s[j];
					if (s[j] == '?')
						pos_k.pb(mp(i,j));
			}
		}
		
		boundaries(mtx,n, m, tt, bb, ll, rr);

		n_k = pos_k.sz;
		if (n_k > 0)
		{
			for (int i = 0; i < (1<<n_k); i++)
			{
					t_ = tt; b_ = bb; r_ = rr; l_ = ll;
					for (int j = 0; j < n_k; j++)
					{
						p = pos_k[j];
						if (i&1<<j)
						{
							t_ = min(t_, p.first);
							b_ = max(b_, p.first);

							l_ = min(l_, p.second);
							r_ = max(r_, p.second);
						}
					}			
					ans += (b_-t_+1) * (r_-l_+1);
			}
		}
		else
		{
			ans = (bb-tt+1) * (rr-ll+1);								
		}

		return ans;
	}
};

int main()
{

	
  return 0;	
}
