impl Solution {
    pub fn find_closest_elements(arr: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
        let mut left = 0usize;
        let mut right = arr.len() - 1;
        while right - left + 1 > k as usize {
            if (arr[left] - x).abs() < (arr[right] - x).abs() || ((arr[left] - x).abs() == (arr[right] - x).abs() && arr[left] < arr[right]) {
                right -= 1;
            } else {
                left += 1;
            }
        }
        (&arr[left..right+1]).to_vec()
    }
}
