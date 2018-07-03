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

int m, n;
bool visited[500][500];

void dfs (int x, int y) {
    visited[x][y] = true;
    if (x + 1 < n && !visited[x + 1][y]) dfs (x + 1, y);
    if (x > 0     && !visited[x - 1][y]) dfs (x - 1, y);
    if (y + 1 < m && !visited[x][y + 1]) dfs (x, y + 1);
    if (y > 0     && !visited[x][y - 1]) dfs (x, y - 1);
}

int main (void) {
    char c;
    int components = 0;
    scanf ("%d %d", &n, &m);
    memset (visited, false, sizeof (visited));
    getchar ();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf ("%c", &c);
            if (c == '#') visited[i][j] = true;
        }
        getchar ();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                components++;
                dfs (i, j);
            }
        }
    }
    printf("%d\n", components);

    return 0;
}
