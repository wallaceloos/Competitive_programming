//Dating On-Line
#include <bits/stdc++.h>
 
using namespace std; 
 
typedef long long ll; 
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back 
#define sz size() 
#define mp make_pair

#define REP(i,a,b) for(int i=a;i<b;i++)
	
int main()
{

	int n, change;
	double ang, ans;
	deque<double> mydeque;
	
	cin >> n;
	
	vector<float> v(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.rbegin(), v.rend());
	
	ang = 360.0/(double)n;
	ang = sin(ang*M_PI / 180.0);
	
	mydeque.push_back(v[0]);
	change = 1;
	for (int i = 1; i < v.sz; i++)
	{
		if (change)
			mydeque.push_back(v[i]);
		else
			mydeque.push_front(v[i]);
		change = 1 - change;
	}
	
	mydeque.push_back(mydeque[0]);
	ans = 0.0;
	for (int i = 0; i < mydeque.sz-1; i++)
	{
		ans += (0.5*mydeque[i]*mydeque[i+1]*ang);
	}
	printf("%.3f", ans);
	cout << endl;
	
	return 0;
}

