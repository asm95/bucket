#include <bits/stdc++.h>

using namespace std;

#define  un         unsigned
#define  ll         long long
#define  ull        unsigned long long
#define  ii         pair < int, int >
#define  vi         vector < int >
#define  vii        vector < ii >
#define  vll        vector < ll >
#define  pb         push_back
#define  mp         make_pair
#define  ff         first
#define  ss         second
#define  pf(a)      printf("%d\n", a);
#define  sf(a)      scanf("%d", &a);
#define  sf2(a,b)   scanf("%d %d", &a, &b);
#define  sf3(a,b,c) scanf("%d %d %d", &a, &b, &c); 
#define  min(x,y)   ((x)<(y)?(x):(y))
#define  max(x,y)   ((x)>(y)?(x):(y))
#define  debug(x)   {cout<<#x<<": "<<x<<"\n";}
#define  cpy(d,s,n) memcpy((d), (s), (n))
#define  inf 		1000000007

void swint (int &a, int &b) { int t = a; a = b; b = t; }
void swchar (char &a, char &b) { char t = a; a = b; b = t; }

#define MAX_SIZE 100001

vector<vector<int>> graph(MAX_SIZE);
vector<vector<int>> comp(MAX_SIZE);
vector<bool> visited(MAX_SIZE, false);

int n, m, a, b;

void dfs(int v, int i)
{
	visited[v] = true;
	comp[i].push_back(v);

	for (int w : graph[v])
	{
		if (!visited[w])
		{
			dfs(w, i);
		}
	}
}

void connectedComponents()
{
	for (int i=0; i<n; i++)
	{
		if (!visited[i])
		{
			dfs(i, i);
			sort(comp[i].begin(), comp[i].end());
		}
	}
}

int main (void) {
	scanf("%d %d", &n, &m);

	for (int i=0; i<m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	connectedComponents();

	fill(visited.begin(), visited.end(), 0);

	for (int i=0; i<n; i++)
	{
		if (!visited[i])
		{
			for (int w : comp[i])
				printf("%d ", w+1);
			if (!comp[i].empty()) printf("\n");
		}
	}

    return 0;
}