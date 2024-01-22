#include "Lila/Lila.h"

#include "imgui.h"
#include "Platform/imgui_impl_glfw.h"
#include "Platform/imgui_impl_opengl3.h"

struct Inspector {
    size_t nameSize = 64;
    char name[64] = "Test Cube";

    Lila::MeshSpecs* meshSpecs;

};

int main(void) {

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	ImGui::StyleColorsDark();

	Lila::Window* Window = new Lila::Window("Hello", 1280, 720);
    
    Lila::FrameSpecs FrameSpecs;
    FrameSpecs.width = Window->getSize().X();
    FrameSpecs.height = Window->getSize().Y();
    Lila::FrameBuffer* FrameBuffer = new Lila::FrameBuffer(FrameSpecs);

    Lila::Texture* Texture;
    #ifdef _WIN32
        Texture = new Lila::Texture("assets/shaders/image.png");
    #else
        Texture = new Lila::Texture("Lila/assets/shaders/image.png");
    #endif

    Lila::MeshSpecs MeshSpecs;
    Lila::Mesh* Mesh = new Lila::Mesh("dfghsdf", &MeshSpecs);

    Inspector inspector;
    inspector.meshSpecs = &MeshSpecs;

    ImGui_ImplOpenGL3_Init();
    ImGui_ImplGlfw_InitForOpenGL(Window->getWindow(), true);

    glEnable(GL_DEPTH_TEST);

    while (!Window->windowClose()) {
        FrameBuffer->Bind();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.1f, 0.3f, 0.4f, 1.0f);

        Texture->Bind();

        Mesh->Render();

        Texture->Unbind();

        FrameBuffer->Unbind();

        // All ImGui Stuff
        if (true) {

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            static bool opt_fullscreen = true;
            static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

            ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
            if (opt_fullscreen) {
                const ImGuiViewport* viewport = ImGui::GetMainViewport();
                ImGui::SetNextWindowPos(viewport->WorkPos);
                ImGui::SetNextWindowSize(viewport->WorkSize);
                ImGui::SetNextWindowViewport(viewport->ID);
                ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
                ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
                window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
                window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;
            }
            else {
                dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
            }

            if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
                window_flags |= ImGuiWindowFlags_NoBackground;

            ImGui::Begin("DockSpace", nullptr, window_flags);

            if (opt_fullscreen)
                ImGui::PopStyleVar(2);

            if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
                ImGuiID dockspace_id = ImGui::GetID("Dockspace");
                ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), 0);
            }

            if (ImGui::BeginMenuBar()) {
                if (ImGui::BeginMenu("Options")) {
                    ImGui::EndMenu();
                }

                ImGui::EndMenuBar();

                ImVec2 size{ 200, 100 };
                ImGui::SetNextWindowSize(size);

                ImGui::Begin("Scene Hierachy", nullptr);

                ImGui::End();

                ImGui::SetNextWindowSize(size);
                ImGui::Begin("Console", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

                ImGui::Text("Hello World");

                ImGui::End();

                ImGui::SetNextWindowSize(size);
                ImGui::Begin("Game Viewport", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

                unsigned int textureID = FrameBuffer->getColorAttachment();

                /*float gameWidth  = ImGui::GetWindowHeight()/9.0f;
                float gameHeight = ImGui::GetWindowWidth()/16.0f;

                if(gameHeight > 16.0f/9.0f && gameWidth*16.0f <= ImGui::GetWindowWidth())
                    ImGui::Image((void*)textureID, ImVec2{ ImGui::GetWindowHeight()/9.0f*16.0f, ImGui::GetWindowHeight() });
                else if(gameWidth > 16.0f/9.0f && gameHeight*9.0f <= ImGui::GetWindowHeight())
                    ImGui::Image((void*)textureID, ImVec2{ ImGui::GetWindowWidth(), ImGui::GetWindowWidth()/16.0f*9.0f });
                else
                    ImGui::Image((void*)textureID, ImVec2{ ImGui::GetWindowWidth(), ImGui::GetWindowWidth()/16.0f*9.0f });*/

                ImGui::Image((void*)textureID, ImVec2{ ImGui::GetWindowWidth(), ImGui::GetWindowHeight() });

                ImGui::End();

                // Inspector
                ImGui::SetNextWindowSize(size);
                ImGui::Begin("Inspector", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

                ImGui::Text("Name");
                ImGui::SameLine();
                ImGui::InputText("##Name", inspector.name, inspector.nameSize);

                //if (ImGui::Button("Show Cube", { 90,20 })) showCube = !showCube;

                ImGui::Separator();

                ImGui::Text("Transformation");

                ImGui::Text("Position   ");
                ImGui::SameLine();
                ImGui::DragFloat3("##Position", inspector.meshSpecs->position.toArray(), 0.01F);

                ImGui::Text("Rotation   ");
                ImGui::SameLine();
                ImGui::DragFloat3("##Rotation", inspector.meshSpecs->rotation.toArray(), 0.5F);

                ImGui::Text("Scale      ");
                ImGui::SameLine();
                ImGui::DragFloat3("##Scale", inspector.meshSpecs->scale.toArray(), 0.01F);

                ImGui::End();

                ImGui::Separator();
            }

            ImGui::End();

            ImGui::Render();

            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
            }

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }

		Window->Update();

        FrameSpecs.width = Window->getSize().X();
        FrameSpecs.height = Window->getSize().Y();
	}

    delete Mesh;
    delete Texture;

    delete FrameBuffer;

	delete Window;

	return 0;
}