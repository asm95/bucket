#include <bits/stdc++.h>

using namespace std;

#define  un         unsigned
#define  ll         long long
#define  ull        unsigned long long
#define  ii         pair < int, int >
#define  vi         vector < int >
#define  vii        vector < ii >
#define  pb         push_back
#define  mp         make_pair
#define  mt         make_tuple
#define  ff         first
#define  ss         second
#define  PRINT(x)   {cout<<#x<<": "<<x<<"\n";}
#define  SET(k,v)   memset((k), (v), sizeof((k)))
#define  CPY(d,s,n) memcpy((d), (s), (n))
#define  mod        (ll)((1e9) + 7)
#define  inf        INT_MAX

int min (int a, int b) { return a < b ? a : b; }
int max (int a, int b) { return a > b ? a : b; }

void bfs(vector < vi > &graph, int start, int dist[], int n){
    bool visited[n];
    queue < int > q;

    memset (visited, false, sizeof(visited));
    visited[start] = true;
    dist[start] = 0;
    q.push (start);

    while (!q.empty()) {
        int u = q.front ();
        q.pop ();

        for (int v: graph[u]) {
            if (!visited[v]) {
                dist[v] = dist[u] + 1;
                q.push (v);
                visited[v] = true;
            }
        }
    }
}

int main (void) {
    int m, n, k, q, u, v;
    scanf ("%d %d", &n, &m);
    scanf ("%d %d", &k, &q);
    vector < vi > graph (n);
    int dist[n];
    memset (dist, -1, sizeof (dist));

    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &u, &v);
        graph[u - 1].push_back (v - 1);
        graph[v - 1].push_back (u - 1);
    }

    bfs (graph, k - 1, dist, n);
    for (int i = 0; i < q; i++) {
        scanf ("%d", &u);
        if (dist[u - 1] == -1) printf("infinito\n");
        else printf("%d\n", dist[u - 1]);
    }

    return 0;
}
