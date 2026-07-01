class CountSquares:

    def __init__(self):
        self.x_dict = dict()
        self.y_dict = dict()
        self.point_dict = dict()
        

    def add(self, point: List[int]) -> None:
        x, y = point
        if x in self.x_dict:
            self.x_dict[x][y] = self.x_dict[x].get(y, 0) + 1
        else:
            self.x_dict[x] = {y: 1}
        if y in self.y_dict:
            self.y_dict[y][x] = self.y_dict[y].get(x, 0) + 1
        else:
            self.y_dict[y] = {x: 1}
        self.point_dict[(x, y)] = self.point_dict.get((x, y), 0) + 1
        

    def count(self, point: List[int]) -> int:
        res = 0
        if point[0] in self.x_dict and point[1] in self.y_dict:
            for y in self.x_dict[point[0]]:
                for x in self.y_dict[point[1]]:
                    if (x, y) in self.point_dict and abs(x-point[0]) == abs(y-point[1]) and x-point[0] != 0:
                        res += self.point_dict[(x, point[1])] * self.point_dict[(point[0], y)] * self.point_dict[(x, y)]
        return res
