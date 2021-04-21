#include <iostream>
#include <vector>

using namespace std;

int main (){
	vector<int> v;
	string input;

	cin >> input;

	for(auto it = input.begin(); it != input.end(); it++)
		v.push_back(int(*it - '0'));
	
	int a = v[0];
	int sum = a;
	int b;
	
//	for(auto it = v.begin() ; it != v.end() ; it++)
//		cout << *it << endl;
	for(auto it = v.begin()+1; it!=v.end(); it++){
		b = *it;
		if(a <= 1 || b <= 1) sum += b;
		else sum *= b;
		a = b;
	}
	
	cout << sum << '\n';

	return 0;
}
