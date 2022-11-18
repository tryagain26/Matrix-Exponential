#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a;  i < b; i++)
const int N  = 3;
#define ll long long
const ll mod = 1000000007;

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

void pow(ll a[3][3], ll n){
	ll f[3][3] = {{3 , 1, 3}, {1, 0, 0}, {0, 1, 3}};

	
	if(n==1){	
		return;
	}
	pow(a, n/2);
	mul(a, a);

	if(n&1){
		mul(a, f);
	}


}



ll getVal(ll n){
	ll d[3][3] = {{3 , 1, 3}, {1, 0, 0}, {0, 1, 3}};

	pow(d, n-2);

	return ((10*d[0][0])%mod  + (3*d[0][1])%mod + (d[0][2])%mod)%mod;

	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin);

	ll n;
	cin >> n;
	if(n==0){
		cout << 1;
		return 0;
	}
	if(n==1){
		cout << 3;
		return 0;
	}
	if(n==2){
		cout << 10;
		return 0;
	}

	ll ans = getVal(n);
	cout << ans;
	return 0; 
}