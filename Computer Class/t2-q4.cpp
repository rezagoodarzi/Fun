#include <iostream>
#include <vector>
using namespace std;
#define N 1000000007

vector<vector<long long int>> dp;

unsigned long long solve(vector<int>& nums) {
    if (nums.size() <= 1) {
        return 1;
    }
    vector<int> left, right;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[0]) {
            right.push_back(nums[i]);
        } else {
            left.push_back(nums[i]);
        }
    }
    int n = left.size(), m = right.size();
    return ((solve(left) * solve(right)) % N * (dp[n + m][n] % N)) % N;
}

void fillDP(int n) {
    dp = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        dp[i][1] = i;
        dp[i][i - 1] =   i;
        dp[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (i >= j) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % N;
            } else {
                break;
            }
        }
    }
}

long long int ways(vector<int>& nums) {
    int n = nums.size();
    fillDP(n);
    return solve(nums) - 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

     cout << ways(arr) << endl;
    return 0;
}
