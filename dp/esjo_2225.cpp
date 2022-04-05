#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n, k, memo[201][201];

int dp(int num, int unit){
    if(memo[num][unit] != -1) return memo[num][unit];
    
    memo[num][unit] = 0;
    for(int i = 0 ; i <= num; i++){
        memo[num][unit] += dp(num-i, unit-1);
        memo[num][unit] %= 1000000000;
    }
    
    return memo[num][unit];
}


int main(){
    cin >> n >> k;
    memset(memo, -1, 201*201*sizeof(int));
    
    for(int i = 0 ; i <= n ; i++)
        memo[i][1] = 1;

    cout << dp(n, k);

    return 0;
}