class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        dec_pos = sorted(list(enumerate(position)), key=lambda x: x[1], reverse=True)
        sorted_speed = [speed[i] for i, _ in dec_pos]
        epsilon = 1e-8
        times = [(target - dec_pos[i][1]) / sorted_speed[i] for i in range(n)]
        num_fleets, first = 0, -1
        for i in range(n):
            if first != -1 and times[i] < first + epsilon:
                continue
            else:
                num_fleets += 1
                first = times[i]
        return num_fleets