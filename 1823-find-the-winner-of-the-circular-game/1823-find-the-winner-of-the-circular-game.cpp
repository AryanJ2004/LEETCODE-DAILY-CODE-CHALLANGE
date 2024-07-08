class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>vec;
        for(int i=1;i<=n;i++)
        vec.push_back(i);
        int idx=0;
        while(vec.size()>1)
        {
            int rmv=(idx+k-1)%vec.size();
            vec.erase(vec.begin()+rmv);
            idx=rmv;
        }
        return vec[0];
    }
};