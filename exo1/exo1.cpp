#include <iostream>
#include <cmath>

class Circle {
private:
  double x, y, radius;

public:
  Circle(double x, double y, double radius) : x(x), y(y), radius(radius) {}

  double perimeter() const
  {
    return 2 * M_PI * radius;
  }

  double area() const
  {
    return M_PI * radius * radius;
  }

  void set_pos(double new_x, double new_y)
  {
    x = new_x;
    y = new_y;
  }

  void set_radius(double new_radius)
  {
    radius = new_radius;
  }

  double get_x() const { return x; }
  double get_y() const { return y; }
  double get_radius() const { return radius; }
};

class Rectangle {
private:
  double x, y, width, height;

public:
  Rectangle(double x, double y, double width, double height)
      : x(x), y(y), width(width), height(height) {}

  double perimeter() const
  {
    return 2 * (width + height);
  }

  double area() const
  {
    return width * height;
  }

  void set_pos(double new_x, double new_y)
  {
    x = new_x;
    y = new_y;
  }

  void set_dimensions(double new_width, double new_height)
  {
    width = new_width;
    height = new_height;
  }

  double get_x() const { return x; }
  double get_y() const { return y; }
  double get_width() const { return width; }
  double get_height() const { return height; }
};

int main() {
  Circle c{0, 0, 1};
  std::cout << "Perimeter: " << c.perimeter() << std::endl;
  c.set_pos(1, 1);
  std::cout << "Coordinates of the center: (" << c.get_x() << ", " << c.get_y() << ")" << std::endl;
  std::cout << "Area: " << c.area() << std::endl;

  Rectangle r{0, 0, 1, 2};
  std::cout << "Perimeter: " << r.perimeter() << std::endl;
  r.set_pos(-1, -1);
  std::cout << "Coordinates of the top left corner: (" << r.get_x() << ", " << r.get_y() << ")" << std::endl;
  std::cout << "Area: " << r.area() << std::endl;

  return 0;
}