#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > v;

bool check(int y, int x){
	if (y < 0 || y >= n || x < 0 | x >= m) return false;
	else return true;
}

int getSum(int y, int x, int type){
	switch(type){
		// bar1
		case 0:
			if(check(y, x) && check(y, x+1) && check(y, x+2) && check(y, x+3))
				return v[y][x] + v[y][x+1] + v[y][x+2] + v[y][x+3];
			else return 0;
			break;
		// bar2
		case 1:
			if(check(y, x) && check(y+1, x) && check(y+2, x) && check(y+3, x))
				return v[y][x] + v[y+1][x] + v[y+2][x] + v[y+3][x];
			else return 0;
			break;
		// square
		case 2:
			if(check(y, x) && check(y, x+1) && check(y+1, x) && check(y+1, x+1))
				return v[y][x] + v[y][x+1] + v[y+1][x] + v[y+1][x+1];
			else return 0;
			break;
		// L(0degree)
		case 3:
			if(check(y, x) && check(y+1, x) && check(y+2, x) && check(y+2, x+1))
				return v[y][x] + v[y+1][x] + v[y+2][x] + v[y+2][x+1];
			else return 0;
			break;
		// L(90 degree)
		case 4:
			if(check(y, x) && check(y, x+1) && check(y, x+2) && check(y+1, x))
				return v[y][x] + v[y][x+1] + v[y][x+2] + v[y+1][x];
			else return 0;
			break;
		// L(180 degree)
		case 5:
			if(check(y, x) && check(y, x+1) && check(y+1, x+1) && check(y+2, x+1))
				return v[y][x] + v[y][x+1] + v[y+1][x+1] + v[y+2][x+1];
			else return 0;
			break;
		// L (270 degree)
		case 6:
			if(check(y+1, x) && check(y+1, x+1) && check(y+1, x+2) && check(y, x+2))
				return v[y+1][x] + v[y+1][x+1] + v[y+1][x+2] + v[y][x+2];
			else return 0;
			break;
		// ㄱ (0degree)
		case 7:
			if(check(y, x) && check(y, x+1) && check(y, x+2) && check(y+1, x+2))
				return v[y][x] + v[y][x+1] + v[y][x+2] + v[y+1][x+2];
			else return 0;
			break;
		// ㄱ (90 degree)
		case 8:
			if(check(y+2, x) && check(y+2, x+1) && check(y+1, x+1) && check(y, x+1))
				return v[y+2][x] + v[y+2][x+1] + v[y+1][x+1] + v[y][x+1];
			else return 0;
			break;
		// ㄱ (180 degree)
		case 9:
			if(check(y, x) && check(y+1, x) && check(y+1, x+1) && check(y+1, x+2))
				return v[y][x] + v[y+1][x] + v[y+1][x+1] + v[y+1][x+2];
			else return 0;
			break;
		// ㄱ (270 degree)
		case 10:
			if(check(y, x) && check(y, x+1) && check(y+1, x) && check(y+2, x))
				return v[y][x] + v[y][x+1] + v[y+1][x] + v[y+2][x];
			else return 0;
			break;
		// ㅁㅁ
		//   ㅁㅁ
		case 11:
			if(check(y, x) && check(y, x+1) && check(y+1, x+1) && check(y+1, x+2))
				return v[y][x] + v[y][x+1] + v[y+1][x+1] + v[y+1][x+2];
			else return 0;
			break;
		//   ㅁ
		// ㅁㅁ
		// ㅁ
		case 12:
			if(check(y, x+1) && check(y+1, x) && check(y+1, x+1) && check(y+2, x))
				return v[y][x+1] + v[y+1][x] + v[y+1][x+1] + v[y+2][x];
			else return 0;
			break;
		//   ㅁㅁ
		// ㅁㅁ
		case 13:
			if(check(y, x+1) && check(y, x+2) && check(y+1, x) && check(y+1, x+1))
				return v[y][x+1] + v[y][x+2] + v[y+1][x] + v[y+1][x+1];
			else return 0;
			break;
		// ㅁ
		// ㅁㅁ
		//   ㅁ
		case 14:
			if(check(y, x) && check(y+1, x) && check(y+1, x+1) && check(y+2, x+1))
				return v[y][x] + v[y+1][x] + v[y+1][x+1] + v[y+2][x+1];
			else return 0;
			break;
		// ㅗ
		case 15:
			if(check(y, x+1) && check(y+1, x) && check(y+1, x+1) && check(y+1, x+2))
				return v[y][x+1] + v[y+1][x] + v[y+1][x+1] + v[y+1][x+2];
			else return 0;
			break;
		// ㅓ
		case 16:
			if(check(y+1, x) && check(y, x+1) && check(y+1, x+1) && check(y+2, x+1))
				return v[y+1][x] + v[y][x+1] + v[y+1][x+1] + v[y+2][x+1];
			else return 0;
			break;
		// ㅜ
		case 17:
			if(check(y, x) && check(y, x+1) && check(y, x+2) && check(y+1, x+1))
				return v[y][x] + v[y][x+1] + v[y][x+2] + v[y+1][x+1];
			else return 0;
			break;
		// ㅏ
		case 18:
			if(check(y, x) && check(y+1, x) && check(y+2, x) && check(y+1, x+1))
				return v[y][x] + v[y+1][x] + v[y+2][x] + v[y+1][x+1];
			else return 0;
			break;
		default:
			return 0;
			break;
	}
}


int main (){
	cin >> n >> m;
	v = vector<vector<int> >(n, vector<int>(m, 0));
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < m ; j++)
		cin >> v[i][j];

	int max = 0;
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < m ; j++)
	for(int k = 0 ; k < 19 ; k++){
		int sum = getSum(i, j, k);
		if (sum > max) max = sum;
	}

	cout << max;
	
	return 0;
}

