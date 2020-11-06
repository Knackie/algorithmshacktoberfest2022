int maxSubArray(vector<int>& nums) {
    int res=nums[0];
    int curr=nums[0];
        
    for(int i=1;i<nums.size();i++)
    {
        curr = max(nums[i],curr+nums[i]);
        res= max(res,curr);     
    }
    
    return res;
}

int main() {
    
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(nums);
    cout << result;
    
    return 0;
}