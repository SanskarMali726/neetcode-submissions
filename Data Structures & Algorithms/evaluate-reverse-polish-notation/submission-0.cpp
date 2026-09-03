class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int result;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                s.push(stoi(tokens[i]));
            }
            else{ 
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                switch(tokens[i][0]){
                    case '+':
                        result = first + second;
                        s.push(result);
                        break;
                    case '-':
                        result = first - second;
                        s.push(result);
                        break;
                    case '*':
                        result = first * second;
                        s.push(result);
                        break;
                    case '/':
                        result = first / second;
                        s.push(result);
                        break;
                }
            }
        }
        return s.top();
    }
};
