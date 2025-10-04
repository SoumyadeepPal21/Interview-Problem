// https://leetcode.com/discuss/post/6033289/google-l3-interview-experience-oct-2024-0xzt8/
// There are n number of routers connected to each other at some distances. A source router src will receive a message and broadcast it to all routers within specified distance d. Return True/False weather destination router des got the message or not. (Simple BFS algorithm).
// Given: router names and their distances, src, des and d.
// FollowUp: Message goes only to first nearest router. Return True/False for the same question.


O(N * D) bfs, {node, no of routers visited till now, distance(d')}
	        O(N ^ 2) create graph, do bfs