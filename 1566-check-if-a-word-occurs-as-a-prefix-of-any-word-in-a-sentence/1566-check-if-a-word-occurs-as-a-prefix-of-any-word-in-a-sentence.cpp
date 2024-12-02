class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 0; 
        int n = sentence.size(); 
        int i = 0;   
        while (i < n) {
            wordIndex++; 
            int j = 0; 
            while (i < n && j < searchWord.size() && sentence[i] == searchWord[j]) {
                i++;
                j++;
            }
            if (j == searchWord.size()) {
                return wordIndex;
            }
            while (i < n && sentence[i] != ' ') {
                i++;
            }
            i++;
        }
        return -1; 
    }
};
