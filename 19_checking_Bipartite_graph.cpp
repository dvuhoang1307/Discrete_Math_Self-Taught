#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int V, E;
vector<int> dsk[MAX];
int color[MAX];

void input(){
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int x, y;
        cin >> x >> y;
        dsk[x].push_back(y);
        dsk[y].push_back(x);
    }
    memset(color, -1, sizeof(color));
}

bool check(int u){
    queue<int> q;
    q.push(u);
    color[u] = 0;
    while(!q.empty()){
        int temp = q.front(); q.pop();
        for(int x : dsk[temp]){
            if(color[x] == -1){
                color[x] = 1 - color[temp];
                q.push(x);
            } else if (color[x] == color[temp]) return false;
        }
    }
    return true;
}

bool dfs(int u, int parent){
    color[u] = 1 - color[parent];
    for(int x : dsk[u]){
        if(color[x] == -1){
            if(!dfs(x, u)) return false;
        } else if(color[x] == color[u]) return false;
    }
    return true;
}
/********** Using DFS ************/
//int main(){
//    input();
//    color[0] = 1;
//    for(int i = 1; i <= V; i++){
//        if(color[i] == -1){
//            if(!dfs(i, 0)){
//                cout << "No\n"; return 0;
//            }
//        }
//    }
//    cout <<"Yes\n";
//    return 0;
//}
/*************************/

int main(){
    input();
    for(int i = 1; i <= V; i++){
        if(color[i] == -1){
            if(!check(i)){
                cout << "No\n"; return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}