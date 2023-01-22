#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#define A 0x0
#define B 0x1
#define C 0x2
#define D 0x3

class Graph {
private:
    std::int16_t vertices;
    std::int16_t **adjacency_matrix;

public:
    Graph(std::int16_t vertices, std::int16_t adjacency_matrix[][0x4]) {
        this->vertices = vertices;
        this->adjacency_matrix = new std::int16_t*[vertices];

        for (std::size_t row {0x0}; row < vertices; ++row) {
            this->adjacency_matrix[row] = new std::int16_t[vertices];

            for (std::size_t column {0x0}; column < vertices; ++column) {
                this->adjacency_matrix[row][column] = adjacency_matrix[row][column];
            }
        }
    }

    [[maybe_unused]] auto print_matrix() -> void {
        for (std::size_t row {0x0}; row < vertices; ++row) {
            for (std::size_t column {0x0}; column < vertices; ++column) {
                std::cout << adjacency_matrix[row][column] << " ";
            }

            std::cout << std::endl;
        }
    }

    [[nodiscard]] auto min_distance(const std::vector<std::int16_t>& dist, const std::vector<bool>& visited) const -> std::int16_t {
        std::int16_t min = std::numeric_limits<std::int16_t>::max();
        std::int16_t min_index;

        for (std::int16_t v = 0x0; v < vertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    auto path_finder(std::int16_t start_vertex, std::int16_t target_vertex) -> void {
        std::vector<std::int16_t> dist(vertices, std::numeric_limits<std::int16_t>::max());
        std::vector<std::int16_t> prev(vertices, -1);
        std::vector<bool> visited(vertices, false);

        dist[start_vertex] = 0;

        for (std::int16_t i = 0; i < vertices; i++) {
            std::int16_t u = min_distance(dist, visited);
            visited[u] = true;

            for (std::int16_t v = 0; v < vertices; v++) {
                if (!visited[v] && adjacency_matrix[u][v] != -1 && dist[u] != std::numeric_limits<std::int16_t>::max()
                    && dist[u] + adjacency_matrix[u][v] < dist[v]) {
                    dist[v] = static_cast<std::int16_t>(dist[u] + adjacency_matrix[u][v]);
                    prev[v] = u;
                }
            }
        }

        std::cout << "Shortest path from vertex " << start_vertex << " to vertex " << target_vertex << ": ";
        std::vector<std::int16_t> path;
        for (std::int16_t vertex = target_vertex; vertex != -1; vertex = prev[vertex]) path.push_back(vertex);
        std::reverse(path.begin(), path.end());
        for (auto i : path) std::cout << i << " ";
        std::cout << std::endl;
    }
};

auto main() -> int {
    std::int16_t vertices {0x4};
    std::int16_t adjacency_matrix[0x4][0x4] = {
            {0, 5, 2, -1},
            {5, 0, 1, 2},
            {2, 1, 0, 3},
            {-1, 2, 3, 0}
    };

    Graph graph(vertices, adjacency_matrix);
    graph.path_finder(A, B);
    graph.path_finder(A, C);
    graph.path_finder(A, D);
    return 0x0;
}
