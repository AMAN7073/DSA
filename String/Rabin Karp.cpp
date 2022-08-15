#include <bits/stdc++.h>
using namespace std;
    
#define PB push_back
#define MP make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define eb emplace_back

    
const int MOD = 1e9 + 9;
const long long INF = 1e18;
const int MX = 100001;


vector<int> rabin_karp(string s,string t){
    long long p = 31;
    int T = t.length() , S = s.length();

    vector<long long> pow(T,1);
    for(int i=1;i<T;i++)
        pow[i] = (pow[i-1] * p) % MOD;
    
    vector<long long> h_t(T+1,0);
    for(int i=0;i<T;i++)
        h_t[i+1] = (h_t[i] + (t[i] - 'a' + 1) * pow[i]) % MOD;

    long long h_s = 0;
    for(int i=0;i<S;i++)
        h_s += ((s[i] - 'a' + 1) * pow[i]) % MOD;
    
    vector<int> occurences;
    for(int i=0;i<=(T - S);i++){
        long long temp = (h_t[i+S] - h_t[i] + MOD) % MOD;
        if(temp == (h_s * pow[i] % MOD)){
            occurences.push_back(i);
        }
    }

    return occurences;
}


int main() {
  FAST
  int t = 1;
  //cin >> t;
  while (t--) {
    string t,s;
    cin>>t>>s;
    vector<int> ans = rabin_karp(s,t);
    cout<<ans.size()<<endl; 
  }
}
