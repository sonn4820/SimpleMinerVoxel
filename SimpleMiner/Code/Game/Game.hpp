#pragma once
#include "Game/GameCommon.hpp"

class World;

enum class GameState 
{
	NONE,
	ATTRACT_MODE,
	PLAY_MODE,
};
class Game
{
public:
	Game();
	~Game();

	void Startup();
	void Update(float deltaSeconds);
	void Render() const;
	void Shutdown();


	// STATE

	void EnterCurrentState();
	void ExitCurrentState();
	void SwitchState(GameState state);
	GameState const GetCurrentState();

public:
	World* m_world = nullptr;
	Clock* m_clock = nullptr;

	Camera* m_screenCamera = nullptr;

	GameState m_currentState = GameState::NONE;
	GameState m_prevState = GameState::NONE;

private:
	float m_screenShakeAmount = 0.0f;
	float m_secondIntoMode = 0.f;

	// UPDATE
	void UpdatePlayMode(float deltaSeconds);
	void UpdateAttractMode(float deltaSeconds);
	void HandleInput();

	// RENDER
	void RenderPlayMode() const;
	void RenderAttractMode() const;
	void RenderScreenWorld() const;

};