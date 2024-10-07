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

    priority_queue<int,vector<int>,greater<int>> pq;

    rep(i,Q){
        int query;
        cin >> query;

        if(query==1){
            int p;
            cin >> p;
            pq.push(p);
        }

        if(query==2){
            int ans = pq.top();
            cout << ans << endl;
        }

        if(query==3){
            pq.pop();

        }

    }
}