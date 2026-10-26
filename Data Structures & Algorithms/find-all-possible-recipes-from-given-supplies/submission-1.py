from collections import defaultdict, deque
class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        waiting=defaultdict(list)
        remaining=[len(row) for row in ingredients]
        for i,row in enumerate(ingredients):
            for item in row:
                waiting[item].append(i)
        queue=deque(supplies)
        answer=[]
        while queue:
            item=queue.popleft()
            for i in waiting[item]:
                remaining[i]-=1
                if remaining[i]==0:
                    answer.append(recipes[i])
                    queue.append(recipes[i])
        return answer