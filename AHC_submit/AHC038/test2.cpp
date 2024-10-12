#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    //入力
    int N,M,V;
    cin >> N >> M >> V;
    vector<vector<char>> S(N,vector<char>(N));
    vector<vector<char>> T(N,vector<char>(N));
    //たこ焼きをキャッチする座標

    vector<pair<int,int>> catch_point;

    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> S[i][j];
        }
    }
    //たこ焼きをドロップする座標
    vector<pair<int,int>> drop_point;

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> T[i][j];
        }
    }

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(S[i][j]=='1' && T[i][j]=='0'){
                catch_point.push_back(make_pair(i,j));
            }

            if(S[i][j]=='0' && T[i][j]=='1'){
                drop_point.push_back(make_pair(i,j));
            }
        }
    }

    //ターン数

    int turn = 0;

    vector<bool> Holding(V,false);

    //armspointが頂点数

    int armspoint = 1;
    ofstream file1("output1.txt");

    cout << armspoint << endl;
    file1 << armspoint << endl;


    int root_x = 0,root_y = 0;
//ここで根に関する情報を持たせて出力

    cout << root_x << " " << root_y << endl;
    file1 << root_x << " " << root_y << endl;


    vector<string> ans;

    int now_x = 0;
    int now_y = 0;

    for(int i = 0 ; i < catch_point.size(); i++){
        int ca_x = catch_point[i].first;
        int ca_y = catch_point[i].second;

        if(now_x < ca_x){
            int diff = ca_x - now_x;
            for(int j = 0; j < diff; j++){
                ans.push_back("D.");
            }
        }

        if(now_x > ca_x){
            int diff = now_x - ca_x;
            for(int j = 0; j < diff; j++){
                ans.push_back("U.");
            }
        }

        if(now_y < ca_y){
            int diff = ca_y - now_y;
            for(int j = 0; j < diff; j++){
                ans.push_back("R.");
            }
        }

        if(now_y > ca_y){
            int diff = now_y - ca_y;
            for(int j = 0 ; j < diff; j++){
                ans.push_back("L.");
            }

        }

        now_x = ca_x;
        now_y = ca_y;

        ans.push_back(".P");

        int dr_x = drop_point[i].first;
        int dr_y = drop_point[i].second;

        if(now_x < dr_x){
            int diff = dr_x - now_x;
            for(int j = 0 ; j < diff; j++){
                ans.push_back("D.");
            }
        }

        if(now_x > dr_x){
            int diff = now_x - dr_x;
            for(int j = 0 ; j < diff; j++){
                ans.push_back("U.");
            }
        }

        if(now_y < dr_y){
            int diff = dr_y - now_y;
            for(int j = 0 ; j < diff; j++){
                ans.push_back("R.");
            }
        }

        if(now_y > dr_y){
            int diff = now_y - dr_y;
            for(int j = 0; j < diff; j++){
                ans.push_back("L.");
            }
        }

        ans.push_back(".P");

        now_x = dr_x;
        now_y = dr_y;

    }


    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << endl;
        file1 << ans[i] << endl;
    }

    file1.close();

    return 0;










}