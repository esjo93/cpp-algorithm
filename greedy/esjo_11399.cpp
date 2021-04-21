#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> v(n);

	for(int i = 0 ; i < n ; i++) cin >> v[i];
	
	sort(v.begin(), v.end());

	int sum = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j <=i ; j++) sum += v[j];

	cout << sum << '\n';

	return 0;

}
