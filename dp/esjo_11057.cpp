#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > memo;

// 1. Memoization Method
// int dp(int size, int num){
//     if(memo[size][num] != -1) return memo[size][num];
//     memo[size][num] = 0;
    
//     for(int i = 0 ; i <= num ; i++)
//         memo[size][num] += dp(size-1, i);

//     return memo[size][num] % 10007;
// }

// int dp(int n){
//     int ans = 0;
//     for(int i = 0 ; i < 10 ; i++)
//         ans += dp(n, i);
    
//     return ans % 10007;
// }

// 2. Tabulation Method
int dp(int n){
    int ans = 0;

    for(int i = 0 ; i < 10 ; i++) 
        memo[1][i] = 1;
    
    int cur = 1;
    while(cur++ < n){
        for(int i = 0 ; i < 10 ; i++){
            memo[cur][i] = 0;

            for(int j = 0 ; j <= i ; j++)
                memo[cur][i] += memo[cur-1][j];

            memo[cur][i] %= 10007;
        }
    }

    for(int i = 0 ; i < 10 ; i++)
        ans += memo[n][i];

    return ans % 10007;
}


int main (){
    cin >> n;
    memo = vector<vector<int> >(n+1, vector<int>(10, -1));
    // for(int i = 0 ; i < 10 ; i++)
    //     memo[1][i] = 1;

    cout << dp(n);

    return 0;
}