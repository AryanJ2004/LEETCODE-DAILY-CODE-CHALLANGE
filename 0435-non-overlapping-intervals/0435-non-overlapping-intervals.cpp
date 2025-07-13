class Solution {
public:

    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int rmv=0;
        sort(intervals.begin(),intervals.end(),compare);
        int edi=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<edi){
                rmv++;
            }else{
                edi=intervals[i][1];
            }
        }

        return rmv;
    }
};