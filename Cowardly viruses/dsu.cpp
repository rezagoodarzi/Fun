#include <bits/stdc++.h>
#define	ss second
#define ff first
#define pb push_back
#define int long long
using namespace std;
 
const int N = 1e6 + 100 ,OO = 2E18 + 7;
typedef pair <int, int> pii;
pair <pii, pii> ed[N];
int n, m, g, s, pr[N], ans = OO;
vector <int> v;
 
int get(int x) {
	if(pr[x] == x)
		return x;
	return (pr[x] = get(pr[x]));
}
 
void cal(int x) {
	vector <pii> p;
	for(auto u : v)
		p.pb({ed[u].ff.ss, u});
	for(int i = 1; i <= n; i++)
		pr[i] = i;
	v.clear();
	sort(p.begin(), p.end());
	int cnt = 0;
	for(auto us : p) {
		int u = us.ss;
		int x = get(ed[u].ss.ff), y = get(ed[u].ss.ss);
		if(x == y)
			continue;
		v.pb(u);
		pr[x] = y;
		cnt = max(cnt, us.ff);
	}
	if((int)v.size() == n - 1)
		ans = min(ans, x * g + cnt * s);
}
 
int32_t main() {
	cin >> n >> m >> g >> s;
	for(int i = 0; i < m; i++) {
		cin >> ed[i].ss.ff >> ed[i].ss.ss >> ed[i].ff.ff >> ed[i].ff.ss;
	}
	sort(ed, ed + m);
	for(int i = 0; i < m; i++) {
		v.pb(i);
		cal(ed[i].ff.ff);
	}
	if(ans == OO)
		ans = -1;
	cout << ans << endl;
	return 0;
}