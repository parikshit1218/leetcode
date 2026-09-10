class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        // kth largest = (n-k)th smallest
        int target = n - k;

        int left = 0;
        int right = n - 1;

        while (left <= right) {

            // Choose a random pivot
            int pivotIndex = left + rand() % (right - left + 1);
            int pivot = nums[pivotIndex];

            // Move pivot to the end
            swap(nums[pivotIndex], nums[right]);

            int i = left;

            // Partition
            for (int j = left; j < right; j++) {

                if (nums[j] < pivot) {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }

            // Put pivot in its correct position
            swap(nums[i], nums[right]);

            // Check pivot position
            if (i == target) {
                return nums[i];
            }
            else if (i < target) {
                left = i + 1;
            }
            else {
                right = i - 1;
            }
        }

        return -1;
    }
};