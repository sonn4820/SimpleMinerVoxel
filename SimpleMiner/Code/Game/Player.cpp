#include "Player.hpp"
#include "Game/GameCommon.hpp"
#include "Game/World.hpp"

Player::Player(World* owner)
	:m_world(owner)
{
	m_playerCamera = new Camera();
	m_playerCamera->SetPerspectiveView(Window::GetMainWindowInstance()->GetAspect(), 60.f, 0.1f, 10000.f);
	m_playerCamera->SetRenderBasis(Vec3(0.f, 0.f, 1.f), Vec3(-1.f, 0.f, 0.f), Vec3(0.f, 1.f, 0.f));
}

Player::~Player()
{
}

void Player::Update(float deltaSeconds)
{
	HandleInput(deltaSeconds);
	Movement(deltaSeconds);
	m_playerCamera->SetTransform(m_position, m_orientationDegrees);
	m_refPos = m_position + 0.2f * GetModelMatrix().GetIBasis3D().GetNormalized();

	DebugAddScreenText(Stringf("Player Global Position: %.1f, %.1f, %.1f", m_position.x, m_position.y, m_position.z), Vec2(20, 15), 20.f);
	DebugAddScreenText(Stringf("Player Local Coord: %i, %i, %i", GetLocalCoord().x, GetLocalCoord().y, GetLocalCoord().z), Vec2(20, 40), 20.f);
	DebugAddScreenText(Stringf("Player Current Chunk Coord: %i, %i", GetCurrentChunkCoord().x, GetCurrentChunkCoord().y), Vec2(20, 65), 20.f);

	if (m_lockRaycast)
	{
		m_lockedHit = m_currentHit;
		if (m_lockedHit.m_didImpact)
		{
			DebugAddWorldPoint(m_lockedHit.m_impactPos, 0.07f, 0, Rgba8::COLOR_WHITE, Rgba8::COLOR_WHITE, DebugRenderMode::XRAY);
			DebugAddWorldLine(m_lockPos, m_lockedHit.m_impactPos, 0.025f, 0.f, Rgba8::COLOR_RED, Rgba8::COLOR_RED, DebugRenderMode::XRAY);
			DebugAddWorldArrow(m_lockedHit.m_impactPos, m_lockedHit.m_impactPos + m_lockFwd * (8.f - m_lockedHit.m_impactDist), 0.025f, 0.f, Rgba8::COLOR_GRAY, Rgba8::COLOR_GRAY, DebugRenderMode::XRAY);
		}
		else
		{
			DebugAddWorldArrow(m_lockPos, m_lockPos + m_lockFwd * 8.f, 0.025f, 0.f, Rgba8::COLOR_GREEN);
		}
	}
	else
	{
		if (m_world->m_activeChunks.size() > 10)
		{
			m_currentHit = m_world->RaycastWorld(m_position, GetModelMatrix().GetIBasis3D(), 8.f);
			//if (m_currentHit.m_didImpact)
			//{
			//	BlockIterator bl = m_currentHit.m_blockIterator;
			//	DebugAddScreenText(Stringf("Current Block Coord: %i, %i, %i", GetBlockCoord(bl.m_blockIndex).x, GetBlockCoord(bl.m_blockIndex).y, GetBlockCoord(bl.m_blockIndex).z), Vec2(900, 115), 10.f);
			//	DebugAddScreenText(Stringf("Current Block: %i, %i, %i", bl.GetBlock()->m_type, bl.GetBlock()->m_lightInfluence, bl.GetBlock()->m_bitFlags), Vec2(900, 100), 10.f);
			//	DebugAddScreenText(Stringf("East Block: %i, %i, %i", bl.GetEastNeighbor().GetBlock()->m_type, bl.GetEastNeighbor().GetBlock()->m_lightInfluence, bl.GetEastNeighbor().GetBlock()->m_bitFlags), Vec2(900, 85), 10.f);
			//	DebugAddScreenText(Stringf("West Block: %i, %i, %i", bl.GetWestNeighbor().GetBlock()->m_type, bl.GetWestNeighbor().GetBlock()->m_lightInfluence, bl.GetWestNeighbor().GetBlock()->m_bitFlags), Vec2(900, 70), 10.f);
			//	DebugAddScreenText(Stringf("North Block: %i, %i, %i", bl.GetNorthNeighbor().GetBlock()->m_type, bl.GetNorthNeighbor().GetBlock()->m_lightInfluence, bl.GetNorthNeighbor().GetBlock()->m_bitFlags), Vec2(900, 55), 10.f);
			//	DebugAddScreenText(Stringf("South Block: %i, %i, %i", bl.GetSouthNeighbor().GetBlock()->m_type, bl.GetSouthNeighbor().GetBlock()->m_lightInfluence, bl.GetSouthNeighbor().GetBlock()->m_bitFlags), Vec2(900, 40), 10.f);
			//	DebugAddScreenText(Stringf("Up Block: %i, %i, %i", bl.GetUpwardNeighbor().GetBlock()->m_type, bl.GetUpwardNeighbor().GetBlock()->m_lightInfluence, bl.GetUpwardNeighbor().GetBlock()->m_bitFlags), Vec2(900, 25), 10.f);
			//	DebugAddScreenText(Stringf("Down Block: %i, %i, %i", bl.GetDownwardNeighbor().GetBlock()->m_type, bl.GetDownwardNeighbor().GetBlock()->m_lightInfluence, bl.GetDownwardNeighbor().GetBlock()->m_bitFlags), Vec2(900, 10), 10.f);
			//}

		}
	}
}

