#include <iostream>
#include <vector>

using namespace std;

void prin(vector<int> sum) {
	cout << sum.size() << endl;

	for (int i = 0; i < sum.size(); i++)
		cout << sum[i] << " ";

	cout << endl;
}

void Group(int n, vector <int>& group1, vector <int>& group2) {
	int sum = (n * (n + 1)) / 2;
	int Sum1 = sum / 2;

	for (int i = n; i > 0; i--) {
		if (Sum1 - i >= 0) {
			group1.push_back(i);
			Sum1 -= i;
		}
		else {
			group2.push_back(i);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> group1, group2;
	Group(n, group1, group2);
	if(group1[0] > group2[0]){
	prin(group1);
	prin(group2);
	}else{
	prin(group2);
	prin(group1);
	}
	return 0;
}
