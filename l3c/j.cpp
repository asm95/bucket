#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

// Sequencia original
int sequence[MAX];

// Registra a LIS (que sempre está ordenada)
int lis_seq[MAX];

int lis(int N) {

    // Tamanho do lis_seq, inicialmente está vazio
    int lis_size = 0;

    for (int i = 0; i < N; ++i) {

        // Encontra a menor posição que é possível inserir o i-ésimo termo na LIS
        int p = lower_bound(lis_seq, lis_seq + lis_size, sequence[i]) - lis_seq;

        lis_seq[p] = sequence[i];
        lis_size = max(lis_size, p + 1);
    }

    return lis_size;
}


int main(){
    int n, aux;
    cin >> n;
    for(int i = 0; i < n; i++)    {
        cin >> aux;
        sequence[i] = aux;
    }
    
    cout << lis(n)<<endl;
}