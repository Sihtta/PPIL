#include "core/Vecteur2D.h"
#include <sstream>

Vecteur2D::Vecteur2D(double x_, double y_) : x(x_), y(y_) {}

Vecteur2D Vecteur2D::operator+(const Vecteur2D &other) const
{
    return Vecteur2D(x + other.x, y + other.y);
}

Vecteur2D Vecteur2D::operator-(const Vecteur2D &other) const
{
    return Vecteur2D(x - other.x, y - other.y);
}

Vecteur2D Vecteur2D::operator*(double a) const
{
    return Vecteur2D(x * a, y * a);
}

Vecteur2D Vecteur2D::operator-() const
{
    return Vecteur2D(-x, -y);
}

double Vecteur2D::det(const Vecteur2D &other) const
{
    return x * other.y - y * other.x;
}

std::string Vecteur2D::toString() const
{
    std::ostringstream oss;
    oss << "( " << x << ", " << y << " )";
    return oss.str();
}

Vecteur2D operator*(double a, const Vecteur2D &v)
{
    return v * a;
}
