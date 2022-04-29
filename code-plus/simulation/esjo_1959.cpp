#include <iostream>
#include <cmath>

using namespace std;

long long m, n;


int main (){
    cin >> m >> n;

    long long y = 0, x = 0, layer, cnt; 

    layer = min((m-1)/2, (n-1)/2);
    
    y = layer; 
    x = layer;
    m -= 2*layer;
    n -= 2*layer;
    cnt = 4*layer;

    if (m == 1)
        x += n-1;
    if (m > 1 && n == 1){
        y += m-1;
        cnt++;
    }
    if (m == 2 && n > 1){
        y++;
        cnt += 2;
    }
    if (m > 2 && n > 1){
        y++;
        cnt += 3;
    }
    
    cout << cnt << '\n' << y + 1 << ' ' << x + 1;

    return 0;
}