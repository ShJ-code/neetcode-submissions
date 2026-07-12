impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let k = k as usize;
        let mut window: HashSet<i32> = HashSet::new();
        let mut l = 0;

        for r in 0..nums.len() {
            if r - l > k {
                window.remove(&nums[l]);
                l += 1;
            }
            if window.contains(&nums[r]) {
                return true;
            }
            window.insert(nums[r]);
        }

        false
    }
}
