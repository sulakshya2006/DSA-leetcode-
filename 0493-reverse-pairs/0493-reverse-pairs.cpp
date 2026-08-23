class Solution {
public:
    int cnt = 0;

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        vector<int> temp;
        int l = left, r = mid + 1;
        while (l <= mid && r <= right) {
            if (nums[l] <= nums[r]) temp.push_back(nums[l++]);
            else temp.push_back(nums[r++]);
        }
        while (l <= mid) temp.push_back(nums[l++]);
        while (r <= right) temp.push_back(nums[r++]);

        for (int i = left; i <= right; i++) {
            nums[i] = temp[i - left];
        }
    }

    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};