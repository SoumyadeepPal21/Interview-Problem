// Given on-call rotation schedule for multiple people by: their name, start time and end time of the rotation:

// Abby 1 10
// Ben 5 7
// Carla 6 12
// David 15 17

// Your goal is to return rotation table without overlapping periods representing who is on call during that time. Return "Start time", "End time" and list of on-call people:

// 1 5 Abby
// 5 6 Abby, Ben
// 6 7 Abby, Ben, Carla
// 7 10 Abby, Carla
// 10 12 Carla
// 15 17 David




#include <bits/stdc++.h>
using namespace std;

struct Person {
	int start;
	int end;
	string name;
};

struct Event {
	int time;
	int type;
	string name;
};

void fun(vector<Person> meetings) {
	vector<Event> events;
	for (int i = 0; i < meetings.size(); i++) {
		Event e1, e2;
		e1.name = e2.name = meetings[i].name;
		e1.time = meetings[i].start;
		e2.time = meetings[i].end;
		e1.type = 1;
		e2.type = 0;
		events.push_back(e1);
		events.push_back(e2);
	}
	sort(events.begin(), events.end());
	// avaibale people
	int lastEventTime = 0;
	unordered_set<string> people;
	for (int i = 0, j; i < events.size(); i = j) {
		if (people.size() > 0) {
			cout << lastEventTime << " " << events[i].time << " ";
			for (auto u : people) {
				cout << u << " ";
			}
			cout << endl;
		}
		for (j = i; j < events.size() && events[j].time == events[i].time; j++) {
			if (events[j].type == 0) {
				people.erase(events[j].name);
			} else {
				people.insert(events[j].name);
			}
		}
		lastEventTime = events[i].time;
	}

}

int main() {
	int n; cin >> n;
	vector<Person> meetings;
	for (int i = 0; i < n; i++) {
		string name;
		int st, end;
		cin >> name >> st >> end;
		Person p;
		p.start = st;
		p.end = end;
		p.name = name;
		meetings.push_back(p);
	}
	fun(meetings);
}