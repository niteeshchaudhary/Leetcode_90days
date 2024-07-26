#include<vector>

#define INF 99999

using namespace std;

void floydWarshall(vector<vector<int>>& dist,int V,vector<int>& ans,int distanceThreshold)
{
    int i, j, k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF)){
                    if(dist[i][j]>distanceThreshold && dist[i][k] + dist[k][j]<=distanceThreshold){
                        ans[i]++;
                        ans[j]++;
                    }
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][j];
                    
                }
            }
        }
    }
}

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n,vector<int>(n));
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j]=INF;
            }
            graph[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]][edges[i][1]]=edges[i][2];
            graph[edges[i][1]][edges[i][0]]=edges[i][2];
            if(edges[i][2]<=distanceThreshold){
                ans[edges[i][0]]++;
                ans[edges[i][1]]++;
            }
        }
        floydWarshall(graph,n,ans,distanceThreshold);
        int mn=INF,city=0;
        for(int i=0;i<n;i++){
            if(mn>=ans[i]){
                mn=ans[i];
                city=i;
            }
        }
        return city;
    }
};