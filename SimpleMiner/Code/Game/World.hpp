#pragma once
#include "Game/GameCommon.hpp"

constexpr uint8_t CHUNK_FILE_FORMAT_VERSION = 2;

constexpr int X_BITS = 4;
constexpr int Y_BITS = 4;
constexpr int Z_BITS = 7;

constexpr int CHUNK_SIZE_X = (1 << X_BITS);
constexpr int CHUNK_SIZE_Y = (1 << Y_BITS);
constexpr int CHUNK_SIZE_Z = (1 << Z_BITS);
constexpr int TOTAL_BLOCKS_SIZE = CHUNK_SIZE_X * CHUNK_SIZE_Y * CHUNK_SIZE_Z;

constexpr int X_MASK = CHUNK_SIZE_X - 1;
constexpr int Y_MASK = (CHUNK_SIZE_Y - 1) << X_BITS;
constexpr int Z_MASK = (CHUNK_SIZE_Z - 1) << (X_BITS + Y_BITS);

constexpr int LIGHT_BITS = 4;
constexpr int LIGHT_INFLUENCE = (1 << LIGHT_BITS);
constexpr int INDOOR_LIGHT_MASK = LIGHT_INFLUENCE - 1;
constexpr int OUTDOOR_LIGHT_MASK = (LIGHT_INFLUENCE - 1) << LIGHT_BITS;

constexpr int BLOCK_BIT_IS_SKY = 0;
constexpr int BLOCK_BIT_IS_LIGHT_DIRTY = 1;
constexpr int BLOCK_BIT_IS_FULL_OPAQUE = 2;
constexpr int BLOCK_BIT_IS_SOLID = 3;
constexpr int BLOCK_BIT_IS_VISIBLE = 4;

constexpr int EXTENDED_CHUNK_RANGE = 3;
constexpr int EXTENDED_CHUNK_SIZE_X = CHUNK_SIZE_X + EXTENDED_CHUNK_RANGE * 2;
constexpr int EXTENDED_CHUNK_SIZE_Y = CHUNK_SIZE_Y + EXTENDED_CHUNK_RANGE * 2;

constexpr int CAVE_RANGE = 70;
constexpr int CAVE_DETECTION_SIZE_X = CHUNK_SIZE_X + CAVE_RANGE * 2;
constexpr int CAVE_DETECTION_SIZE_Y = CHUNK_SIZE_Y + CAVE_RANGE * 2;


class World;
class Chunk;
struct Block;
class Player;
struct BlockIterator;

enum Direction
{
	EAST,
	WEST,
	NORTH,
	SOUTH,
	UPWARD,
	DOWNWARD
};

enum class ChunkStatus
{
	MISSING,
	ON_DISK,
	CONSTRUCTING,

	ACTIVATING_QUEUE_LOAD,
	ACTIVATING_LOADING,
	ACTIVATING_LOAD_COMPLETE,

	ACTIVATING_QUEUE_GENERATE,
	ACTIVATING_GENERATING,
	ACTIVATING_GENERATE_COMPLETE,

	ACTIVE,

	DEACTIVATING_QUEUE_SAVE,
	DEACTIVATING_SAVING,
	DEACTIVATING_SAVE_COMPLETE,
	DECONSTRUCTING,

	NUM_CHUNK_STATES
};

struct GameConstants
{
	Vec4		b_camWorldPos;
	Vec4		b_skyColor;
	Vec4		b_outdoorLightColor;
	Vec4		b_indoorLightColor;
	float		b_fogStartDist;
	float		b_fogEndDist;
	float		b_fogMaxAlpha;
	float		b_time;
};
struct BlockDefinition
{
	std::string m_name = "";
	unsigned char m_type = 0;
	bool m_isVisible = false;
	bool m_isSolid = false;
	bool m_isOpaque = false;
	unsigned char m_lightInfluence = 0;
	IntVec2 m_topUVtexCoords;
	IntVec2 m_sideUVtexCoords;
	IntVec2 m_bottomUVtexCoords;

	BlockDefinition(); //XmlElement& element
	static void InitializeBlockDefs(char const* filePath);
	static void ClearDefinition();
	static void CreateNewBlockDef(std::string name, unsigned char ID, bool visible, bool solid, bool opaque, IntVec2 topSprite, IntVec2 sideSprite, IntVec2 bottomSprite, unsigned char m_lightInfluence = 0);
	static BlockDefinition* GetByName(std::string name);
	static BlockDefinition* GetByType(unsigned int type);
	static std::vector<BlockDefinition*> s_blockDefList;
};

