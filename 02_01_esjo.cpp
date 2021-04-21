#include <iostream>

using namespace std;

int main (){
	int n, k;

	cin >> n >> k;
	int cnt = 0;
	while(n!=1){
		if(n % k == 0) n /= k;
		else n--;
		cnt++;
	}
	cout << cnt;
}


