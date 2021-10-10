#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int> > v;
vector<vector<bool> > visited;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void flood(int h){
    visited = vector<vector<bool> >(n, vector<bool>(n, false));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            if (v[i][j] <= h) visited[i][j] = true;
}

bool check(int i, int j){
    if (i < 0 || i >= n || j < 0 || j >= n) return false;
    if (visited[i][j]) return false;
    else return true;
}

void bfs(int i, int j){
    queue<int> qy, qx;
    qy.push(i); 
    qx.push(j); 
    visited[i][j] = true;
    
    while(!qy.empty()){
        int y = qy.front(); qy.pop();
        int x = qx.front(); qx.pop();
        
        for (int k = 0 ; k < 4 ; k++){
            int newy = y + dy[k];
            int newx = x + dx[k];
            if(check(newy, newx)){
                qy.push(newy);
                qx.push(newx);
                visited[newy][newx] = true;
            }
        }
    }
}

int count_area(){
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            if (check(i, j)) {
                bfs(i, j);
                cnt++;
            }
    return cnt;
}


int main (){
    cin >> n;
    v = vector<vector<int> >(n, vector<int>(n, 0));
    visited = vector<vector<bool> >(n, vector<bool>(n, false));
    
    int max_height = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            cin >> v[i][j];
            if (v[i][j] > max_height) max_height = v[i][j];
        }

    int cnt;
    int max_cnt = 1;
    for(int i = 1; i < max_height; i++){
        flood(i);
        cnt = count_area();
        if (cnt > max_cnt) max_cnt = cnt;
    }

    cout << max_cnt;
    return 0;
}