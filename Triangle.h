#ifndef OOP6_TRIANGLE_H
#define OOP6_TRIANGLE_H

#include <vector>
#include <cmath>

#define EDGES_COUNT 3

template <class T>
using vertex_t = std::pair<T,T>;

template <class T>
class Triangle {
public:
    vertex_t<T> a,b,c;
    std::vector<vertex_t<T>> edges;
    double get_square() const;
    explicit Triangle(vertex_t<T>& _a,vertex_t<T>& _b,vertex_t<T>& _c);
    explicit Triangle(std::vector<vertex_t<T>> _vec);
};

template <class T>
std::ostream& operator << (std::ostream& out, const Triangle<T>& tr);

#include "Triangle.cpp"
#endif //OOP6_TRIANGLE_H
