#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N;
    cin >> N;
    vector<int> A(N),ans(N);
    rep(i,N)cin >> A[i];

    stack<pair<int,int>> sta;

    //スタック変化の再現

    for(int i = 0; i < N; i++){
        if(i>=1){
            sta.push(make_pair(i-1,A[i-1]));
            while(!sta.empty()){
                int kabuka = sta.top().second;
                if(kabuka <= A[i])sta.pop();
                else break;

            }


        }

        if(!sta.empty()){
            ans[i] = sta.top().first + 1;
        }else ans[i] = -1;
    }

    for(int i = 0; i < N; i++){
        if(i>=1)cout << " ";
        cout << ans[i];
    }
    cout << endl;



}