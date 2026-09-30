class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        queue<pair<int,int>>q;
        vector<vector<int>>ans ={{-1,0},{1,0},{0,1},{0,-1}};
         for(int i=0;i<grid.size();i++){
             for(int j=0;j<grid[i].size();j++){
                 if(grid[i][j]=='1'){
                     q.push({i,j});
                     count++;
                     while(!q.empty()){
                         int size=q.size();
                         for(int k=0;k<size;k++){
                             auto n =q.front();
                             q.pop();
                             int x =n.first;
                             int y= n.second;
                             
                             for(int a=0;a<4;a++){
                                 int u=x+ans[a][0];
                                 int v=y+ans[a][1];
                                 if(u>=0 && u<grid.size() && v>=0 && v<grid[0].size() && grid[u][v]=='1'){
                                     grid[u][v]='0';
                                     q.push({u,v});
                                 }
                             }
                         }
                         
                     }
                 }
             }
         }
         return count;
    }
};