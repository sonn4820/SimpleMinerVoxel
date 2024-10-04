#include "Game/Game.hpp"
#include "Game/Player.hpp"
#include "Game/GameCommon.hpp"
#include "Game/World.hpp"

bool g_debugMode = false;

Game::Game()
{
	m_screenCamera = new Camera();
	m_screenCamera->SetOrthographicView(Vec2(0, 0), Vec2(g_gameConfigBlackboard.GetValue("screenSizeX", 1600.f), g_gameConfigBlackboard.GetValue("screenSizeY", 800.f)));
	m_clock = new Clock(*Clock::s_theSystemClock);
}
//..............................
Game::~Game()
{

}
//..............................
void Game::Startup()
{
	CreateFolder("Saves");
	BlockDefinition::InitializeBlockDefs("");
	BlockTemplate::InitializeBlockTemplate();
	SwitchState(GameState::ATTRACT_MODE);
	g_theJobSystem->SetWorkerThreadJobFlags(2, 1);
}
//..............................
void Game::Shutdown()
{
}

//----------------------------------------------------------------------------------------------------------------------------------------
// UPDATE

void Game::Update(float deltaSeconds)
{
	m_secondIntoMode += deltaSeconds;

	//UpdateCamera();
	HandleInput();

	if (m_currentState == GameState::PLAY_MODE)
	{
		UpdatePlayMode(deltaSeconds);
	}
	if (m_currentState == GameState::ATTRACT_MODE)
	{
		UpdateAttractMode(deltaSeconds);
	}
}
//..............................
void Game::UpdatePlayMode(float deltaSeconds)
{
	m_world->m_player->Update(deltaSeconds);
	m_world->Update(deltaSeconds);
	DebugAddWorldBasis(Mat44(), 0.f);
	if (g_theInput->WasKeyJustPressed(KEYCODE_F1))
	{
		g_debugMode = !g_debugMode;
	}
}
//..............................
void Game::UpdateAttractMode(float deltaSeconds)
{
	UNUSED(deltaSeconds);
	if (g_theInput->WasKeyJustPressed(KEYCODE_SPACE))
	{
		SwitchState(GameState::PLAY_MODE);
	}
	if (g_theInput->WasKeyJustPressed(KEYCODE_ESCAPE) || g_theInput->GetController(0).WasButtonJustPressed(XBOX_BUTTON_BACK))
	{
		if (m_currentState == GameState::ATTRACT_MODE)
		{
			if (m_secondIntoMode > 0.2f)
			{
				g_theApp->m_isQuitting = true;
			}
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------
// RENDER 

void Game::Render() const
{
	if (m_currentState == GameState::PLAY_MODE)
	{
		RenderPlayMode();
		DebugRenderWorld(*m_world->m_player->GetCamera());
		DebugRenderScreen(*m_screenCamera);
	}
	if (m_currentState == GameState::ATTRACT_MODE)
	{
		RenderAttractMode();
	}
	RenderScreenWorld();
}
//..............................

void Game::RenderPlayMode() const
{
	g_theRenderer->ClearScreen(Rgba8::Create_ExchangeFromVec3(m_world->m_skyColor));
	g_theRenderer->BeginCamera(*m_world->m_player->GetCamera());
	m_world->Render();
	g_theRenderer->EndCamera(*m_world->m_player->GetCamera());

	g_theRenderer->BeginCamera(*m_screenCamera);
	std::vector<Vertex_PCU> readMeVerts;
	g_theFont->AddVertsForTextInBox2D(readMeVerts, AABB2(10, 760, 1590, 790), 20.f, "Press WASD to move, QE to ascend/descend, Shift to move fast, F1: Debug Mode, F8: Re-generated", Rgba8::COLOR_YELLOW, 1.f, Vec2(0.f, 0.5f));
	int numBlock = 0;
	int numVerts = 0;
	for (const std::pair<IntVec2, Chunk*>& chunk : m_world->m_activeChunks)
	{
		numBlock += TOTAL_BLOCKS_SIZE;
		numVerts += (int)chunk.second->m_cpuMeshVerts.size();
	}
	Rgba8 fpsColor = Rgba8::COLOR_CYAN;
	if (1.f / m_clock->GetDeltaSeconds() < 50.f)
	{
		fpsColor = Rgba8::COLOR_RED;
	}
	g_theFont->AddVertsForTextInBox2D(readMeVerts, AABB2(10, 720, 1590, 750), 20.f, Stringf("NumChunks: %i/%i, NumBlocks: %i, NumVerts: %i, FPS: %.1f", m_world->m_activeChunks.size(), m_world->m_maxChunks, numBlock, numVerts, 1.f / m_clock->GetDeltaSeconds()), fpsColor, 1.f, Vec2(0.f, 0.5f));
	g_theFont->AddVertsForTextInBox2D(readMeVerts, AABB2(10, 680, 1590, 710), 20.f, Stringf("Daytime: %.2f", m_world->m_worldDay), Rgba8::COLOR_PINK, 1.f, Vec2(0.f, 0.5f));
	g_theFont->AddVertsForTextInBox2D(readMeVerts, AABB2(10, 640, 1590, 670), 20.f, Stringf("World Seed: %i", m_world->m_worldSeed), Rgba8::COLOR_VIOLET, 1.f, Vec2(0.f, 0.5f));
	g_theRenderer->BindTexture(&g_theFont->GetTexture());
	g_theRenderer->BindShader(nullptr);
	g_theRenderer->SetModelConstants();
	g_theRenderer->SetDepthStencilMode(DepthMode::DISABLED);
	g_theRenderer->SetRasterizerMode(RasterizerMode::SOLID_CULL_NONE);
	g_theRenderer->DrawVertexArray((int)readMeVerts.size(), readMeVerts.data());
	g_theRenderer->EndCamera(*m_screenCamera);
}
//..............................
void Game::RenderAttractMode() const
{
	g_theRenderer->ClearScreen(Rgba8(10, 10, 10, 255));
	g_theRenderer->BeginCamera(*m_screenCamera);

	g_theRenderer->SetDepthStencilMode(DepthMode::DISABLED);
	g_theRenderer->SetBlendMode(BlendMode::ALPHA);
	g_theRenderer->SetRasterizerMode(RasterizerMode::SOLID_CULL_NONE);
	g_theRenderer->SetSamplerMode(SampleMode::POINT_CLAMP);
	g_theRenderer->SetModelConstants();
	g_theRenderer->BindTexture(&g_theFont->GetTexture());

	std::vector<Vertex_PCU> textVerts;
	g_theFont->AddVertsForTextInBox2D(textVerts, AABB2(550, 300, 1000, 600), 50.f, "Simple Miner");
	g_theFont->AddVertsForTextInBox2D(textVerts, AABB2(560, 50, 1000, 100), 50.f, "Press Space to Start", Rgba8::COLOR_GREEN);
	g_theRenderer->DrawVertexArray((int)textVerts.size(), textVerts.data());

	g_theRenderer->EndCamera(*m_screenCamera);
}
//..............................
void Game::RenderScreenWorld() const
{
	g_theRenderer->BeginCamera(*m_screenCamera);
	g_theRenderer->SetDepthStencilMode(DepthMode::DISABLED);
	g_theRenderer->SetBlendMode(BlendMode::ALPHA);
	g_theRenderer->SetRasterizerMode(RasterizerMode::SOLID_CULL_NONE);
	g_theRenderer->SetSamplerMode(SampleMode::POINT_CLAMP);

	AABB2 screenBound = AABB2(m_screenCamera->GetOrthographicBottomLeft(), m_screenCamera->GetOrthographicTopRight());

	std::vector<Vertex_PCU> UIVerts;
	UIVerts.reserve(6);

	if (m_clock->IsPaused())
	{
		AddVertsForAABB2D(UIVerts, screenBound, Rgba8::DARK);
	}

	g_theRenderer->SetModelConstants();
	g_theRenderer->BindTexture(nullptr);
	g_theRenderer->DrawVertexArray((int)UIVerts.size(), UIVerts.data());

	g_theDevConsole->Render(screenBound, g_theRenderer);
}

void Game::HandleInput()
{
	if (g_theInput->WasKeyJustPressed(KEYCODE_ESCAPE) || g_theInput->GetController(0).WasButtonJustPressed(XBOX_BUTTON_BACK))
	{
		g_theGame->SwitchState(GameState::ATTRACT_MODE);
	}
}

void Game::EnterCurrentState()
{
	switch (m_currentState)
	{
	case GameState::NONE:
		break;
	case GameState::ATTRACT_MODE:
		break;
	case GameState::PLAY_MODE:
		m_world = new World();
		m_world->StartUp();
		break;
	}
}

void Game::ExitCurrentState()
{
	switch (m_currentState)
	{
	case GameState::NONE:
		break;
	case GameState::ATTRACT_MODE:
		break;
	case GameState::PLAY_MODE:
		delete m_world;
		m_world = nullptr;
		g_theJobSystem->ClearAllJobs();
		break;
	}
}

void Game::SwitchState(GameState state)
{
	if (state == m_currentState)
	{
		return;
	}
	m_secondIntoMode = 0.f;
	ExitCurrentState();
	m_prevState = m_currentState;
	m_currentState = state;
	EnterCurrentState();
}

GameState const Game::GetCurrentState()
{
	return m_currentState;
}
