#include <iostream>
#include <vector>
#include <fstream>

#include "vec3.h"
#include "body.h"

using namespace std;

// Global Variable
const double dt = 0.01; // Time step for simulation (Not capitalized because of mathematical convention. DT is weird)

Vec3 calc_gravity(const Body& b1, const Body& b2);
vector<Body> rk4_sim(const int bodies, const double max_time, const double dt);
void file_output(const vector<Body>& body_list, const string& filename);

// *************************************************** Main program ****************************************************
int main() {
    vector<Body> body_list = rk4_sim(50, 10.0, dt);
    file_output(body_list, "output.csv");
    return 0;
}

//  ********************************************** Function Definitions ************************************************

// Calculates the gravitational force (gravity is like 1.5*10^11 times as strong in this sim)
Vec3 calc_gravity(const Body& b1, const Body& b2) {
    const double G = 1.0;  // Gravitational constant, adjust as needed. the real value is 6.67430e-11, but thats too little.
    Vec3 r = b2.positions.back() - b1.positions.back();
    double distance = r.magnitude();

    if (distance == 0) return Vec3(0, 0, 0);

    Vec3 force = r * (G * b1.mass * b2.mass / (distance * distance * distance));
    return force;
}

// This is the function that does Runge-Kutta Order 4 for every object. This is O(n^2), unfortunately.
// Better grav sims are O(nlog(n)), but they are very complicated
vector<Body> rk4_sim(const int bodies, const double max_time, const double dt) {
    double current_time = 0.0;

    vector<Body> body_list;
    for (int i = 0; i < bodies; i++) {
        Body body;
        body_list.push_back(body);
    }

    // ********************************** RK4 loop for differential equation solution **********************************
    while (current_time < max_time) {
        vector<Body> temp_bodies = body_list;

        for (int i = 0; i < bodies; i++) {
            Vec3 pos0 = body_list[i].positions.back();
            Vec3 vel0 = body_list[i].velocities.back();

            auto get_acceleration = [&](const Vec3& pos, const vector<Body>& state_bodies, int idx) -> Vec3 {
                Vec3 net_force(0, 0, 0);
                for (int j = 0; j < bodies; j++) {
                    if (j == idx) continue;
                    Vec3 other_pos = state_bodies[j].positions.back();
                    Vec3 r = other_pos - pos;
                    double dist = r.magnitude();
                    if (dist == 0) continue;
                    net_force = net_force + (r * (1.0 * body_list[i].mass * body_list[j].mass / (dist * dist * dist)));
                }
                return net_force / body_list[i].mass;
            };

            // k1
            Vec3 k1_v = get_acceleration(pos0, body_list, i);
            Vec3 k1_r = vel0;

            // k2
            Vec3 k2_r_input = pos0 + k1_r * (dt / 2.0);
            Vec3 k2_v_input = vel0 + k1_v * (dt / 2.0);
            temp_bodies[i].positions.back() = k2_r_input;
            Vec3 k2_v = get_acceleration(k2_r_input, temp_bodies, i);
            Vec3 k2_r = k2_v_input;

            // k3
            Vec3 k3_r_input = pos0 + k2_r * (dt / 2.0);
            Vec3 k3_v_input = vel0 + k2_v * (dt / 2.0);
            temp_bodies[i].positions.back() = k3_r_input;
            Vec3 k3_v = get_acceleration(k3_r_input, temp_bodies, i);
            Vec3 k3_r = k3_v_input;

            // k4
            Vec3 k4_r_input = pos0 + k3_r * dt;
            Vec3 k4_v_input = vel0 + k3_v * dt;
            temp_bodies[i].positions.back() = k4_r_input;
            Vec3 k4_v = get_acceleration(k4_r_input, temp_bodies, i);
            Vec3 k4_r = k4_v_input;

            // Final updates
            Vec3 next_velocity = vel0 + (dt / 6.0) * (k1_v + 2.0 * k2_v + 2.0 * k3_v + k4_v);
            Vec3 next_position = pos0 + (dt / 6.0) * (k1_r + 2.0 * k2_r + 2.0 * k3_r + k4_r);

            Vec3 net_force = get_acceleration(pos0, body_list, i) * body_list[i].mass;
            
            // Storing forces, accelerations, velocities, and positions
            body_list[i].forces.push_back(net_force);
            body_list[i].accelerations.push_back(k1_v);
            body_list[i].velocities.push_back(next_velocity);
            body_list[i].positions.push_back(next_position);
        }
        current_time += dt;
    }
    return body_list;
}

// Writes the data to a file
void file_output(const vector<Body>& body_list, const string& filename) {
    ofstream out(filename);

    // Check if the file opened successfully
    if (!out.is_open()) {
        cerr << "Failed to open output file.\n";
        return;
    }
    // Write time header
    out << "t,";

    // Write header
    for (size_t i = 0; i < body_list.size(); ++i) {
        out << "x" << i << ",y" << i << ",z" << i;
        if (i != body_list.size() - 1) out << ",";
    }
    out << "\n";

    // Find number of recorded time steps
    size_t steps = body_list[0].positions.size();

    // Write the data.
    for (size_t t = 0; t < steps; ++t) {
        out << t * dt << ",";  // Time step
        for (size_t i = 0; i < body_list.size(); ++i) {
            const Vec3& pos = body_list[i].positions[t];
            out << pos.x << "," << pos.y << "," << pos.z;
            if (i != body_list.size() - 1) out << ",";
        }
        out << "\n";
    }

    out.close();
}

