class Solution {
public:
    vector<vector<int>> dfs(vector<vector<int>>&image,int initC,int sr,int sc,int color,int delR[],int delC[],vector<vector<int>>&ans){
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nRow=sr+delR[i];
            int nCol=sc+delC[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && ans[nRow][nCol]!=color && image[nRow][nCol]==initC){
                dfs(image,initC,nRow,nCol,color,delR,delC,ans);
            }
        }
        return ans;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initC=image[sr][sc];
        vector<vector<int>>ans=image;
        int delR[]={-1,0,+1,0};
        int delC[]={0,+1,0,-1};
        return dfs(image,initC,sr,sc,color,delR,delC,ans);
    }
};