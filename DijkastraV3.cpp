#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <limits> // for numeric_limits

#include <queue>
#include <utility> // for pair
#include <algorithm>
#include <iterator>
using namespace std;



typedef int vertex_t;
typedef double weight_t;

typedef pair<vertex_t, weight_t> Neighbor;
typedef vector<Neighbor> Neighbors;
typedef vector<Neighbors> Neighborhood;

void DijkstraComputePaths(vertex_t source, const Neighborhood &neighborhood, vector<weight_t> &min_distance, vector<vertex_t> &previous) {
    int n = neighborhood.size();
    min_distance.clear();
    min_distance.resize(n, numeric_limits<double>::infinity());
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    // we use greater instead of less to turn max-heap into min-heap
    priority_queue<Neighbor, vector<Neighbor>, greater<Neighbor>> vertex_queue;
    vertex_queue.push(make_pair(min_distance[source], source));

    while (!vertex_queue.empty()) {
        weight_t dist = vertex_queue.top().first;
        vertex_t u = vertex_queue.top().second;
        vertex_queue.pop();

        // Because we leave old copies of the vertex in the priority queue
        // (with outdated higher distances), we need to ignore it when we come
        // across it again, by checking its distance against the minimum distance
        if (dist > min_distance[u]) continue;
        // Visit each edge exiting u
        const Neighbors &neighbors = neighborhood[u];
            for (Neighbors::const_iterator neighbor_iter = neighbors.begin(); neighbor_iter != neighbors.end(); neighbor_iter++) {
                vertex_t v = neighbor_iter->first;
                weight_t weight = neighbor_iter->second;
                weight_t distance_through_u = dist + weight;
            if (distance_through_u < min_distance[v]) {
                min_distance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.push(make_pair(min_distance[v], v));
            }
        }
    }
}


list<vertex_t> DijkstraGetShortestPathTo(vertex_t vertex, const vector<vertex_t> &previous) {
    list<vertex_t> path;
    for ( ; vertex != -1; vertex = previous[vertex]) path.push_front(vertex);
    return path;
}


int main() {
    // remember to insert edges both ways for an undirected graph
    Neighborhood neighborhood(6);
    // 0 = a
    neighborhood[0].push_back(make_pair(1, 7));
    neighborhood[0].push_back(make_pair(2, 9));
    neighborhood[0].push_back(make_pair(5, 14));
    // 1 = b
    neighborhood[1].push_back(make_pair(0, 7));
    neighborhood[1].push_back(make_pair(2, 10));
    neighborhood[1].push_back(make_pair(3, 15));
    // 2 = c
    neighborhood[2].push_back(make_pair(0, 9));
    neighborhood[2].push_back(make_pair(1, 10));
    neighborhood[2].push_back(make_pair(3, 11));
    neighborhood[2].push_back(make_pair(5, 2));
    // 3 = d
    neighborhood[3].push_back(make_pair(1, 15));
    neighborhood[3].push_back(make_pair(2, 11));
    neighborhood[3].push_back(make_pair(4, 6));
    // 4 = e
    neighborhood[4].push_back(make_pair(3, 6));
    neighborhood[4].push_back(make_pair(5, 9));
    // 5 = f
    neighborhood[5].push_back(make_pair(0, 14));
    neighborhood[5].push_back(make_pair(2, 2));
    neighborhood[5].push_back(make_pair(4, 9));

    vector<weight_t> min_distance;
    vector<vertex_t> previous;
    DijkstraComputePaths(0, neighborhood, min_distance, previous);
    cout << "Distance from 0 to 5: " << min_distance[5] << endl;
    list<vertex_t> path = DijkstraGetShortestPathTo(5, previous);
    cout << "Path : ";
    copy(path.begin(), path.end(), ostream_iterator<vertex_t>(cout, " "));
    cout << endl;

    return 0;
}
