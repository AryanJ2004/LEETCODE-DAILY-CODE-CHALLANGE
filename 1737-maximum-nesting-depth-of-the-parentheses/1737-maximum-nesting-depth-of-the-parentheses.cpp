class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max_num = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
                max_num=max(max_num,count);
            } else if (c == ')') {
                count--;
            }
        }
        return max_num;
    }
};