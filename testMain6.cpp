#include <SFML/Graphics.hpp>
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

// Function to calculate the intersection between a ray and a sphere
bool raySphereIntersect(const Ray &ray, const Sphere &sphere)
{
    Vector3 oc = {ray.origin.x - sphere.center.x, ray.origin.y - sphere.center.y, ray.origin.z - sphere.center.z};
    float a = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z;
    float b = 2.0f * (oc.x * ray.direction.x + oc.y * ray.direction.y + oc.z * ray.direction.z);
    float c = oc.x * oc.x + oc.y * oc.y + oc.z * oc.z - sphere.radius * sphere.radius;
    float discriminant = b * b - 4 * a * c;
    return discriminant >= 0;
}

// Function to generate rays from the camera origin to each pixel on the screen
std::vector<Ray> generateRays(const Vector3 &cameraOrigin, const Vector3 &screenCenter, float screenWidth, float screenHeight)
{
    std::vector<Ray> rays;
    float pixelWidth = screenWidth / 426.0f;
    float pixelHeight = screenHeight / 240.0f;

    // Calculate the direction from the camera origin to the screen center
    Vector3 screenDirection = {screenCenter.x - cameraOrigin.x, screenCenter.y - cameraOrigin.y, screenCenter.z - cameraOrigin.z};

    // Normalize the screen direction vector
    float length = sqrt(screenDirection.x * screenDirection.x + screenDirection.y * screenDirection.y + screenDirection.z * screenDirection.z);
    screenDirection.x /= length;
    screenDirection.y /= length;
    screenDirection.z /= length;

    // Calculate the right and up vectors based on the screen direction
    Vector3 right = {screenDirection.y, -screenDirection.x, 0}; // Cross product with (0, 0, 1)
    Vector3 up = {right.y * screenDirection.z - right.z * screenDirection.y, right.z * screenDirection.x - right.x * screenDirection.z, right.x * screenDirection.y - right.y * screenDirection.x};

    // Calculate the top left corner of the screen
    Vector3 topLeft = {screenCenter.x - (screenWidth / 2), screenCenter.y + (screenHeight / 2), screenCenter.z};

    // Generate rays for each pixel
    for (int y = 0; y < 240; ++y) {
        for (int x = 0; x < 426; ++x) {
            // Calculate the position of the current pixel
            Vector3 pixelPosition = {topLeft.x + (x + 0.5f) * pixelWidth, topLeft.y - (y + 0.5f) * pixelHeight, topLeft.z};

            // Calculate the direction from the camera origin to the current pixel
            Vector3 direction = {pixelPosition.x - cameraOrigin.x, pixelPosition.y - cameraOrigin.y, pixelPosition.z - cameraOrigin.z};

            // Normalize the direction vector
            length = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
            direction.x /= length;
            direction.y /= length;
            direction.z /= length;

            // Create a ray from the camera origin to the current pixel
            Ray ray = {cameraOrigin, direction};
            rays.push_back(ray);
        }
    }

    return rays;
}

int main()
{
    // Define camera parameters
    Vector3 cameraOrigin = {0, 0, 0};
    float screenWidth = 426;
    float screenHeight = 240;
    Vector3 screenCenter = {0, 0, 10};

    // Define sphere parameters
    Sphere sphere = {{0, 0, 50}, 5};

    // Generate rays for each pixel on the screen
    std::vector<Ray> rays = generateRays(cameraOrigin, screenCenter, screenWidth, screenHeight);

    // Create an SFML window
    sf::RenderWindow window(sf::VideoMode(426, 240), "Ray Casting");

    // Main loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Render rays
        for (const Ray &ray : rays) {
            // Check if the ray intersects the sphere
            if (raySphereIntersect(ray, sphere)) {
                // If the ray hits the sphere, draw a red pixel
                sf::RectangleShape pixel(sf::Vector2f(1, 1));
                pixel.setPosition(ray.origin.x + 213, 240 - ray.origin.y); // Draw the pixel at the ray origin
                pixel.setFillColor(sf::Color::Red);
                window.draw(pixel);
            }
        }

        // Display the window
        window.display();
    }

    return 0;
}
