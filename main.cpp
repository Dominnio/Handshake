#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

float connection(int i);
void fillin();
long** handshake;
long N,K;
bool m = 0;

int main()
{
    N = 13; // liczność grupy
    K = 3; // ilość uścisków dłoni każdego człowieka
    fillin();
    for(int i = 0; i<N; i++){
        connection(i);
    }
    if(m == 0){
        cout << "\n\n===============\n\nWszyscy polaczeni\n\n===============";
    }
    return 0;
}

void fillin(){
    int p = 0;
    int k = 0;
    bool c = 0;
    bool w = 0;
    bool d = 0;
    handshake = new long *[N];
    for(int i=0;i<N;i++){
        handshake[i] = new long[K];
        for(int j=0;j<K;j++){
            handshake[i][j] = -1;
        }
    }
    srand(time(NULL));
    int h = 0;
    for(int i=0;i<N;i++){
       // cout << i << "\n";
        h = 0;
        for(int j=0;j<K;j++){
            if(h > N*10){
                break;
            }
            h++;
            if(handshake[i][j] != -1){
                continue;
            }
            p = (rand()%N);
            if(p == i){
                j--;
                continue;
            }
            for(int k=0;k<K;k++){
                if(handshake[i][k] == p){
                    c = 1;
                    break;
                }
            }
            if(c == 1){
                c = 0;
                j--;
                continue;
            }
            k = 0;
            while(handshake[p][k] != -1){
                k++;
                if(k == K){
                    w = 1;
                    break;
                }
            }
            if(w == 1){
                w = 0;
                j--;
                continue;
            }
            handshake[p][k] = i;
            handshake[i][j] = p;
        }
    }
    for(int i=0;i<N;i++){
            cout << i << "  podal reke:  ";
            for(int j=0;j<K;j++){
                if(handshake[i][j] == -1){
                    cout << "";
                    d = 1;
                    continue;
                }
                cout << handshake[i][j] << "    ";
            }
            cout << "\n";
    }
    if(d == 1){
        cout << "\n\n// konieczna modyfikacja wymagan//\n\n";
    }else{
        cout << "\n\n// polaczono zgodnie z wymaganiami //\n\n";
    }
}
float connection(int i){
    int* t_con = new int[N];
    bool* q = new bool[N];
    for(int j=0; j< N; j++){
        t_con[j] = N;
        q[j] = 0;
    }
    t_con[i] = 0;
    int p = N;
    int r = N;
    for(int k = 0; k<N; k++){
        p = N;
        r = N;
        for(int j=0; j<N; j++){
            if(t_con[j] < p && q[j] == 0){
                p = t_con[j];
                r = j;
            }
        }
        if(r == N){
            continue;
        }
        q[r] = 1;
        for(int j = 0; j<K; j++){
            if(q[handshake[r][j]] == 0){
                if(t_con[handshake[r][j]] > t_con[r] + 1){
                    t_con[handshake[r][j]] = t_con[r] + 1;
                }
            }
        }
    }
    cout << "siec polaczen wierzcholka " << i << " : ";
    for(int j = 0; j<N; j++){
        if(t_con[j] == N){
            cout << "i  ";
            m = 1;
            continue;
        }
        cout << t_con[j] << "  ";
    }
    cout <<"\n";
}
