#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int n, m, v;
vector<bool> visited;
vector<vector<bool> > adj;
queue<int> q;
stack<int> s;

bool check(int src, int dst){
    if(!visited[dst] && adj[src][dst])
        return true;
    return false;
}

void bfs(int vertex){
    visited = vector<bool>(n, false);
    
    q.push(vertex);
    visited[vertex] = true;
    
    int cur;
    while(!q.empty()){
        cur = q.front(); q.pop();
        cout << cur + 1 << ' ';
        for(int i = 0 ; i < n ; i++)
            if (check(cur, i)){
                q.push(i);
                visited[i] = true;
            }
    }
    cout << '\n';
}

void dfs(int vertex){
    visited = vector<bool>(n, false);
    
    s.push(vertex);
    visited[vertex] = true;
    cout << vertex + 1 << ' ';
    
    int cur;
    bool flag;

    while(!s.empty()){
        cur = s.top();
        flag = false;

        for(int i = 0 ; i < n ; i++)
            if(check(cur, i)){
                s.push(i);
                visited[i] = true;
                flag = true;
                cout << i + 1 << ' ';
                break;
            }

        if(!flag) s.pop();
    }
    cout << '\n';
}


int main (){
    cin >> n >> m >> v;

    adj = vector<vector<bool> >(n, vector<bool>(n, false));
    
    int n1, n2;

    while(m--){
        cin >> n1 >> n2;
        adj[n1-1][n2-1] = true;
        adj[n2-1][n1-1] = true;
    }
    
    dfs(v-1);
    bfs(v-1);
    
    return 0;
}