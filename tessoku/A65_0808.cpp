#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

vector<int> G[100009];
int N,A[100009],ans[100009];


int main(){
    cin >> N;
    for(int i = 2; i <= N; i++){
        cin >> A[i];
        G[A[i]].push_back(i);
    }

    for(int i = N; i >= 1; i--){
        ans[i] = 0;
        for(int j = 0; j < G[i].size(); j++){
            ans[i] += ans[G[i][j]] + 1;
        }
    }

    for(int i = 1; i <= N; i++){
        if(i>=2)cout << " ";
        cout << ans[i];
    }
    cout << endl;






}