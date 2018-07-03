#include <bits/stdc++.h>

using namespace std;

#define GRAPH_MAX_SIZE 1000100

vector<int> graph[GRAPH_MAX_SIZE];

int n,x;

int bfs(int start){
    
    queue<pair<int, int>> q;
    q.push({start, 0});

    vector<bool> visited(GRAPH_MAX_SIZE,false);
    

    while(q.size()){//Enquanto houver vértices na fila
		auto u = q.front();
        q.pop();

		if(u.first == x){
			return u.second;
		}

		visited[start] = true;
		
		if((u.first*2 < 10e5) and (u.first*2>0) and !(visited[u.first*2])){
			q.push({u.first*2, u.second+1});
			visited[u.first*2] = true;
		}

		if((u.first-3 < 10e5) and (u.first-3>0) and !(visited[u.first-3])){
			q.push({u.first-3, u.second+1});
			visited[u.first-3] = true;
		}
	}

	return -1;
		
}

int main(){

	cin >> n >> x;

	cout << bfs(n) << endl;
	
	return 0;
}