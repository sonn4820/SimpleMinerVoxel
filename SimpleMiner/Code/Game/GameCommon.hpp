#pragma once
#include "Engine/Core/VertexUtils.hpp"
#include "Engine/Core/JobSystem.hpp"
#include "Engine/Core/ErrorWarningAssert.hpp"
#include "Engine/Core/StringUtils.hpp"
#include "Engine/Core/EngineCommon.hpp"
#include "Engine/Core/DevConsole.hpp"
#include "Engine/Core/EventSystem.hpp"
#include "Engine/Input/InputSystem.hpp"
#include "Engine/Audio/AudioSystem.hpp"
#include "Engine/Renderer/Renderer.hpp"
#include "Engine/Math/MathUtils.hpp"
#include "Engine/Math/RandomNumberGenerator.hpp"
#include "Engine/Renderer/DebugRender.hpp"
#include "Engine/Renderer/Camera.hpp"
#include "Engine/Core/FileUtils.hpp"
#include "Game/App.hpp"

#include <vector>
#include <deque>
#include <set>

extern App* g_theApp;
extern Renderer* g_theRenderer;
extern InputSystem* g_theInput;
extern AudioSystem* g_theAudio;
extern RandomNumberGenerator* g_theRNG;
extern BitmapFont* g_theFont;
extern JobSystem* g_theJobSystem;
extern Game* g_theGame;
extern bool g_debugMode;

constexpr float WORLD_SIZE_X = 200.f;
constexpr float WORLD_SIZE_Y = 100.f;
constexpr float MAX_SHAKE = 10.f;
constexpr float SHAKE_REDUCTION_PER_SEC = 7.f;
