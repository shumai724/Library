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

    int armspoint = V;
    ofstream file1("output1.txt");

    cout << armspoint << endl;
    file1 << armspoint << endl;


    int root_x = 0,root_y = 0;

//ここで根に関する情報を持たせて出力
    rep(i,armspoint - 1){
        cout << i << " " << 2;
        file1 << i << " " << 2;
    }


    cout << root_x << " " << root_y << endl;
    file1 << root_x << " " << root_y << endl;

//答えを格納するvector
    vector<string> ans;
//現在の頂点0の位置
    int now_x = 0;
    int now_y = 0;
//arms_locが各点における座標
    vector<pair<int,int>> arms_loc(armspoint);
    rep(i,armspoint){
        arms_loc[i] = make_pair(0,i*2);
    }

//X方向とY方向に移動させるときのベクトルを作る
    vector<int> DX = {0,1,0,-1};
    vector<int> DY = {1,0,-1,0};
    vector<char> DIR = {'R','D','L','U'};

//訪問したことがあるかどうかを判定するvisited
    vector<vector<bool>> visited(N,vector<bool>(N,false));

    int remain_tako = catch_point.size();

    while(remain_tako != 0){
        int point = 0;
        //pointが評価関数
        //たこ焼きをとったり適切な位置で離すと高得点になる
        int direction;

        for(int a = 0; a < 4; a++){
            //scoreの初期化
            int score = 0;
            for(int i = 0 ; i < armspoint; i++){
                //平行移動後のそれぞれのX座標、Y座標
                int xx = arms_loc[i].first + DX[a];
                int yy = arms_loc[i].second + DY[a];

                //範囲外参照を取り除く
                if(xx < 0 || xx >= N)continue;
                if(yy < 0 || yy >= N)continue;

                //今何も持っていなくて、今の座標にたこ焼きがある場合、
                //つかんだことにして得点を与える

                if(Holding[i]==false){
                    if(S[xx][yy]=='1' && T[xx][yy]=='0'){
                        score += 1000;
                    }
                }

                //今たこ焼きをつかんでいて、今の座標にたこ焼きを落としたい場合
                //落としたことにして得点を与える

                if(Holding[i] == true){
                    if(S[xx][yy]=='0' && T[xx][yy]=='1'){
                        score += 1000;
                    }
                }
                //どっちにも引っかからなかった場合どうするか
                //まだ訪れていない地点であれば得点を少し与える
                //ただ、分断されるとどうしようもなさそう

                if(visited[xx][yy]==false){
                    score += 10;
                }
                //スコアが0の時に最寄りのたこやきがあるところにいきたい

                if(score==0){
                    int dis = 1e9;

                    if(Holding[i]==false){
                        
                        for(int j = 0; j < catch_point.size(); j++){
                            int ca_x = catch_point[j].first;
                            int ca_y = catch_point[j].second;
                            int d = abs(xx - ca_x) + abs(yy - ca_y);
                            dis = min(dis,d);
                        }

                    }else{

                        for(int j = 0 ; j < drop_point.size(); j++){
                            int dr_x = drop_point[j].first;
                            int dr_y = drop_point[j].second;
                            int d = abs(xx - dr_x) + abs(yy - dr_y);
                            dis = min(dis,d);
                        }
                    }

                    score += 10/(dis+1);



                }



            }
            //スコア更新をしたらpoint=SCOREにして
            //移動する向きも更新

            if(score > point){
                point = score;
                direction = a;
            }


        }

        //ここで移動する方向が確定したので実際に動かす
        //ANSに格納するstring ssを作る

        string ss;
        
        //動かす方向を入力
        ss += DIR[direction];

        //それぞれのアームに対して反映させる
        //操作の有無を確認するためのvectorをつくる

        vector<bool> change(armspoint,false);

        for(int i = 0; i < armspoint; i++){
            int xx = arms_loc[i].first + DX[direction];
            int yy = arms_loc[i].second + DY[direction];

            arms_loc[i].first = xx;
            arms_loc[i].second = yy;
            //範囲外参照の時にcontinueさせる

            if(xx < 0 || xx >= N)continue;
            if(yy < 0 || yy >= N)continue;
            //訪れました
            visited[xx][yy] = true;

            //手が空いてて
            if(Holding[i]==false){
                //そこにたこ焼きがあったらとる
                if(S[xx][yy]=='1' && T[xx][yy]=='0'){
                    Holding[i] = true;
                    change[i] = true;
                    S[xx][yy] = '0';
                    catch_point.erase(catch_point.begin() + i);
                }
            }

            //手が空いてなくて
            if(Holding[i]==true){
                //そこにたこ焼きを置くのなら置く
                if(S[xx][yy]=='0' && T[xx][yy]=='1'){
                    Holding[i] = false;
                    change[i] = true;
                    T[xx][yy] = '0';
                    drop_point.erase(catch_point.begin() + i);
                }
            }

        }

        for(int i = 1; i < armspoint; i++){
            ss += ".";
        }

        for(int i = 0 ; i < armspoint; i++){
            if(change[i]){
                ss += "P";
            }else{
                ss += ".";
            }
        }
        

        ans.push_back(ss);

        if(catch_point.size()==0 && drop_point.size()==0)break;


    }


    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << endl;
        file1 << ans[i] << endl;
    }

    file1.close();

    return 0;


}