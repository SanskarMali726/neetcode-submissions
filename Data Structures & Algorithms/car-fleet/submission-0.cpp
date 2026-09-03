class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
          int n = position.size();
        map<int, int> coordinate;

        for (int i = 0; i < n; i++) {
            coordinate[position[i]] = speed[i];
        }

        stack<double> st;

        for (auto it = coordinate.rbegin(); it != coordinate.rend(); ++it) {
            double time = (double)(target - it->first) / it->second;
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};
