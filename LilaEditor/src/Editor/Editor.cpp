#include "Editor.h"

namespace Editor {

	Editor::Editor(Lila::Window* window, Lila::Registry* registry) {
        hierarchy = new Hierarchy(registry);
        inspector = new Inspector(registry);

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		ImGui::StyleColorsDark();

		ImGui_ImplOpenGL3_Init();
		ImGui_ImplGlfw_InitForOpenGL(window->getWindow(), true);

		frame = new Lila::FrameBuffer();
		frame->width  = window->getSize().X();
		frame->height = window->getSize().Y();
		frame->Create();
	}
	Editor::~Editor() {
		
		frame->Unbind();

		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		delete frame;

        delete hierarchy;
        delete inspector;
	}

	void Editor::update() {
        frame->Unbind();
    }

    void Editor::onImGui() {
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
            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        }
        else {
            dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
        }

        if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
            window_flags |= ImGuiWindowFlags_NoBackground;

        ImGui::Begin("DockSpace", nullptr, window_flags);

        if (opt_fullscreen)
            ImGui::PopStyleVar(2);

        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DockingEnable) {
            ImGuiID dockspace_id = ImGui::GetID("Dockspace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), 0);
        }

        if (ImGui::BeginMenuBar()) {
            if (ImGui::BeginMenu("Options")) {
                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }

        ImVec2 size{200, 100};

        ImGui::SetNextWindowSize(size);
        ImGui::Begin("Console", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

        ImGui::Text("Hello World");

        ImGui::End();

        ImGui::SetNextWindowSize(size);
        ImGui::Begin("Game Viewport", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

        unsigned int textureID = frame->getColorAttachment();
        ImGui::Image((void*)textureID, ImVec2{ ImGui::GetWindowWidth(), ImGui::GetWindowHeight() });

        ImGui::End();

        ImGui::SetNextWindowSize(size);
        hierarchy->onImGui();

        inspector->setSelected(hierarchy->getSelected());

        ImGui::SetNextWindowSize(size);
        inspector->onImGui();

        ImGui::End();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        frame->Bind();
	}

};