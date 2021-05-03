#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int t, n;

vector<long long> arr;


int main (){
    cin >> t;

    while(t--){
        cin >> n;
        vector<vector<long long> > v(n, vector<long long>(2));
        
        for(int i = 0 ; i < n ; i++) {
            cin >> v[i][0] >> v[i][1];               
        }
        
        arr = vector<long long>(n, -1LL);
        fill(arr.begin() + n/2, arr.end(), 1LL);
        sort(arr.begin(), arr.end());


        double sum;
        double min = -1.0;
        long long xsum, ysum;

        do{
            sum = 0.0;
            xsum = 0LL;
            ysum = 0LL;

            for(int i = 0 ; i < n ; i++){
                xsum += v[i][0] * arr[i];
                ysum += v[i][1] * arr[i];
            }

            sum = xsum * xsum + ysum * ysum;

            if (min == -1.0) min = sum;
            else if (min > sum) min = sum;
        }while(next_permutation(arr.begin(), arr.end()));
        arr.clear();
        
        printf("%.6f\n", sqrt(double(min)));
    
    }
    return 0;

}