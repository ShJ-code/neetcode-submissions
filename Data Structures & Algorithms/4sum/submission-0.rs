impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();
        let mut res = Vec::new();
        let n = nums.len();

        for i in (0..n).map(|x| x as usize) {
            if i > 0 && nums[i] == nums[i-1] { continue; }

            for j in ((i+1)..n).map(|x| x as usize) {
                if j > i+1 && nums[j] == nums[j-1] { continue; }

                let mut left = j + 1;
                let mut right = n as i32 - 1;

                while (left as i32) < right {
                    let r = right as usize;
                    let sum = nums[i] as i64 + nums[j] as i64
                        + nums[left] as i64 + nums[r] as i64;
                    if sum == target as i64 {
                        res.push(vec![nums[i], nums[j], nums[left], nums[r]]);
                        left += 1;
                        right -= 1;
                        while (left as i32) < right && nums[left] == nums[left-1] {
                            left += 1;
                        }
                        while (left as i32) < right && nums[right as usize] == nums[right as usize + 1] {
                            right -= 1;
                        }
                    } else if sum < target as i64 {
                        left += 1;
                    } else {
                        right -= 1;
                    }
                }
            }
        }

        res
    }
}
