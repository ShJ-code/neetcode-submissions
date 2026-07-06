impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        let mut new = vec![0; 2*nums.len()];
        for i in 0..nums.len() {
            new[i] = nums[i];
            new[i+nums.len()] = nums[i];
        }
        new
    }
}
