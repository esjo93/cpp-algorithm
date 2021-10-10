#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > v;
vector<vector<int> > original;
stack<vector<int> > s;

int n;
int r = 0;
int c = 1;
int pos = 0;
int sum = 0;


bool check(){
    switch(pos){
        case 0:
            if ( r >= 0 && r < n && c >= 1 && c < n){
                if (!v[r][c]) return true;
                else return false;
            } 
            else return false;
            break;
        case 1:
            if ( r >= 1 && r < n && c >= 0 && c < n ){
                if (!v[r][c]) return true;
                else return false;
            } 
            else return false;
            break;
        case 2:
            if ( r >= 1 && r < n && c >= 1 && c < n ) {
                if (!v[r][c] && !v[r-1][c] && !v[r][c-1]) return true;
                else return false;
            } 
            else return false;
            break;
    }
}

void move(int way){
    switch(way){
        case 0:
        c++;
        pos = 0;
        break;

        case 1:
        r++;
        pos = 1;
        break;

        case 2:
        r++;
        c++;
        pos = 2;
        break;
    }
}

void set(int row, int col, int ori){
    r = row;
    c = col;
    pos = ori;
}

void count_path(){
    // end position (r, c)
    // way (0: right, 1: down, 2: diagonal)
    if (r == n-1 && c == n-1) {
        sum++;
        return;
    }
    int row = r;
    int col = c;
    int ori = pos;
    switch(pos){
        case 0: // horizontal (r, c) (r, c+1)
        move(0);
        if (check()){
            count_path();
        }
        set(row, col, pos);
        move(2);
        if (check()){
            count_path();
        }
        set(row, col, pos);
        break;

        case 1: // vertical (r, c) (r+1, c)
        move(1);
        if (check()){
            count_path();
        }
        set(row, col, pos);
        move(2);
        if (check()){
            count_path();
        }
        set(row, col, pos);
        break;

        case 2: // diagonal (r, c) (r+1, c+1)
        move(0);
        if (check()){
            count_path();
        }
        set(row, col, pos);
        move(1);
        if (check()){
            count_path();
        }
        set(row, col, pos);
        move(2);
        if (check()){
            count_path();
        }
        set(row, col, pos);
        break;
    }
    return;
}


int main(){
    cin >> n;
    v = vector<vector<int> >(n, vector<int>(n));
    original = v;
        
    for (int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n; j++) cin >> v[i][j];

    count_path();
    
    cout << sum << '\n';

    return 0;
}