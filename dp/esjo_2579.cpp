#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<vector<int> > cache;

int dp(int n, int step){
    if (cache[n][step-1] != -1) return cache[n][step-1];
    
    vector<int> cand;

    if(step + 1 < 3){
        cache[n-1][step] = dp(n-1, step+1);
        cand.push_back(v[n] + cache[n-1][step]);
    }

    cand.push_back(v[n] + dp(n-2, 1));

    cache[n][step-1] = *max_element(cand.begin(), cand.end());
    return cache[n][step-1];
}


int main (){
    cin >> n;
    v = vector<int>(n+1, 0);
    cache = vector<vector<int> >(n+1, vector<int>(2, -1));
    
    for(int i = 1 ; i < n+1 ; i++) cin >> v[i];
    
    cache[0][0] = v[0];
    cache[0][1] = v[0];
    cache[1][0] = v[1];
    cache[1][1] = v[1];

    cout << dp(n, 1);
    
    return 0;
}