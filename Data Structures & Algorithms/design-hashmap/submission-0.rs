struct MyHashMap {
    buckets: Vec<Vec<(i32, i32)>>,
}

impl MyHashMap {
    pub fn new() -> Self {
        Self {
            buckets: vec![Vec::new(); 1000],
        }
    }

    fn hash(key: i32) -> usize {
        key as usize % 1000
    }

    pub fn put(&mut self, key: i32, value: i32) {
        let idx = Self::hash(key);
        for pair in self.buckets[idx].iter_mut() {
            if pair.0 == key {
                pair.1 = value;
                return;
            }
        }
        self.buckets[idx].push((key, value));
    }

    pub fn get(&self, key: i32) -> i32 {
        let idx = Self::hash(key);
        for pair in &self.buckets[idx] {
            if pair.0 == key {
                return pair.1;
            }
        }
        -1
    }

    pub fn remove(&mut self, key: i32) {
        let idx = Self::hash(key);
        if let Some(pos) = self.buckets[idx].iter().position(|p| p.0 == key) {
            self.buckets[idx].remove(pos);
        }
    }
}
