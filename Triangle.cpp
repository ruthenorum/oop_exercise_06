double get_det(const double x1, const double y1,
               const double x2, const double y2){
    return x1 * y2 - x2 * y1;
}

template <class T>
double gauss_area(const std::vector<std::pair<T,T>>& nodes, size_t size){
    double out = 0.0;
    auto count = size;
    for(size_t i = 0; i < (count - 1); i++){
        out += get_det(static_cast<double>(nodes[i].first),static_cast<double>(nodes[i].second),
                       static_cast<double>(nodes[i+1].first),static_cast<double>(nodes[i+1].second));
    }
    out += get_det(static_cast<double>(nodes[count-1].first),static_cast<double>(nodes[count-1].second),
                   static_cast<double>(nodes[0].first),static_cast<double>(nodes[0].second));
    return fabs(0.5 * out);
}

template<class T>
double Triangle<T>::get_square() const {
    return gauss_area<T>(edges,EDGES_COUNT);
}

template<class T>
Triangle<T>::Triangle(vertex_t<T>& _a, vertex_t<T>& _b, vertex_t<T>& _c) {
    a = _a;
    b = _b;
    c = _c;
    edges.resize(EDGES_COUNT);
    edges[0] = a;
    edges[1] = b;
    edges[2] = c;
    if (get_square() == 0){
        throw std::logic_error("It's not triangle");
    }
}

template<class T>
Triangle<T>::Triangle(std::vector<vertex_t<T>> _vec) {
    edges = _vec;
    if (get_square() == 0){
        throw std::logic_error("It's not triangle");
    }
}

template <class T>
std::ostream& operator << (std::ostream& out, const vertex_t<T>& p){
    out << p.first << " " << p.second << std::endl;
    return out;
}

template <class T>
std::ostream &operator<<(std::ostream& out, const Triangle<T>& tr) {
    out << "begin of Triangle" << std::endl;
    for(size_t i = 0; i < EDGES_COUNT; i++){
        out << tr.edges[i];
    }
    out << "Square is: " << tr.get_square() << std::endl;
    out << "end of Triangle" << std::endl;
    return out;
}