struct BlockTemplateEntry
{
	BlockTemplateEntry(unsigned char type, IntVec3 relativeCoord);
	unsigned char m_type;
	IntVec3 m_relativeCoord;
};
struct BlockTemplate
{
	BlockTemplate() = default;
	void AddEntry(BlockTemplateEntry entry);

	std::string m_name;
	std::vector<BlockTemplateEntry> m_blockTemplateEntries;

	static void InitializeBlockTemplate();
	static BlockTemplate* GetByName(std::string name);
	static void AddNewBlockTemplate(std::string name, BlockTemplate* blockTemplate);
	static std::vector<BlockTemplate*> s_blockTemplateList;
};
struct Block
{
	unsigned char m_type;
	unsigned char m_lightInfluence;
	unsigned char m_bitFlags;

public:
	unsigned char GetOutdoorLightInfluence() const;
	unsigned char GetIndoorLightInfluence() const;
	unsigned char GetIndoorLightInfluenceFromBlockDef() const;
	void SetOutdoorLightInfluence(unsigned char newOutdoorLightInfluence);
	void SetIndoorLightInfluence(unsigned char newIndoorLightInfluence);

	bool CanSeeSky() const;
	bool IsLightDirty() const;
	bool IsBlockSolid() const;
	bool IsBlockVisible() const;
	bool IsBlockOpaque() const;
	void SetLightDirty();
	void SetLightNotDirty();
	void SetIsSky();
	void SetIsNotSky();
};

struct CaveDiggerMachine
{
	CaveDiggerMachine(Chunk* chunk, IntVec3 startGlobalCoord);

	Chunk* m_chunk = nullptr;
	Vec3 m_startGlobalPosition;
	int m_totalStep = 0;
	float m_distanceEachStep = 0.f;
	float m_radius = 10.f;
	EulerAngles m_orientationForward;
	EulerAngles m_orientationBackward;

	Capsule3 m_forwardMachine;
	Capsule3 m_backwardMachine;

	void GenerateCave();
	void DigOneStepForward(Vec3 startPos);
	void DigOneStepBackward(Vec3 startPos);
	bool CanThisMachineModifyChunk(Capsule3 capsule);
	void MakeCaveOnCurrentChunk(bool isForward = true);
};

class Chunk
{
public:
	Chunk(World* world, IntVec2 coord);
	~Chunk();

	void Update(float deltaSeconds);
	void Render() const;

	IntVec3 GetBlockGlobalCoord(IntVec3 local);
	IntVec3 GetBlockLocalCoord(IntVec3 global);
	Block* GetBlock(IntVec3 coord);
	Block* GetBlock(int index);
	void SetBlockType(IntVec3 blockCoord, std::string name);
	void SetBlockType(IntVec3 blockCoord, unsigned int type);
	void SetBlockType(int index, std::string name);
	void SetBlockType(int index, unsigned int type);

	void SetMeshDirty();
	void SetChunkNeedsSave();
	bool SaveData();
	bool LoadData();

	void PlaceBlockTemplateOnCoord(BlockTemplate* blockTemplate, IntVec3 globalRootCoord);
	bool CanSpawnTreeAtThisSpot(int globalX, int globalY, float treeNoiseThreshold);
	bool DoesMeetAllRequirementsForBuildingMesh();

	void GenerateAllBlockData();
	bool BuildCPUMesh();
	void LightInfluenceInitialization();

	CaveDiggerMachine* IsThisStartPointOfTheCave(int globalX, int globalY, float caveNoiseThreshold);

public:

	std::atomic<ChunkStatus> m_status = ChunkStatus::MISSING;

	Block* m_blocks = nullptr;
	IntVec2 m_coord;
	AABB3 m_bound;

	std::vector<Vertex_PCU> m_cpuMeshVerts;
	std::vector<unsigned int> m_cpuMeshIndexes;

	std::vector<int> m_terrainHeightList;
	std::vector<float> m_hillinessList;
	std::vector<float> m_oceannessList;
	std::vector<float> m_temperatureList;
	std::vector<float> m_humidityList;
	std::vector<float> m_forestnessList;
	std::vector<float> m_lavanessList;

	VertexBuffer* m_gpuMeshVBO = nullptr;
	IndexBuffer* m_gpuMeshIBO = nullptr;

	World* m_world = nullptr;

	Chunk* m_northNeighbor = nullptr;
	Chunk* m_eastNeighbor = nullptr;
	Chunk* m_southNeighbor = nullptr;
	Chunk* m_westNeighbor = nullptr;

