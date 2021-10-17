#include<iostream>
#include<queue>
#include<map>
#define MAX_VALUE 100000

using namespace std;

int n, k;

queue<int> qx, qt;
map<int, bool> visited;

int main (){
    cin >> n >> k;
    qx.push(n);
    qt.push(0);
    visited[n] = true;
    
    int curx, curt;
    while(!qx.empty()){
        curx = qx.front(); qx.pop();
        curt = qt.front(); qt.pop();
        
        if (curx == k){
            cout << curt;
            return 0;
        }
        
        vector<int> step = {2*curx, curx-1, curx+1};
        
        for(int item : step){
            if (item >= 0 && item <= MAX_VALUE && !visited[item]){
                qx.push(item);
                qt.push(curt+1);
                visited[item] = true;
            }
        }
    }
        
    return 0;
}