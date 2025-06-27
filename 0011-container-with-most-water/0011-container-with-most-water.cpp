class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=0;
        int ed=height.size()-1;
        int mx=INT_MIN;
        while(st<ed){
            int h=min(height[st],height[ed]);
            int w=ed-st;
            int area=h*w;
            mx=max(mx,area);
            if(height[st]<height[ed]){
                st++;
            }else{
                ed--;
            }
        }
        return mx;
    }
};