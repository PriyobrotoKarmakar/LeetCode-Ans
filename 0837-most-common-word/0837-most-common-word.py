from collections import Counter
from typing import List

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = ""
        
        for ch in paragraph:
            if(ch>='a' and ch<='z'):
                words+=ch
            elif(ch>='A' and ch<='Z'):
                words+= ch.lower()
            elif(ch==' '):
                words+=ch
            else:
                words+=' '
        print(words)
        wordsArray = [word for word in words.split() if word not in banned]      
        word_counts = Counter(wordsArray)
        max_count = 0
        most_common_word = ""
        for word, count in word_counts.items():
            if count > max_count:
                max_count = count
                most_common_word = word.lower()
        
        return most_common_word