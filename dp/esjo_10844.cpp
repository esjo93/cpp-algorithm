// 1) Top-Down Method
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > cache;

bool check(int i){
    if (i < 0 || i > 9) return false;
    else return true;
}

int dp(int m, int n){
    if(cache[m][n] != -1) return cache[m][n];
    
    cache[m][n] = 0;
    if(check(n-1)) cache[m][n] += dp(m-1, n-1);
    if(check(n+1)) cache[m][n] += dp(m-1, n+1);
    
    cache[m][n] %= 1000000000;
    return cache[m][n];
}

int dp(int n){
    int ans = 0;

    cache[0][0] = 0;
    for(int i = 1 ; i < 10 ; i++)
        cache[0][i] = 1;

    for(int i = 0 ; i < 10 ; i++){
        ans += dp(n-1, i);
        ans %= 1000000000;
    }

    return ans;
}


int main (){
    cin >> n;
    cache = vector<vector<int> >(n, vector<int>(10, -1));
    
    cout << dp(n);    

    return 0;
}

// 2) Bottop-Up Method

// #include <iostream>
// #include <vector>

// using namespace std;

// int n;
// vector<vector<int> > cache;

// bool check(int i){
//     if (i < 0 || i > 9) return false;
//     else return true;
// }

// int dp(int n){
//     int ans = 0;

//     for(int i = 1 ; i < 10; i++)
//         cache[0][i] = 1;
    
//     for(int i = 1 ; i < n ; i++)
//         for(int j = 0; j < 10; j++){
//             if(check(j-1)) cache[i][j] += cache[i-1][j-1];
//             if(check(j+1)) cache[i][j] += cache[i-1][j+1];
//             cache[i][j] %= 1000000000;
//         }

//     for(auto it = cache[n-1].begin() ; it != cache[n-1].end() ; it++){
//         ans += *it;
//         ans %= 1000000000;
//     }
    
//     return ans;
// }


// int main (){
//     cin >> n;
//     cache = vector<vector<int> >(n, vector<int>(10, 0));
    
//     cout << dp(n);    

//     return 0;
// }