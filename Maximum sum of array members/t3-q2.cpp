#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

#define INT_MAX 214748364
int main(){		
    int n;
    vector <int> arr;
    cin >> n;
    bool chek = false;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;

        if (x < 0)
            cnt++;

        arr.push_back(x);
        if (x == 0){
            chek = true;
        }
    }
    if (cnt % 2 == 0){
        chek = true;
    }
    if (chek == true){
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += abs(arr[i]);
        }
        cout << sum;
        return 0;
    }else{
        int sum = 0;
        int min = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if (abs(arr[i]) < min)
                min = abs(arr[i]);

            sum += abs(arr[i]);
        }
        cout << sum - 2 * min;
        return 0;
    }
}