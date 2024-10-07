#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int Q;
    cin >> Q;

    set<int> S;

    rep(i,Q){
        int query;
        cin >> query;
        if(query==1){
            int x;
            cin >> x;
            S.insert(x);


        }

        if(query==2){
            int x;
            cin >> x;
            S.erase(x);
        }

        if(query==3){
            int x;
            cin >> x;

            auto itr = S.lower_bound(x);

            if(itr==S.end())cout << -1 << endl;
            else cout << (*itr) << endl;
        }
    }
}