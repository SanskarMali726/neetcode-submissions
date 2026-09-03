class LRUCache {
public:
    int cap;
    list<pair<int,int>> dq; // stores {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> m;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) 
            return -1;

        // Move this key to front (most recently used)
        dq.splice(dq.begin(), dq, m[key]);
        return m[key]->second;
    }

    void put(int key, int value) {
        // If key exists, update value and move to front
        if (m.find(key) != m.end()) {
            m[key]->second = value;
            dq.splice(dq.begin(), dq, m[key]);
            return;
        }

        // If capacity full, remove least recently used
        if (dq.size() == cap) {
            auto last = dq.back();
            m.erase(last.first);
            dq.pop_back();
        }

        // Insert new element at front
        dq.push_front({key, value});
        m[key] = dq.begin();
    }
};
