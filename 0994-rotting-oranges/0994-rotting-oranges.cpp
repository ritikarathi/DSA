class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0; i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]== 1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>>g={{1,0},{0,1},{0,-1},{-1,0}};
        int count=0;
        while(!q.empty()){
            int size= q.size();
            while(size--){
                pair<int,int>temp= q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                for(int k=0; k<g.size();k++){
                    int i =x+g[k][0];
                    int j= y+g[k][1];
                    if(i<n && i>=0 && j<m && j>=0 && grid[i][j]==1){
                        grid[i][j]=2;
                        q.push({i,j});
                        fresh--;
                    }
                }
            }
            count++;
        }
        if(fresh==0){
            return count-1;
        }
        return -1;
    }
};