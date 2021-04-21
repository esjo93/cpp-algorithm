#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<int> > spread(vector<vector<int> > mat){
	int n = mat.size();
	int m = mat[0].size();

	vector<vector<int> > result = mat;
	int row, col;
	do{
		mat = result;
		for(int i = 0; i < n ; i ++){
			for(int j = 0 ; j < m ; j++){
				if (result[i][j] == 2)
					for (int k = 0 ; k < 4 ; k++){
						row = i + dx[k];
						col = j + dy[k];
						if ((row >=0 && row < n) && (col >= 0  && col < m))
							if (!result[row][col]) result[row][col] = 2;
					}
				else continue;
			}
		}
	}while(mat != result);

	return result;
}

int count(vector<vector<int> > mat){
	int cnt = 0;
	for(auto i : mat)
		for(auto j : i)
			if (!j) cnt++;
	return cnt;
}

vector<pair<int, int> > getZeroLoc(vector<vector<int> > mat){
	vector<pair<int, int> > arr;
	for (int i = 0 ; i < mat.size() ; i++)
		for(int j = 0 ; j < mat[0].size() ; j++)
			if(!mat[i][j]) arr.push_back(pair<int,int>(i, j));
	return arr;
} 

int main (){
	int n, m;
	cin >> n >> m;
	
	vector<vector<int> > mat(n, vector<int>(m));
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> mat[i][j];
		}
	}
		
	vector<pair<int, int> > arr = getZeroLoc(mat);
	int best = 0;
	int zeroCnt;
	vector<vector<int> > temp = mat;
	for(int i = 0 ; i < arr.size() - 2 ; i++){
		for(int j = i+1 ; j < arr.size() -1; j++){
			for(int k = j+1 ; k < arr.size() ; k++){
				temp[arr[i].first][arr[i].second] = 1;
				temp[arr[j].first][arr[j].second] = 1;
				temp[arr[k].first][arr[k].second] = 1;
				zeroCnt = count(spread(temp));
				if (zeroCnt > best) best = zeroCnt;
				temp = mat;
			}
		}
	}

	cout << best << '\n';
	
	return 0;
}

