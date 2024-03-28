#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, a;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.rbegin(), v.rend());
	cin >> a;
	cout << v[a - 1];




}