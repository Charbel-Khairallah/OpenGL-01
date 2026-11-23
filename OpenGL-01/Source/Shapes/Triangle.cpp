#include "Triangle.h"


Triangle::Triangle() {

}

Triangle::Triangle(Vertex first, Vertex second, Vertex third) {
	AssignVerticies(std::vector<Vertex>{first, second, third});
}