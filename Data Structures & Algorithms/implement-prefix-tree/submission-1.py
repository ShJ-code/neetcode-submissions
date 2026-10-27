class PrefixTree:

    def __init__(self):
        self.next = [None] * 26
        self.end = False


    def insert(self, word: str) -> None:
        curr = self
        for c in word:
            nxt = curr.next[ord(c) - ord('a')]
            if nxt:
                curr = nxt
            else:
                curr.next[ord(c) - ord('a')] = PrefixTree()
                curr = curr.next[ord(c) - ord('a')]
        curr.end = True


    def search(self, word: str) -> bool:
        curr = self
        for c in word:
            nxt = curr.next[ord(c) - ord('a')]
            if nxt:
                curr = nxt
            else:
                return False
        return curr.end
        

    def startsWith(self, prefix: str) -> bool:
        curr = self
        for c in prefix:
            nxt = curr.next[ord(c) - ord('a')]
            if nxt:
                curr = nxt
            else:
                return False
        return curr is not None
        
        