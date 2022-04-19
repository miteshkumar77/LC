// https://leetcode.com/problems/remove-vowels-from-a-string

object Solution {
    def removeVowels(S: String): String = {
        val vowels: List[Char] = List('a', 'e', 'i', 'o', 'u')
        return S.filterNot(vowels.contains(_))
    }
}