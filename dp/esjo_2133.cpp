#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> memo;

int dp(int n){
    if(memo[n] != -1)
        return memo[n];

    memo[n] = 0;
    if(n % 2 == 0) memo[n] += 2;
    else return memo[n];
    
    memo[n] += dp(n-2) * 3;
    for(int i = 4 ; n-i >= 2 ; i += 2)
        memo[n] += dp(n - i) * 2;

    return memo[n];
}


int main (){
    cin >> n;
    memo = vector<int>(n+1, -1);
    memo[1] = 0;
    memo[2] = 3;

    cout << dp(n);

    return 0;
}