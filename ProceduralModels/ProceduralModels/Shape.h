// Shape.h			10/25/2016

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "glm/glm.hpp"


// Vertex location - v
struct Loc
{
	glm::vec3 loc;

	Loc(float v1, float v2, float v3)
	{
		loc = glm::vec3(v1, v2, v3);
	}
};

// Texture - vt
struct UV
{
	glm::vec2 uv;

	UV(float vt1, float vt2)
	{
		uv = glm::vec2(vt1, vt2);
	}
};

// Normal vertex/vertices - n
struct Norm
{
	glm::vec3 norm;

	Norm(float vn1, float vn2, float vn3)
	{
		norm = glm::vec3(vn1, vn2, vn3);
	}
};

// Vertex
struct Vertex
{
	float loc;
	float uv;
	float norm;
};

// Faces, indices... - f
struct Face
{
	Vertex v1;
	Vertex v2;
	Vertex v3;
};

class Shape
{

private:
	std::vector<Loc> location;
	std::vector<UV> texture;
	std::vector<Norm> normal;
	std::vector<Face> face;

public:
	void addLoc(Loc newLoc)
	{
		location.push_back(newLoc);
	}

	void addUV(UV newUV)
	{
		texture.push_back(newUV);
	}

	void addNorm(Norm newNorm)
	{
		normal.push_back(newNorm);
	}

	void addFace(Face newFace)
	{
		face.push_back(newFace);
	}

	bool writeObj(std::string fileName)
	{
		// Check if any of collections is empty
		if (location.empty() && texture.empty()
				&& normal.empty() && face.empty())
		{
			return false;
		}

		// Create ofstream object
		fileName.append(".obj");
		std::ofstream file(fileName);

		// Try to upload data
		if (file.is_open())
		{
			// Location
			for (int i = 0; i < location.size(); i++)
			{
				file << "v " << location[i].loc.x << " " << location[i].loc.y << " " << location[i].loc.z << std::endl;
			}

			// UV
			for (int i = 0; i < texture.size(); i++)
			{
				file << "vt " << texture[i].uv.x << " " << texture[i].uv.y << " " << std::endl;
			}

			// Normal
			for (int i = 0; i < normal.size(); i++)
			{
				file << "vn " << normal[i].norm.x << " " << normal[i].norm.y << " " << normal[i].norm.z << std::endl;
			}

			// Face
			for (int i = 0; i < face.size(); i++)
			{
				file << "f " << face[i].v1.loc << "/" << face[i].v1.uv << "/" << face[i].v1.norm << " "
					<< face[i].v2.loc << "/" << face[i].v2.uv << "/" << face[i].v2.norm << " "
					<< face[i].v3.loc << "/" << face[i].v3.uv << "/" << face[i].v3.norm << std::endl;
			}

			file.close();
			return true;
		}
		else
		{
			return false;
		}
	}

};