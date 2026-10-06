class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(int i=0;i<relations.size();i++){
            int u=relations[i][0]-1;
            int v=relations[i][1]-1;
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        vector<int>finish(n);
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                finish[i]=time[i];
            }
        }
        int total=0;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            total=max(total,finish[n]);
            for(int i=0;i<adj[n].size();i++){
                int x =adj[n][i];
                finish[x]= max(finish[x], finish[n]+time[x]);
                indeg[adj[n][i]]--;
                if(indeg[adj[n][i]]==0){
                    q.push(adj[n][i]);
                    
                }
            }
            
        }
        return total;

    }
};