impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let first = strs[0].as_bytes();
        for i in 0..first.len() {
            for s in strs.iter() {
                let sb = s.as_bytes();
                if i == sb.len() || sb[i] != first[i] {
                    return s[..i].to_string();
                }
            }
        }
        strs[0].clone()
    }
}
