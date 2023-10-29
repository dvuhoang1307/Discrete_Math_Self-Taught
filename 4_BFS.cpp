#include <bits/stdc++.h>
using namespace std;
int E;
vector<int> dsk[100001];
bool visited[100001];

void inp(){
    cin >> E;
    for(int i = 1; i <= E; i++){
        int x, y;
        cin >> x >> y;
        dsk[x].emplace_back(y);
        dsk[y].emplace_back(x);
    }
}

queue<int> q;
void bfs(int i){
    cout << i << " ";
    visited[i] = true;
    q.push(i);

    while(!q.empty()){
        int u = q.front();
        for(auto x : dsk[u]){
            if(!visited[x]){
                cout << x << " ";
                visited[x] = true;
                q.push(x);
            }
        }
        cout << endl;
        q.pop();
    }
}
int main(){
    inp();
    bfs(1);
}