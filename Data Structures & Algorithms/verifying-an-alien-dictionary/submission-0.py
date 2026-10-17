class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_dict = {order[i]: i for i in range(len(order))}
        for i in range(len(words) - 1):
            cont = False
            for j in range(min(len(words[i]), len(words[i+1]))):
                if order_dict[words[i][j]] > order_dict[words[i+1][j]]:
                    return False
                elif order_dict[words[i][j]] < order_dict[words[i+1][j]]:
                    cont = True
                    break
            if cont:
                continue
            if len(words[i]) > len(words[i+1]):
                return False
        return True