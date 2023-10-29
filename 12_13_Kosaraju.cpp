#include <bits/stdc++.h>
using namespace std;
/*
Bước 1: Gọi DFS trên đồ thị ban đầu và lưu thứ tự duyệt đỉnh vào trong 1 stack
Bước 2: Xây dựng đồ thị lật ngược Transpose Graph của đồ thị ban đầu
Bước 3: Lần lượt pop các đỉnh trong stack ra và gọi DFS để liệt kê các thành phần liên thông
 */
#define MAX 10001

int V, E;
vector<int> dsk[10001];
vector<int> ng_dsk[MAX];
bool visited[MAX];

void inp(){
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int x, y; cin >> x >> y;
        dsk[x].push_back(y);
        ng_dsk[y].push_back(x);
    }
}

stack<int> st;
void dfs1(int x){
    visited[x] = true;
    for(int u : dsk[x]){
        if(!visited[u]){
            dfs1(x);
        }
    }
    //da duyet xong dinh x
    cout << x << " ";
    st.push(x);
}

void dfs2(int y){
    visited[y] = true;
    for(int v : ng_dsk[y]){
        if(!visited[v]){
            cout << v << " ";
            dfs2(v);
        }
    }
}

void SCC(){
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            dfs1(i);
        }
    }

    memset(visited, false, sizeof(visited));
    int count_CC = 0;
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        if(!visited[temp]){
            ++count_CC;
            dfs2(temp);
            cout << endl;
        }
    }
}
int main(){
    inp();
    SCC();
}