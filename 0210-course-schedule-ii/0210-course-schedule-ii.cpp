class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                indegree[x]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adj[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        if(ans.size()==V)return ans;
        else return {};
    }
};