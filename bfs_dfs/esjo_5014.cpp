#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
/*
 * f: building height
 * s: current
 * g: goal
 * u: up unit
 * d: down unit
*/
queue<int> qy;
queue<int> qc;
vector<bool> visited;

bool check(int y){
	if ( y < 1 || y > F ) return false;
	
	if (!visited[y]) return true;
	else return false;
}

int main (){
	cin >> F >> S >> G >> U >> D;
	
	int choice[2] = {U, -D};

	if (G > S && U == 0){
		cout << "use the stairs";
		return 0;
	}
	else if (G < S && D == 0){
		cout << "use the stairs";
		return 0;
	}
	else if (G == S) {
		cout << 0;
		return 0;
	}

	visited = vector<bool>(F+1, false); 
	visited[0] = true;

	qy.push(S);
	qc.push(0);
	visited[S] = true;
	
	int y, c;
	while(!qy.empty()){
		y = qy.front(); qy.pop();
		c = qc.front(); qc.pop();

		if (y == G) {
			cout << c;
			return 0;
		}
		for (int i = 0 ; i < 2 ; i++){
			int newy = y + choice[i];
			if (check(newy)){
				qy.push(newy); 
				qc.push(c+1);
				visited[newy] = true;
			}
			else continue;
		}
	}

	cout << "use the stairs";
	return 0;
}

