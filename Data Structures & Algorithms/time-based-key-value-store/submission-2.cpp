class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
    if(mp[key].empty()) return "";

    auto &v = mp[key]; // use reference, not copy
    auto it = lower_bound(v.begin(), v.end(), make_pair(timestamp, ""),
        [](const pair<int,string>& a, const pair<int,string>& b){
            return a.first < b.first;
        }
    );

    if(it == v.end()) {
        // all timestamps < target, take last element
        return v.back().second;
    }

    if(it->first == timestamp) {
        // exact match
        return it->second;
    }

    if(it != v.begin()) {
        // no exact match, take previous
        --it;
        return it->second;
    }

    // timestamp < first element
    return "";
}

};
