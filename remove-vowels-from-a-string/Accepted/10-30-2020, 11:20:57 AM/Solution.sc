// https://leetcode.com/problems/remove-vowels-from-a-string

object Solution {
    def removeVowels(S: String): String = {
        S.filter { v => 
            v match {
                case 'a' => false
                case 'e' => false
                case 'i' => false
                case 'o' => false
                case 'u' => false
                case _ => true
            }
        }
    }
}