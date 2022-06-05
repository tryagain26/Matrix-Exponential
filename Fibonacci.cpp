#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

void mul(ll X[2][2], ll Y[2][2]){
    ll Z[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            Z[i][j] = 0;
            for(int k = 0; k < 2; k++){
                Z[i][j] += (X[i][k]%mod*Y[k][j]%mod)%mod;
                Z[i][j]%=mod;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            X[i][j] = Z[i][j];
        }
    }
}

void power(ll F[2][2] , ll n){
    ll M[2][2] = {{0,1}, {1,1}};


    if(n==1){
        return;
    }
    power(F, n/2);
    mul(F, F);
    if(n&1){
        mul(F, M);
    }


}

ll fib(ll n){
    ll F[2][2] = {{0,1},{1, 1}};
    if(n==0){
        return 0;
    }
    power(F, n);
    return F[0][1]%mod;
}


int main(){

    //freopen("fibonacci.in", "r", stdin);
    //freopen("fibonacci.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll n;
    cin >> n;
    ll F[2][2] = {{0,1},{1, 1}};


    //ll res = fib(n);
    //cout << res << endl;

    power(F, 2);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << F[i][j] << "";
        }
        cout <<endl;
    }
    return 0;
}
