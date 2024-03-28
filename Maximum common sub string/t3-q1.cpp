#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int main(){
    int a , b , c;
    int dp [50][50][50];
    cin >> a >> b >> c;
    vector <int> a1;
    vector <int> b1;
    vector <int> c1;
    
    for(int i = 0;i <= a ; i++){
        for(int j = 0 ; j <= b ; j++){
            for(int k = 0 ; k <= c ; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    
    for(int i = 0 ; i < a ; i++){
        int x;
        cin>>x;
        a1.push_back(x);
    }
    for(int i = 0 ; i < b ; i++){
        int x;
        cin>>x;
        b1.push_back(x);
    }
    for(int i = 0 ; i < c ; i++){
        int x;
        cin>>x;
        c1.push_back(x);
    }

    //dp[0][0][0] = 0;
    for(int i = 1;i <= a ; i++){
        for(int j = 1 ; j <= b ; j++){
            for(int k = 1 ; k <= c ; k++){
                if(a1[i - 1] == b1[j - 1] && a1[i - 1] == c1[k - 1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                }
            }
        }
    }
    cout<<dp[a][b][c];
    return 0;
}