#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list< pair <int,int > > * adjList;
public:
    Graph(int v)
    {
        V=v;
        adjList=new list< pair <int,int > >[V];
    }
     void addEdge(int u, int v,int w)
     {
         adjList[u].push_back(make_pair(w,v));
         adjList[v].push_back(make_pair(w,u));
     }
     void dijkstra(int start)
     {
         int *dist=new int[V];
         for(int i=0;i<V;i++)
         {
             dist[i]=INT_MAX;
         }
         dist[start]=0;
         set< pair<int,int> > s;
         s.insert(make_pair(0,start));
         while(!s.empty())
         {
             set< pair<int,int> >:: iterator it=s.begin();
             int f=it->second;
             s.erase(it);
             for(list< pair <int,int > >:: iterator j=adjList[f].begin();j!=adjList[f].end();j++)
             {
                 int olddist=dist[j->second];
                 int oldnode=j->second;
                 if(dist[f]+(j->first)<olddist)
                 {
                     dist[j->second]=dist[f]+(j->first);
                     if(s.find(make_pair(olddist,oldnode))!=s.end())
                {
                    s.erase(make_pair(olddist,oldnode));
                }
                    s.insert(make_pair(dist[j->second],oldnode));
                 }
             }
         }
         for(int i=0;i<V;i++)
         {
             cout<<start<<"-"<<i<<"--->"<<dist[i]<<endl;
         }
     }
};

int main()
{

    int n,m,u,v,w,start;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    cin>>start;
    g.dijkstra(start);
}
