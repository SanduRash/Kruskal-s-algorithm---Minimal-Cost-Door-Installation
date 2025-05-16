// Sandu Galbokka Hewa
// Project 4
// May 4, 2025
// Find minimal total cost

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// This represents a connection between two rooms (an Edge)
class Connection {
public:
    int roomA, roomB;
    int connectionCost;

    Connection(int roomA, int roomB, int connectionCost)
        : roomA(roomA), roomB(roomB), connectionCost(connectionCost) {}

  // This is for sort algorithm
    bool operator<(const Connection& other) const {
        return connectionCost < other.connectionCost;
    }
};

// This represents Union-Find structure 
class UnionFind {
    vector<int> parent;
public:
    UnionFind(int numElements) {
        parent.resize(numElements);
        for (int i = 0; i < numElements; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
	  parent[x] = find(parent[x]); //This will keep checking room's root
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false; //if both roots is same
        parent[rootX] = rootY; // connect the two doors
        return true;
    }
};

// Function to get the index of a room or assign a new one
int getRoomIndex(const string& roomName, vector<string>& roomList) {
    for (unsigned long i = 0; i < roomList.size(); ++i)
        if (roomList[i] == roomName)
            return i;
    roomList.push_back(roomName);
    return roomList.size() - 1;
}

int main(int argc, char* argv[]) {
    ifstream inputFile(argv[1]);

    vector<string> roomList;
    vector<Connection> connections;
    string roomName1, roomName2;
    int cost;

    // Read the input file and create connections
    while (inputFile >> roomName1 >> roomName2 >> cost) {
        int index1 = getRoomIndex(roomName1, roomList);
        int index2 = getRoomIndex(roomName2, roomList);
        connections.push_back(Connection(index1, index2, cost));
    }

    // Sort connections by cost 
    sort(connections.begin(), connections.end());

    UnionFind uf(roomList.size());
    int totalMinimumCost = 0;

    // Apply Kruskal's algorithm
    for (const auto& connection : connections) {
        if (uf.unite(connection.roomA, connection.roomB)) {
            totalMinimumCost += connection.connectionCost;
        }
    }

    cout << totalMinimumCost << endl;
    return 0;
}
