class Solution {
public:
    bool solve(int u, int v, vector<bool>visited, vector<vector<int>>&adj){
        if(u==v){
            return true;
        }
        visited[u]=1;
        for(int i=0; i<adj[u].size();i++){
            if(!visited[adj[u][i]] && solve(adj[u][i],v,visited,adj)){
                return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[u].push_back(v);
        }
        vector<bool>visited(numCourses,0);
        vector<bool>ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];

            if(solve(u,v,visited,adj)){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;

    }
};