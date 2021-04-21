#include <iostream>
#include <vector>

using namespace std;

int count(int c, int p, vector<int> height){
	int cnt = 0;
	switch(p){
		case 1:
			cnt += c;
			for(int i = 0; i <= c-4; i++)
				if(height[i] == height[i+1] && height[i+1] == height[i+2] && height[i+2] == height[i+3])
					cnt++;
			break;
		case 2:
			for(int i = 0; i<= c-2; i++)
				if(height[i] == height[i+1]) cnt++;
			break;
		case 3:
			for(int i = 0 ; i <= c-2 ; i++)
				if(height[i] - height[i+1] == 1) cnt++;
			for(int i = 0 ; i <= c-3 ; i++)
				if(height[i] == height[i+1] && height[i+1] - height[i+2] == -1) cnt++;
			break;
		case 4:
			for(int i = 0 ; i <= c-2 ; i++)
				if(height[i+1] - height[i] == 1) cnt++;
			for(int i = 0 ; i <= c-3 ; i++)
				if(height[i] - height[i+1] == 1 && height[i+1] == height[i+2]) cnt++;
			break;
		case 5:
			for(int i = 0 ; i <= c-2 ; i++){
				if(height[i] - height[i+1] == 1) cnt++;
				if(height[i] - height[i+1] == -1) cnt++;
			}
			for(int i = 0 ; i <= c-3 ; i++){
				if(height[i] == height[i+1] && height[i+1] == height[i+2]) cnt++;
				if(height[i] == height[i+2] && height[i+1] - height[i+2] == -1) cnt++;
			}
			break;
		case 6:
			for(int i = 0; i <= c-2 ; i++){
				if(height[i] == height[i+1]) cnt++;
				if(height[i] - height[i+1] ==2) cnt++;
			}
			for(int i = 0 ; i <= c-3 ; i++){
				if(height[i] == height[i+1] && height[i+1] == height[i+2]) cnt++;
				if(height[i] - height[i+1] == -1 && height[i+1] == height[i+2]) cnt++;
			}
			break;	
		case 7:
			for(int i = 0 ; i <= c-2 ; i++){
				if(height[i] == height[i+1]) cnt++;
				if(height[i+1] - height[i] == 2) cnt++;
			}
			for(int i = 0 ; i <= c-3 ; i++){
				if(height[i] == height[i+1] && height[i+1] == height[i+2]) cnt++;	
				if(height[i] == height[i+1] && height[i+1] - height[i+2] == 1) cnt++;
			}
			break;
	}
	return cnt;
}


int main(){
	int c, p;
	cin >> c >> p;
	vector<int> height(c);

	for(int i = 0 ; i < c ; i++) cin >> height[i];

	cout << count(c, p, height) << '\n';

	return 0;	
}
