impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut stack: Vec<String> = Vec::new();
        let mut cur = String::new();

        for c in path.chars().chain(std::iter::once('/')) {
            if c == '/' {
                if cur == ".." {
                    stack.pop();
                } else if !cur.is_empty() && cur != "." {
                    stack.push(cur.clone());
                }
                cur.clear();
            } else {
                cur.push(c);
            }
        }

        format!("/{}", stack.join("/"))
    }
}
