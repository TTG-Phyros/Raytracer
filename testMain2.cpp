/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-maxime.coustabeau
** File description:
** testMain2
*/

#include <cmath>
#include <iostream>

struct Vector3 {
    float x, y, z;
};

struct Ray {
    Vector3 origin;
    Vector3 direction;
};

struct Sphere {
    Vector3 center;
    float radius;
};

bool rayPointSphere(const Ray &ray, const Sphere &sphere)
{
    // Calculate the vector from the ray origin to the sphere center
    Vector3 toCenter = {sphere.center.x - ray.origin.x, sphere.center.y - ray.origin.y, sphere.center.z - ray.origin.z};

    // Calculate the dot product of the ray direction and the vector to the sphere center
    float dotProduct = ray.direction.x * toCenter.x + ray.direction.y * toCenter.y + ray.direction.z * toCenter.z;

    // If the dot product is negative, the ray is pointing towards the sphere
    return dotProduct >= 0;
}

bool raySphereIntersect(const Ray &ray, const Sphere &sphere)
{
    Vector3 oc = {ray.origin.x - sphere.center.x, ray.origin.y - sphere.center.y, ray.origin.z - sphere.center.z};
    float a = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z;
    float b = 2.0f * (oc.x * ray.direction.x + oc.y * ray.direction.y + oc.z * ray.direction.z);
    float c = oc.x * oc.x + oc.y * oc.y + oc.z * oc.z - sphere.radius * sphere.radius;
    float discriminant = b * b - 4 * a * c;
    return discriminant >= 0;
}

int main()
{
    Ray ray = {{0, 0, 0}, {1, 1, 1}};
    Sphere sphere = {{5, 5, 5}, 2};

    if (rayPointSphere(ray, sphere) && raySphereIntersect(ray, sphere)) {
        std::cout << "Ray intersects the sphere." << std::endl;
    } else {
        std::cout << "Ray does not intersect the sphere." << std::endl;
    }

    return 0;
}
