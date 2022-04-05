#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
vector<vector<int> > v, vinit;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool check(int y, int x){
    if(y < 0 || y >= n || x < 0 || x >= m) return false;
    if(v[y][x] == 6) return false;
    else return true;
}

class cam{
public:
    int type;
    int y;
    int x;
    int dir = 0;
    
    cam(int type, int y, int x){
        this->type = type;
        this->y = y;
        this->x = x;
    }
    
    void setDir(int dir){
        this->dir = dir;
    }
    
    void seek(int dir){
        int cury = this->y + dy[dir];
        int curx = this->x + dx[dir];
        
        while(check(cury, curx)){
            if(v[cury][curx] == 0) v[cury][curx] = 9;
            cury += dy[dir];
            curx += dx[dir];
        }
    }
    
    void run(){
        switch(this->type){
        case 1:
            seek(this->dir);
            break;
        case 2:
            seek(this->dir);
            seek((this->dir + 2) % 4);
            break;
        case 3:
            seek(this->dir);
            seek((this->dir + 1) % 4);
            break;
        case 4:
            seek(this->dir);
            seek((this->dir + 1) % 4);
            seek((this->dir + 2) % 4);
            break;
        case 5:
            seek(this->dir);
            seek((this->dir + 1) % 4);
            seek((this->dir + 2) % 4);
            seek((this->dir + 3) % 4);
            break;
        }
    }
};
vector<cam> vcam;

void resetMatrix(){
    v = vector<vector<int> >(vinit);
}

int count(){
    int num = 0;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(!v[i][j]) num++;

    resetMatrix();
    return num;
}

int solution(){
    vector<int> cand;
    int numcam = vcam.size();
    int exp = -1;

    while(++exp < (int)pow(4, numcam)){
        int rem;
        int quot=exp;
        int isOverlap = false;

        for(int i = 0 ; i < numcam ; i++){
            rem = quot % 4;
            quot /= 4;
            if(vcam[i].type == 2 && rem >= 2){
                isOverlap = true;
                break;
            }
            if(vcam[i].type == 5 && rem >= 1){
                isOverlap = true;
                break;
            }
            vcam[i].setDir(rem);
            vcam[i].run();
        }

        if(isOverlap) {
            resetMatrix();
            continue;
        }

        cand.push_back(count());
    }
    return *min_element(cand.begin(), cand.end());
}


int main (){
    cin >> n >> m;
    v = vector<vector<int> >(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            cin >> v[i][j];
            if(v[i][j] > 0 && v[i][j] < 6)
                vcam.push_back(cam(v[i][j], i, j));
        }
    vinit = vector<vector<int> >(v);

    cout << solution();
    return 0;
}