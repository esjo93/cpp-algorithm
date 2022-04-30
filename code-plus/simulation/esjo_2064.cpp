#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;


int main (){
    cin >> n;
    vector<vector<int> > v(n, vector<int>(4));
    int addr[32];
    int mask[32];
    int powered;
    bool beq, is_done=false;
    int ans;

    for(int i = 0 ; i < n ; i++)
        scanf("%d.%d.%d.%d", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
    
    for(int i = 0 ; i < 32 ; i++){
        powered = pow(2, 7 - (i%8));
        for(int j = 0 ; j < n ; j++){
            if (is_done) break;
            if (j == 0) beq = (v[j][i/8] >= powered);
            
            if ( beq == (v[j][i/8] >= powered) ){
                if(beq) v[j][i/8] -= powered;
            }
            else is_done = true;
        }

        if (is_done) {
            addr[i] = 0;
            mask[i] = 0;
        }
        else{
            addr[i] = (beq)? 1 : 0;
            mask[i] = 1;
        }
    }
    
    for(int i = 0 ; i < 32; i++){
        powered = pow(2, 7-(i%8));
        if (i % 8 == 0) ans = 0;
        ans += addr[i] * powered;
        if (i % 8 == 7) {
            cout << ans;
            if (i == 31) cout << '\n';
            else cout << '.';
        }
    }

    for(int i = 0 ; i < 32; i++){
        powered = pow(2, 7-(i%8));
        if (i % 8 == 0) ans = 0;
        ans += mask[i] * powered;
        if (i % 8 == 7) {
            cout << ans;
            if (i == 31) cout << '\n';
            else cout << '.';
        }
    }

    return 0;
}