#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main (){
    int group = 0;
    int num = 4;
    string ans; 
    queue<char> q;   
    char c1=' ', c2;
    int repidx = -1;

    do{
        scanf("%c", &c2);
        if(c1 == ':' && c2 == ':')
            repidx = ans.size();
        else if(c1 != ':' && c2 == ':'){
            while(num--) ans.push_back('0');
            num = 4;
            while(!q.empty()){
                ans.push_back(q.front()); 
                q.pop();
            }
            if (++group < 8) ans.push_back(':');
        }
        else if(c2 == '\n'){
            while(num--) ans.push_back('0');
            while(!q.empty()){
                ans.push_back(q.front()); 
                q.pop();
            }
        }
        else{
            num--;
            q.push(c2);
        }
        c1 = c2;
    }while(c2 != '\n');

    if (repidx != -1){
        while(ans.size() != 39) ans.insert(repidx, "0000:");
    }

    cout << ans;
    return 0;
}