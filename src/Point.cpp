#include "Point.hpp"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point &p) {
    this->x = p.get_x();
    this->y = p.get_y();
}

int Point::get_x() const {
    return this->x;
}

int Point::get_y() const {
    return this->y;
}

void Point::set_x(int x) {
    this->x = x;
}

void Point::set_y(int y) {
    this->y = y;
}

int Point::orientation(const Point &p, const Point &q, const Point &r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int Point::distSq(const Point &p1, const Point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool Point::operator==(const Point &o) {
    return this->get_x() == o.get_x() && this->get_y() == o.get_y();
}

std::ostream& operator<<(std::ostream &out, const Point &i) {
    return out << i.get_x() << ' ' << i.get_y();
}

double Point::dot_product(Point p) {
    return this->x * p.get_x() + this->y * p.get_y();
}

double Point::norm() {
    return sqrt(x * x + y * y);
}

double Point::angle(Point p) {
    Point v = Point(this->x - p.get_x(), this->y - p.get_y());
    Point w = Point(1,0);

    if (v.norm() == 0) return 0;

    return acos(v.dot_product(w) / (v.norm() * w.norm()));
}
