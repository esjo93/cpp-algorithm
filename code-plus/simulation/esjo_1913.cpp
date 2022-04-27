#include <iostream>
#include <vector>

using namespace std;

int n, target;
vector<vector<int> > v;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool check(int y, int x){
    if (y < 0 || y >= n || x < 0 || x >= n) return false;
    return true;
}


int main (){
    cin >> n >> target;
    v = vector<vector<int> >(n, vector<int>(n, 0));
    
    int cury=n/2, curx=n/2, cur=1;
    int ansy, ansx;
    int dir = 0, newdir;
    
    while(check(cury, curx)){
        v[cury][curx] = cur++;
        if(v[cury][curx] == target){
            ansy = cury;
            ansx = curx;
        }
        
        cury = cury + dy[dir];
        curx = curx + dx[dir];

        newdir = (dir + 1) % 4;
        if(check(cury+dy[newdir], curx+dx[newdir]))
            if(!v[cury+dy[newdir]][curx+dx[newdir]]) 
                dir = newdir;
    }
    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            cout << v[i][j];
            if (j < n-1) cout << ' ';
            else cout << '\n';
        }

    cout << ansy+1 << ' ' << ansx+1;
    return 0;
}