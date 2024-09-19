class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> answer;

        for(int i = 0; i < expression.size(); i++){
            char op = expression[i];
            if(op == '+' || op == '-' || op == '*'){
                vector<int> leftStr = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightStr = diffWaysToCompute(expression.substr(i + 1));

                for(int x : leftStr){
                    for(int y : rightStr){
                        if(op == '+')
                            answer.push_back(x + y);
                        else if(op == '-')
                            answer.push_back(x - y);
                        else if(op == '*')
                            answer.push_back(x * y);
                    }
                }
            }
        }
        if(answer.empty())
            answer.push_back(stoi(expression));
        
        return answer;
    }
};