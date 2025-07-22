class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visit[i][j]=1;
                }else{
                    visit[i][j]=-1;
                }
            }
        }

        int delR[]={-1,0,+1,0};
        int delC[]={0,+1,0,-1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[row][col]=steps;
            for(int i=0;i<4;i++){
                int newR=row+delR[i];
                int newC=col+delC[i];
                if(newR>=0 && newR<n && newC>=0 && newC<m && visit[newR][newC]==-1){
                    visit[newR][newC]=1;
                    q.push({{newR,newC},steps+1});
                }
            }
            
        }
        return dist;
    }
};