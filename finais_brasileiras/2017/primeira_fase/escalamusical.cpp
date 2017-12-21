#include <bits/stdc++.h>
 
using namespace std; 
 
typedef long long ll; 
typedef pair<int, int> pii;
 
#define MOD 1000000007
#define INF 1000000000
#define pb push_back 
#define sz size() 
#define mp make_pair

struct notas{
	string name;
	bool has[12];
};

void createTons(vector<string> key, vector<notas> &ts, int note)
{
	int id = note;
	int qtd = 0, ind;	
	int tempos[7]={2,2,1,2,2,2,1};
	vector<string> v;
	
	(ts[id]).has[note] = 1;

	while (qtd < 7)
	{
		ind = (note+tempos[qtd])%12;
		(ts[id]).has[ind] = 1;
		note = ind;
		qtd++;
	}
}

int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, note, ind;
	vector<string> key;
	key.pb("do");key.pb("do#");key.pb("re");key.pb("re#");key.pb("mi");key.pb("fa");key.pb("fa#");key.pb("sol");key.pb("sol#");key.pb("la");key.pb("la#");key.pb("si");
	vector<notas> tons(12);
	int count[12] = {0};
	string ans = "desafinado";

	for (int i = 0; i < 12; i++)
	{
		tons[i].name = key[i];
		for (int j = 0; j < 12; j++)
			(tons[i]).has[j] = 0;
	}

	for (int i = 0; i < 12; i++)
			createTons(key, tons, i);

	cin >> n;
	for(int i = 0; i < n; i++)
	{	
		cin >> note;
		note--;
		ind = note%12;

		for (int j = 0; j < 12; j++)
		{
			if (tons[j].has[ind])
				count[j]++;
		}
	}

	for (int j = 0; j < 12; j++)
	{
		if (count[j] == n)
		{
			ans = key[j];
			break;
		}
	}

	cout << ans << endl;
	
  return 0;
}
