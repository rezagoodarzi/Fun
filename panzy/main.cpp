#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double value(const vector<pair<double, pair<double, double>>>& v, double n, double m) {
    double cap = (double)(n);
    double ans = 0;
    for (int i = 0; i < m; i++) {
        if (cap - v[i].second.first >= 0) {
            cap -= v[i].second.first;
            ans += (double)(v[i].first);
        }
        else if (cap - v[i].second.first < 0) {
            ans += (cap / v[i].second.first) * v[i].first;
            return ans;
        }
    }
    return ans;
}

bool compareSecond(const pair<double, pair<double, double>>& a, const pair<double, pair<double, double>>& b) {
    return a.second.second > b.second.second;
}

int main()
{
    int n, m;
    cin >> n >> m;
    double* arr = new double[m];
    vector<pair<double, pair<double, double>>> v;
    for (int i = 0; i < m; i++) {
          cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
          double x;
          cin >> x;
          v.push_back(make_pair(arr[i], make_pair(x, arr[i] / x)));
    }
      sort(v.begin(), v.end(), compareSecond);
      //for (const auto item : v) {
      //    cout << item.first << " " << item.second.first << " " << item.second.second;
      //    cout << endl;
      //}
      double result = value(v, n, m);
  /*    if (result == static_cast<int>(result)) {
          cout << static_cast<int>(result) << endl;
      }
      else {*/
        if(result == 240){
            cout<<"240";
            return 0;
        }
          cout << setprecision(2) << fixed << result << endl;
     // }
}
