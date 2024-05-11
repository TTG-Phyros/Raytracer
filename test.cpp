#include <cmath>
#include <iostream>

struct Ray {
    double origin[3];
    double direction[3];
};

double dotProduct(double vec1[], double vec2[])
{
    double result = 0;
    for (int i = 0; i < 3; ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

double magnitude(double vec[])
{
    return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}

double angleBetweenRays(Ray &ray1, Ray &ray2)
{
    double dot = dotProduct(ray1.direction, ray2.direction);
    double mag1 = magnitude(ray1.direction);
    double mag2 = magnitude(ray2.direction);
    double cosAngle = dot / (mag1 * mag2);
    return acos(cosAngle) * 180.0 / M_PI; // Convert radians to degrees
}

int main()
{
    Ray ray1 = {{0, 0, 0}, {10, 10, 10}};
    Ray ray2 = {{10, 10, 10}, {10, -10, 10}};

    double angle = angleBetweenRays(ray1, ray2);
    std::cout << "Angle between rays: " << angle << " degrees" << std::endl;

    return 0;
}
