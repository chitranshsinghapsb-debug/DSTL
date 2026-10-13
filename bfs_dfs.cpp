#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node,vector<vector<int>>& adjMatrix,vector<bool>& visited){
    visited[node]=true;
    cout<<char('A'+node)<<" ";

    for(int i=0;i<adjMatrix.size();i++){
        if(adjMatrix[node][i]==1&&!visited[i]){
            DFS(i,adjMatrix,visited);
        }
    }
}

void BFS(int start,vector<vector<int>>& adjList){
    vector<bool> visited(adjList.size(),false);
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int node=q.front();
        q.pop();

        cout<<char('A'+node)<<" ";

        for(int neighbour:adjList[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
}

int main(){
    int n,edges;

    cout<<"Enter number of locations: ";
    cin>>n;

    cout<<"Enter number of connections: ";
    cin>>edges;

    vector<vector<int>> adjMatrix(n,vector<int>(n,0));
    vector<vector<int>> adjList(n);

    cout<<"\nEnter the connected locations:\n";
    cout<<"Example: A B\n\n";

    for(int i=0;i<edges;i++){
        char city1,city2;

        cout<<"Connection "<<i+1<<": ";
        cin>>city1>>city2;

        int u=city1-'A';
        int v=city2-'A';

        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout<<"\nAdjacency Matrix:\n\n";

    cout<<"  ";
    for(int i=0;i<n;i++){
        cout<<char('A'+i)<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<char('A'+i)<<" ";

        for(int j=0;j<n;j++){
            cout<<adjMatrix[i][j]<<" ";
        }

        cout<<endl;
    }

    vector<bool> visited(n,false);

    cout<<"\nDFS Traversal starting from A: ";
    DFS(0,adjMatrix,visited);

    cout<<"\nBFS Traversal starting from A: ";
    BFS(0,adjList);

    cout<<endl;

    return 0;
}

/*Enter number of locations: 6
Enter number of connections: 8

Enter the connected locations:
Example: A B

Connection 1: A B
Connection 2: A C
Connection 3: B D
Connection 4: B E
Connection 5: C E
Connection 6: C F
Connection 7: D F 
Connection 8: E F

Adjacency Matrix:
  A B C D E F 
A 0 1 1 0 0 0 
B 1 0 0 1 1 0 
C 1 0 0 0 1 1 
D 0 1 0 0 0 1 
E 0 1 1 0 0 1 
F 0 0 1 1 1 0 

DFS Traversal starting from A: A B D F C E 
BFS Traversal starting from A: A B C D E F 
*/

