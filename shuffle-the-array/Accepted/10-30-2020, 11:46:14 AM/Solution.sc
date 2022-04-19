// https://leetcode.com/problems/shuffle-the-array

object Solution {
    def shuffle(nums: Array[Int], n: Int): Array[Int] = {
        // [x1, x2, x3, y1, y2, y3]
        
        (0 to 2*n - 1).toArray.map{ idx =>
            idx % 2 match {
                case  0 => nums(idx/2)
                case  1 => nums(idx/2 + n)
            }
        }
        
    }
}