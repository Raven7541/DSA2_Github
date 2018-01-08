// GenerateModels.h			10/25/2016

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Shape.h"


// Make a triangle
bool makeTriangle(std::string fileName)
{
	Shape triangle;

	// Location
	triangle.addLoc(Loc(1.0, 0.0, 0.0));
	triangle.addLoc(Loc(1.0, 2.0, 0.0));
	triangle.addLoc(Loc(-1.0, 0.0, 0.0));

	// UV
	triangle.addUV(UV(1.0, 0.0));
	triangle.addUV(UV(.5, 1.0));
	triangle.addUV(UV(0.0, 0.0));

	// Normal
	triangle.addNorm(Norm(1.0, 1.0, 1.0));

	// Face
	triangle.addFace(Face { Vertex {1, 1, 1}, Vertex{2, 2, 2}, Vertex{3, 3, 3} });

	return triangle.writeObj(fileName);
}

// Make a quad
bool makeQuad(std::string fileName)
{
	Shape quad;

	// Location
	quad.addLoc(Loc(-1.0, -1.0, 0.0));
	quad.addLoc(Loc(-1.0, 1.0, 0.0));
	quad.addLoc(Loc(1.0, -1.0, 0.0));
	quad.addLoc(Loc(1.0, 1.0, 0.0));

	// UV
	quad.addUV(UV(0.0, 0.0));
	quad.addUV(UV(0.0, 1.0));
	quad.addUV(UV(1.0, 0.0));
	quad.addUV(UV(1.0, 1.0));

	// Normal
	quad.addNorm(Norm(0.0, 0.0, 1.0));
	quad.addNorm(Norm(0.0, 0.0, -1.0));

	// Face
	quad.addFace(Face { Vertex{1, 1, 1}, Vertex{3, 3, 1}, Vertex{2, 2, 1} });
	quad.addFace(Face { Vertex{2, 2, 1}, Vertex{3, 3, 1}, Vertex{4, 4, 1} });
	quad.addFace(Face{ Vertex{1, 3, 2}, Vertex{2, 4, 2}, Vertex{3, 1, 2} });
	quad.addFace(Face{ Vertex{4, 2, 2}, Vertex{3, 1, 2}, Vertex{2, 4, 2} });

	return quad.writeObj(fileName);
}

