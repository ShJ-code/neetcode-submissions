impl Solution {
    pub fn cal_points(operations: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();
        for op in &operations {
            match op.as_str() {
                "+" => {
                    let top = stack[stack.len() - 1];
                    let second = stack[stack.len() - 2];
                    stack.push(top + second);
                }
                "D" => {
                    stack.push(2 * stack.last().unwrap());
                }
                "C" => {
                    stack.pop();
                }
                _ => {
                    stack.push(op.parse::<i32>().unwrap());
                }
            }
        }
        stack.iter().sum()
    }
}
