#include<bits/stdc++.h>
using namespace std;

vector<int> e[200010];
bool flag[200010];
deque<int> deq;
bool stop;

void dfs(int k, int to){
  if(!stop)deq.push_back(k);
  if(k == to)stop = true;
  flag[k] = true;
  int sz = e[k].size();
  for(int i=0; i<sz; i++){
    if(!flag[e[k][i]]){
      dfs(e[k][i],to);
    }
  }
  if(!stop)deq.pop_back();
  return;
}


int main(void){
  int n,x,y;
  int u,v;

  cin >> n >> x >> y;
  for(int i=0; i<n-1;i++){
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  for(int i=1; i<=n; i++) flag[i]=false;
  stop = false;

  dfs(x,y);

  while(!deq.empty()){
    cout << deq.front();
    deq.pop_front();
    if(deq.empty()) cout << endl;
    else cout << " ";
  }
  return 0;



}