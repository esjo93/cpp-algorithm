#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<int> > v, cache;

int dp(int n, int c){
    if (cache[n][c] != -1) return cache[n][c];
    
    vector<int> cand;
    for(int i = 0 ; i < 3 ; i++){
        if(i == c) continue;
        cand.push_back(v[n][c] + dp(n-1, i));
    }
    cache[n][c] = *min_element(cand.begin(), cand.end());
    return cache[n][c];
}

int dp(int n){
    vector<int> cand;
    for(int i = 0 ; i < 3 ; i++)
        cand.push_back(dp(n, i));
    
    return *min_element(cand.begin(), cand.end());
}

int main (){
    cin >> n;
    v = vector<vector<int> >(n+1, vector<int>(3, -1));
    cache = vector<vector<int> >(n+1, vector<int>(3, -1));

    for(int i = 1 ; i < n + 1; i++)
        for(int j = 0 ; j < 3 ; j++)
            cin >> v[i][j];

    cache[1][0] = v[1][0];
    cache[1][1] = v[1][1];
    cache[1][2] = v[1][2];
    
    cout << dp(n);

    return 0;

}
