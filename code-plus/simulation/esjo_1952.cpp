#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<bool> > visited;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool check(int y, int x){
    if(y < 0 || y >= m || x < 0 || x >= n) return false;
    return true;
}

int main (){
    cin >> m >> n;
    visited = vector<vector<bool> >(m, vector<bool>(n, 0));
    int y=0, x=0, d=0, cnt=0, loop=1;

    while(loop++ < m*n){
        visited[y][x] = true;
        y += dy[d];
        x += dx[d];

        if(loop == m*n) break;
        if(!check(y+dy[d], x+dx[d])){
            d = (d+1) % 4;
            cnt++;
        }
        else if(visited[y+dy[d]][x+dx[d]]){
            d = (d+1) % 4;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}