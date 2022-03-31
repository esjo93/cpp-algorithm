#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> cache;

int dp(int n){
    if(cache[n-1] != -1) return cache[n-1];
    
    vector<int> cand;
    
    if(n % 3 == 0) cand.push_back(dp(n/3) + 1);
    if(n % 2 == 0) cand.push_back(dp(n/2) + 1);
    cand.push_back(dp(n-1) + 1);
    
    cache[n-1] = *min_element(cand.begin(), cand.end());
    return cache[n-1];
}


int main (){
    cin >> n;
    cache = vector<int>(n, -1);
    cache[0] = 0;
    
    cout << dp(n);
    
    return 0;
}