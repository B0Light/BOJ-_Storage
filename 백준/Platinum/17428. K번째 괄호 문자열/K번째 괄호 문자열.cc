#include<cstdio>
#include<cstring>
#include<iostream>

typedef long long ll;
const int MAX_N = 50;

int N;
ll dp[MAX_N][MAX_N];
using namespace std;

ll rec(int p, int r){
    if(r < 0) return 0;
    if(p == N) return !r;

    ll& ret = dp[p][r];
    if(ret != -1) return ret;
    ret = rec(p+1,r+1); // p+1위치에 ( 를 넣음
    if(r) ret += rec(p+1,r-1); // '(' 이 더 많다면 p+1위치에 ) 를 넣음
/*
    cout << endl << "p : " << p << " r : " << r << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%2d ",dp[i][j]);
        }
        cout << endl;
    }
*/
    return ret;
}

void f(int p, int r, ll K){
    if(p == N) return;
    if(rec(p+1,r+1) <= K) {
        printf(")");
        f(p+1, r-1, K - rec(p+1,r+1));
    } else {
        printf("(");
        f(p+1, r+1, K);
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    ll K;

    scanf("%d%lld",&N,&K);
    if(rec(0, 0) <= K) puts("-1");
    else f(0,0,K);

    return 0;
}