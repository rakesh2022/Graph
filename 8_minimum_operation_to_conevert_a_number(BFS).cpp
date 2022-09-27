
  https://leetcode.com/contest/weekly-contest-265/problems/minimum-operations-to-convert-number/

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
       vector<int>vis(1001);
        queue<int>q;
        q.push(start);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
               int x=q.front();
                q.pop();
                if(x==goal)return ans;
                if(x<0 || x>1000)continue;
                if(vis[x]==1)continue;
                vis[x]=1;
                for(int i=0;i<nums.size();i++){
                    q.push(x+nums[i]);
                    q.push(x-nums[i]);
                    q.push(x^nums[i]);
                }
            }
            ans++;
        }
        return -1;
    }
};