#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main (){
	int n, k;
	
	cin >> n >> k;
	vector<int> v(n);

	for(int i = 0 ; i < n ; i++) cin >> v[i];
	
	sort(v.begin(), v.end(), greater<int>());
	int sum = 0;
	int quot;
	for(auto item : v){
		if (item > k) continue;
		else{
			quot = k / item;
			sum += quot;
			if(quot > 0) k -= (item * quot);
		}
	}
	cout << sum << '\n';

	return 0;	
}
