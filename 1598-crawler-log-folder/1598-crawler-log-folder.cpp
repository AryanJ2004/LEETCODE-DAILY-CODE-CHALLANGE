class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                if(count>0){
                    count--;
                }
            }
            
            else if(logs[i]!="./"){
                count++;
            }
        }
        return count;
    }
};