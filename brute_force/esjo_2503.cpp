#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

string q;
int b, st;

typedef struct{
    string query;
    int strike;
    int ball;
}game;

vector<game> gv;

int main (){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> q >> st >> b;
        game g = {q, st, b};
        gv.push_back(g);
    }

    int cnt = 0;
    for(int l = 1; l <= 9; l++){
        for(int m = 1 ; m <=9 ; m++){
            for(int n = 1 ; n <=9 ; n++){
                if (l == m || m == n || n == l) continue;
                bool check;
                for(auto it = gv.begin(); it != gv.end(); it++){
                    vector<int> a(3);
                    for(int i = 0 ; i < 3; i++)
                        a[i] = int(it->query[i] - '0');

                    int ball = 0;
                    int strike = 0;
                    
                    if(l == a[0]) strike++;
                    if(l == a[1]) ball++;
                    if(l == a[2]) ball++;

                    if(m == a[0]) ball++;
                    if(m == a[1]) strike++;
                    if(m == a[2]) ball++;

                    if(n == a[0]) ball++;
                    if(n == a[1]) ball++;
                    if(n == a[2]) strike++;

                    if (ball == it->ball && strike == it->strike){
                        check = true;
                        continue;
                    } 
                    else {
                        check = false;
                        break;
                    }
                }
                if (check) cnt++; 
            }
        }
    }

    cout << cnt;

    return 0;
}