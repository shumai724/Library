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
    map<string,int> Ma;

    rep(i,Q){
        int query;
        cin >> query;

        if(query==1){
            string S;
            int score;
            cin >> S >> score;
            Ma[S] = score;


        }

        if(query==2){
            string S;
            cin >> S;
            cout << Ma[S] << endl;
        }

    }
    return 0;

}