void Player::Render() const
{
	std::vector<Vertex_PCU> verts;

	AddVertsForArrow3D(verts, m_refPos, m_refPos + Vec3(0.01f, 0.f, 0.f), 0.00025f, Rgba8::COLOR_RED);
	AddVertsForArrow3D(verts, m_refPos, m_refPos + Vec3(0.f, 0.01f, 0.f), 0.00025f, Rgba8::COLOR_GREEN);
	AddVertsForArrow3D(verts, m_refPos, m_refPos + Vec3(0.f, 0.f, 0.01f), 0.00025f, Rgba8::COLOR_BLUE);

	if (m_currentHit.m_didImpact)
	{
		Vec3 center = m_currentHit.m_blockIterator.GetWorldCenter();
		if (m_currentHit.m_impactNormal.x > 0)
		{
			// EAST
			Vec3 centerEast = center + Vec3(0.5f, 0, 0);
			AddVertsForWireframeQuad3D(verts,
				centerEast + Vec3(0, -0.5f, -0.5f),
				centerEast + Vec3(0, 0.5f, -0.5f),
				centerEast + Vec3(0, -0.5f, 0.5f),
				centerEast + Vec3(0, 0.5f, 0.5f),
				Rgba8::COLOR_VIOLET);
		}
		if (m_currentHit.m_impactNormal.x < 0)
		{
			// WEST
			Vec3 centerWest = center + Vec3(-0.5f, 0, 0);
			AddVertsForWireframeQuad3D(verts,
				centerWest + Vec3(0, 0.5f, -0.5f),
				centerWest + Vec3(0, -0.5f, -0.5f),
				centerWest + Vec3(0, 0.5f, 0.5f),
				centerWest + Vec3(0, -0.5f, 0.5f),
				Rgba8::COLOR_VIOLET);
		}
		if (m_currentHit.m_impactNormal.y > 0)
		{
			// NORTH
			Vec3 centerEast = center + Vec3(0, 0.5f, 0);
			AddVertsForWireframeQuad3D(verts,
				centerEast + Vec3(-0.5f, 0, -0.5f),
				centerEast + Vec3(0.5f, 0, -0.5f),
				centerEast + Vec3(-0.5f, 0, 0.5f),
				centerEast + Vec3(0.5f, 0, 0.5f),
				Rgba8::COLOR_VIOLET);
		}
		if (m_currentHit.m_impactNormal.y < 0)
		{
			// SOUTH
			Vec3 centerWest = center + Vec3(0, -0.5f, 0);
			AddVertsForWireframeQuad3D(verts,
				centerWest + Vec3(-0.5f, 0, -0.5f),
				centerWest + Vec3(0.5f, 0, -0.5f),
				centerWest + Vec3(-0.5f, 0, 0.5f),
				centerWest + Vec3(0.5f, 0, 0.5f),
				Rgba8::COLOR_VIOLET);
		}
		if (m_currentHit.m_impactNormal.z > 0)
		{
			// UP
			Vec3 centerEast = center + Vec3(0, 0, 0.5f);
			AddVertsForWireframeQuad3D(verts,
				centerEast + Vec3(-0.5f, -0.5f, 0),
				centerEast + Vec3(0.5f, -0.5f, 0),
				centerEast + Vec3(-0.5f, 0.5f, 0),
				centerEast + Vec3(0.5f, 0.5f, 0),
				Rgba8::COLOR_VIOLET);
		}
		if (m_currentHit.m_impactNormal.z < 0)
		{
			// UP
			Vec3 centerEast = center + Vec3(0, 0, -0.5f);
			AddVertsForWireframeQuad3D(verts,
				centerEast + Vec3(-0.5f, -0.5f, 0),
				centerEast + Vec3(0.5f, -0.5f, 0),
				centerEast + Vec3(-0.5f, 0.5f, 0),
				centerEast + Vec3(0.5f, 0.5f, 0),
				Rgba8::COLOR_VIOLET);
		}
	}

	g_theRenderer->BindShader(nullptr);
	g_theRenderer->BindTexture(nullptr);
	g_theRenderer->SetModelConstants();
	g_theRenderer->SetDepthStencilMode(DepthMode::ENABLED);
	g_theRenderer->SetRasterizerMode(RasterizerMode::SOLID_CULL_BACK);
	g_theRenderer->DrawVertexArray((int)verts.size(), verts.data());
}

