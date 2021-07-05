#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > adj; // adjacency matrix
vector<int> visit; // visited or not
queue<int> qn, qc; // queues of node and count

int n, a, b, m; 
/* 
n: number of relatives
a: the first person
b: the second person
*/

int main (){
    cin >> n >> a >> b >> m;
    adj = vector<vector<int> >(n, vector<int>(n, 0));
    visit = vector<int>(n, 0);
    
    int p1, p2; // person 1 and 2
    
    while(m--){
        cin >> p1 >> p2;
        adj[p1-1][p2-1] = 1; adj[p2-1][p1-1] = 1;
    }
    
    qn.push(a-1); qc.push(0); visit[a-1] = 1;
    
    int cur, cnt;
    while(!qn.empty()){
        cur = qn.front(); qn.pop();
        cnt = qc.front(); qc.pop();
        
        if(cur == b-1) break;

        for(int i = 0 ; i < n ; i++){
            if(!visit[i] && adj[cur][i]){
                qn.push(i); qc.push(cnt+1); visit[i] = 1;
            }
        }

    }
    if(cur != b-1) cout << -1 << '\n';
    else cout << cnt << '\n';
    
    return 0;
}