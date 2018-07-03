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


int main (void) {
    int m, n, q, u, v;
    ii dg[100005];
    memset (dg, 0, sizeof (dg));
    scanf ("%d %d %d", &n, &m, &q);

    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &u, &v);
        dg[u].ff++;
        dg[v].ss++;
    }
    for (int i = 0; i < q; i++) {
        scanf ("%d %d", &u, &v);
        if (u == 1) printf("%d\n", dg[v].ff);
        else printf("%d\n", dg[v].ss);
    }

    return 0;
}
