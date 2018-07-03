#include <bits/stdc++.h>
using namespace std;

long long memo[100001];
vector<int> values;

int dp(int indice_atual, int n, int x){
    if(memo[indice_atual]!=-1) return memo[indice_atual];
    if((indice_atual+x)>n) return 0;

    int val_min=10000000;

    for(int i = indice_atual; i < indice_atual+x; i++){
        val_min = min(val_min, values[i]);
    }
    
    int pegar = val_min+dp(indice_atual+x, n, x);
    int nao_pegar = dp(indice_atual+1, n, x);

    return memo[indice_atual] = max(pegar, nao_pegar); 
}

int main(){
	memset(memo, -1, sizeof memo);	
	int n,x,aux;
    cin >>n>>x;
    
    for(int i = 0; i < n; i++){
        cin >> aux;
        values.push_back(aux);
    }    
    cout << dp(0, n, x) <<endl;

	return 0;
}