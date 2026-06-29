class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        a, b, c = target
        i, j, k = False, False, False
        for x, y, z in triplets:
            # if (x == a and (y > b or z > c)) or (y == b and (x > a or z > c)) or (z == c and (x > a or y > b)):
            #     return False
            if x == a and y <= b and z <= c:
                i = True
            if y == b and x <= a and z <= c:
                j = True
            if z == c and x <= a and y <= b:
                k = True
        if not i or not j or not k:
            return False
        return True