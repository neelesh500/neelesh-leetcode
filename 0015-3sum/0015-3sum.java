class Solution {
    public List<List<Integer>> threeSum(int[] nums) {

        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        HashSet<List<Integer>> set = new HashSet<>();

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int target = 0 - val;

            int j = i + 1, k = n - 1;

            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    set.add(Arrays.asList(val, nums[j], nums[k]));

                    j++;
                    k--;
                    while (j < n && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    while (k > i && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else if(nums[j] + nums[k] > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        for(List<Integer> l : set) res.add(l);
        return res;
    }
}