Camera* Player::GetCamera()
{
	return m_playerCamera;
}

Mat44 Player::GetModelMatrix() const
{
	Mat44 modelMat = Mat44();
	modelMat = m_orientationDegrees.GetAsMatrix_IFwd_JLeft_KUp();
	modelMat.SetTranslation3D(m_position);
	return modelMat;
}

IntVec2 Player::GetCurrentChunkCoord() const
{
	return IntVec2(RoundDownToInt(m_position.x / CHUNK_SIZE_X), RoundDownToInt(m_position.y / CHUNK_SIZE_Y));
}

IntVec3 Player::GetLocalCoord() const
{
	IntVec2 chunkGlobalCoord = GetCurrentChunkCoord() * IntVec2(CHUNK_SIZE_X, CHUNK_SIZE_Y);
	IntVec3 playerGlobalCoord = IntVec3(RoundDownToInt(m_position.x), RoundDownToInt(m_position.y), RoundDownToInt(m_position.z));

	return IntVec3(playerGlobalCoord.x - chunkGlobalCoord.x, playerGlobalCoord.y - chunkGlobalCoord.y, playerGlobalCoord.z);
}

void Player::HandleInput(float deltaSeconds)
{
	UNUSED(deltaSeconds);
	Vec3 forwardDir = GetModelMatrix().GetIBasis3D().GetNormalized();
	Vec3 rightDir = GetModelMatrix().GetJBasis3D().GetNormalized();
	Vec3 upDir = GetModelMatrix().GetKBasis3D().GetNormalized();

	m_velocity = Vec3::ZERO;
	m_orientationDegrees.m_pitchDegrees += g_theInput->GetCursorClientDelta().y * 0.075f;
	m_orientationDegrees.m_yawDegrees -= g_theInput->GetCursorClientDelta().x * 0.075f;

	if (g_theInput->IsKeyDown('W'))
	{
		m_velocity += Vec3(forwardDir.x, forwardDir.y, 0.f).GetNormalized() * m_movingSpeed;
	}
	if (g_theInput->IsKeyDown('S'))
	{
		m_velocity -= Vec3(forwardDir.x, forwardDir.y, 0.f).GetNormalized() * m_movingSpeed;
	}
	if (g_theInput->IsKeyDown('A'))
	{
		m_velocity += Vec3(rightDir.x, rightDir.y, 0.f).GetNormalized() * m_movingSpeed;
	}
	if (g_theInput->IsKeyDown('D'))
	{
		m_velocity -= Vec3(rightDir.x, rightDir.y, 0.f).GetNormalized() * m_movingSpeed;
	}
	if (g_theInput->IsKeyDown('Q'))
	{
		m_velocity += Vec3(0, 0, m_movingSpeed);
	}
	if (g_theInput->IsKeyDown('E'))
	{
		m_velocity -= Vec3(0, 0, m_movingSpeed);
	}
	if (g_theInput->IsKeyDown(KEYCODE_SHIFT))
	{
		m_velocity *= 20.f;
	}
	if (g_theInput->WasKeyJustPressed(KEYCODE_F8))
	{
		m_world->FlushEntireWorld();
	}
	if (g_theInput->WasKeyJustPressed(49))
	{
		m_currentType = 9;
	}
	if (g_theInput->WasKeyJustPressed(50))
	{
		m_currentType = 10;
	}
	if (g_theInput->WasKeyJustPressed(51))
	{
		m_currentType = 1;
	}
	if (g_theInput->WasKeyJustPressed(52))
	{
		m_currentType = 2;
	}
	if (g_theInput->WasKeyJustPressed(53))
	{
		m_currentType = 3;
	}
	if (g_theInput->WasKeyJustPressed(54))
	{
		m_currentType = 4;
	}
	if (g_theInput->WasKeyJustPressed(55))
	{
		m_currentType = 5;
	}
	if (g_theInput->WasKeyJustPressed(56))
	{
		m_currentType = 6;
	}
	if (g_theInput->WasKeyJustPressed(57))
	{
		m_currentType = 7;
	}

	if (g_theInput->WasKeyJustPressed(KEYCODE_LEFT_MOUSE))
	{
		DigBlock();
	}
	if (g_theInput->WasKeyJustPressed(KEYCODE_RIGHT_MOUSE))
	{
		PlaceBlock(m_currentType);
	}
	if (g_theInput->WasKeyJustPressed('R'))
	{
		m_lockRaycast = !m_lockRaycast;
		if (m_lockRaycast)
		{
			m_lockPos = m_position;
			m_lockFwd = GetModelMatrix().GetIBasis3D();
		}
	}
}

