#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

vector<int> a[MAX];
int V, E;
bool visited[MAX];
vector<int> topo;
int deg_in[MAX];

void inp(){
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        ++deg_in[y];
    }
    memset(visited, false, size(visited));
}
void kahn(){
    queue<int> q;
    for(int i = 1; i <= V; i++){
        if(deg_in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : a[v]){
            --deg_in[x];
            if(deg_in[x] == 0) q.push(x);
        }
        topo.push_back(v);
    }
    for(auto x : topo) cout << x << " ";
}
void by_dfs(int i){
    visited[i] = true;
    for(int x : a[i]){
        if(!visited[x]) {
            by_dfs(x);
        }
    }
    topo.push_back(i);
}

int main(){
    inp();
    kahn();
}