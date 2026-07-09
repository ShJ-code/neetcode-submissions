impl Solution {
    pub fn num_rescue_boats(mut people: Vec<i32>, limit: i32) -> i32 {
        people.sort_unstable();

        let mut left = 0usize;
        let mut right = people.len();
        let mut res = 0;

        while left < right {
            right -= 1; // 当前最重的人上船

            if left < right && people[left] + people[right] <= limit {
                left += 1; // 最轻的人也一起上船
            }

            res += 1;
        }

        res
    }
}
