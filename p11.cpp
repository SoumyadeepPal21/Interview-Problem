// https://leetcode.com/discuss/post/5584385/google-interview-experience-l4-software-7n277/

// Design a music playlist shuffler (music are represented as array of anything(can be integer, string, etc))

// It should always return a random music.
//                         The returned music should not be returned again for the next K plays.


#include <bits/stdc++.h>
using namespace std;


class RandomSongPlayer {
	vector<string> allSongs;
	int totalSongs = 0;
	int k;
	int blockedSongs = 0;
	unordered_map<string, int> indices;
	int events = 0;
	map<int, string> getBack;
public:
	RandomSongPlayer(int k) {
		this->k = k;
	}

	void f(int event) {
		string s = getBack[event];
		int index = indices[s];
		int blockedSongIndex = allSongs.size() - blockedSongs;
		blockedSongs--;
		if (index == blockedSongIndex) return;
		indices[allSongs[index]] = blockedSongIndex;
		indices[allSongs[blockedSongIndex]] = index;
		swap(allSongs[blockedSongIndex], allSongs[index]);
	}
	void insertSong(string& song) {
		++events;
		if (getBack.count(events)) {
			f(events);
		}
		if (blockedSongs == 0) {
			allSongs.push_back(song);
			indices[song] = allSongs.size() - 1;
			return;
		}
		int firstBlockedSongIndex = allSongs.size() - blockedSongs;
		string blockedSong = allSongs[firstBlockedSongIndex];
		allSongs[firstBlockedSongIndex] = song;
		indices[song] = firstBlockedSongIndex;
		allSongs.push_back(blockedSong);
		indices[blockedSong] = allSongs.size() - 1;
	}

	string getRandomSong()  {
		events++;
		if (getBack.count(events)) {
			f(events);
		}
		int totalSongs = allSongs.size();
		int avaliableSongs = totalSongs - blockedSongs;
		if (avaliableSongs == 0) return "";
		blockedSongs++;
		int index = rand() % avaliableSongs;
		string ans = allSongs[index];
		if (avaliableSongs > 1) {
			indices[allSongs[avaliableSongs - 1]] = index;
			indices[allSongs[index]] = avaliableSongs - 1;
			swap(allSongs[avaliableSongs - 1], allSongs[index]);
		}
		getBack[events + k] = ans;
		blockedSongs++;
		return ans;
	}
};