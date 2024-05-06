/*
THIS CODE HAS BEEN TESTED AND IS FULLY OPERATIONAL.

Problem Statement: Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.

Code from DataStructuresAndAlgorithms (SPPU - Second Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-se-comp-content/DataStructuresAndAlgorithms/
*/

// BEGINNING OF CODE
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<vector<int>> &g, int start, vector<int> &vis) {
    vis[start] = 1;
    cout<<start<<" ";
    for(auto child: g[start]){
        if(!vis[child]){
            dfs(g,child,vis);
        }
    }
}

void bfs(vector<vector<int>>& g, int start) {
    vector<int> vis(g.size(),0);
    queue<int> q;
    q.push(start);
    vis[start]=1;

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<< " ";
        for(auto child: g[cur]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
            }
        }
    }
}

void displayAdjacencyMatrix(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> adjacencyMatrix(V, vector<int>(V, 0));
    
    for (int i = 0; i < V; i++) {
        for (int j : graph[i]) {
            adjacencyMatrix[i][j] = 1;
        }
    }
   
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int V,E;

    cout << "Number of vertices:\t";
    cin >> V;
    vector<vector<int>> g;


    for(int i=0;i<V;i++){
        vector<int> temp;
        g.push_back(temp);
    }

    cout << "Number of edges:\t";
    cin >> E;
	
    for(int i=0;i<E;i++){
        int a,b;
        cout<<"Start node:\t";
        cin>>a;
        cout<<"End node:\t";
        cin>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    displayAdjacencyMatrix(g);
    vector<int> vis(V,0);
    cout<<endl<<"DFS:\t";
    dfs(g,0,vis);
    cout<<endl<<"BFS:\t";
    bfs(g,0);
    cout<<"\n\n// END OF CODE\n\n";
}
// END OF CODE

/*
SAMPLE OUTPUT:
Number of vertices:	3
Number of edges:	2
Start node:	1
End node:	2
Start node:	2
End node:	3
Adjacency Matrix:
0 0 0 
0 0 1 
0 1 0 

DFS:	0 
BFS:	0 
*/