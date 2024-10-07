#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int N,A[100009],B[100009],dp[100009];

int main(){
    cin >> N;

    for(int i = 2; i <= N; i++)cin >> A[i];
    for(int i = 3; i <= N; i++)cin >> B[i];

    dp[1] = 0;
    dp[2] = A[2];

    for(int i = 3; i <= N; i++){
        dp[i] = min(dp[i-1] + A[i],dp[i-2] + B[i]);

    }

    vector<int> Ans;

    int Place = N;
    while(true){
        Ans.push_back(Place);

        if(Place==1)break;

        if(dp[Place-1] + A[Place]==dp[Place]){
            Place -= 1;
        } else{
            Place -= 2;
        }

    }

    reverse(Ans.begin(),Ans.end());

    cout << Ans.size() << "\n";


    for(int i = 0; i < Ans.size(); i++){
        if(i >= 1)cout << " ";
        cout << Ans[i];
    }
    cout << "\n";
    


}