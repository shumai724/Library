//https://atcoder.jp/contests/adt_easy_20240516_3/tasks/abc311_c//

#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }

  vector<int> fl(n+1,0),s;
  int v=1; // any vertex is ok to start
  while(fl[v]==0){
    fl[v]=1;
    s.push_back(v);
    v=a[v];
  }

  vector<int> res;
  for(auto &nx : s){
    if(nx==v){v=-1;}
    if(v==-1){res.push_back(nx);}
  }
  cout << res.size() << "\n";
  for(int i=0;i<res.size();i++){
    if(i){cout << " ";}
    cout << res[i];
  }cout << "\n";
  return 0;
}


