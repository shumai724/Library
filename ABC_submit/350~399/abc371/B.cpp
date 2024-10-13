#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N,M;
    cin >> N >> M;

    vector<int> A(N);

    rep(i,M){
        int a;
        string B;
        cin >> a >> B;
        a--;

        if(A[a] == 0 && B == "M"){
            cout << "Yes" << endl;
            A[a] += 1;
        }
        else cout << "No" << endl;
    }

    return 0;

 



}