	bool m_isDirty = true;
	bool m_isActive = false;
	bool m_needSaving = false;

private:
	void CreateBlockMesh(BlockIterator blockIter);
};

struct BlockIterator
{
	BlockIterator() = default;
	explicit BlockIterator(Chunk* chunk, int blockIndex);
	Chunk* m_chunk = nullptr;
	int m_blockIndex = 0;

	Block* GetBlock() const;
	Vec3 GetWorldCenter() const;
	Rgba8 GetFaceTintForLightInfuenceValues(Direction direction) const;

	BlockIterator GetEastNeighbor() const;
	BlockIterator GetWestNeighbor() const;
	BlockIterator GetNorthNeighbor() const;
	BlockIterator GetSouthNeighbor() const;
	BlockIterator GetUpwardNeighbor() const;
	BlockIterator GetDownwardNeighbor() const;
};

struct GameRaycastResult3D
{
	// Basic raycast result information (required)
	bool	m_didImpact = false;
	float	m_impactDist = 0.f;
	Vec3	m_impactPos;
	Vec3	m_impactNormal;
	BlockIterator m_blockIterator;

	// Original raycast information (optional)
	Vec3	m_rayFwdNormal;
	Vec3	m_rayStartPos;
	float	m_rayMaxLength = 1.f;
};

class ChunkGenerateJob : public Job
{
public:
	ChunkGenerateJob(Chunk* chunk) { m_chunk = chunk; }
	void Execute() override;

	Chunk* m_chunk = nullptr;
};


class ChunkLoadJob : public Job
{
public:
	ChunkLoadJob(Chunk* chunk) { m_chunk = chunk; m_Bitflags = 2; }
	void Execute() override;

	Chunk* m_chunk = nullptr;
};

class ChunkSaveJob : public Job
{
public:
	ChunkSaveJob(Chunk* chunk) { m_chunk = chunk; m_Bitflags = 2;}
	void Execute() override;

	Chunk* m_chunk = nullptr;
};

class World
{
public:
	World();
	~World();

	void StartUp();
	void Update(float deltaSeconds);
	void Render() const;

	void BuildChunkDirtyMeshes();
	void RequestToActivateChunk(IntVec2& chunkCoords);
	void ActivateChunk(Chunk* newChunk);
	void RequestToDeactivateChunk(IntVec2& chunkCoords);
	void DeactivateChunk(Chunk* chunk);

	bool RequestCreationOfNearestMissingChunkInRange();
	bool RequestDeactivationFarthestChunkOutOfRange();
	void ManagingChunks();
	void FlushEntireWorld();

	void ProcessDirtyLighting();
	void ProcessNextDirtyLightBlock(BlockIterator iter);
	void MarkLightingDirty(BlockIterator iter);
	void UndirtyAllBlocksInChunk(IntVec2& chunkCoords);

	void SkyUpdate(float deltaSeconds);

	Chunk* GetChunkAtCoord(IntVec2 chunkCoord) const;
	Chunk* GetChunkAtPosition(Vec3 position) const;
	IntVec3 GetBlockLocalCoord(IntVec3 global) const;

	bool IsNightTime();
	float GetCurrentTimeOfDay();

	GameRaycastResult3D RaycastWorld(Vec3 startPos, Vec3 fwdNormal, float maxDist) const;

	bool RetrievedCompletedGenerateJob();

public:
	ConstantBuffer* m_gameCBO = nullptr;
	Player* m_player = nullptr;
	Shader* m_worldShader = nullptr;
	Texture* m_worldTexture = nullptr;
	SpriteSheet* m_worldSpriteSheet = nullptr;
	std::map<IntVec2, Chunk*> m_activeChunks;
	std::vector<Chunk*> m_dirtyMeshChunks;
	std::set<IntVec2> m_chunksBeingGeneratedOrLoaded;
	std::set<IntVec2> m_chunksBeingDeactivated;
	std::deque<BlockIterator> m_dirtyLightBlocks;
	int m_chunkActivationRange = 0;
	int m_chunkDeactivationRange = 0;
	int m_maxChunksRadiusX = 0;
	int m_maxChunksRadiusY = 0;
	int m_maxChunks = 0;
	float m_worldDay = 0.f;
	float m_worldTimeScale = 200.f;
	Vec3 m_skyColor;

	unsigned int m_worldSeed = 0;
};

int		GetBlockIndex(IntVec3 localBlockCoord);
IntVec3 GetBlockCoord(int index);
IntVec2 GetChunkGoord(IntVec3 globalBlockCoord);

