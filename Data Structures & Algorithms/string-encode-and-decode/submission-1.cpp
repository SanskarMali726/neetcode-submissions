class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded= "";
        for(int i=0;i<strs.size();i++){
            encoded +=to_string(strs[i].length()) + '#' + strs[i];
        }

        return encoded;

    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i=0;
        while(i<s.size()){
            int j=i;

            while(s[j] !='#'){
                j++;
            }

            int length = stoi(s.substr(i,j-i));
            i=j+1;
            string word = s.substr(i,length);
            decoded.push_back(word);

            i=i+length;
        }
        return decoded;
    }
};
