#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i< b; i++)
const ll mod = 1e15 +7;

void mul(ll X[3][3], ll Y[3][3]){
    ll Z[3][3];
    rep(i, 0, 3){
        rep(j, 0, 3){
            Z[i][j] = 0;
            rep(k, 0, 3){
                Z[i][j] += ((X[i][k])%mod *Y[k][j]%mod)%mod;
                Z[i][j]%=mod;
            }
        }
    }
    rep(i, 0, 3){
        rep(j, 0, 3){
            X[i][j] = Z[i][j];
        }
    }
}
void power(ll F[3][3], ll n){
    ll M[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1 , 0}};
    if(n==1){
        return;
    }
    power(F, n/2);
    mul(F, F);
    if(n&1){
        mul(F, M);
    }
}

ll Tri(ll n){
    if(n==0 || n==1){
        return 0;
    }
    ll F[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1 , 0}};
    //ll base[3][3] = {{3}, {2}, {1}};
    power(F, n-2);

    return F[0][0]%mod;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    freopen("Tribonacci.in", "r", stdin);
    freopen("Tribonacci.out", "w", stdout);
    ll n;
    cin >> n;
    cout << Tri(8) << " ";
    return 0;

}
