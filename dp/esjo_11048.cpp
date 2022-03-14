#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<vector<int> > v;
vector<vector<int> > cache;


bool check(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= m)
        return false;
    return true;
}

int dp(int r, int c){
    if(cache[r][c] != -1) return cache[r][c];

    vector<int> cand;

    if(check(r-1, c)) cand.push_back(dp(r-1, c));
    if(check(r, c-1)) cand.push_back(dp(r, c-1));
    if(check(r-1, c-1)) cand.push_back(dp(r-1, c-1));
    
    if(v.size() > 0) cache[r][c] = v[r][c] + *max_element(cand.begin(), cand.end());
    else cache[r][c] = v[r][c];
    
    return cache[r][c];
}


int main (){
    cin >> n >> m;
    
    v = vector<vector<int> >(n, vector<int>(m, 0));
    cache = vector<vector<int> >(n, vector<int>(m, -1));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> v[i][j];
        
    cache[0][0] = v[0][0];
       
    cout << dp(n-1, m-1);
    
    return 0;

}