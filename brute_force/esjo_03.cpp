#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	string s;
	cin >> s;
	vector<char> vc;
	vector<int> vi;


	for (auto it = s.begin(); it != s.end(); it++){
		//cout << *it << endl;
		if (*it >= 'A' && *it <='Z') vc.push_back(*it);
		if (*it >= '0' && *it <= '9') vi.push_back(int(*it - '0'));
	}
	int sum = 0;
	for (auto it = vi.begin(); it != vi.end(); it++) sum += *it;
	sort( vc.begin() , vc.end());

	for (auto it = vc.begin(); it!=vc.end() ; it++) cout << *it;
	cout << sum  << endl;
	

}

