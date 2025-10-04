// https://leetcode.com/discuss/post/6033289/google-l3-interview-experience-oct-2024-0xzt8/
// There are n number of routers connected to each other at some distances. A source router src will receive a message and broadcast it to all routers within specified distance d. Return True/False weather destination router des got the message or not. (Simple BFS algorithm).
// Given: router names and their distances, src, des and d.
1. // FollowUp: Message goes only to first nearest router. Return True/False for the same question.

O(N ^ 2) create graph, do bfs





2. https://leetcode.com/discuss/post/5741664/google-l4-backened-bangalore-or-hyderaba-dard/

	q.push({source_x, source_y, 0});
while (!q.empty()) {
	auto u = q.front(); q.pop();
	int x = u[0], y = u[1], obs = u[2];
	if (x == dest) return obs;
	if (visited[x][y]) continue;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (isObs[nx][ny]) {
			q.push_back({nx, ny, obs + 1});
		} else {
			q.push_front({nx, ny, obs});
		}
	}
}

