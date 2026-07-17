impl Solution {
    pub fn find_in_mountain_array(target: i32, mountain_arr: &dyn MountainArray) -> i32 {
        let mut cache = HashMap::new();
        let length = mountain_arr.length() as i32;

        let mut get = |i: i32| -> i32 {
            if let Some(&v) = cache.get(&i) {
                return v;
            }
            let v = mountain_arr.get(i);
            cache.insert(i, v);
            v
        };

        let (mut l, mut r) = (1i32, length - 2);
        let mut peak = 0i32;
        while l <= r {
            let m = (l + r) >> 1;
            let left = get(m-1);
            let mid = get(m);
            let right = get(m+1);
            if left < mid && mid < right {
                l = m + 1;
            } else if left > mid && mid > right {
                r = m - 1;
            } else {
                peak = m;
                break;
            }
        }

        let binary_search = |lo: i32, hi: i32, ascending: bool, cache: &mut HashMap<i32, i32>| -> i32 {
            let (mut l, mut r) = (lo, hi);
            while l <= r {
                let m = (l + r) >> 1;
                let val = if let Some(&v) = cache.get(&m) { v } else {
                    let v = mountain_arr.get(m);
                    cache.insert(m, v);
                    v
                };
                if val == target {
                    return m;
                }
                if ascending == (val < target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            -1
        };

        let res = binary_search(0, peak, true, &mut cache);
        if res != -1 {
            return res;
        }

        binary_search(peak, length-1, false, &mut cache)
    }
}
