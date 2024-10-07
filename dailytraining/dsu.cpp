#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;


int main(){
  int N,M;
  cin >> N >> M;

  dsu g(N);

  for(int i = 0; i < M; i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    g.merge(a,b);
  }

  int ans = g.groups().size() - 1;
  cout << ans << endl;





}