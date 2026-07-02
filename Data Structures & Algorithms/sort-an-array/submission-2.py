class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def mergesort(arr, lo, hi):
            if hi - lo <= 1:
                return
            mid = lo + (hi - lo) // 2
            mergesort(arr, lo, mid)
            mergesort(arr, mid, hi)
            merge(arr, lo, mid, hi)

        def merge(arr, lo, mid, hi):
            new_arr = [0] * (hi - lo)
            i1, i2 = lo, mid
            for i in range(hi - lo):
                if i2 == hi or (i1 != mid and arr[i1] < arr[i2]):
                    new_arr[i] = arr[i1]
                    i1 += 1
                else:
                    new_arr[i] = arr[i2]
                    i2 += 1
            
            for i in range(hi - lo):
                arr[lo+i] = new_arr[i]

        mergesort(nums, 0, len(nums))
        return nums