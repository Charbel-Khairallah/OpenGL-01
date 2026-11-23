#include "TestWindow.h"
#include "../Shapes/Triangle.h"

TestWindow::TestWindow() : Window() {
	testTriangle = Triangle(Vertex(-0.5f, -0.5f), Vertex(0.0f, 0.5f), Vertex(0.5f, -0.5f));

	this->dynamicVertexBuffer->Add(testTriangle.GetVerticies(), testTriangle.GetVertexCount());
}


TestWindow::TestWindow(int width, int height) : Window(width, height) {

}


void TestWindow::UpdateContent() {
	glDrawArrays(GL_TRIANGLES, 0, dynamicVertexBuffer->GetVertexCount());
}