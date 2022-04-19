// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortedSquares($A) {
        $B = [];
        $i = 0;
        $j = count($A)-1;
        while ($i <= $j) {
            $a = $A[$i] ** 2;
            $b = $A[$j] ** 2;
            if ($a > $b) {
                array_push($B, $a);
                $i++;
            } else {
                array_push($B, $b);
                $j--;
            }
        }
        return array_reverse($B);
        
    }
}