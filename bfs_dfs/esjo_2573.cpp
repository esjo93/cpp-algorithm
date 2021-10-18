#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int n, m;
vector<vector<int> > v;
vector<vector<bool> > visited;


bool check(int y, int x){
    if (y < 0 || y >= n || x < 0 || x >= m)
        return false;
    
    if (v[y][x] && !visited[y][x]) return true;
    else return false;
}

bool check_water(int y, int x){
    if (y < 0 || y >= n || x < 0 || x >= m)
        return false;
    
    if (!v[y][x]) return true;
    else return false;
}

bool bfs(int y, int x){
    if (!check(y, x)) return false;

    queue<int> qy, qx;
    int cury, curx, newy, newx;
    
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
            }
        }
    }
    
    return true;
}

int count_area(){
    int area = 0;

    visited = vector<vector<bool> >(n, vector<bool>(m, false));

    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < m; j++)
            if(bfs(i, j)) area++;

    return area;
}

void melt(){
    vector<vector<int> > temp(v);

    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < m; j++){
            if (!v[i][j]) continue;
            int cnt = 0;
            for(int k = 0 ; k < 4 ; k++)
                if(check_water(i+dy[k], j+dx[k]))
                    cnt++;

            temp[i][j] -= cnt;
            if (temp[i][j] < 0) temp[i][j] = 0;
        }

    v = temp;
}


int main (){
    int area;
    int ans = 0;

    cin >> n >> m;
    v = vector<vector<int> >(n, vector<int>(m, 0));
    
    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < m; j++)
            cin >> v[i][j];
    
    while(true){
        area = count_area();
        if(area == 0){
            ans = 0;
            break;
        }
        else if(area >= 2) break;
        melt(); ans++;
    }

    cout << ans;

    return 0;
}