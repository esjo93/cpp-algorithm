#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dy[4] = {-1, 1, 0, 0}; // UDLR
int dx[4] = {0, 0, -1, 1};

class Game{
    public:
    int r, c;
    int y, x;
    int boxcnt=0;
    vector<vector<char> > v;
    string con;
    
    Game(int row, int col){
        r = row;
        c = col;
    }

    void input(){
        v = vector<vector<char> >(r, vector<char>(c));
        
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++){
                cin >> v[i][j];
                if(v[i][j] == 'b') boxcnt++;
                if(v[i][j] == 'W' || v[i][j] == 'w'){
                    y = i;
                    x = j;
                }
            }
        getline(cin, con);
        getline(cin, con);
    }
    
    bool check(int i, int j){
        if(i < 0 || i >= r || j < 0 || j >= c) return false;
        if(v[i][j] == '.' || v[i][j] == '+') return true;
        return false;
    }

    void move(char dir){
        int d;
        if (dir == 'U') d = 0;
        else if (dir == 'D') d = 1;
        else if (dir == 'L') d = 2;
        else if (dir == 'R') d = 3;

        // vacant
        if(v[y+dy[d]][x+dx[d]] == '.' || v[y+dy[d]][x+dx[d]] == '+'){
            v[y][x] = (v[y][x] == 'w') ? '.' : '+';
            
            y += dy[d];
            x += dx[d];
            v[y][x] = (v[y][x] == '.') ? 'w' : 'W';
            return;
        }

        // blocked
        if(v[y+dy[d]][x+dx[d]] == '#')
            return;

        // box condition
        if(v[y+dy[d]][x+dx[d]] == 'b' || v[y+dy[d]][x+dx[d]] == 'B'){
            // movable
            if(check(y+2*dy[d], x+2*dx[d])){
                v[y][x] = (v[y][x] == 'w') ? '.' : '+';

                y += dy[d];
                x += dx[d];
                if(v[y][x] == 'b')
                    v[y][x] = 'w';
                else if(v[y][x] == 'B'){
                    v[y][x] = 'W';
                    boxcnt++;
                }
                
                if(v[y+dy[d]][x+dx[d]] == '.')
                    v[y+dy[d]][x+dx[d]] = 'b';
                else if(v[y+dy[d]][x+dx[d]] == '+'){
                    v[y+dy[d]][x+dx[d]] = 'B';
                    boxcnt--;
                }
                return;
            }
            // unmovable
            return;
        }
    }

    void print(){
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++)
                cout << v[i][j];
            cout << '\n';
        }
    }

    string is_complete(){
        if (!boxcnt) return "complete";
        return "incomplete";
    }

    void run(){
        char dir;
        for(auto it = con.begin(); it!= con.end(); it++){
            if (!boxcnt) break;
            dir = *it;
            move(dir);
        }
    }
};


int main (){
    int r, c;
    int num = 1;
    while(true){
        cin >> r >> c;
        if (!r && !c) break;
        Game g(r, c);
        g.input();
        g.run();
        
        cout << "Game "<< num << ": " << g.is_complete() << '\n'; 
        num++;
        g.print();
    }
    
    return 0;
}