class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []
        self.size = 0
        

    def push(self, val: int) -> None:
        self.stack.append(val)
        if self.size > 0:
            self.min_stack.append(min(self.min_stack[-1], val))
        else:
            self.min_stack.append(val)
        self.size += 1
        

    def pop(self) -> None:
        self.stack.pop()
        self.min_stack.pop()
        self.size -= 1
        

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.min_stack[-1]
        
