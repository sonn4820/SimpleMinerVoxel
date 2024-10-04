#pragma once
#include "Game/GameCommon.hpp"
#include "Game/World.hpp"


class Player
{
public:
	Player(World *owner);
	virtual ~Player();
	
	void Update(float deltaSeconds);
	void Render() const;

	Camera* GetCamera();
	Mat44 GetModelMatrix() const;
	IntVec2 GetCurrentChunkCoord() const;
	IntVec3 GetLocalCoord() const;

public:
	World* m_world = nullptr;
	Vec3 m_position;
	Vec3 m_velocity;
	EulerAngles m_orientationDegrees;
	EulerAngles m_angularVelocity;
	Rgba8 m_color = Rgba8::COLOR_WHITE;
	GameRaycastResult3D m_currentHit;
	GameRaycastResult3D m_lockedHit;
	unsigned char m_currentType = 9;
private:
	Camera* m_playerCamera = nullptr;
	float m_movingSpeed = 4.f;
	float m_rotatingSpeed = 90.f;
	Vec3 m_refPos;
	bool m_lockRaycast = false;
	Vec3 m_lockPos;
	Vec3 m_lockFwd;

private:
	void HandleInput(float deltaSeconds);
	void Movement(float deltaSeconds);
	void PlaceBlock(unsigned char type);
	void DigBlock();
};