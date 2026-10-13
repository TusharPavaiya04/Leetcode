class Solution {
    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     queue<pair<int,int>>q;
     int n=image.size();
     int m=image[0].size();
     vector<vector<int>>vis(n,vector<int>(m,0));
     q.push({sr,sc});
     vis[sr][sc]=1;
     int delRow[]={1,0,-1,0};
     int delCol[]={0,1,0,-1};
     int initialColor=image[sr][sc];
     while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        image[row][col]=color;
        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];
            if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m&&!vis[nRow][nCol]&&image[nRow][nCol]==initialColor){
        vis[nRow][nCol]=1;
                q.push({nRow,nCol});
            }
        }
     }
     return image;

    }
};