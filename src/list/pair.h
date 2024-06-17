

#ifndef AIZO_GRAPHS_PAIR_H
#define AIZO_GRAPHS_PAIR_H

#include <ostream>

template<class T1, class T2>
class pair {
public:
    T1 first;
    T2 second;

    pair() = default;
    ~pair() = default;
    pair(T1 first, T2 second) : first(first), second(second) {}

    bool operator==(const pair<T1, T2> &other) const {
        return this->first == other.first && this->second == other.second;
    }

    bool operator!=(const pair<T1, T2> &other) const {
        return this->first != other.first || this->second != other.second;
    }

    friend auto operator<<(std::ostream& os, pair const& pair) -> std::ostream& {
        return os << "(" << pair.first << ", " << pair.second << ")";
    }
};

template class pair<unsigned long, unsigned long>;
template class pair<int, ushort*>;

#endif //AIZO_GRAPHS_PAIR_H
