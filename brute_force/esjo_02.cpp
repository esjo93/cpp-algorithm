#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

int main (){
	int row, col;
	char temp;
	cin >> temp >> row;

	col = int(temp - 'a');
	row--;
	int cnt = 0;
	for (int i = 0 ; i < 8 ; i++)
		if(( row + dx[i] >= 0 && row+dx[i] < 8) &&(col + dy[i] >= 0 && col + dy[i] < 8)) 	
			cnt++;

	cout << cnt << '\n';
	return 0;
}
