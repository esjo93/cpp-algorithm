#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
 * For the d-value
 * 0 -> north (goes to [0, -1])
 * 1 -> east (goes to [-1, 0])
 * 2 -> south (goes to [0, 1])
 * 3 -> west (goes to [1, 0])
*/
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int back_dy[4] = {1, 0, -1, 0};
int back_dx[4] = {0, -1, 0, 1};

int n, m, r, c, d;  
vector<vector<int> > v;
vector<vector<bool> > visited;


bool check_blocked(int y, int x){
    if (v[y][x]) return true;
    else return false;
}

bool check_visited(int y, int x){
    if (visited[y][x]) return true;
    else return false;
}

bool check(int y, int x){
    if (y < 0 || y >= n || x < 0 || x >= m) return false;
    if (!check_visited(y, x) && !check_blocked(y, x)) return true;
    else return false;
}

int bfs(int y, int x, int d){
    int cury, curx, curd, curc, newy, newx, newd, newc;
    bool cur_blocked, cannot_move;
    queue<int> qy, qx, qc, qd;    
    
    qy.push(y); 
    qx.push(x);
    qd.push(d); 
    qc.push(1);
    visited[y][x] = true;
    curc=1;

    while(!qy.empty()){
        cury = qy.front(); qy.pop();
        curx = qx.front(); qx.pop();
        curd = qd.front(); qd.pop();
        curc = qc.front(); qc.pop();
        
        cannot_move = true;
        for(int i = 0 ; i < 4; i++){
            newy = cury + dy[curd];
            newx = curx + dx[curd];
            newd = (curd + 3) % 4;
            newc = curc + 1;
            
            cur_blocked = !check(newy, newx);

            if(!cur_blocked){
                qy.push(newy);
                qx.push(newx);
                qd.push(newd);
                qc.push(newc);
                visited[newy][newx] = 1;
                cannot_move = false;
                break;
            }
            curd = newd;
        }

        if (cannot_move){
            newy = cury + back_dy[curd];
            newx = curx + back_dx[curd];
            newd = curd;
            newc = curc;
            if (check_blocked(newy, newx)) return curc;
            else{
                qy.push(newy);
                qx.push(newx);
                qd.push(newd);
                qc.push(newc);
            }
        }
    }
    return curc;
}

int main (){
    cin >> n >> m >> r >> c >> d;

    v = vector<vector<int> >(n, vector<int>(m, 0));
    visited = vector<vector<bool> >(n, vector<bool>(m, false));

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> v[i][j];

    int ans = bfs(r, c, d);
    cout << ans;
}