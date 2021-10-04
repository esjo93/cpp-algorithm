#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int m, n, h;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

queue<int> qx, qy, qz, qd;


vector<vector<vector<int> > > v;

bool checkDone(){
    for(int i = 0 ; i < m ; i++)
        for(int j = 0; j < n ; j++)
            for(int k = 0; k < h ; k++)
                if (v[i][j][k] == 0) return false;

    return true;
}

bool check(int i, int j, int k){
    if (i < 0 || i >= m || j < 0 || j >= n || k < 0 || k >= h) 
        return false;
    
    if (v[i][j][k] == 0) return true;
    
    else return false;
}

int bfs(){
    int curx, cury, curz, curd;
    curd = 0;
    while(!qx.empty()){
        curx = qx.front(); qx.pop();
        cury = qy.front(); qy.pop();
        curz = qz.front(); qz.pop();
        curd = qd.front(); qd.pop();
        
        for(int i = 0 ; i < 6; i++){
            int newx, newy, newz, newd;
            newx = curx + dx[i];
            newy = cury + dy[i];
            newz = curz + dz[i];
            newd = curd + 1;

            if (check(newx, newy, newz)){
                v[newx][newy][newz] = 1;
                qx.push(newx); 
                qy.push(newy); 
                qz.push(newz); 
                qd.push(newd);
            }
            else continue;
        }
    }
    
    return curd;
}


int main(){
    cin >> m >> n >> h;

    v = vector<vector<vector<int> > >(m, vector<vector<int> >(n, vector<int>(h, 0)));

    for(int k = 0 ; k < h; k++)
        for(int j = 0 ; j < n ; j++)
            for(int i = 0 ; i < m ; i++){
                cin >> v[i][j][k];
                if (v[i][j][k] == 1){
                    qx.push(i);
                    qy.push(j);
                    qz.push(k);
                    qd.push(0);
                }
            }
    
    int ans = bfs();

    if (!checkDone()) cout << -1;
    else cout << ans;
    
    return 0;
}
