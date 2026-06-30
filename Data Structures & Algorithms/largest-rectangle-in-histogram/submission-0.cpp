class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>s;h.push_back(0);int ans=0;
        for(int i=0;i<h.size();i++){
            int cur=h[i];
            while(!s.empty() && cur<h[s.top()]){
                int x=h[s.top()];
                s.pop();int pre;
                if(s.empty())pre=-1;
                else pre=s.top();
                int curans=x*((i-pre)-1);ans=max(ans,curans);
            }
            s.push(i);
        }

        return ans;
    }
};