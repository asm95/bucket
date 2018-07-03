#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
typedef long long ll;

const int N = 100005;
const ll oo = 1e18;

ll d[N]; // vetor onde guardamos as distancias

int n; // numeros de vertices

// lista de adjacencias guarda
// pair <vertice para onde a aresta vai, peso da aresta>
vector<pair<int, ll>> g[N];

void dijkstra(int start){

	// inicialmente a distancia do vertice
	// start para todo os outros é infinita
	for(int u = 1; u <= n; u++)
		d[u] = oo;

	// fila de prioridade de pair<ll, int>, mas que o
	// menor pair fica no topo da fila
	// guardamos um pair <distancia ate o vertice, vertice>
	// assim o topo da fila sempre é o vertice com menor distancia
	priority_queue<pair<ll, int>, vector<pair<ll, int>>,
		greater<pair<ll, int>> > pq;

	d[start] = 0;
	pq.emplace(d[start], start);

	ll dt, w;
	int u, v;
	while(!pq.empty()){
		tie(dt, u) = pq.top(); pq.pop();

		for(auto edge : g[u]){
			tie(v, w) = edge;

			// se a distancia ate o u somado com o peso
			// da aresta é menor do que a distancia ate o v que
			// tinhamos antes, melhoramos a distancia ate o v
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.emplace(d[v], v);
			}
		}
	}
}

int main(){

    int qt_v, qt_ar, k, q, a, b, start, aux, c;
    cin >> qt_v >> qt_ar >> k >> q;
    n = qt_v;

    ii ar_aux;
    
    for(int i = 0; i < qt_ar; i++){
        cin >>  a >> b >> c;
        ar_aux.first = b; // valor
        ar_aux.second = c; // obs: peso sempre 1 pq o grafo eh n direcionado.

        g[a].push_back(ar_aux); // inserindo no grafo feito de array de vector de pair.

        ar_aux.first = a; // valor
        g[b].push_back(ar_aux); // inserindo no grafo feito de array de vector de pair.
    }

    start = k;
    dijkstra(k);

	for(int u = 1; u <= q; u++){
        cin >> aux;
        if(d[aux] !=  1000000000000000000)
		    printf("%lld\n", d[aux]);
        else
		    printf("infinito\n");
	}
    
}