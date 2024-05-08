/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-maxime.coustabeau
** File description:
** testMain3
*/

#include <cmath>
#include <iostream>
#include <vector>

struct Vector3 {
    float x, y, z;
};

struct Ray {
    Vector3 origin;
    Vector3 direction;
};

struct Camera {
    Vector3 origin;
    float width;
    float height;
    Vector3 screenCenter;
};

// Function to generate rays from the camera origin to each pixel on the screen
std::vector<Ray> generateRays(const Camera &camera, int screenWidth, int screenHeight)
{
    std::vector<Ray> rays;
    float pixelWidth = camera.width / screenWidth;
    float pixelHeight = camera.height / screenHeight;

    // Calculate the direction from the camera origin to the screen center
    Vector3 screenDirection = {camera.screenCenter.x - camera.origin.x, camera.screenCenter.y - camera.origin.y, camera.screenCenter.z - camera.origin.z};

    // Normalize the screen direction vector
    float length = sqrt(screenDirection.x * screenDirection.x + screenDirection.y * screenDirection.y + screenDirection.z * screenDirection.z);
    screenDirection.x /= length;
    screenDirection.y /= length;
    screenDirection.z /= length;

    // Calculate the right and up vectors based on the screen direction
    Vector3 right = {screenDirection.y, -screenDirection.x, 0}; // Cross product with (0, 0, 1)
    Vector3 up = {right.y * screenDirection.z - right.z * screenDirection.y, right.z * screenDirection.x - right.x * screenDirection.z, right.x * screenDirection.y - right.y * screenDirection.x};

    // Calculate the top left corner of the screen
    Vector3 topLeft = {camera.screenCenter.x - (camera.width / 2), camera.screenCenter.y + (camera.height / 2), camera.screenCenter.z};

    // Generate rays for each pixel
    for (int y = 0; y < screenHeight; ++y) {
        for (int x = 0; x < screenWidth; ++x) {
            // Calculate the position of the current pixel
            Vector3 pixelPosition = {topLeft.x + (x + 0.5f) * pixelWidth, topLeft.y - (y + 0.5f) * pixelHeight, topLeft.z};

            // Calculate the direction from the camera origin to the current pixel
            Vector3 direction = {pixelPosition.x - camera.origin.x, pixelPosition.y - camera.origin.y, pixelPosition.z - camera.origin.z};

            // Normalize the direction vector
            length = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
            direction.x /= length;
            direction.y /= length;
            direction.z /= length;

            // Create a ray from the camera origin to the current pixel
            Ray ray = {camera.origin, direction};
            rays.push_back(ray);
        }
    }

    return rays;
}

int main()
{
    // Define camera parameters
    Camera camera = {{0, 0, 0}, 426, 240, {0, 0, 10}};
    int screenWidth = 426;
    int screenHeight = 240;

    // Generate rays for each pixel on the screen
    std::vector<Ray> rays = generateRays(camera, screenWidth, screenHeight);

    // Output the number of rays generated
    std::cout << "Number of rays generated: " << rays.size() << std::endl;

    return 0;
}
