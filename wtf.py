from heapq import heappush, heappop
from collections import defaultdict, deque

def min_cost_to_reach_city(n, m, bus_info, roads):
    # Tạo đồ thị
    graph = defaultdict(list)
    for u, v in roads:
        graph[u].append(v)
        graph[v].append(u)
    
    # Dijkstra-like BFS
    pq = []  # Priority queue: (current_cost, current_city, current_bus)
    dist = [[float('inf')] * (n + 1) for _ in range(n + 1)]  # dist[city][bus]: Chi phí tối thiểu đến city bằng bus
    
    # Khởi tạo tại thành phố 1 với xe buýt 1
    dist[1][1] = bus_info[0][0]  # Giá khởi đầu khi dùng bus tại thành phố 1
    heappush(pq, (bus_info[0][0], 1, 1))  # Chi phí, thành phố, xe buýt đang sử dụng

    while pq:
        current_cost, city, bus = heappop(pq)
        
        # Bỏ qua trạng thái không tối ưu
        if current_cost > dist[city][bus]:
            continue

        # Lấy thông tin của tuyến buýt hiện tại
        bus_cost, max_range = bus_info[bus - 1]  # bus - 1 vì danh sách bus_info bắt đầu từ 0
        
        # BFS trong phạm vi của bus
        visited = set()
        queue = deque([(city, 0)])  # (current_city, distance_traveled)
        while queue:
            u, distance = queue.popleft()
            if u in visited or distance > max_range:
                continue
            visited.add(u)
            for v in graph[u]:
                if v not in visited:
                    queue.append((v, distance + 1))
                
                # Cập nhật chi phí khi đến v bằng cùng tuyến buýt
                if current_cost < dist[v][bus]:
                    dist[v][bus] = current_cost
                    heappush(pq, (current_cost, v, bus))

        # Thử đổi xe buýt tại thành phố hiện tại
        if current_cost + bus_info[city - 1][0] < dist[city][city]:
            new_cost = current_cost + bus_info[city - 1][0]
            dist[city][city] = new_cost
            heappush(pq, (new_cost, city, city))
    
    # Kết quả: Tìm chi phí nhỏ nhất để đến thành phố n bằng bất kỳ tuyến buýt nào
    return min(dist[n])

# Input example
n = 6
m = 6
bus_info = [
    (10, 2),  # C[1], D[1]
    (30, 1),  # C[2], D[2]
    (50, 1),  # C[3], D[3]
    (20, 3),  # C[4], D[4]
    (30, 1),  # C[5], D[5]
    (20, 1)   # C[6], D[6]
]
roads = [
    (1, 2),
    (1, 3),
    (1, 5),
    (2, 4),
    (2, 5),
    (4, 6)
]

# Output
print(min_cost_to_reach_city(n, m, bus_info, roads))  # Output: 30
