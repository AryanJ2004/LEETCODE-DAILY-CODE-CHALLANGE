class Solution {
public:
    bool checkValidString(string s) {
        int min=0,max=0;

        for(auto c:s){
            if(c=='('){
                min++,max++;
            }else if(c==')'){
                min--;
                max--;
            }else{
                min--;
                max++;
            }
            if(min<0) min=0;
            if(max<0) return false;
        }

        return min==0;
    }
};