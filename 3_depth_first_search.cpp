#include <bits/stdc++.h>
using namespace std;

vector<int> dsk[100001];
bool visited[100001];
int V, E;
int mtk[1001][1001];

void inp1(){
    cin >> V >> E;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= E; i++){
        int x, y;
        cin >> x >> y;
        dsk[x].emplace_back(y);
        dsk[y].emplace_back(x);
    }
}
void depth_first_search_1(int pos){
    cout << pos << " ";
    visited[pos] = true;
    for(int i = 0; i < dsk[pos].size(); i++){
        if(visited[dsk[pos][i]] == false) depth_first_search_1(dsk[pos][i]);
    }
}

void inp2(){
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int x, y;
        cin >> x >> y;
        ++mtk[x][y];
        ++mtk[y][x];
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int pos){
    cout << pos << " ";
    visited[pos] = true;
    for(int i = 1; i <= V; i++){
        if(mtk[i][pos] == 1 && !visited[i]){
            dfs(i);
        }
    }
}


vector<pair<int,int>> dsc;

void inp3()
{   memset(visited, false, sizeof(visited));
    dsc.emplace_back(make_pair(0,0));
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int x, y;
        cin >> x >> y;
        dsc.emplace_back(make_pair(x, y));
        dsc.emplace_back(make_pair(y, x));
    }
}
void dfs2(int pos){
    cout << pos << " ";
    visited[pos] = true;
    for(int i = 0; i < dsc.size(); i++){
        if(dsc[i].first == pos && !visited[dsc[i].second]){
            dfs2(dsc[i].second);
        }
    }
}

int main(){
//    inp1();
//    depth_first_search_1(1);
//
    inp2();
    dfs(1);

//    inp3();
//    dfs2(2);
}