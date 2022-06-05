#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e9 + 7;
#define REP(i, a, b) for(int i = a; i < b; i++)

void mul(ll X[6][6], ll Y[6][6]){
    ll Z[6][6];
    REP(i, 0, 6){
        REP(j, 0, 6){
            Z[i][j] = 0;
            REP(k, 0, 6){
                Z[i][j] += (X[i][k]%M*Y[k][j]%M)%M;
            }
        }
    }
    REP(i, 0, 6){
        REP(j, 0, 6){
            X[i][j] =Z[i][j];
        }
    }
}

void power(ll F[6][6], ll n){
    ll X[6][6] = {{1, 1, 1 , 1, 1, 1}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0 , 0}, {0, 0, 1, 0 , 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}};
    if(n==1){
        return;
    }
    power(F, n/2);
    mul(F, F);
    if(n&1){
        mul(F, X);
    }
}

ll dice(ll n){
    ll F[6][6] = {{1, 1, 1 , 1, 1, 1}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0 , 0}, {0, 0, 1, 0 , 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}};

    ll B[6][6] = {{32}, {16}, {8}, {4}, {2}, {1}};
    if(n<= 5){
        return B[5-n][0];
    }
    power(F, n-5);

    mul(F, B);
    return F[0][0]%M;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll n;
    cin >> n;
    ll X[6][6] = {{1, 1, 1 , 1, 1, 1}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0 , 0}, {0, 0, 1, 0 , 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}};
    ll ans = dice(n-1);
    cout << ans;
    return 0;
}
