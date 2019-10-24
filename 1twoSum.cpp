class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            // 将数组元素做为key，便于查找
            map.put(nums[i],i);
        }
        for(int j=0;j<nums.length;j++){
            // 获得相减数
            int com = target - nums[j];
            // 假如存在，则比较是否重复
            if(map.containsKey(com) && map.get(com) != j){
                return new int[]{j,map.get(com)};
            }
        }
        return null;
    }
}
