class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        if (x > y) {
            for (int i = s.size() - 2; i >= 0; i--) {
                if (s[i] == 'a' && s[i + 1] == 'b') {
                    score += x;
                    s.erase(s.begin() + i, s.begin() + i + 2);
                }
            }
            for (int i = s.size() - 2; i >= 0; i--) {
                if (s[i] == 'b' && s[i + 1] == 'a') {
                    score += y;
                    s.erase(s.begin() + i, s.begin() + i + 2);
                }
            }
        } else {
            for (int i = s.size() - 2; i >= 0; i--) {
                if (s[i] == 'b' && s[i + 1] == 'a') {
                    score += y;
                    s.erase(s.begin() + i, s.begin() + i + 2);
                }
            }
            for (int i = s.size() - 2; i >= 0; i--) {
                if (s[i] == 'a' && s[i + 1] == 'b') {
                    score += x;
                    s.erase(s.begin() + i, s.begin() + i + 2);
                }
            }
        }
        return score;
    }
};