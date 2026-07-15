struct FreqStack {
    cnt: HashMap<i32, i32>,
    stacks: HashMap<i32, Vec<i32>>,
    max_cnt: i32,
}

impl FreqStack {
    pub fn new() -> Self {
        FreqStack {
            cnt: HashMap::new(),
            stacks: HashMap::new(),
            max_cnt: 0,
        }
    }

    pub fn push(&mut self, val: i32) {
        let val_cnt = *self.cnt.entry(val).or_insert(0) + 1;
        self.cnt.insert(val, val_cnt);
        if val_cnt > self.max_cnt {
            self.max_cnt = val_cnt;
            self.stacks.entry(val_cnt).or_insert_with(Vec::new);
        }
        self.stacks.get_mut(&val_cnt).unwrap().push(val);
    }

    pub fn pop(&mut self) -> i32 {
        let res = self.stacks.get_mut(&self.max_cnt).unwrap().pop().unwrap();
        *self.cnt.get_mut(&res).unwrap() -= 1;
        if self.stacks[&self.max_cnt].is_empty() {
            self.max_cnt -= 1;
        }
        res
    }
}
