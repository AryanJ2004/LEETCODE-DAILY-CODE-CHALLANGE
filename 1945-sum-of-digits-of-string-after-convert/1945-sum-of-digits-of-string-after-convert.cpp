class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (char c : s) {
            int num = c - 'a' + 1;  
            while (num > 0) {      
                sum += num % 10;
                num /= 10;
            }
        }

        if(k==1){
            return sum;
        }
       for (int i = 1; i < k; ++i) {
            int nextSum = 0;
            while (sum > 0) {
                nextSum += sum % 10;
                sum /= 10;
            }
            sum = nextSum;
        }

        return sum;
    }
};