// Make a box
bool makeBox(std::string fileName)
{
	Shape box;

	// Location
	box.addLoc(Loc(-1.0, -1.0, 1.0));
	box.addLoc(Loc(1.0, -1.0, 1.0));
	box.addLoc(Loc(-1.0, 1.0, 1.0));
	box.addLoc(Loc(1.0, 1.0, 1.0));
	box.addLoc(Loc(-1.0, 1.0, -1.0));
	box.addLoc(Loc(1.0, 1.0, -1.0));
	box.addLoc(Loc(-1.0, -1.0, -1.0));
	box.addLoc(Loc(1.0, -1.0, -1.0));

	// UV
	box.addUV(UV(0.5, 0.666));  // front
								// vt1
	box.addUV(UV(0.75, 0.666)); // vt2
	box.addUV(UV(0.75, 0.333)); // vt3
	box.addUV(UV(0.5, 0.333));  // vt4

	box.addUV(UV(1.0, 0.666));  // right - reuse vt2 and vt3
								// vt5
	box.addUV(UV(1.0, 0.333));  // vt6

	box.addUV(UV(0.25, 0.666)); // left - reuse vt1 and vt4
								// vt7
	box.addUV(UV(0.25, 0.333)); // vt8

	box.addUV(UV(0.0, 0.666));  // back - reuse vt7 and vt8
								// vt9
	box.addUV(UV(0, 0.333));    // vt10

	box.addUV(UV(0.5, 1.0));    // top - reuse vt1 and vt2
								// vt11
	box.addUV(UV(0.75, 1.0));   // vt12
	box.addUV(UV(0.5, 0.0));    // bottom - reuse vt3 and vt4
								// vt13
	box.addUV(UV(0.75, 0.0));   // vt14

	// Normal
	box.addNorm(Norm(0.0, 0.0, 1.0));
	box.addNorm(Norm(0.0, 1.0, 0.0));
	box.addNorm(Norm(0.0, 0.0, -1.0));
	box.addNorm(Norm(0.0, -1.0, 0.0));
	box.addNorm(Norm(1.0, 0.0, 0.0));
	box.addNorm(Norm(-1.0, 0.0, 0.0));

	// Face
	box.addFace(Face { Vertex {1, 10, 1}, Vertex {2, 8, 1}, Vertex {3, 9, 1}});  // back
	box.addFace(Face { Vertex {3, 9, 1}, Vertex {2, 8, 1}, Vertex {4, 7, 1}});

	box.addFace(Face{ Vertex {2, 8, 5}, Vertex{ 8, 4, 5 }, Vertex{ 4, 7, 5 }  });  // left
	box.addFace(Face{ Vertex{ 4, 7, 5 }, Vertex{ 8, 4, 5 }, Vertex{ 6, 1, 5 } });

	box.addFace(Face{ Vertex{ 8, 4, 3 }, Vertex{ 7, 3, 3 }, Vertex{ 6, 1, 3 } });  // front
	box.addFace(Face{ Vertex{ 7, 3, 3}, Vertex {5, 2, 3}, Vertex{ 6, 1, 3 } });

	box.addFace(Face{ Vertex{ 7, 3, 6 }, Vertex{ 1, 6, 6 }, Vertex{ 5, 2, 6 } });  // right
	box.addFace(Face{ Vertex{ 1, 6, 6 }, Vertex{ 3, 5, 6 }, Vertex{ 5, 2, 6 } });

	box.addFace(Face{ Vertex{ 6, 1, 2 }, Vertex{ 5, 2, 2 }, Vertex{ 4, 11, 2 } });  // top
	box.addFace(Face{ Vertex{ 5, 2, 2 }, Vertex{ 3, 12, 2  }, Vertex{ 4, 11, 2, } });

	box.addFace(Face{ Vertex{ 8, 4, 4 }, Vertex{ 2, 13, 4 }, Vertex{ 1, 14, 4 }  });  // bottom
	box.addFace(Face{ Vertex{ 1, 14, 4 }, Vertex{ 7, 3, 4 }, Vertex{ 8, 4, 4 },  });


	return box.writeObj(fileName);
}

// Make a disc (for realzies!)
bool makeDisc(std::string fileName, float verts)
{
	Shape disc;

	if (verts < 3)
	{
		std::cout << "Not enough sides!" << std::endl;
		return false;
	}

	disc.addLoc(Loc(0, 0, 0));
	disc.addUV(UV(0.5, 0.5));
	disc.addNorm(Norm(0, 0, 1));

	for (float i = 0; i < verts; i++)
	{
		float t = i / verts;
		float x = glm::cos((2 * M_PI) * t);
		float y = glm::sin((2 * M_PI) * t);
		
		// Location
		disc.addLoc(Loc(x, y, 0));

		// UV - ((x+1)/2, (y+1)/2)
		disc.addUV(UV ((x + 1) / 2, (y + 1) / 2));

		// Face - i/i-1/1 (pattern)
		if (i == verts - 1)
		{
			disc.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ verts + 1, verts + 1, 1 }, Vertex{ 2, 2, 1 } });
		}
		else
		{
			disc.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ i + 2, i + 2, 1 }, Vertex{ i + 3, i + 3, 1 } });
		}
	}

	return disc.writeObj(fileName);
}

