#include <iostream>

using namespace std;

int main(){
	int n;

	cin >> n;

	int f1=0;
	int f2=0;
	int f3=0;
	int cnt = 0; 
	for(int i = 0 ; i <= n ; i++){
		if (i == 3){
			f1 = 1;
		}
		else f1 = 0;
		for(int j = 0 ; j <60 ; j++){
			if ( j % 10 == 3 || j / 10 ==3)
				f2 = 1;
			else f2 = 0;
			for(int k = 0 ; k < 60 ; k++){
				if (k % 10 == 3 || k / 10 ==3)
					f3 = 1;
				else f3=0;
				if ( f1 || f2 || f3) cnt++;
							
			}	

		}
	}
	cout << cnt << '\n';

	return 0;

}


	
