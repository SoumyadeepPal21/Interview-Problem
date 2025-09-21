#include <bits/stdc++.h>
using namespace std;

// Assume Player and GameServer are given
class Player {
    int rating;
public:
    Player(int r) : rating(r) {}
    int GetRating() const { return rating; }
};

class GameServer {
public:
    static void StartGame(Player* p1, Player* p2) {
        cout << "Starting game: " << p1->GetRating()
             << " vs " << p2->GetRating() << "\n";
    }
};

class MatchMaker {
    int maxDiff;
    multiset<pair<int, Player*>> waiting; // (rating, player)

public:
    MatchMaker(int diff) : maxDiff(diff) {}

    void AddPlayer(Player* p) {
        int rating = p->GetRating();

        // Find first player >= rating - maxDiff
        auto it = waiting.lower_bound({rating - maxDiff, nullptr});

        while (it != waiting.end() && abs(it->first - rating) <= maxDiff) {
            Player* candidate = it->second;
            // Found a match
            GameServer::StartGame(candidate, p);
            waiting.erase(it);
            return; // don't insert current player
        }

        // No match found, add to waiting pool
        waiting.insert({rating, p});
    }
};
