impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut count: HashMap<i32, usize> = HashMap::new();

        for &num in &nums {
            *count.entry(num).or_insert(0) += 1;

            if count.len() > 2 {
                let new_count: HashMap<i32, usize> = count
                    .iter()
                    .filter(|&(_, &v)| v>1)
                    .map(|(&k, &v)| (k, v-1))
                    .collect();
                count = new_count;
            }
        }

        let n = nums.len();
        count.keys()
            .filter(|&&k| nums.iter().filter(|&&x| x == k).count() > n/3)
            .copied()
            .collect()
    }
}
