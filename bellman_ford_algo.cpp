// This is a solution code for the exercise "실습 문제 15: 욕심쟁이 로봇" in the book "코딩 테스트를 위한 자료 구조와 알고리즘 with c++"
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

const int UNKNOWN = INT_MIN;

struct Edge {
    int src;
    int dst;
    int w;
};

int shortest_path(int n, vector<Edge>& edges) {
    vector<int> dist(n*n, UNKNOWN);
    dist[0] = 0;

    // Update shortest path
    for (int i = 0; i < n-1; i++) {
        for (auto e : edges) {
            if (dist[e.src] != UNKNOWN && dist[e.dst] < dist[e.src] + e.w) {
                dist[e.dst] = dist[e.src] + e.w;
            }
        }
    }

    // check for negative weight cycle
    for (int i = 0; i < n-1; i++) {
        for (auto e : edges) {
            if (dist[e.src] != UNKNOWN && dist[e.dst] < dist[e.src] + e.w) {
                cout << "Terminate Search." << endl;
            }
        }
    }

    // For displaying the dist vector
    // for (auto x : dist) {
    //     cout << x << " ";
    // }
    // cout << endl;

    return dist.back();
}

int main() {
    int n;
    cin >> n;

    vector<Edge> edges;
    string raw_input;
    int w;
    for (int i = 0; i < n*n-1; i++) {
        cin >> raw_input;
        cin >> w;

        for (char x : raw_input) {
            int d;
            if (x == 'E') {d = i+1;}
            else if (x == 'W') {d = i-1;}
            else if (x == 'S') {d = i+n;}
            else if (x == 'N') {d = i-n;}
            Edge e = {i,d,w};
            edges.emplace_back(e);
        }
    }

    int ans = shortest_path(n, edges);
    if (ans != UNKNOWN) {cout << ans;}
    
    return 0;
}

/*
Test Case 1:
3
E -1
E -5
S 6
S -2
W 15
W -10
E -5
NE 5

Ans: 11

Test Case 2:
4
S -83
E -77
SE -93
S 86
SE -49
N -62
SE -90
S -63
S 40
NW -72
SW -11
W 67
E -82
N -62
E -67

Ans: -352

Test Case 3:
3
E -1
E -5
S 6
S -2
W 15
W -10
E -5
NE 5

Ans: Terminate Search.
*/