#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<int> memo;

int dp(int a){
    if(memo[a]) return memo[a];
    vector<int> cand;
    
    if(a <= n) cand.push_back(v[a]);
    
    for(int i = 1 ; i < a ; i++)
        cand.push_back(dp(i) + dp(a-i));

    memo[a] = *max_element(cand.begin(), cand.end());
    return memo[a];
}


int main (){
    cin >> n;
    v = vector<int>(n+1, 0);
    memo = vector<int>(n+1, 0);
    for(int i = 1 ; i <= n ; i++)
        cin >> v[i];
    
    memo[1] = v[1];
    
    cout << dp(n);

    return 0;
}