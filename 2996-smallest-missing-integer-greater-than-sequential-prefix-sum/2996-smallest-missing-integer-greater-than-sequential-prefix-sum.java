class Solution {
    public int missingInteger(int[] nums) {
        
        int maxi = nums[0];
        int sum = nums[0];
        for(int i = 1; i<nums.length; i++) {

            if((nums[i] - nums[i-1]) != 1) {
                break;
            } else {
                sum += nums[i];
            }

            maxi = Math.max(maxi,sum);
        }

        HashSet<Integer> set = new HashSet<>();
        for(int p : nums) set.add(p);

        for(int i = maxi; i<=2501; i++) {
            if(!set.contains(i))  return i;
        }
        return -1;
    }
}