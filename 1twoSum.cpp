class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            // ������Ԫ����Ϊkey�����ڲ���
            map.put(nums[i],i);
        }
        for(int j=0;j<nums.length;j++){
            // ��������
            int com = target - nums[j];
            // ������ڣ���Ƚ��Ƿ��ظ�
            if(map.containsKey(com) && map.get(com) != j){
                return new int[]{j,map.get(com)};
            }
        }
        return null;
    }
}
