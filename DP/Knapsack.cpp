#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
    
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forn(i, arr, b) for (long long i = arr; i < b; i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mid(l,r)        (l+(r-l)/2)
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define dtb(n,x) bitset<n>(x).to_string()
#define inp(arr, n)  for(ll i = 0; i < n; i++) cin >> arr[i]
#define inp_1(arr, n)  for(ll i = 1; i <= n; i++) cin >> arr[i]
    
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef pair<int, int> pi;
    
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
    
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef tuple<int, int, int> iii;
    
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int MX = 100001;
    
int power(long long x, unsigned int y, int p = MOD){
    int res = 1;
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
    
vector <bool> prime;
    
void SieveOfEratosthenes(long long n){
    prime.assign(n+1,true);
    for (int p = 2; p * p <= n; p++){
        if (prime[p] == true){
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1] = false;
}

class Knapsack
{
public:
  long long capacity;
  vector<long long> Weight;
  vector<long long> Values;

  Knapsack(long long capacity , vector<long long> Weight , vector<long long> Values){
    this->capacity = capacity;
    this->Weight = Weight;
    this->Values = Values;
  }

  long long Zero_One(){

    int N = Weight.size();
    vector<vector<long long>> DP(N + 1 , vector<long long> (capacity + 1 , 0));
    for (int i = 1; i <= N; ++i)
    {
      int W = Weight[i-1] , V = Values[i-1];
      for (int j = 0; j <= capacity; ++j)
      {
        DP[i][j] = DP[i-1][j];
        if(j >= W && (DP[i-1][j-W] + V > DP[i][j])){
          DP[i][j] = DP[i-1][j-W] + V;
        }
      }
    }

    int sz = capacity;

    vector<long long> Selected;
    for (int i = N; i > 0; --i)
    {
      if (DP[i][sz] != DP[i-1][sz])
      {
        Selected.PB(i);
        sz -= Weight[i-1];
      }
    }

    return DP[N][capacity];
  }
  //~Knapsack();
  
};


int main() {
    FAST
    int t = 1;
    cin >> t;
    while (t--) {
    }
}
