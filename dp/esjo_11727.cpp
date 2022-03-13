#include <iostream>
#include <cstdlib>
#include <memory.h>


using namespace std;

int n, cache[1001];


int dp(int n){
    if (cache[n] != -1) return cache[n];
    cache[n] = (dp(n-1) + 2 * dp(n-2)) % 10007;
    return cache[n];
}


int main (){
    cin >> n;
    
    memset(cache, -1, sizeof(int) * 1001);

    cache[1] = 1;
    cache[2] = 3;

    cout << dp(n);
    
    return 0;
}