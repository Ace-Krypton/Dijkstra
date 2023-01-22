#include <iostream>
#include <iterator>

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

    auto print_matrix() -> void {
        for (std::size_t row {0x0}; row < vertices; ++row) {
            for (std::size_t column {0x0}; column < vertices; ++column) {
                std::cout << adjacency_matrix[row][column] << " ";
            }

            std::cout << std::endl;
        }
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
    graph.print_matrix();

    return 0x0;
}
