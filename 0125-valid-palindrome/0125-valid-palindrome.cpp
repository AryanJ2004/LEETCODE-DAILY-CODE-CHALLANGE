class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); // Already converting to lowercase
        int j = s.length() - 1;
        int fl = 0;
        
        for (int i = 0; i < j; i++) {
            // Skip non-alphanumeric characters for i
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            // Skip non-alphanumeric characters for j
            while (i < j && !isalnum(s[j])) {
                j--;
            }

            // If characters don't match
            if (s[i] != s[j]) {
                fl = 1;
                break;
            }
            j--; // Move the right pointer left
        }
        
        return fl == 0;
    }
};