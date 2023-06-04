#pragma once

#include <cmath>

class Point {
  private:
    int x, y;

    double dot_product(Point p);
    double norm();

  public:
    Point(int x = 0, int y = 0);
    Point(const Point &p);

    int get_x() const;
    int get_y() const;
    void set_x(int x);
    void set_y(int y);

    static int orientation(const Point &p, const Point &q, const Point &r);

    static int distSq(const Point &p1, const Point &p2);

    bool operator==(const Point &o);

    double angle(Point p);
};
