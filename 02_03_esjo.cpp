#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	int n;
	
	cin >> n;

	vector<int> v;
	int temp;
	while(n--){
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());

//	for (auto it = v.begin() ; it != v.end(); it++) cout << *it;

	int memNum=0;
	int groupNum=0;
	for(auto it = v.begin(); it != v.end(); it++){
		memNum += 1;
		if(memNum >= *it){
			groupNum++;
			memNum = 0;
		}
	}

	cout << groupNum << '\n';

	return 0;

}
