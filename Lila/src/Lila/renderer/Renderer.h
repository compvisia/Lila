#pragma once

#include "Lila/renderer/Mesh.h"
#include "Lila/renderer/Texture.h"

#include <vector>

namespace Lila {

	class Renderer {
	public:
		Renderer();
		~Renderer();

		Mesh* newMesh(const char* path);
		Mesh* newQueueMesh(const char* path);

		void renderQueue();
		void renderSingle(Mesh* mesh);
		void renderCamera(Mesh* mesh, Camera camera);
		void renderTexture(Mesh* mesh, Texture* texture);

		void deleteQueue();

	private:
		std::vector<Mesh*> render;
		std::vector<Mesh*> meshes;
	};

}