
https://leetcode.com/problems/perfect-squares/

//Input: n = 12
//Output: 3
// Explanation: 12 = 4 + 4 + 4.

class Solution {
public:
    int ans=INT_MAX;
    void findcount(int cnt,int sum){
            if(sum==0){
            ans=min(cnt,ans);
                return;
            }
        if(sum<0)return;
        for(int i=1;i<=sqrt(sum);i++){
                int p=i*i;
            findcount(cnt+1,sum-p);
            
        }
    }
    int numSquares(int n) {
        // int num=sqrt(n);
         findcount(0,n);
        return ans;
    }
};
  