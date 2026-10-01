class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V= numCourses;
        vector<int>Indeg(V,0);
        vector<vector<int>>adj(V);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            Indeg[prerequisites[i][0]]++;
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<V;i++){
            if(Indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int n=q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[n].size();i++){
                Indeg[adj[n][i]]--;
                if(Indeg[adj[n][i]]==0){
                    q.push(adj[n][i]);
                }
            }
        }
        if(count==numCourses){
            return true;
        }
        return false;

    }
};