#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > v;
vector<vector<bool> > visited;
vector<int> num_house;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool check(int y, int x){
    if (y < 0 || y >= n || x < 0 || x >= n) return false;
    
    if (!visited[y][x] && v[y][x]) return true;
    else return false;
}

int bfs(int y, int x){
    queue<int> qy, qx;
    int cury, curx, newy, newx, cnt;

    cnt = 1;
    qy.push(y);
    qx.push(x);
    visited[y][x] = true;
    
    while(!qy.empty()){
        cury = qy.front(); qy.pop();
        curx = qx.front(); qx.pop();

        for(int i = 0 ; i < 4 ; i++){
            newy = cury + dy[i];
            newx = curx + dx[i];
            if (check(newy, newx)){
                qy.push(newy);
                qx.push(newx);
                visited[newy][newx] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main (){
    int cnt = 0;

    cin >> n;
    v = vector<vector<int> >(n, vector<int>(n, 0));
    visited = vector<vector<bool> >(n, vector<bool>(n, false));

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            scanf("%1d", &v[i][j]);

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            if (check(i, j)) {
                num_house.push_back(bfs(i, j));
                cnt++;
            }
        }
    
    sort(num_house.begin(), num_house.end());
    
    cout << cnt << '\n';
    for(auto it = num_house.begin(); it != num_house.end(); it++)
        cout << *it << '\n';
    
    return 0;
}