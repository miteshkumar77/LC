// https://leetcode.com/problems/degree-of-an-array

class Solution {
    public int findShortestSubArray(int[] data) {
        int max = 0;
        Map<Integer, Integer> map = new HashMap<>();
        Map<Integer, Integer> startIndex = new HashMap<>();
        Map<Integer, Integer> endIndex = new HashMap<>();
        for(int i = 0; i < data.length; i++){
           int value = data[i];
           if(map.containsKey(value)){
              map.put(value, map.get(value) + 1);
           }else{
              startIndex.put(value, i);
              map.put(value, 1);
           }
           endIndex.put(value, i);
           max = Integer.max(max, map.get(value));//Calculate the degree of the array
        }
        int result = data.length;
        for(int i : map.keySet()){
           if(map.get(i) == max){
              int len = endIndex.get(i) - startIndex.get(i) + 1;
              result = Integer.min(result, len);
           }
        }
        return result;
    }
}