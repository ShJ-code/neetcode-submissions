struct MyCircularQueue {
    q: VecDeque<i32>,
    capacity: usize,
}

impl MyCircularQueue {
    pub fn new(k: i32) -> Self {
        Self {
            q: VecDeque::new(),
            capacity: k as usize,
        }
    }

    pub fn en_queue(&mut self, value: i32) -> bool {
        if self.is_full() {
            return false;
        }
        self.q.push_back(value);
        true
    }

    pub fn de_queue(&mut self) -> bool {
        if self.is_empty() {
            return false;
        }
        self.q.pop_front();
        true
    }

    pub fn front(&self) -> i32 {
        if self.is_empty() { -1 } else { *self.q.front().unwrap() }
    }

    pub fn rear(&self) -> i32 {
        if self.is_empty() { -1 } else { *self.q.back().unwrap() }
    }

    pub fn is_empty(&self) -> bool {
        self.q.is_empty()
    }

    pub fn is_full(&self) -> bool {
        self.q.len() == self.capacity
    }
}