void Player::Movement(float deltaSeconds)
{
	m_orientationDegrees.m_pitchDegrees = Clamp(m_orientationDegrees.m_pitchDegrees, -85.f, 85.f);
	m_position += m_velocity * deltaSeconds;
}

void Player::PlaceBlock(unsigned char type)
{
	if (m_currentHit.m_didImpact)
	{
		BlockIterator newBlock;
		if (m_currentHit.m_impactNormal.x > 0.f)
		{
			newBlock = m_currentHit.m_blockIterator.GetEastNeighbor();
		}
		if (m_currentHit.m_impactNormal.x < 0.f)
		{
			newBlock = m_currentHit.m_blockIterator.GetWestNeighbor();
		}
		if (m_currentHit.m_impactNormal.y > 0.f)
		{
			newBlock = m_currentHit.m_blockIterator.GetNorthNeighbor();
		}
		if (m_currentHit.m_impactNormal.y < 0.f)
		{
			newBlock = m_currentHit.m_blockIterator.GetSouthNeighbor();
		}
		if (m_currentHit.m_impactNormal.z > 0.f)
		{
			newBlock = m_currentHit.m_blockIterator.GetUpwardNeighbor();
		}
		if (m_currentHit.m_impactNormal.z < 0.f)
		{
			newBlock = m_currentHit.m_blockIterator.GetDownwardNeighbor();
		}

		if (newBlock.GetBlock()->CanSeeSky() && BlockDefinition::s_blockDefList[type]->m_isOpaque)
		{
			BlockIterator downwardBlock = newBlock.GetDownwardNeighbor();
			while (!downwardBlock.GetBlock()->IsBlockOpaque())
			{
				downwardBlock.GetBlock()->SetIsNotSky();
				m_world->MarkLightingDirty(downwardBlock);
				downwardBlock = downwardBlock.GetDownwardNeighbor();
			}
		}

		newBlock.m_chunk->SetBlockType(newBlock.m_blockIndex, type);
		newBlock.m_chunk->SetMeshDirty();
		newBlock.m_chunk->SetChunkNeedsSave();
		m_world->MarkLightingDirty(newBlock);
	}
}

void Player::DigBlock()
{
	if (m_currentHit.m_didImpact)
	{
		m_currentHit.m_blockIterator.m_chunk->SetBlockType(m_currentHit.m_blockIterator.m_blockIndex, 0);
		m_currentHit.m_blockIterator.m_chunk->SetMeshDirty();
		if (m_currentHit.m_blockIterator.GetEastNeighbor().m_chunk)		m_currentHit.m_blockIterator.GetEastNeighbor().m_chunk->SetMeshDirty();
		if (m_currentHit.m_blockIterator.GetWestNeighbor().m_chunk)		m_currentHit.m_blockIterator.GetWestNeighbor().m_chunk->SetMeshDirty();
		if (m_currentHit.m_blockIterator.GetNorthNeighbor().m_chunk)	m_currentHit.m_blockIterator.GetNorthNeighbor().m_chunk->SetMeshDirty();
		if (m_currentHit.m_blockIterator.GetSouthNeighbor().m_chunk)	m_currentHit.m_blockIterator.GetSouthNeighbor().m_chunk->SetMeshDirty();
		if (m_currentHit.m_blockIterator.GetUpwardNeighbor().m_chunk)	m_currentHit.m_blockIterator.GetUpwardNeighbor().m_chunk->SetMeshDirty();
		if (m_currentHit.m_blockIterator.GetDownwardNeighbor().m_chunk)	m_currentHit.m_blockIterator.GetDownwardNeighbor().m_chunk->SetMeshDirty();
		m_currentHit.m_blockIterator.m_chunk->SetChunkNeedsSave();

		if (m_currentHit.m_blockIterator.GetUpwardNeighbor().GetBlock() && m_currentHit.m_blockIterator.GetUpwardNeighbor().GetBlock()->CanSeeSky())
		{
			BlockIterator downwardBlock = m_currentHit.m_blockIterator;
			while (!downwardBlock.GetBlock()->IsBlockOpaque())
			{
				downwardBlock.GetBlock()->SetIsSky();
				m_world->MarkLightingDirty(downwardBlock);
				downwardBlock = downwardBlock.GetDownwardNeighbor();
			}
		}
		else
		{
			m_world->MarkLightingDirty(m_currentHit.m_blockIterator);
		}
	}
}