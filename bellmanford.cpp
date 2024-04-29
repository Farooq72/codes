#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src,dest,weight;
};

struct Graph{
    int V,E;
    vector<Edge>edge;
};

struct Graph* createGraph(int V,int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    return graph;
}

void printArr(vector<int>&dist,vector<int>&pred,int src){
    for(int i=0;i<dist.size();i++){
        cout<< i <<"\t\t"<<dist[i]<<"\t\t";
        stack<int>printStack;
        int j = i;
        while(j!=src){
            printStack.push(j);
            j = pred[j];
        }
        cout<<src;
        while(!printStack.empty()){
            cout<<" -> "<<printStack.top();
            printStack.pop();
        }
        cout<<endl;
    }
}

void bellmanFord(struct Graph* graph,int src){
    int V = graph -> V;
    int E = graph -> E;
    vector<int>dist(V,INT_MAX);
    vector<int>pred(V,-1);
    dist[src] = 0;

    for(int i=1;i<=V-1;i++){
        for(int j=0;j<E;j++){
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v] ){
                dist[v] = dist[u] + weight;
                pred[v] = u;
            }
        }
    }

    for(int i=0;i<E;i++){
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if(dist[u] !=INT_MAX && dist[u] + weight < dist[v]){
            cout<<"There is a negative cycle";
            return;
        }
    }

    printArr(dist,pred,src);

}

int main(){
    int V,E;
    cout<<"Enter the vertices and edges:";
    cin>>V>>E;

    
    struct Graph* graph = createGraph(V,E);
    cout<<"Enter the source,destination,weight"<<endl;
    for(int i=0;i<E;i++){
        int src,dest,weight;
        cin>>src >> dest >> weight;
        graph->edge.push_back({src,dest,weight});
    }
    int source;
    cout<<"Enter source : ";
    cin>>source;

    bellmanFord(graph,source);

}