class TimeMap {
public:

    unordered_map<string,map<int,string>> storage;

    TimeMap() {  
    }
    
    void set(string key, string value, int timestamp) {
        storage[key][timestamp] = value; 
    }
    
    string get(string key, int timestamp) {
        for( auto it = storage[key].rbegin(); it != storage[key].rend(); it++){
            auto &p = *it;
            if(p.first <= timestamp){
                return p.second;
            }
        }
        return "";
    }
};