// Make a cylinder
bool makeCylinder(std::string fileName, float verts)
{
	Shape cylinder;

	// Top disc
	cylinder.addLoc(Loc(0, 0, 0));  // anchor
	cylinder.addUV(UV(0, 0.439));
	cylinder.addNorm(Norm(0, 0, -1));

	for (int i = 0; i < verts; i++)
	{
		float t = (float) i / verts;
		float x = glm::cos((2 * M_PI) * t);
		float y = glm::sin((2 * M_PI) * t);

		// Location
		cylinder.addLoc(Loc(x, y, 0));

		// UV - ((x+1)/2, (y+1)/2)
		cylinder.addUV(UV((x + 1) / 2, (y + 1) / 2));
	}

	// Bottom disc
	cylinder.addLoc(Loc(0, 0, 1));  // anchor
	cylinder.addUV(UV(0, 0.187));
	cylinder.addNorm(Norm(0, 0, -1));

	for (int i = 0; i < verts; i++)
	{
		float t = (float)i / verts;
		float x = glm::cos((2 * M_PI) * t);
		float y = glm::sin((2 * M_PI) * t);

		// Location
		cylinder.addLoc(Loc(x, y, 1));

		// UV - ((x+1)/2, (y+1)/2)
		cylinder.addUV(UV((x + 1) / 2, (y + 1) / 2));
	}

	// UV
	cylinder.addUV(UV(0, 1));
	cylinder.addUV(UV(1, 1));
	cylinder.addUV(UV(1, 0.374));
	cylinder.addUV(UV(0, 0.374));

	// Sides + faces
	for (int i = 0; i < verts; i++)
	{
		// Normal
		float theta = (float)(i * 2 * M_PI)/verts;
		cylinder.addNorm(Norm(glm::cos(theta), glm::sin(theta), 0));  // sides

		if (i == verts - 1)
		{
			// Top face
			cylinder.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ 2, 2, 1 }, Vertex{ verts + 1, verts + 1, 1 } });

			// Bottom face
			cylinder.addFace(Face{ Vertex{ verts + 2, verts + 2, 2 }, Vertex{ (float)i + verts + 3, (float)i + verts + 3, 2 }, Vertex{ verts + 3, verts + 3, 2 } });

			// Sides
			cylinder.addFace(Face{ Vertex{ 2, 2, 3 }, Vertex{ (float)verts + 3, (float)verts + 3, 3 }, Vertex{ (float)i + verts + 3, (float)i + verts + 3, 3 } });
			cylinder.addFace(Face{ Vertex{ (float)i + verts + 3, (float)i + verts + 3, 3 }, Vertex{ (float)verts + 1, (float)verts + 1, 3 }, Vertex{ 2, 2, 3 } });
		}
		else
		{
			// Top face
			cylinder.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ (float)i + 3, (float)i + 3, 1 }, Vertex{ (float)i + 2, (float)i + 2, 1 } });

			// Bottom face
			cylinder.addFace(Face{ Vertex{ (float)verts + 2, (float)verts + 2, 2 }, Vertex{ (float)i + verts + 3, (float)i + verts + 3, 2 }, Vertex{ (float)i + verts + 4, (float)i + verts + 4, 2 } });

			// Sides
			cylinder.addFace(Face{ Vertex{ (float)i + 3, (float)i + 3, (float)i + 3 }, Vertex{ (float)i + verts + 4, i + verts + 4, (float)i + 3 }, Vertex{ (float)i + verts + 3, (float)i + verts + 3, (float)i + 3 } });
			cylinder.addFace(Face{ Vertex{ (float)i + verts + 3, (float)i + verts + 3, (float)i + 3 }, Vertex{ (float)i + 2, (float)i + 2, (float)i + 3 }, Vertex{ (float)i + 3, (float)i + 3, (float)i + 3 } });
		}

	}

	return cylinder.writeObj(fileName);
}

