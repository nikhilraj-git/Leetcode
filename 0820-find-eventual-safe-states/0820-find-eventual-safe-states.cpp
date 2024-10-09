class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     int V=graph.size();
     vector<int> adj[V];
     vector<int> indegree(V,0);
     for(int i=0;i<V;i++)
     {
        for(auto x:graph[i])
        {
            adj[x].push_back(i);
        }
     }   
     for(int i=0;i<V;i++)
     {
        for(auto x:adj[i])
        {
            indegree[x]++;
        }
     }
     queue<int> q;
     for(int i=0;i<V;i++)
    {
        
        if(indegree[i]==0)q.push(i);
    }
    vector<int> ans;
    while(!q.empty())
    {
        int node= q.front();
        q.pop();
        ans.push_back(node);
        for(auto x:adj[node])
        {
            indegree[x]--;
            if(indegree[x]==0)q.push(x);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
    }
};