class Solution {
public:
    int climbStairs(int n) {
        int x=1;int y=2;
        if(n==1)return 1;if(n==2)return 2;
        for(int i=3;i<=n;i++){
            int z=x+y;
            x=y;
            y=z;
        }
        return y;
    }
};
