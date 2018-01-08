#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"  // glm::rotate(angle, x, y, z) gives a mat4
								  // v' = m * v
								  // v' = v rotated by m
#include <fstream>

struct aabb
{
	glm::vec3 c, r;  // center, half-width
};

struct obb
{
	glm::vec3 c, r;  // center, half-width

	glm::vec3 axis;
	float angle;
};

struct sphere
{
	glm::vec3 c;	// center
	float r;		// radius
};

int main()
{
	// declare an aabb, obb and sphere
	aabb box1;
	obb box2;
	sphere orb;

	// open teapot obj
	

	// for each vertex location v,
		// for OBB, record x, y and z for v if it's min or max
		// transform the location to v' using glm::rotate()
		// for AABB, record x, y or z for v' if it's min or max

	// print min and max for OBB and AABB
	// derive center and half-width for boxes and print them

	// call bounding sphere function, which derives and prints center and radius

	return 0;
}