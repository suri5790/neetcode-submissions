class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>x=m[key];
        int h=x.size()-1;
        int l=0;
        if(x.empty())return "";
        string res="";
        while(l<=h){
            int m=l+(h-l)/2;
            if(x[m].first<=timestamp){
                res=x[m].second;
                l=m+1;
            }
            else {
                h=m-1;
            }
        }
        return res;
    }
};
