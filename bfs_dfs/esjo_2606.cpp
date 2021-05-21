#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n; // number of computers
int m; // number of edges
vector<vector<int> > adj; // adjacency matrix
vector<int> visit; // visited node
queue<int> qn;


int main (){
    cin >> n >> m;

    adj = vector<vector<int> >(n, vector<int>(n, 0));
    visit = vector<int>(n, 0);
    int n1, n2;
        
    while(m--){
        cin >> n1 >> n2;
        adj[n1-1][n2-1] = 1;
        adj[n2-1][n1-1] = 1;
    }

    visit[0] = 1; qn.push(0);

    int cur;
    int cnt = 0;
    
    while(!qn.empty()){
        cur = qn.front(); qn.pop();
        for(int i = 0 ; i < n ; i++)
            if(adj[cur][i] && !visit[i]){
                qn.push(i); visit[i] = 1; cnt++;
            }
    }
    
    cout << cnt << '\n';

    return 0;
}