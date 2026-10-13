#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of locations: ";
    cin>>n;
    int adj[20][20],list[20][20],deg[20]={0};
    cout<<"Enter adjacency matrix:"<<endl;;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
            if(adj[i][j]){
                list[i][deg[i]++]=j;}
        }
    }
    int start;
    cout<<"Enter starting location (0 for A): ";
    cin>>start;
    cout<<"Adj Matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }cout<<endl;
    }
    bool visited[20]={false};
    int stack[20],top=-1;
    stack[++top]=start;
    cout<<"DFS: ";
    while(top!=-1){
        int u=stack[top--];
        if(!visited[u]){
            visited[u]=true;
            cout<<char('A'+u)<<"->";
            for(int i=n-1;i>=0;i--){
                if(adj[u][i]&&!visited[i]){
                    stack[++top]=i;}
            }
        }
    }cout<<endl;
    for(int i=0;i<n;i++){visited[i]=false;}
    int queue[20],front=0,rear=0;
    queue[rear++]=start;
    visited[start]=true;
    cout<<"BFS: ";
    while(front<rear){
        int u=queue[front++];
        cout<<char('A'+u)<<"->";
        for(int i=0;i<deg[u];i++){
            int v=list[u][i];
            if(!visited[v]){
                visited[v]=true;
                queue[rear++]=v;
            }
        }
    }cout<<endl;
    return 0;
}
/*6
0 1 1 0 0 0
1 0 1 1 0 0
1 1 0 0 1 0
0 1 0 0 0 1
0 0 1 0 0 1
0 0 0 1 1 0

Enter number of locations: 6
Enter adjacency matrix:
0 1 1 0 0 0 1 0 1 1 0 0 1 1 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 0 1 1 0
Enter starting location (0 for A): 0
Adj Matrix:
0 1 1 0 0 0 
1 0 1 1 0 0 
1 1 0 0 1 0 
0 1 0 0 0 1 
0 0 1 0 0 1 
0 0 0 1 1 0 
DFS: A->B->C->E->F->D
BFS: A->B->C->D->E->F*/
