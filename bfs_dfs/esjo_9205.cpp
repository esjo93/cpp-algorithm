#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int t, n;
vector<bool> visited;
vector<int> vx, vy;

bool bfs(){
    int beer = 20;
    int curnode, curbeer;
    
    queue<int> qnode, qbeer;
    qnode.push(0);
    qbeer.push(beer);
    
    while(!qnode.empty()){
        curnode = qnode.front(); qnode.pop();
        curbeer = qbeer.front(); qbeer.pop();
        int drink;
        
        for(int i = 0 ; i < n+2 ; i++){
            if(!visited[i]){
                drink = (abs(vx[i] - vx[curnode]) + abs(vy[i] - vy[curnode]) - 1) / 50 + 1;
                if(curbeer < drink) continue;
                visited[i] = true;
                qnode.push(i);
                if (i != n+1) qbeer.push(20);
                else break;
            }
        }
        if (curnode == n+1) return true;
    }
    
    return false;
}

int main (){
    cin >> t;
    while(t--){
        cin >> n;
        vx = vector<int>(n+2, 0);
        vy = vector<int>(n+2, 0);
        visited = vector<bool>(n+2, false);
        visited[0] = true;

        for(int i = 0 ; i < n+2 ; i++)
            cin >> vx[i] >> vy[i];
        
        bool ans = bfs();
        if(ans) cout << "happy\n";
        else cout << "sad\n";
    }

    return 0;
}