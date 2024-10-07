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

    queue<string> que;

    rep(i,Q){
        int query;
        cin >> query;

        if(query==1){
            string x;
            cin >> x;
            que.push(x);
        }

        if(query==2){
            cout << que.front() << endl;
        }

        if(query==3){
            que.pop();
        }
    } 

    return 0;
}