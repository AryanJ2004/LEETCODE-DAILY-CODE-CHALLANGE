class Solution {
public:
    int trap(vector<int>& heights) {
        vector<int>lmax(heights.size(),0);
        vector<int>rmax(heights.size(),0);


        lmax[0]=0;

        for(int i=1;i<heights.size();i++){
            lmax[i]=max(lmax[i-1],heights[i-1]);    
        }

        rmax[heights.size()-1]=0;
        for(int i=heights.size()-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],heights[i+1]);    
        }


        int ans=0;

        for(int i=0;i<heights.size();i++){
            int wt=min(rmax[i],lmax[i])-heights[i];

            if(wt>0){
                ans+=wt;
            }
        }


        return ans;

    }
};