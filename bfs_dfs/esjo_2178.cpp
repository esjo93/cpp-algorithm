#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > v;
vector<vector<int> > visited;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool check(int y, int x, int n, int m){
    if (y >= 0 && y < n && x >= 0 && x < m){
        if (v[y][x] && !visited[y][x]) return true;
        else return false;
    }

    else return false;
}

int main (){
    cin >> n >> m;
    v = vector<vector<int> >(n, vector<int>(m));
    visited = vector<vector<int> >(n, vector<int>(m, 0)); visited[0][0] = 1;

    for(int i = 0; i < n ; i++) for(int j = 0 ; j < m ; j++)
        scanf("%1d", &v[i][j]);

    queue<int> qy, qx, qc;
    qy.push(0); qx.push(0); qc.push(1);
    
    int y, x, cnt, cy, cx, cc;

    while(!qy.empty()){
        y = qy.front(); qy.pop();
        x = qx.front(); qx.pop();
        cnt = qc.front(); qc.pop();

        if (y == n-1 && x == m-1) break;

        for(int i = 0 ; i < 4; i++){
            cy = y + dy[i]; cx = x + dx[i]; cc = cnt+1;
            if (check(cy, cx, n, m)){
                qy.push(cy); qx.push(cx); qc.push(cc); visited[cy][cx]=1;
            }
        }
    }
    cout << cnt << '\n';
    
    return 0;
}