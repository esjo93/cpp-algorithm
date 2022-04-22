#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<int> operv;

int cal(int a, int b, int oper){
    switch(oper){
        case 0:
        return a + b;
        break;
        case 1:
        return a - b;
        break;
        case 2:
        return a * b;
        break;
        case 3:
        return a / b;
        break;
        default:
        break;
    }
    return 0;
}


int main (){
    cin >> n;
    v = vector<int>(n, 0);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    
    int oper_num = 0;
    int oper_type = 0;
    for(int i = 0 ; i < 4 ; i++){
        cin >> oper_num;
        while(oper_num--) operv.push_back(oper_type);
        oper_type++;
    }

    vector<int> temp_operv;
    vector<int> temp_v;
    vector<int> cand;
    do{
        temp_operv = vector<int>(operv);
        temp_v = vector<int>(v);
        
        int ans = temp_v.front(); temp_v.erase(temp_v.begin());
        while(!temp_v.empty()){
            int operand = temp_v.front(); temp_v.erase(temp_v.begin());
            int oper = temp_operv.front(); temp_operv.erase(temp_operv.begin());
            ans = cal(ans, operand, oper);
        }
        cand.push_back(ans);
    }while(next_permutation(operv.begin(), operv.end()));

    cout << *max_element(cand.begin(), cand.end()) << '\n'
        << *min_element(cand.begin(), cand.end());
}