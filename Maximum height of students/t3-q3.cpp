#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


int maxSumRectangularGrid(const vector<vector<int>>& grid , int n) {
   int sum1 = 0 , sum2 = 0;
   for(int i =0 ; i < n ; i ++){
    if(i % 2 == 0){
        sum1 += grid[0][i];
        sum2 += grid[1][i];
    }else{
        sum1 += grid[1][i];
        sum2 += grid[0][i];
    }
   }
    return max(sum1,sum2);
}

int main(){
    int n;
    cin >> n;
    vector <int> a;
    vector <int> b;
    vector<vector<int>> grid ;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin>>x;
        a.push_back(x);                

    }
    grid.push_back(a);
    for(int i = 0 ; i < n ; i++){
        int x;
        cin>>x;
        b.push_back(x);

    }
        grid.push_back(b);

    int max_sum = maxSumRectangularGrid(grid,n);
    cout << max_sum << endl;

    return 0;
}