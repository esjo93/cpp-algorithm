#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v, cache;

int dp(int n){
    cache[1] = 1;
    
    for(int i = 2 ; i <= n ; i++)
        for(int j = 1 ; j < i ; j++)
            if (v[j] < v[i] && cache[j] + 1 > cache[i])
                cache[i] = cache[j] + 1;

    return *max_element(cache.begin(), cache.end());
}


int main (){
    cin >> n;
    v = vector<int>(n+1, 0);
    cache = vector<int>(n+1, 1);
    for(int i = 1 ; i < n+1 ; i++) cin >> v[i];

    cout << dp(n);

    return 0;
}