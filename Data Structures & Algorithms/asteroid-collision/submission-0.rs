impl Solution {
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<i32> = Vec::new();
        for &asteroid in &asteroids {
            let mut a = asteroid;
            while !stack.is_empty() && a < 0 && *stack.last().unwrap() > 0 {
                let diff = a + stack.last().unwrap();
                if diff < 0 {
                    stack.pop();
                } else if diff > 0 {
                    a = 0;
                } else {
                    a = 0;
                    stack.pop();
                }
            }
            if a != 0 {
                stack.push(a);
            }
        }
        stack
    }
}
