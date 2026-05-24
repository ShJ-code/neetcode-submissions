class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        up, bottom, left, right = 0, m, 0, n
        while up < bottom:
            mid1 = (up + bottom) // 2
            if matrix[mid1][0] <= target <= matrix[mid1][n-1]:
                while left < right:
                    mid2 = (left + right) // 2
                    if matrix[mid1][mid2] == target:
                        return True
                    elif matrix[mid1][mid2] < target:
                        left = mid2 + 1
                    else:
                        right = mid2
                return False
            elif matrix[mid1][0] > target:
                bottom = mid1
            else:
                up = mid1 + 1
        return False