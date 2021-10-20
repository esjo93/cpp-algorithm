#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef struct _snake{
    int d;
    int y;
    int x;
}snake;

typedef struct _apple{
    int y;
    int x;
}apple;

typedef struct _dir{
    int time;
    char direct;
}dir;

int n, k, l;
int length = 1;
int time = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<vector<int> > v;
vector<snake> s;
vector<apple> a;
vector<dir> d;


bool check(){
    auto head = s.begin();
    const int y = head->y;
    const int x = head->x;

    if (y < 1 || y > n || x <1 || x > n)
        return false;
    
    auto it = find_if(s.begin()+1, s.end(), [y, x](snake item) -> bool{
        return item.y == y && item.x == x;
    });

    if (it == s.end()) return true;
    else return false;
}

bool isApple(const int y, const int x){
    auto it = find_if(a.begin(), a.end(), [y, x](apple item) -> bool{
        return item.y == y && item.x == x;
    });
    
    if (it != a.end()){
        a.erase(it);
        return true;
    }
    else return false;
}

bool move(){
    auto head = s.begin();
    // step 1: lengthen
    s.insert(head, {head->d, head->y+dy[head->d], head->x+dx[head->d]});
    head = s.begin();
    if(!check()) return false;
    
    // step 2: check apple
    // if apple exists pass, else shorten tail
    if (!isApple(head->y, head->x)){
        s.pop_back();
    }
    // step 3: check direction change
    if (d.size()){
        if (time == d[0].time){
            dir info = d[0];
            if (info.direct == 'D') head->d = (head->d+1) % 4;
            else if (info.direct == 'L') head->d = (head->d+3) % 4;
            d.erase(d.begin());
        }
    }

    return true;
}


int main (){
    cin >> n >> k;
    
    while(k--){
        apple item;
        cin >> item.y >> item.x;
        a.push_back(item);
    }

    cin >> l;
    while(l--){
        dir item;
        cin >> item.time >> item.direct;
        d.push_back(item);
    }

    s.push_back({0, 1, 1});
    while(true){
        time++;
        if(!move()) break;
    }

    cout << time;
}


