#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    string S;
    cin >> S;

    int t = S.size();

    if(S[t-3]=='s' && S[t-2]=='a' && S[t-1]=='n')cout << "Yes" << endl;
    else cout << "No" << endl;
    


}