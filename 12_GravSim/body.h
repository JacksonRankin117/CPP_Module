#include <vector>
#include <cmath>
#include <random>  // Include this for random number generation
#include "vec3.h"  // Include vec3 header to update positions of bodies

using namespace std;

class Body {
  public:
    static random_device rd;
    static mt19937 gen;
    static uniform_real_distribution<double> dist;


    Vec3 init_position;
    Vec3 init_velocity;
    Vec3 init_acceleration = {0, 0, 0};
    Vec3 init_force = {0, 0, 0};

    double mass = 100000000.0;
    double radius = 1.0;

    vector<Vec3> forces;
    vector<Vec3> accelerations;
    vector<Vec3> velocities;
    vector<Vec3> positions;

    Body() {
        init_position = Vec3(dist(gen), dist(gen), dist(gen));
        init_velocity = Vec3(0.0 * dist(gen), 0.0 * dist(gen), 0.0 * dist(gen));

        // Initialize state history based on initial conditions
        positions.push_back(init_position);
        velocities.push_back(init_velocity);
        accelerations.push_back(init_acceleration);
        forces.push_back(init_force);
    }

    // Funstion to display the body's state
    void display() const {
        cout << "Position: ";
        positions.back().display();
        cout << "Velocity: ";
        velocities.back().display();
        cout << "Acceleration: ";
        accelerations.back().display();
        cout << "Mass: " << mass << endl;
        cout << "Radius: " << radius << endl;
        cout << "Force: ";
        forces.back().display();
    }
};

// Static member initialization
random_device Body::rd;
mt19937 Body::gen(Body::rd());
uniform_real_distribution<double> Body::dist(-10000.0, 10000.0);


