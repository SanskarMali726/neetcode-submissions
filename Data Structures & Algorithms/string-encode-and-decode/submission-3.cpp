class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(int i=0;i<strs.size();i++){
            result += to_string(strs[i].length()) + '#' + strs[i];
        }
        cout <<result; 
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i= 0;
        while(i < s.length()){
            string r="";
            int size;
            string num = "";

            while(s[i] != '#'){
                num += s[i];
                i++;
            }
            size = stoi(num);

            cout<< size << endl;
            for(int j= i+1; j <i+1+size ; j++ ){
                r += s[j];
            }
            result.push_back(r);
            i = i + size + 1;
        }

        return result;
    }
};
