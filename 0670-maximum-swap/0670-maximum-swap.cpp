class Solution {
public:
    int maximumSwap(int num) {

        string s = to_string(num);
        
        for(int i=0;i<s.size();i++){
            int ind = i;

            for(int j=s.size()-1;j>i;j--){
                if(s[ind]<s[j]){
                    ind = j;
                }
            }

            if(ind != i and s[i]<s[ind]){
                swap(s[i],s[ind]);
          
                return stoi(s);
            }
        }

        return num;
    }
};