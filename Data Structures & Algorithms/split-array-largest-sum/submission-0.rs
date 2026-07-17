impl Solution {
    pub fn split_array(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as i32;
        let can_split = |largest: i32| -> bool {
            let mut subarray = 1;
            let mut cur_sum = 0;
            for &num in &nums {
                cur_sum += num;
                if cur_sum > largest {
                    subarray += 1;
                    if subarray > k {
                        return false;
                    }
                    cur_sum = num;
                }
            }
            true
        };

        let mut l = *nums.iter().max().unwrap();
        let mut r: i32 = nums.iter().sum();
        let mut res = r;

        while l <= r {
            let mid = l + (r - l) / 2;
            if can_split(mid) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        res
    }
}
