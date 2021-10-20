#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _shark{
    int row;
    int col;
    int speed;
    int direct;
    int size;
} shark;

int r, c, m;
int p = 0;
int ans = 0;

vector<vector<int> > v;
vector<shark> vs;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};


void move(shark &s){
    if(!s.speed) return;

    int dir = s.direct;
    int cnt = s.speed;
    int cury = s.row;
    int curx = s.col;
    int newy = cury;
    int newx = curx;
    
    v[cury][curx]--;

    if (cnt > 1){
        int divisor;
        if (dir <= 2) divisor= 2*r -2;
        else divisor = 2*c -2;
        if (divisor > 0) cnt %= divisor;
    }

    while(cnt--){
        newy = cury + dy[dir];
        newx = curx + dx[dir];
        if (newy < 1 || newy > r || newx < 1 || newx > c){
            if (dir == 1 || dir == 3) dir++;
            else if (dir == 2 || dir == 4) dir--;
            newy = cury + dy[dir];
            newx = curx + dx[dir];
        }
        cury = newy;
        curx = newx;
    }
    s.direct = dir;
    s.row = newy;
    s.col = newx;
    v[newy][newx]++;
}

void remove(){
    for(int i = 1; i < r+1; i++)
    for(int j = 1; j < c+1; j++){
        if (v[i][j] <= 1) continue;

        // if 2 or more sharks found, sort by size in ascending order
        sort(vs.begin(), vs.end(), 
            [](shark i, shark j) -> bool {
                return i.size < j.size;
        });

        // remove smallest ones until the last one's left
        while(v[i][j] > 1){
            auto it = find_if(vs.begin(), vs.end(), 
                [i, j](shark s) -> bool {
                    return s.row == i && s.col ==j;
            });
            
            vs.erase(it);
            v[i][j]--;
        }
    }
}


int main(){
    cin >> r >> c >> m;

    v = vector<vector<int> >(r+1, vector<int>(c+1, 0));
    vs = vector<shark>(m);

    // read shark info
    for (int i = 0; i < m ; i++){
        shark s;
        cin >> s.row >> s.col >> s.speed >> s.direct >> s.size;
        v[s.row][s.col]++;
        vs[i] = s;
    }
    
    while(++p != c+1){
        // find shark
        sort(vs.begin(), vs.end(), [](shark i, shark j) -> bool{
            return i.row < j.row;
        });

        const int person = p;
        auto iter = find_if(vs.begin(), vs.end(), [person](shark s) -> bool{
            return s.col == person;
        });
        
        // catch shark
        if (iter != vs.end()){
            ans += iter->size;
            v[iter->row][iter->col]--;
            vs.erase(iter);
        }
        
        // sharks are moved and eaten here
        for(auto it = vs.begin(); it != vs.end(); it++) move(*it);
        remove();
    }

    cout << ans;

    return 0;
}