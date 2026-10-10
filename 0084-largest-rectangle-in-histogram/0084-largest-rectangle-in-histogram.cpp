class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsl(n);
        vector<int>nsr(n);

        stack<int>st;

        nsl[0]=-1;
        st.push(0);

        for(int i=1;i<n;i++){
            int curr=heights[i];

            while(!st.empty() && heights[st.top()]>=curr){
                st.pop();
            }

            if(st.empty()){
                nsl[i]=-1;
            }else{
                nsl[i]=st.top();
            }
            st.push(i);

        }

        while(!st.empty()){
            st.pop();
        }

        st.push(n-1);
        nsr[n-1]=n;

        for(int i=n-2;i>=0;i--){
            int curr=heights[i];


            while(!st.empty() && heights[st.top()]>=curr){
                st.pop();
            }
            if(st.empty()){
                nsr[i]=n;
            }else{
                nsr[i]=st.top();
            }

            st.push(i);
        }

        int maxArea=0;

        for(int i=0;i<n;i++){
            int area=heights[i]*(nsr[i]-nsl[i]-1);
            maxArea=max(area,maxArea);
        }

        return maxArea;
    }

};