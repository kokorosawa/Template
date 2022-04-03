int Binary_Search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid;
    while(left <= right){
        mid = (right - left) / 2 + left;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) right = mid - 1;
        else if(nums[mid] < target) left = mid + 1;
    }
    return -1;
}