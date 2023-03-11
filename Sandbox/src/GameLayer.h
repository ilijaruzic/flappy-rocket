#pragma once

#include "Navia.h"

#include "Level.h"
#include <imgui/imgui.h>

class GameLayer : public Navia::Layer
{
public:
	GameLayer();
	virtual ~GameLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Navia::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Navia::Event& e) override;
	bool OnMouseButtonPressed(Navia::MouseButtonPressedEvent& e);
	bool OnWindowResize(Navia::WindowResizeEvent& e);
private:
	void CreateCamera(uint32_t width, uint32_t height);
private:
	Navia::Scope<Navia::OrthographicCamera> m_Camera;
	Level m_Level;
	ImFont* m_Font;
	float m_Time = 0.0f;
	bool m_Blink = false;

	enum class GameState
	{
		Play = 0, MainMenu = 1, GameOver = 2
	};

	GameState m_State = GameState::MainMenu;
};