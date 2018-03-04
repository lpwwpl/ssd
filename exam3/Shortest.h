#ifndef SHORTEST_H
#define SHORTEST_H

#include <vector>
#include <map>
#include <set>
#include <queue>
#include "Client.h"

using namespace std;

#define END_SHORTEST_ITERATOR -1

static const int START = 0;
static const int NONE = 1;
static const int BUYER = 2;
static const int SELLER = 3;

class ShortestEntry {

public:
	string email;
    set<string> bids;
    set<string> offerings;
    string via;
    int hop_count;
    int relationship;
};

class Shortest {

  private:
    map<string, ShortestEntry> table;
    queue<ShortestEntry> recently_known;

  public:

    Shortest (const string &start_email);
    vector<string> get_path(const string &destination_email);
};

#endif
