#include<vector>
#include<string>
using namespace std;

#define INF 10e7
void floydWarshall(vector<vector<int>>& dist,int V)
{
    int i, j, k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        long long ans=0;
        vector<vector<int>> graph(26,vector<int>(26,INF));
        for(int i=0;i<26;i++){
            graph[i][i]=0;
        }
        for(int i=0;i<n;i++){
            graph[original[i]-97][changed[i]-97]=min(graph[original[i]-97][changed[i]-97],cost[i]);
        }
        floydWarshall(graph,26);
        for(int i=0;i<source.size();i++){
            ans+=graph[source[i]-97][target[i]-97];
            if(graph[source[i]-97][target[i]-97]>=INF){
                return -1;
            }
        }
        
        return ans;
    }
};