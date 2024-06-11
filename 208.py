class Trie:

    def __init__(self):
        self.dic = ['']*27

    def insert(self, word: str) -> None:
        cur = self.dic
        for w in word:
            if cur[ord(w)-97]=='':
                cur[ord(w)-97] = ['']*27
            cur = cur[ord(w)-97]
        cur[26] = '.'

    def search(self, word: str) -> bool:
        cur = self.dic
        for w in word:
            if cur[ord(w)-97]=='':
                return False
            cur = cur[ord(w)-97]
        return True if cur[26]!='' else False

    def startsWith(self, prefix: str) -> bool:
        cur = self.dic
        for w in prefix:
            if cur[ord(w)-97]=='':
                return False
            cur = cur[ord(w)-97]
        return True
        
