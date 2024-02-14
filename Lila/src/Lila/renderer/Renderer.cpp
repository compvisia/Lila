#include "Renderer.h"

namespace Lila {

	Renderer::Renderer() {

	}
	Renderer::~Renderer() {
		deleteQueue();
		meshes.clear();
		render.clear();
	}

	Mesh* Renderer::newMesh(const char* path) {
		Mesh* mesh = new Mesh(path);

		meshes.push_back(mesh);

		return mesh;
	}

	Mesh* Renderer::newQueueMesh(const char* path) {
		Mesh* mesh = new Mesh(path);

		meshes.push_back(mesh);
		render.push_back(mesh);

		return mesh;
	}

	void Renderer::renderQueue() {
		for(Mesh* mesh : render)
			mesh->Render();
	}
	void Renderer::renderSingle(Mesh* mesh) {
		mesh->Render();
	}
	void Renderer::renderCamera(Mesh* mesh, Camera camera) {
		mesh->Render(camera);
	}
	void Renderer::renderTexture(Mesh* mesh, Texture* texture) {
		texture->Bind();
		mesh->Render();
		texture->Unbind();
	}

	void Renderer::deleteQueue() {
		for(Mesh* mesh : meshes)
			mesh->Delete();
	}

}