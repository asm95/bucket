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
#define  fill(x, y) memset(x, y, sizeof x)
#define  inf 		1000000007

void swint (int &a, int &b) { int t = a; a = b; b = t; }
void swchar (char &a, char &b) { char t = a; a = b; b = t; }

int weight[1005], value[1005];

int dp(int w, int n)
{
   int K[n+1][w+1];
 
   for (int i = 0; i <= n; i++)
   {
       for (int j = 0; j <= w; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (weight[i-1] <= j)
                 K[i][j] = max(value[i-1] + K[i-1][j-weight[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
       }
   }
 
   return K[n][w];
}

int main (void) {
	int w, n, x;
	scanf("%d %d", &w, &n);

	for (int i=0; i<n; i++)
		scanf("%d", &weight[i]);
	for (int i=0; i<n; i++)
		scanf("%d", &value[i]);

	printf("%d\n", dp(w, n));
	
    return 0;
}