// Make a sphere
bool makeSphere(std::string fileName, float lon, float lat)
{
	Shape sphere;
	
	for (int i = 0; i < lat+1; i++)
	{
		for (int j = 0; j < lon; j++)
		{
			// Location
			float u = -j / lon;
			float v = -i / lat;
			float x = glm::sin(M_PI * v) * glm::cos(2 * M_PI * u);
			float y = -glm::cos(M_PI * v);
			float z = glm::sin(M_PI * v) * glm::sin(2 * M_PI * u);
			sphere.addLoc(Loc(x, y, z));

			// UV
			sphere.addUV(UV(-u, -v));

			// Normal
			sphere.addNorm(Norm(x, y, z));
		}
	}

	sphere.addLoc(Loc(0.0, 1.0, 0.0));

	// Faces - i/i+1/i+m
	//		   i/i-1/i-m
	for (float i = 0; i < (lon * lat) + lat; i++)
	{
		if (((i + 1) + lon) < (lon * (lat+1))+2)
		{
			if (((i + 1) + lon) == (lon * (lat + 1))+1)
			{
				sphere.addFace(Face{ Vertex{ i + 1, i + 1 , i + 1 }, Vertex{ i + 2, i + 2, i + 2 }, Vertex{ (i + 1) + lon, i + lon, i + lon } });
				sphere.addFace(Face{ Vertex{ i + 1 , i + 1, i + 1 }, Vertex{ i, i, i }, Vertex{ (i + 1) - lon, (i + 1) - lon, (i + 1) - lon } });
			}
			else
			{
				if (((i + 1) - lon) <= 0)
				{
					if (i == 0)
					{
						sphere.addFace(Face{ Vertex{ i + 1, i + 1 , i + 1 }, Vertex{ i + 2, i + 2, i + 2 }, Vertex{ (i + 1) + lon, (i + 1) + lon, (i + 1) + lon } });
						sphere.addFace(Face{ Vertex{ i + 1 , i + 1 ,i + 1 }, Vertex{ i + 2, i + 2, i + 2 }, Vertex{ (i + 1), (i + 1), (i + 1) } });
					}
					else
					{
						sphere.addFace(Face{ Vertex{ i + 1, i + 1 , i + 1 }, Vertex{ i + 2, i + 2, i + 2 }, Vertex{ (i + 1) + lon, (i + 1) + lon, (i + 1) + lon } });
						sphere.addFace(Face{ Vertex{ i + 1 , i + 1 ,i + 1 }, Vertex{ i, i, i }, Vertex{ (i + 1), (i + 1), (i + 1) } });
					}
				}
				else
				{
					sphere.addFace(Face{ Vertex{ i + 1, i + 1 , i + 1 }, Vertex{ i + 2, i + 2, i + 2 }, Vertex{ (i + 1) + lon, (i + 1) + lon, (i + 1) + lon } });
					sphere.addFace(Face{ Vertex{ i + 1 , i + 1 ,i + 1 }, Vertex{ i, i, i }, Vertex{ (i + 1) - lon, (i + 1) - lon, (i + 1) - lon } });
				}
			}
		}
	}

	return sphere.writeObj(fileName);
}

// Make a hex (testing for disc)
bool makeHex(std::string fileName)
{
	Shape hex;  // radius of 1

				// Location
	hex.addLoc(Loc(1.0, 0.5, 0.0));
	hex.addLoc(Loc(1.5, 1.0, 0.0));
	hex.addLoc(Loc(1.75, 0.5, 0.0));
	hex.addLoc(Loc(1.5, 0.0, 0.0));
	hex.addLoc(Loc(0.5, 0.0, 0.0));
	hex.addLoc(Loc(0.25, 0.5, 0.0));
	hex.addLoc(Loc(0.5, 1.0, 0.0));

	// UV - ((x+1)/2, (y+1)/2)
	hex.addUV(UV(1.0, 0.75));
	hex.addUV(UV(1.25, 1.0));
	hex.addUV(UV(1.375, 0.75));
	hex.addUV(UV(1.25, 0.5));
	hex.addUV(UV(0.75, 0.5));
	hex.addUV(UV(0.625, 0.75));
	hex.addUV(UV(0.75, 1.0));

	// Normal
	hex.addNorm(Norm(0, 0, 1));

	// Face - i/i-1/1 (pattern)
	hex.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ 3, 3, 3 }, Vertex{ 2, 2, 2 } });
	hex.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ 4, 4, 4 }, Vertex{ 3, 3, 3 } });
	hex.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ 5, 5, 5 }, Vertex{ 4, 4, 4 } });
	hex.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ 6, 6, 6 }, Vertex{ 5, 5, 5 } });
	hex.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ 7, 7, 7 }, Vertex{ 6, 6, 6 } });
	hex.addFace(Face{ Vertex{ 1, 1, 1 }, Vertex{ 2, 2, 2 }, Vertex{ 7, 7, 7 } });

	// 3/2/1
	// 4/3/1
	// 5/4/1
	// 2/n/1	 (exception)

	return hex.writeObj(fileName);
}