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
    ll q, x, fat[1000005];
    scanf ("%lld", &q);

    fat[0] = 1ll;
    for (ll i = 1ll; i <= 1000000ll; i++) {
        fat[i] = i * fat[i-1];
        fat[i] %= mod;
    }

    for (ll i = 0; i < q; i++) {
        scanf ("%lld", &x);
        printf("%lld\n", fat[x]);
    }

    return 0;
}
