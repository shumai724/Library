#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    
    int N,M;
    cin >> N >> M;
    vector<int> A(M),B(M);
    for(int i = 0 ; i < M; i++)cin >> A[i] >> B[i];
    
    vector<pair<int,int>> point(N);
    
    for(int i = 0 ; i < N; i++){
        point[i].second = i+1;
    }
    for(int i = 0 ; i < M; i++){
        point[A[i]-1].first += point[B[i]-1].first + 1;
    }
    
    sort(point.begin(),point.end());
    reverse(point.begin(),point.end());
    
    vector<int> ans;
    
    for(int i = 0 ; i < N-1; i++){
        int f_point = point[i].first;
        int s_point = point[i+1].first;
        if(f_point==s_point){
            cout << -1 << "\n";
            return 0;
        }else{
            ans.push_back(point[i].second);
        }
        
        
        if(i==N-2)ans.push_back(point[i+1].second);
    }
    
    for(int i = 0 ; i < N; i++){
        cout << ans[i];
        if(i != N-1)cout << ' ';
    }
    
    cout << "\n";
    return 0;
    
    
    

}