#pragma once
#include "framework.h"

class Shoal
{
public:

	struct paramsStruct {
		float s, a, c, margin, turn, max_speed, min_speed, visibility_radius;
		float height, width;
		float vertices[6];
	};

	struct paramsStruct params;

	glm::vec3 positions[Application::N];
	glm::vec3 positions_bb[Application::N];
	glm::vec3 velocities[Application::N];
	glm::vec3 velocities_bb[Application::N];
	glm::mat4 models[Application::N];

	Shoal();

	void init_positions();
	void init_velocities();

	glm::mat4 calculate_rotate(glm::vec3 pos, glm::vec3 vel);

	void update_boids_cpu(double d);
	void update_boids_gpu(cudaArrays soa, double d, struct cudaGraphicsResource* cudaVBO);
	void calculate_all_models();

	//const int N = 5000;

private:
	void apply_boid_rules(int i);
	void turn_from_wall(int i);
	void speed_limit(int i);
	void teleport_through_wall(int i);
};

