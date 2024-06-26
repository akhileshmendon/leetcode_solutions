class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int sum = 0, prevDiff = INT_MAX;

        for (int i = 0; i<n-2; i++){
            int left = i+1 , right = n-1;
            while(left<right){
                int currSum = nums[i] + nums[left] + nums[right];
                int diff = abs(target - currSum);

                if(diff<prevDiff){
                    sum = currSum;
                    prevDiff = diff;
                }

                if(target > sum){
                    left++;
                }
                else{
                    right--;
                }
            }
        }

        return sum;
    }
};

