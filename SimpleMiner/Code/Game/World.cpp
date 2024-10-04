#include "Game/World.hpp"
#include "Game/Game.hpp"
#include "Game/Player.hpp"

std::vector<BlockDefinition*> BlockDefinition::s_blockDefList;

void BlockTemplate::InitializeBlockTemplate()
{
	// OAK TREE
	BlockTemplate* oakTree = new BlockTemplate();

	// LOG
	oakTree->AddEntry(BlockTemplateEntry(13, IntVec3(0, 0, 0)));
	oakTree->AddEntry(BlockTemplateEntry(13, IntVec3(0, 0, 1)));
	oakTree->AddEntry(BlockTemplateEntry(13, IntVec3(0, 0, 2)));
	oakTree->AddEntry(BlockTemplateEntry(13, IntVec3(0, 0, 3)));
	oakTree->AddEntry(BlockTemplateEntry(13, IntVec3(0, 0, 4)));
	oakTree->AddEntry(BlockTemplateEntry(13, IntVec3(0, 0, 5)));
	oakTree->AddEntry(BlockTemplateEntry(13, IntVec3(0, 0, 6)));
	oakTree->AddEntry(BlockTemplateEntry(13, IntVec3(0, 0, 7)));

	// LEAVES LAYER 1
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(1, 0, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-1, 0, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, 1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, -1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(1, 1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-1, -1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-1, 1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(1, -1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(2, 1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(2, 0, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(2, -1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-2, 1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-2, 0, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-2, -1, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-1, 2, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, 2, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(1, 2, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-1, -2, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, -2, 3)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(1, -2, 3)));
	// LEAVES LAYER 2
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(1, 0, 4)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-1, 0, 4)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, 1, 4)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, -1, 4)));
	// LEAVES LAYER 3
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(1, 0, 5)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-1, 0, 5)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, 1, 5)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, -1, 5)));
	// LEAVES LAYER 4
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(1, 0, 6)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-1, 0, 6)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, 1, 6)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, -1, 6)));
	// LEAVES LAYER 5
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(1, 0, 7)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(-1, 0, 7)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, 1, 7)));
	oakTree->AddEntry(BlockTemplateEntry(14, IntVec3(0, -1, 7)));

	AddNewBlockTemplate("oakTree", oakTree);

	// SPRUCE TREE
	BlockTemplate* spruceTree = new BlockTemplate();

	// LOG
	spruceTree->AddEntry(BlockTemplateEntry(15, IntVec3(0, 0, 0)));
	spruceTree->AddEntry(BlockTemplateEntry(15, IntVec3(0, 0, 1)));
	spruceTree->AddEntry(BlockTemplateEntry(15, IntVec3(0, 0, 2)));
	spruceTree->AddEntry(BlockTemplateEntry(15, IntVec3(0, 0, 3)));
	spruceTree->AddEntry(BlockTemplateEntry(15, IntVec3(0, 0, 4)));
	spruceTree->AddEntry(BlockTemplateEntry(15, IntVec3(0, 0, 5)));
	spruceTree->AddEntry(BlockTemplateEntry(15, IntVec3(0, 0, 6)));
	spruceTree->AddEntry(BlockTemplateEntry(15, IntVec3(0, 0, 7)));

	// LEAVES LAYER 1
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(1, 0, 3)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(-1, 0, 3)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, 1, 3)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, -1, 3)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(1, 1, 3)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(-1, -1, 3)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(-1, 1, 3)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(1, -1, 3)));
	// LEAVES LAYER 2
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(1, 0, 4)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(-1, 0, 4)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, 1, 4)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, -1, 4)));
	// LEAVES LAYER 3
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(1, 0, 5)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(-1, 0, 5)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, 1, 5)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, -1, 5)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(1, 1, 5)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(-1, -1, 5)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(-1, 1, 5)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(1, -1, 5)));
	// LEAVES LAYER 4
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(1, 0, 6)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(-1, 0, 6)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, 1, 6)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, -1, 6)));
	// LEAVES LAYER 5
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(1, 0, 7)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(-1, 0, 7)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, 1, 7)));
	spruceTree->AddEntry(BlockTemplateEntry(16, IntVec3(0, -1, 7)));

	AddNewBlockTemplate("spruceTree", spruceTree);


	// CACTUS
	BlockTemplate* cactus = new BlockTemplate();

	// LOG
	cactus->AddEntry(BlockTemplateEntry(17, IntVec3(0, 0, 0)));
	cactus->AddEntry(BlockTemplateEntry(17, IntVec3(0, 0, 1)));
	cactus->AddEntry(BlockTemplateEntry(17, IntVec3(0, 0, 2)));

	AddNewBlockTemplate("cactus", cactus);
}

BlockTemplate* BlockTemplate::GetByName(std::string name)
{
	for (size_t i = 0; i < s_blockTemplateList.size(); i++)
	{
		if (s_blockTemplateList[i]->m_name == name)
		{
			return s_blockTemplateList[i];
		}
	}
	return nullptr;
}

void BlockTemplate::AddNewBlockTemplate(std::string name, BlockTemplate* blockTemplate)
{
	blockTemplate->m_name = name;
	s_blockTemplateList.emplace_back(blockTemplate);
}

std::vector<BlockTemplate*> BlockTemplate::s_blockTemplateList;

int GetBlockIndex(IntVec3 blockCoord)
{
	return blockCoord.x | blockCoord.y << X_BITS | blockCoord.z << (X_BITS + Y_BITS);
}

IntVec3 GetBlockCoord(int index)
{
	return IntVec3(index & X_MASK, (index & Y_MASK) >> X_BITS, index >> (X_BITS + Y_BITS));
}

IntVec2 GetChunkGoord(IntVec3 globalBlockCoord)
{
	return IntVec2(globalBlockCoord.x / CHUNK_SIZE_X, globalBlockCoord.y / CHUNK_SIZE_Y);
}

BlockDefinition::BlockDefinition() // XmlElement& element

{
	//:  m_isVisible(ParseXmlAttribute(element, "visible", false)),
	//	m_isSolid(ParseXmlAttribute(element, "solid", false)),
	//	m_isOpaque(ParseXmlAttribute(element, "opaque", false)),
	//	m_topUVtexCoords(ParseXmlAttribute(element, "topUVCoords", IntVec2::ZERO)),
	//	m_sideUVtexCoords(ParseXmlAttribute(element, "sideUVCoords", IntVec2::ZERO)),
	//	m_bottomUVtexCoords(ParseXmlAttribute(element, "bottomUVCoords", IntVec2::ZERO))
}

void BlockDefinition::InitializeBlockDefs(char const* filePath)
{
	UNUSED(filePath);

	// 	XmlDocument file;
	// 	XmlError result = file.LoadFile(filePath);
	// 	GUARANTEE_OR_DIE(result == tinyxml2::XML_SUCCESS, "FILE IS NOT LOADED");
	// 
	// 	XmlElement* rootElement = file.RootElement();
	// 	GUARANTEE_OR_DIE(rootElement, "Root Element is null");
	// 
	// 	XmlElement* blockDefElement = rootElement->FirstChildElement();
	// 
	// 	while (blockDefElement)
	// 	{
	// 		std::string name = blockDefElement->Name();
	// 		GUARANTEE_OR_DIE(name == "TileDefinition", "Root child element is in the wrong format");
	// 		BlockDefinition* newBlockDef = new BlockDefinition(*blockDefElement);
	// 		s_blockDefList.push_back(newBlockDef);
	// 		blockDefElement = blockDefElement->NextSiblingElement();
	// 	}

	CreateNewBlockDef("air", 0, false, false, false, IntVec2(0, 0), IntVec2(0, 0), IntVec2(0, 0));
	CreateNewBlockDef("water", 1, true, false, false, IntVec2(32, 44), IntVec2(32, 44), IntVec2(32, 44));
	CreateNewBlockDef("stone", 2, true, true, true, IntVec2(33, 32), IntVec2(33, 32), IntVec2(33, 32));
	CreateNewBlockDef("dirt", 3, true, true, true, IntVec2(32, 34), IntVec2(32, 34), IntVec2(32, 34));
	CreateNewBlockDef("grass", 4, true, true, true, IntVec2(32, 33), IntVec2(33, 33), IntVec2(32, 34));
	CreateNewBlockDef("coal", 5, true, true, true, IntVec2(63, 34), IntVec2(63, 34), IntVec2(63, 34));
	CreateNewBlockDef("iron", 6, true, true, true, IntVec2(63, 35), IntVec2(63, 35), IntVec2(63, 35));
	CreateNewBlockDef("gold", 7, true, true, true, IntVec2(63, 36), IntVec2(63, 36), IntVec2(63, 36));
	CreateNewBlockDef("diamond", 8, true, true, true, IntVec2(63, 37), IntVec2(63, 37), IntVec2(63, 37));
	CreateNewBlockDef("cobbleStone", 9, true, true, true, IntVec2(42, 40), IntVec2(42, 40), IntVec2(42, 40));
	CreateNewBlockDef("glowstone", 10, true, true, true, IntVec2(46, 34), IntVec2(46, 34), IntVec2(46, 34), 15);
	CreateNewBlockDef("glacier", 11, true, true, true, IntVec2(36, 35), IntVec2(36, 35), IntVec2(36, 35));
	CreateNewBlockDef("sand", 12, true, true, true, IntVec2(34, 34), IntVec2(34, 34), IntVec2(34, 34));
	CreateNewBlockDef("oakLog", 13, true, true, true, IntVec2(38, 33), IntVec2(36, 33), IntVec2(38, 33));
	CreateNewBlockDef("oakLeaf", 14, true, true, true, IntVec2(32, 35), IntVec2(32, 35), IntVec2(32, 35));
	CreateNewBlockDef("spruceLog", 15, true, true, true, IntVec2(38, 33), IntVec2(35, 33), IntVec2(38, 33));
	CreateNewBlockDef("spruceLeaf", 16, true, true, true, IntVec2(34, 35), IntVec2(34, 35), IntVec2(34, 35));
	CreateNewBlockDef("cactus", 17, true, true, true, IntVec2(38, 36), IntVec2(37, 36), IntVec2(39, 36));
	CreateNewBlockDef("snowyGrass", 18, true, true, true, IntVec2(36, 35), IntVec2(33, 35), IntVec2(32, 34));
	CreateNewBlockDef("lava", 19, true, false, true, IntVec2(48, 43), IntVec2(48, 43), IntVec2(48, 43), 15);
	CreateNewBlockDef("ice", 20, true, true, true, IntVec2(47, 34), IntVec2(47, 34), IntVec2(47, 34));
}

void BlockDefinition::ClearDefinition()
{
	for (size_t i = 0; i < s_blockDefList.size(); i++)
	{
		if (s_blockDefList[i] != nullptr)
		{
			delete s_blockDefList[i];
			s_blockDefList[i] = nullptr;
		}
	}
}

void BlockDefinition::CreateNewBlockDef(std::string name, unsigned char ID, bool visible, bool solid, bool opaque, IntVec2 topSprite, IntVec2 sideSprite, IntVec2 bottomSprite, unsigned char m_lightInfluence)
{
	BlockDefinition* blockDef = new BlockDefinition();
	blockDef->m_name = name;
	blockDef->m_type = ID;
	blockDef->m_isVisible = visible;
	blockDef->m_isSolid = solid;
	blockDef->m_isOpaque = opaque;
	blockDef->m_topUVtexCoords = topSprite;
	blockDef->m_sideUVtexCoords = sideSprite;
	blockDef->m_bottomUVtexCoords = bottomSprite;
	blockDef->m_lightInfluence = m_lightInfluence;

	s_blockDefList.emplace_back(blockDef);
}

BlockDefinition* BlockDefinition::GetByName(std::string name)
{
	for (size_t i = 0; i < s_blockDefList.size(); i++)
	{
		if (s_blockDefList[i]->m_name == name)
		{
			return s_blockDefList[i];
		}
	}
	return nullptr;
}

BlockDefinition* BlockDefinition::GetByType(unsigned int type)
{
	for (size_t i = 0; i < s_blockDefList.size(); i++)
	{
		if (s_blockDefList[i]->m_type == type)
		{
			return s_blockDefList[i];
		}
	}
	return nullptr;
}

bool Block::IsBlockSolid() const
{
	return (m_bitFlags >> BLOCK_BIT_IS_SOLID) & 1;
}

bool Block::IsBlockVisible() const
{
	return (m_bitFlags >> BLOCK_BIT_IS_VISIBLE) & 1;
}

bool Block::IsBlockOpaque() const
{
	return (m_bitFlags >> BLOCK_BIT_IS_FULL_OPAQUE) & 1;
}

unsigned char Block::GetOutdoorLightInfluence() const
{
	return (m_lightInfluence & OUTDOOR_LIGHT_MASK) >> LIGHT_BITS;
}

unsigned char Block::GetIndoorLightInfluence() const
{
	return  m_lightInfluence & INDOOR_LIGHT_MASK;
}

unsigned char Block::GetIndoorLightInfluenceFromBlockDef() const
{
	return BlockDefinition::s_blockDefList[m_type]->m_lightInfluence;
}

void Block::SetOutdoorLightInfluence(unsigned char newOutdoorLightInfluence)
{
	m_lightInfluence &= ~OUTDOOR_LIGHT_MASK;
	m_lightInfluence |= (newOutdoorLightInfluence << LIGHT_BITS);
}

void Block::SetIndoorLightInfluence(unsigned char newIndoorLightInfluence)
{
	m_lightInfluence &= ~INDOOR_LIGHT_MASK;
	m_lightInfluence |= newIndoorLightInfluence;
}

bool Block::CanSeeSky() const
{
	return  (m_bitFlags >> BLOCK_BIT_IS_SKY) & 1;
}

bool Block::IsLightDirty() const
{
	return (m_bitFlags >> BLOCK_BIT_IS_LIGHT_DIRTY) & 1;
}

void Block::SetLightDirty()
{
	m_bitFlags |= (1 << BLOCK_BIT_IS_LIGHT_DIRTY);
}

void Block::SetLightNotDirty()
{
	m_bitFlags &= ~(1 << BLOCK_BIT_IS_LIGHT_DIRTY);
}

void Block::SetIsSky()
{
	m_bitFlags |= (1 << BLOCK_BIT_IS_SKY);
}

void Block::SetIsNotSky()
{
	m_bitFlags &= ~(1 << BLOCK_BIT_IS_SKY);
}

BlockIterator::BlockIterator(Chunk* chunk, int blockIndex)
	:m_chunk(chunk), m_blockIndex(blockIndex)
{

}

Block* BlockIterator::GetBlock() const
{
	if (!m_chunk)
	{
		return nullptr;
	}

	return m_chunk->GetBlock(m_blockIndex);
}

Vec3 BlockIterator::GetWorldCenter() const
{
	IntVec3 blockCoord = GetBlockCoord(m_blockIndex);
	return Vec3((float)(m_chunk->m_coord.x * CHUNK_SIZE_X + blockCoord.x) + 0.5f,
		(float)(m_chunk->m_coord.y * CHUNK_SIZE_Y + blockCoord.y) + 0.5f,
		(float)blockCoord.z + 0.5f);
}

Rgba8 BlockIterator::GetFaceTintForLightInfuenceValues(Direction direction) const
{
	float outdoorLighting = 15.f;
	float indoorLighting = 0.f;

	Rgba8 color;
	switch (direction)
	{
	case EAST:
		color = Rgba8(230, 230, 230);
		outdoorLighting = (float)GetEastNeighbor().GetBlock()->GetOutdoorLightInfluence();
		indoorLighting = (float)GetEastNeighbor().GetBlock()->GetIndoorLightInfluence();
		break;
	case WEST:
		color = Rgba8(230, 230, 230);
		outdoorLighting = (float)GetWestNeighbor().GetBlock()->GetOutdoorLightInfluence();
		indoorLighting = (float)GetWestNeighbor().GetBlock()->GetIndoorLightInfluence();
		break;
	case NORTH:
		color = Rgba8(200, 200, 200);
		outdoorLighting = (float)GetNorthNeighbor().GetBlock()->GetOutdoorLightInfluence();
		indoorLighting = (float)GetNorthNeighbor().GetBlock()->GetIndoorLightInfluence();
		break;
	case SOUTH:
		color = Rgba8(200, 200, 200);
		outdoorLighting = (float)GetSouthNeighbor().GetBlock()->GetOutdoorLightInfluence();
		indoorLighting = (float)GetSouthNeighbor().GetBlock()->GetIndoorLightInfluence();
		break;
	case UPWARD:
		color = Rgba8(255, 255, 255);
		if (GetUpwardNeighbor().GetBlock())
		{
			outdoorLighting = (float)GetUpwardNeighbor().GetBlock()->GetOutdoorLightInfluence();
			indoorLighting = (float)GetUpwardNeighbor().GetBlock()->GetIndoorLightInfluence();
		}
		break;
	case DOWNWARD:
		color = Rgba8(255, 255, 255);
		if (GetDownwardNeighbor().GetBlock())
		{
			outdoorLighting = (float)GetDownwardNeighbor().GetBlock()->GetOutdoorLightInfluence();
			indoorLighting = (float)GetDownwardNeighbor().GetBlock()->GetIndoorLightInfluence();
		}
		break;
	}

	unsigned char rValue = (unsigned char)RangeMapClamped(outdoorLighting, 0.f, 15.f, 0.f, (float)color.r);
	unsigned char gValue = (unsigned char)RangeMapClamped(indoorLighting, 0.f, 15.f, 0.f, (float)color.g);
	unsigned char bValue = 127;


	return Rgba8(rValue, gValue, bValue);
}

BlockIterator BlockIterator::GetEastNeighbor() const
{
	if (m_chunk == nullptr)
	{
		return BlockIterator(nullptr, -1);
	}

	int localX = m_blockIndex & X_MASK;
	if (localX == X_MASK)
	{
		return BlockIterator(m_chunk->m_eastNeighbor, m_blockIndex & ~X_MASK);
	}
	else
	{
		return BlockIterator(m_chunk, m_blockIndex + 1);
	}
}

BlockIterator BlockIterator::GetWestNeighbor() const
{
	if (m_chunk == nullptr)
	{
		return BlockIterator(nullptr, -1);
	}

	int localX = m_blockIndex & X_MASK;
	if (localX == 0)
	{
		return BlockIterator(m_chunk->m_westNeighbor, m_blockIndex | X_MASK);
	}
	else
	{
		return BlockIterator(m_chunk, m_blockIndex - 1);
	}
}

BlockIterator BlockIterator::GetNorthNeighbor() const
{
	if (m_chunk == nullptr)
	{
		return BlockIterator(nullptr, -1);
	}

	int localY = m_blockIndex & Y_MASK;
	if (localY == Y_MASK)
	{
		return BlockIterator(m_chunk->m_northNeighbor, m_blockIndex & ~Y_MASK);
	}
	else
	{
		return BlockIterator(m_chunk, m_blockIndex + CHUNK_SIZE_X);
	}
}

BlockIterator BlockIterator::GetSouthNeighbor() const
{
	if (m_chunk == nullptr)
	{
		return BlockIterator(nullptr, -1);
	}

	int localY = m_blockIndex & Y_MASK;
	if (localY == 0)
	{
		return BlockIterator(m_chunk->m_southNeighbor, m_blockIndex | Y_MASK);
	}
	else
	{
		return BlockIterator(m_chunk, m_blockIndex - CHUNK_SIZE_X);
	}
}

BlockIterator BlockIterator::GetUpwardNeighbor() const
{
	if (m_chunk == nullptr || (m_blockIndex + (CHUNK_SIZE_X * CHUNK_SIZE_Y)) >> (X_BITS + Y_BITS) >= CHUNK_SIZE_Z)
	{
		return BlockIterator(nullptr, -1);
	}

	return BlockIterator(m_chunk, m_blockIndex + (CHUNK_SIZE_X * CHUNK_SIZE_Y));
}

BlockIterator BlockIterator::GetDownwardNeighbor() const
{
	if (m_chunk == nullptr || (m_blockIndex - (CHUNK_SIZE_X * CHUNK_SIZE_Y)) >> (X_BITS + Y_BITS) < 0)
	{
		return BlockIterator(nullptr, -1);
	}

	return BlockIterator(m_chunk, m_blockIndex - (CHUNK_SIZE_X * CHUNK_SIZE_Y));
}

Chunk::Chunk(World* owner, IntVec2 coord)
	:m_world(owner), m_coord(coord)
{
	m_blocks = new Block[TOTAL_BLOCKS_SIZE];
	m_cpuMeshVerts.reserve(25000);
	m_cpuMeshIndexes.reserve(30000);

	m_bound = AABB3((float)(m_coord.x * CHUNK_SIZE_X), (float)(m_coord.y * CHUNK_SIZE_Y), 0.f,
		(float)((m_coord.x + 1) * CHUNK_SIZE_X), (float)((m_coord.y + 1) * CHUNK_SIZE_Y), (float)CHUNK_SIZE_Z);

	m_cpuMeshIndexes.clear();
	m_cpuMeshVerts.clear();
}

Chunk::~Chunk()
{
	if (m_northNeighbor)
	{
		m_northNeighbor->m_southNeighbor = nullptr;
		m_northNeighbor = nullptr;
	}

	if (m_southNeighbor)
	{
		m_southNeighbor->m_northNeighbor = nullptr;
		m_southNeighbor = nullptr;
	}

	if (m_eastNeighbor)
	{
		m_eastNeighbor->m_westNeighbor = nullptr;
		m_eastNeighbor = nullptr;
	}

	if (m_westNeighbor)
	{
		m_westNeighbor->m_eastNeighbor = nullptr;
		m_westNeighbor = nullptr;
	}

	if (m_gpuMeshIBO)
	{
		delete m_gpuMeshIBO;
	}
	m_gpuMeshIBO = nullptr;

	if (m_gpuMeshVBO)
	{
		delete m_gpuMeshVBO;
	}
	m_gpuMeshVBO = nullptr;

	delete[] m_blocks;
	m_blocks = nullptr;
}

void Chunk::Update(float deltaSeconds)
{
	UNUSED(deltaSeconds);

	//BuildCPUMesh();
}

void Chunk::Render() const
{
	if (!m_isActive)
	{
		return;
	}

	if (!m_gpuMeshVBO || !m_gpuMeshIBO)
	{
		return;
	}

	g_theRenderer->DrawIndexedBuffer(m_gpuMeshVBO, m_gpuMeshIBO, (int)m_cpuMeshIndexes.size(), 0, VertexType::Vertex_PCU);
}

void Chunk::SetBlockType(IntVec3 blockCoord, std::string name)
{
	SetBlockType(GetBlockIndex(blockCoord), name);
}

void Chunk::SetBlockType(int index, std::string name)
{
	m_blocks[index].m_bitFlags = 0;

	BlockDefinition* blockDef = BlockDefinition::GetByName(name);
	m_blocks[index].m_type = blockDef->m_type;
	m_blocks[index].m_lightInfluence = blockDef->m_lightInfluence;
	if (blockDef->m_isVisible)
	{
		m_blocks[index].m_bitFlags |= (1 << BLOCK_BIT_IS_VISIBLE);
	}
	if (blockDef->m_isSolid)
	{
		m_blocks[index].m_bitFlags |= (1 << BLOCK_BIT_IS_SOLID);
	}
	if (blockDef->m_isOpaque)
	{
		m_blocks[index].m_bitFlags |= (1 << BLOCK_BIT_IS_FULL_OPAQUE);
	}
	if (blockDef->m_lightInfluence > 0)
	{
		m_blocks[index].SetIndoorLightInfluence(blockDef->m_lightInfluence);
	}
}

void Chunk::SetBlockType(IntVec3 blockCoord, unsigned int type)
{
	SetBlockType(GetBlockIndex(blockCoord), type);
}

void Chunk::SetBlockType(int index, unsigned int type)
{
	m_blocks[index].m_bitFlags = 0;

	BlockDefinition* blockDef = BlockDefinition::GetByType(type);
	m_blocks[index].m_type = blockDef->m_type;
	m_blocks[index].m_lightInfluence = blockDef->m_lightInfluence;
	if (blockDef->m_isVisible)
	{
		m_blocks[index].m_bitFlags |= (1 << BLOCK_BIT_IS_VISIBLE);
	}
	if (blockDef->m_isSolid)
	{
		m_blocks[index].m_bitFlags |= (1 << BLOCK_BIT_IS_SOLID);
	}
	if (blockDef->m_isOpaque)
	{
		m_blocks[index].m_bitFlags |= (1 << BLOCK_BIT_IS_FULL_OPAQUE);
	}
	if (blockDef->m_lightInfluence > 0)
	{
		m_blocks[index].SetIndoorLightInfluence(blockDef->m_lightInfluence);
	}
}

void Chunk::SetMeshDirty()
{
	for (size_t i = 0; i < m_world->m_dirtyMeshChunks.size(); i++)
	{
		if (m_world->m_dirtyMeshChunks[i] == this)
		{
			m_isDirty = true;
			return;
		}
	}

	m_world->m_dirtyMeshChunks.push_back(this);
	m_isDirty = true;
}

void Chunk::SetChunkNeedsSave()
{
	m_needSaving = true;
}

bool Chunk::SaveData()
{
	if (!m_blocks)
	{
		return false;
	}

	m_status = ChunkStatus::DEACTIVATING_SAVING;

	m_needSaving = false;

	CreateFolder(Stringf("Saves/World_%u", m_world->m_worldSeed));

	std::vector<uint8_t> chunkDataBuffer;
	chunkDataBuffer.reserve(10000);

	chunkDataBuffer.emplace_back('G');
	chunkDataBuffer.emplace_back('C');
	chunkDataBuffer.emplace_back('H');
	chunkDataBuffer.emplace_back('K');

	chunkDataBuffer.emplace_back(CHUNK_FILE_FORMAT_VERSION);
	chunkDataBuffer.emplace_back((uint8_t)X_BITS);
	chunkDataBuffer.emplace_back((uint8_t)Y_BITS);
	chunkDataBuffer.emplace_back((uint8_t)Z_BITS);

	uint8_t* asByteArray = reinterpret_cast<uint8_t*>(&m_world->m_worldSeed);

	chunkDataBuffer.emplace_back(asByteArray[0]);
	chunkDataBuffer.emplace_back(asByteArray[1]);
	chunkDataBuffer.emplace_back(asByteArray[2]);
	chunkDataBuffer.emplace_back(asByteArray[3]);

	unsigned char currentType = m_blocks[0].m_type;
	int currentSameTypeCount = 0;


	for (int i = 0; i < TOTAL_BLOCKS_SIZE; i++)
	{
		unsigned char blockType = GetBlock(i)->m_type;

		if (blockType != currentType || currentSameTypeCount == 0xFF)
		{
			chunkDataBuffer.emplace_back((uint8_t)currentType);
			chunkDataBuffer.emplace_back((uint8_t)currentSameTypeCount);

			currentType = blockType;
			currentSameTypeCount = 0;
		}

		currentSameTypeCount++;

		if (i == TOTAL_BLOCKS_SIZE - 1)
		{
			chunkDataBuffer.emplace_back((uint8_t)currentType);
			chunkDataBuffer.emplace_back((uint8_t)currentSameTypeCount);
		}
	}


	std::string fileName = Stringf("Saves/World_%u/Chunk(%i,%i).chunk", m_world->m_worldSeed, m_coord.x, m_coord.y);
	return FileWriteFromBuffer(chunkDataBuffer, fileName);
}

bool Chunk::LoadData()
{
	std::vector<uint8_t> chunkDataBuffer;
	chunkDataBuffer.reserve(10000);

	std::string fileName = Stringf("Saves/World_%u/Chunk(%i,%i).chunk", m_world->m_worldSeed, m_coord.x, m_coord.y);
	FileReadToBuffer(chunkDataBuffer, fileName);

	GUARANTEE_OR_DIE(chunkDataBuffer[0] == 'G', Stringf("Chunk(%i,%i).chunk doesn't have correct format", m_coord.x, m_coord.y));
	GUARANTEE_OR_DIE(chunkDataBuffer[1] == 'C', Stringf("Chunk(%i,%i).chunk doesn't have correct format", m_coord.x, m_coord.y));
	GUARANTEE_OR_DIE(chunkDataBuffer[2] == 'H', Stringf("Chunk(%i,%i).chunk doesn't have correct format", m_coord.x, m_coord.y));
	GUARANTEE_OR_DIE(chunkDataBuffer[3] == 'K', Stringf("Chunk(%i,%i).chunk doesn't have correct format", m_coord.x, m_coord.y));

	GUARANTEE_RECOVERABLE(chunkDataBuffer[4] == CHUNK_FILE_FORMAT_VERSION, Stringf("Chunk(%i,%i).chunk file format version outdated", m_coord.x, m_coord.y));
	GUARANTEE_OR_DIE(chunkDataBuffer[5] == (uint8_t)X_BITS, Stringf("Chunk(%i,%i).chunk doesn't have correct format", m_coord.x, m_coord.y));
	GUARANTEE_OR_DIE(chunkDataBuffer[6] == (uint8_t)Y_BITS, Stringf("Chunk(%i,%i).chunk doesn't have correct format", m_coord.x, m_coord.y));
	GUARANTEE_OR_DIE(chunkDataBuffer[7] == (uint8_t)Z_BITS, Stringf("Chunk(%i,%i).chunk doesn't have correct format", m_coord.x, m_coord.y));

	uint8_t asByteArray[4] = { chunkDataBuffer[8], chunkDataBuffer[9] , chunkDataBuffer[10] , chunkDataBuffer[11] };
	uint32_t* worldSeedFromFile = reinterpret_cast<uint32_t*>(asByteArray);

	if (*worldSeedFromFile != m_world->m_worldSeed)
	{
		return false;
	}

	int currentIndex = 0;

	for (size_t i = 12; i < chunkDataBuffer.size(); i += 2)
	{
		for (uint8_t j = 0; j < chunkDataBuffer[i + 1]; j++)
		{
			SetBlockType(currentIndex, (unsigned char)chunkDataBuffer[i]);
			currentIndex++;
		}
	}
	return true;
}

void Chunk::PlaceBlockTemplateOnCoord(BlockTemplate* blockTemplate, IntVec3 globalRootCoord)
{
	IntVec3 localRootCoord = GetBlockLocalCoord(globalRootCoord);

	for (size_t i = 0; i < blockTemplate->m_blockTemplateEntries.size(); i++)
	{
		IntVec3 localCoord = blockTemplate->m_blockTemplateEntries[i].m_relativeCoord + localRootCoord;

		if (localCoord.x < 0
			|| localCoord.x > CHUNK_SIZE_X - 1
			|| localCoord.y < 0
			|| localCoord.y > CHUNK_SIZE_Y - 1
			|| localCoord.z < 0
			|| localCoord.z > CHUNK_SIZE_Z - 1)
		{
			continue;
		}

		SetBlockType(localCoord, blockTemplate->m_blockTemplateEntries[i].m_type);
	}
}

bool Chunk::CanSpawnTreeAtThisSpot(int globalX, int globalY, float treeNoiseThreshold)
{
	float currentValue = Get2dNoiseZeroToOne(globalX, globalY);

	if (currentValue <= treeNoiseThreshold)
	{
		return false;
	}

	float neighborsValue[9];
	int index = 0;

	for (int Py = globalY - 1; Py <= globalY + 1; Py++)
	{
		for (int Px = globalX - 1; Px <= globalX + 1; Px++)
		{
			neighborsValue[index] = Get2dNoiseZeroToOne(Px, Py);
			index++;
		}
	}

	for (size_t i = 0; i < index; i++)
	{
		if (currentValue < neighborsValue[i])
		{
			return false;
		}
	}

	return true;
}

bool Chunk::DoesMeetAllRequirementsForBuildingMesh()
{
	if (!m_isDirty)								return false;
	if (!m_westNeighbor)						return false;
	if (!m_eastNeighbor)						return false;
	if (!m_northNeighbor)						return false;
	if (!m_southNeighbor)						return false;
	//if (m_westNeighbor && !m_westNeighbor->m_northNeighbor)		return false;
	//if (m_westNeighbor && !m_westNeighbor->m_southNeighbor)		return false;
	//if (m_eastNeighbor && !m_eastNeighbor->m_northNeighbor)		return false;
	//if (m_eastNeighbor && !m_eastNeighbor->m_southNeighbor)	    return false;
	if (m_status != ChunkStatus::ACTIVE) return false;
	return true;
}

CaveDiggerMachine* Chunk::IsThisStartPointOfTheCave(int globalX, int globalY, float caveNoiseThreshold)
{
	float currentValue = Get2dNoiseZeroToOne(globalX, globalY);

	if (currentValue <= caveNoiseThreshold)
	{
		return nullptr;
	}

	for (int Py = globalY - CAVE_RANGE; Py <= globalY + CAVE_RANGE; Py++)
	{
		for (int Px = globalX - CAVE_RANGE; Px <= globalX + CAVE_RANGE; Px++)
		{
			if (currentValue < Get2dNoiseZeroToOne(Px, Py))
			{
				return nullptr;
			}
		}
	}

	CaveDiggerMachine* cave = new CaveDiggerMachine(this, IntVec3(globalX, globalY, 0));

	return cave;
}

void Chunk::GenerateAllBlockData()
{
	//std::this_thread::sleep_for(std::chrono::milliseconds(200));

	m_status = ChunkStatus::ACTIVATING_GENERATING;

	int waterlevel = CHUNK_SIZE_Z / 2;
	int riverDepth = g_gameConfigBlackboard.GetValue("riverDepth", 5);
	int riverBed = waterlevel - riverDepth;
	int maxHeightAboveRiver = g_gameConfigBlackboard.GetValue("maxGeneratedTerrainHeight", 100) - waterlevel;
	int maxOceanDepth = g_gameConfigBlackboard.GetValue("maxOceanDepth", 40);

	BlockTemplate* oakTree = BlockTemplate::GetByName("oakTree");
	BlockTemplate* spruceTree = BlockTemplate::GetByName("spruceTree");
	BlockTemplate* cactus = BlockTemplate::GetByName("cactus");

	std::vector<int> randomDirtBelowList;

	int XYSize = CHUNK_SIZE_Y * CHUNK_SIZE_X;
	randomDirtBelowList.reserve(XYSize);
	m_terrainHeightList.reserve(XYSize);
	m_hillinessList.reserve(XYSize);
	m_oceannessList.reserve(XYSize);
	m_humidityList.reserve(XYSize);
	m_temperatureList.reserve(XYSize);

	for (int y = 0; y < EXTENDED_CHUNK_SIZE_Y; y++)
	{
		for (int x = 0; x < EXTENDED_CHUNK_SIZE_X; x++)
		{
			int globalX = m_coord.x * CHUNK_SIZE_X + x;
			int globalY = m_coord.y * CHUNK_SIZE_Y + y;
			float fglobalX = (float)globalX;
			float fglobalY = (float)globalY;

			float hillness = 0.5f + 0.5f * Compute2dPerlinNoise(fglobalX, fglobalY, 2000.f, 10, 0.5f, 2.0f, false, m_world->m_worldSeed + 1);
			float oceanness = 0.5f + 0.5f * Compute2dPerlinNoise(fglobalX, fglobalY, 2000.f, 1, 0.5f, 2.0f, false, m_world->m_worldSeed + 2);
			float humidity = 0.5f + 0.5f * Compute2dPerlinNoise(fglobalX, fglobalY, 500.f, 6, 0.5f, 2.0f, false, m_world->m_worldSeed + 3);
			float temperature = 0.5f + 0.5f * Compute2dPerlinNoise(fglobalX, fglobalY, 900.f, 7, 0.5f, 2.0f, false, m_world->m_worldSeed + 4);
			float forestness = 0.5f + 0.5f * Compute2dPerlinNoise(fglobalX, fglobalY, 100.f, 7, 0.5f, 5.0f, false, m_world->m_worldSeed + 5);
			float lavaness = 0.5f + 0.5f * Compute2dPerlinNoise(fglobalX, fglobalY, 500.f, 1, 1.5f, 1.0f, false, m_world->m_worldSeed + 6);

			hillness = SmoothStep3(SmoothStep3(hillness));
			lavaness = SmoothStep3(lavaness);
			oceanness = SmoothStep3(SmoothStep3(oceanness));
			forestness = SmoothStart6(forestness);
			humidity = 1.f - (1.f - humidity) * (1.f - oceanness);
			//temperature = 1.f - (temperature) * (1.f - hillness);

			float terrainHeightNoise = fabsf(Compute2dPerlinNoise(fglobalX, fglobalY, 500.f, 7, 0.5f, 2.0f, false, m_world->m_worldSeed));

			float theoreticalTerrainHeightAboveRiver = float(maxHeightAboveRiver) * terrainHeightNoise;

			if (RoundDownToInt(theoreticalTerrainHeightAboveRiver) >= riverDepth)
			{
				theoreticalTerrainHeightAboveRiver *= hillness;
			}

			int actualTerrainHeight = riverBed + RoundDownToInt(theoreticalTerrainHeightAboveRiver);

			if (oceanness >= 0.5f)
			{
				if (oceanness >= 0.75f)
				{
					actualTerrainHeight -= maxOceanDepth;
				}
				else
				{
					float oceanLoweringStrength = RangeMapClamped(oceanness, 0.5f, 0.75f, 0.f, 1.f);
					int oceanDepth = int((float)maxOceanDepth * oceanLoweringStrength);
					actualTerrainHeight -= oceanDepth;
				}
			}


			float radomDirtNum = Compute2dPerlinNoise(fglobalX, fglobalY, 200.f, 4, 0.5f, 2.0f, false, m_world->m_worldSeed);
			randomDirtBelowList.push_back((int)RangeMapClamped(radomDirtNum, -1.f, 1.f, 3.f, 4.f));

			m_terrainHeightList.push_back(actualTerrainHeight);
			m_hillinessList.push_back(hillness);
			m_oceannessList.push_back(oceanness);
			m_humidityList.push_back(humidity);
			m_temperatureList.push_back(temperature);
			m_forestnessList.push_back(forestness);
			m_lavanessList.push_back(lavaness);
		}
	}

	for (int z = 0; z < CHUNK_SIZE_Z; z++)
	{
		for (int neighborY = 0; neighborY < EXTENDED_CHUNK_SIZE_Y; neighborY++)
		{
			for (int neighborX = 0; neighborX < EXTENDED_CHUNK_SIZE_X; neighborX++)
			{
				int localX = neighborX - EXTENDED_CHUNK_RANGE;
				int localY = neighborY - EXTENDED_CHUNK_RANGE;

				if (localX < 0 || localX >= CHUNK_SIZE_X || localY < 0 || localY >= CHUNK_SIZE_Y)
				{
					continue;
				}

				int noiseIndex = neighborX + neighborY * (CHUNK_SIZE_X + EXTENDED_CHUNK_RANGE * 2);

				int blockIndex = GetBlockIndex(IntVec3(localX, localY, z));

				if (z > m_terrainHeightList[noiseIndex])
				{
					if (m_terrainHeightList[noiseIndex] <= waterlevel && z <= waterlevel)
					{
						if (m_temperatureList[noiseIndex] < 0.4f)
						{
							if (m_oceannessList[noiseIndex] > 0.5f)
							{
								SetBlockType(blockIndex, 11); // GLACIER
							}
							else
							{
								SetBlockType(blockIndex, 20); // ICE
							}
						}
						else
						{
							SetBlockType(blockIndex, 1); // WATER
						}
					}
					else
					{
						SetBlockType(blockIndex, 0); // AIR
					}
				}
				else
				{
					if (z == m_terrainHeightList[noiseIndex])
					{
						if (m_humidityList[noiseIndex] < 0.6f && z == waterlevel)
						{
							SetBlockType(blockIndex, 12); // SAND
						}
						else
						{
							if (m_humidityList[noiseIndex] < 0.4f)
							{
								SetBlockType(blockIndex, 12); // SAND
							}
							else
							{
								if (m_temperatureList[noiseIndex] < 0.4f)
								{
									SetBlockType(blockIndex, 18); // SNOW GRASS
								}
								else
								{
									SetBlockType(blockIndex, 4); // GRASS
								}
							}
						}

					}
					else
					{
						if (z >= m_terrainHeightList[noiseIndex] - randomDirtBelowList[noiseIndex])
						{
							if (m_humidityList[noiseIndex] < 0.4f)
							{
								SetBlockType(blockIndex, 12); // SAND
							}
							else
							{
								SetBlockType(blockIndex, 3); // DIRT
							}
						}
						else
						{
							if (g_theRNG->RollRandomChance(0.05f))
							{
								SetBlockType(blockIndex, 5); // COAL
							}
							else
							{
								if (g_theRNG->RollRandomChance(0.02f))
								{
									SetBlockType(blockIndex, 6); // IRON
								}
								else
								{
									if (g_theRNG->RollRandomChance(0.005f) && z < 30)
									{
										SetBlockType(blockIndex, 7); // GOLD
									}
									else
									{
										if (g_theRNG->RollRandomChance(0.001f) && z < 15)
										{
											SetBlockType(blockIndex, 8); // DIAMOND
										}
										else
										{
											SetBlockType(blockIndex, 2); // STONE
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}


	//_______________________________________________________________________________
	// CAVE GENERATION
	 
	for (int neighborY = 0; neighborY < CAVE_DETECTION_SIZE_Y; neighborY++)
	{
		for (int neighborX = 0; neighborX < CAVE_DETECTION_SIZE_X; neighborX++)
		{
			int globalX = m_coord.x * CHUNK_SIZE_X + (neighborX - CAVE_RANGE);
			int globalY = m_coord.y * CHUNK_SIZE_Y + (neighborY - CAVE_RANGE);

			CaveDiggerMachine* cave = IsThisStartPointOfTheCave(globalX, globalY, 0.99f);
			if (cave)
			{
				cave->GenerateCave();
			}
		}
	}

	//_______________________________________________________________________________

	for (int neighborY = 0; neighborY < EXTENDED_CHUNK_SIZE_Y; neighborY++)
	{
		for (int neighborX = 0; neighborX < EXTENDED_CHUNK_SIZE_X; neighborX++)
		{
			int globalX = m_coord.x * CHUNK_SIZE_X + (neighborX - EXTENDED_CHUNK_RANGE);
			int globalY = m_coord.y * CHUNK_SIZE_Y + (neighborY - EXTENDED_CHUNK_RANGE);

			int noiseIndex = neighborX + neighborY * (CHUNK_SIZE_X + EXTENDED_CHUNK_RANGE * 2);

			float treeNoiseThreshold = RangeMapClamped(m_forestnessList[noiseIndex], 0.6f, 1.f, 0.996f, 0.7f);

			IntVec3 treeSpawnGlobalCoord = IntVec3(globalX, globalY, m_terrainHeightList[noiseIndex] + 1);

			if (CanSpawnTreeAtThisSpot(globalX, globalY, treeNoiseThreshold))
			{
				if (m_terrainHeightList[noiseIndex] > waterlevel && m_oceannessList[noiseIndex] < 0.5f)
				{
					if (m_humidityList[noiseIndex] < 0.4f)
					{
						PlaceBlockTemplateOnCoord(cactus, treeSpawnGlobalCoord);
					}
					else
					{
						if (m_temperatureList[noiseIndex] < 0.4f)
						{
							PlaceBlockTemplateOnCoord(spruceTree, treeSpawnGlobalCoord);
						}
						else
						{
							PlaceBlockTemplateOnCoord(oakTree, treeSpawnGlobalCoord);
						}
					}
				}
			}
		}
	}

	for (int z = 0; z < CHUNK_SIZE_Z; z++)
	{
		for (int neighborY = 0; neighborY < EXTENDED_CHUNK_SIZE_Y; neighborY++)
		{
			for (int neighborX = 0; neighborX < EXTENDED_CHUNK_SIZE_X; neighborX++)
			{
				int localX = neighborX - EXTENDED_CHUNK_RANGE;
				int localY = neighborY - EXTENDED_CHUNK_RANGE;

				if (localX < 0 || localX >= CHUNK_SIZE_X || localY < 0 || localY >= CHUNK_SIZE_Y || z > 2)
				{
					continue;
				}

				int blockIndex = GetBlockIndex(IntVec3(localX, localY, z));

				if (z == 0)
				{
					SetBlockType(blockIndex, 2); // STONE
					continue;
				}

				int noiseIndex = neighborX + neighborY * (CHUNK_SIZE_X + EXTENDED_CHUNK_RANGE * 2);

				if (m_blocks[blockIndex].m_type == 0 && m_lavanessList[noiseIndex] > 0.5f)
				{
					SetBlockType(blockIndex, 19); // LAVA
				}
			}
		}
	}

	for (int i = 0; i < TOTAL_BLOCKS_SIZE; i++)
	{
		BlockIterator currentBlock = BlockIterator(this, i);
		if (m_blocks[i].m_type == 1)
		{
			while (currentBlock.GetDownwardNeighbor().GetBlock() && currentBlock.GetDownwardNeighbor().GetBlock()->m_type == 0)
			{
				SetBlockType(currentBlock.GetDownwardNeighbor().m_blockIndex, 1); // WATER
				currentBlock = currentBlock.GetDownwardNeighbor();
			}
		
		}
	}
}

void Chunk::LightInfluenceInitialization()
{
	// ALL BORDER BLOCK DIRTY
	for (int i = 0; i < TOTAL_BLOCKS_SIZE; i++)
	{
		IntVec3 coord = GetBlockCoord(i);

		if (m_westNeighbor && coord.x == 0 && !m_blocks[i].IsBlockOpaque())
		{
			m_world->MarkLightingDirty(BlockIterator(this, i));
			continue;
		}
		if (m_eastNeighbor && coord.x == X_MASK && !m_blocks[i].IsBlockOpaque())
		{
			m_world->MarkLightingDirty(BlockIterator(this, i));
			continue;
		}
		if (m_southNeighbor && coord.y == 0 && !m_blocks[i].IsBlockOpaque())
		{
			m_world->MarkLightingDirty(BlockIterator(this, i));
			continue;
		}
		if (m_northNeighbor && coord.y == Y_MASK && !m_blocks[i].IsBlockOpaque())
		{
			m_world->MarkLightingDirty(BlockIterator(this, i));
			continue;
		}
	}
	// MARK SKY BLOCKS
	for (int y = 0; y < CHUNK_SIZE_Y; y++)
	{
		for (int x = 0; x < CHUNK_SIZE_X; x++)
		{
			for (int z = CHUNK_SIZE_Z - 1; z >= 0; z--)
			{
				Block* block = GetBlock(IntVec3(x, y, z));
				if (!block->IsBlockOpaque())
				{
					block->SetIsSky();
				}
				else
				{
					break;
				}
			}
		}
	}
	// SET LIGHT INFLUENCE AND MARK HORIZONTAL BLOCKS DIRTY
	for (int y = 0; y < CHUNK_SIZE_Y; y++)
	{
		for (int x = 0; x < CHUNK_SIZE_X; x++)
		{
			for (int z = CHUNK_SIZE_Z - 1; z >= 0; z--)
			{
				int index = GetBlockIndex(IntVec3(x, y, z));
				Block* block = GetBlock(index);
				if (!block->IsBlockOpaque())
				{
					block->SetOutdoorLightInfluence(15);
					BlockIterator currentBlock = BlockIterator(this, index);
					Block* east = currentBlock.GetEastNeighbor().GetBlock();
					Block* west = currentBlock.GetWestNeighbor().GetBlock();
					Block* north = currentBlock.GetNorthNeighbor().GetBlock();
					Block* south = currentBlock.GetSouthNeighbor().GetBlock();
					if (east && !east->IsBlockOpaque() && !east->CanSeeSky())
					{
						m_world->MarkLightingDirty(currentBlock.GetEastNeighbor());
					}
					if (west && !west->IsBlockOpaque() && !west->CanSeeSky())
					{
						m_world->MarkLightingDirty(currentBlock.GetWestNeighbor());
					}
					if (north && !north->IsBlockOpaque() && !north->CanSeeSky())
					{
						m_world->MarkLightingDirty(currentBlock.GetNorthNeighbor());
					}
					if (south && !south->IsBlockOpaque() && !south->CanSeeSky())
					{
						m_world->MarkLightingDirty(currentBlock.GetSouthNeighbor());
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	// SET LIGHT DIRTY FOR BLOCK THAT EMITS LIGHT
	for (int i = 0; i < TOTAL_BLOCKS_SIZE; i++)
	{
		if (m_blocks[i].GetIndoorLightInfluenceFromBlockDef() > 0)
		{
			m_world->MarkLightingDirty(BlockIterator(this, i));
		}
	}
}

bool Chunk::BuildCPUMesh()
{
	if (m_gpuMeshVBO) delete m_gpuMeshVBO;
	if (m_gpuMeshIBO) delete m_gpuMeshIBO;

	m_cpuMeshVerts.clear();
	m_cpuMeshIndexes.clear();

	for (int i = 0; i < TOTAL_BLOCKS_SIZE; i++)
	{
		CreateBlockMesh(BlockIterator(this, i));
	}

	m_gpuMeshVBO = g_theRenderer->CreateVertexBuffer(sizeof(Vertex_PCU) * (int)m_cpuMeshVerts.size());
	m_gpuMeshIBO = g_theRenderer->CreateIndexBuffer(sizeof(unsigned int) * m_cpuMeshIndexes.size());
	g_theRenderer->CopyCPUToGPU(m_cpuMeshVerts.data(), (int)(m_cpuMeshVerts.size() * sizeof(Vertex_PCU)), m_gpuMeshVBO);
	g_theRenderer->CopyCPUToGPU(m_cpuMeshIndexes.data(), (int)(m_cpuMeshIndexes.size() * sizeof(unsigned int)), m_gpuMeshIBO);

	m_isDirty = false;

	return true;
}

IntVec3 Chunk::GetBlockGlobalCoord(IntVec3 local)
{
	return IntVec3(m_coord.x * CHUNK_SIZE_X + local.x, m_coord.y * CHUNK_SIZE_Y + local.y, local.z);
}

IntVec3 Chunk::GetBlockLocalCoord(IntVec3 global)
{
	int x = global.x - m_coord.x * CHUNK_SIZE_X;
	int y = global.y - m_coord.y * CHUNK_SIZE_Y;
	return IntVec3(x, y, global.z);
}

Block* Chunk::GetBlock(IntVec3 coord)
{
	int blockIndex = GetBlockIndex(coord);
	GUARANTEE_OR_DIE(blockIndex >= 0 && blockIndex < TOTAL_BLOCKS_SIZE, "Bad block index");
	return &m_blocks[blockIndex];
}

Block* Chunk::GetBlock(int index)
{
	GUARANTEE_OR_DIE(index >= 0 && index < TOTAL_BLOCKS_SIZE, "Bad block index");
	return &m_blocks[index];
}

void Chunk::CreateBlockMesh(BlockIterator blockIter)
{
	Block* block = blockIter.GetBlock();

	if (!block->IsBlockVisible())
	{
		return;
	}

	AABB2 bottomUvBox = m_world->m_worldSpriteSheet->GetSpriteUVs(m_world->m_worldSpriteSheet->GetSpriteIndex(BlockDefinition::s_blockDefList[block->m_type]->m_bottomUVtexCoords));
	AABB2 topUvBox = m_world->m_worldSpriteSheet->GetSpriteUVs(m_world->m_worldSpriteSheet->GetSpriteIndex(BlockDefinition::s_blockDefList[block->m_type]->m_topUVtexCoords));
	AABB2 sideUvBox = m_world->m_worldSpriteSheet->GetSpriteUVs(m_world->m_worldSpriteSheet->GetSpriteIndex(BlockDefinition::s_blockDefList[block->m_type]->m_sideUVtexCoords));

	Vec3 worldCoordPos = blockIter.GetWorldCenter() - Vec3(0.5f, 0.5f, 0.5f);

	//EAST
	if (blockIter.GetEastNeighbor().GetBlock() && !blockIter.GetEastNeighbor().GetBlock()->IsBlockVisible() && !blockIter.GetEastNeighbor().GetBlock()->IsBlockOpaque())
	{
		AddVertsForQuad3D(m_cpuMeshVerts, m_cpuMeshIndexes,
			Vec3(worldCoordPos.x + 1, worldCoordPos.y, worldCoordPos.z),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y + 1, worldCoordPos.z),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y, worldCoordPos.z + 1),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y + 1, worldCoordPos.z + 1),
			blockIter.GetFaceTintForLightInfuenceValues(EAST), sideUvBox);
	}

	//WEST
	if (blockIter.GetWestNeighbor().GetBlock() && !blockIter.GetWestNeighbor().GetBlock()->IsBlockVisible() && !blockIter.GetWestNeighbor().GetBlock()->IsBlockOpaque())
	{
		AddVertsForQuad3D(m_cpuMeshVerts, m_cpuMeshIndexes,
			Vec3(worldCoordPos.x, worldCoordPos.y + 1, worldCoordPos.z),
			Vec3(worldCoordPos.x, worldCoordPos.y, worldCoordPos.z),
			Vec3(worldCoordPos.x, worldCoordPos.y + 1, worldCoordPos.z + 1),
			Vec3(worldCoordPos.x, worldCoordPos.y, worldCoordPos.z + 1),
			blockIter.GetFaceTintForLightInfuenceValues(WEST), sideUvBox);
	}

	//NORTH
	if (blockIter.GetNorthNeighbor().GetBlock() && !blockIter.GetNorthNeighbor().GetBlock()->IsBlockVisible() && !blockIter.GetNorthNeighbor().GetBlock()->IsBlockOpaque())
	{
		AddVertsForQuad3D(m_cpuMeshVerts, m_cpuMeshIndexes,
			Vec3(worldCoordPos.x + 1, worldCoordPos.y + 1, worldCoordPos.z),
			Vec3(worldCoordPos.x, worldCoordPos.y + 1, worldCoordPos.z),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y + 1, worldCoordPos.z + 1),
			Vec3(worldCoordPos.x, worldCoordPos.y + 1, worldCoordPos.z + 1),
			blockIter.GetFaceTintForLightInfuenceValues(NORTH), sideUvBox);
	}
	//SOUTH
	if (blockIter.GetSouthNeighbor().GetBlock() && !blockIter.GetSouthNeighbor().GetBlock()->IsBlockVisible() && !blockIter.GetSouthNeighbor().GetBlock()->IsBlockOpaque())
	{
		AddVertsForQuad3D(m_cpuMeshVerts, m_cpuMeshIndexes,
			Vec3(worldCoordPos.x, worldCoordPos.y, worldCoordPos.z),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y, worldCoordPos.z),
			Vec3(worldCoordPos.x, worldCoordPos.y, worldCoordPos.z + 1),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y, worldCoordPos.z + 1),
			blockIter.GetFaceTintForLightInfuenceValues(SOUTH), sideUvBox);
	}
	//TOP
	if (GetBlockCoord(blockIter.m_blockIndex).z == CHUNK_SIZE_Z - 1 || (blockIter.GetUpwardNeighbor().GetBlock() && !blockIter.GetUpwardNeighbor().GetBlock()->IsBlockVisible() && !blockIter.GetUpwardNeighbor().GetBlock()->IsBlockOpaque()))
	{
		AddVertsForQuad3D(m_cpuMeshVerts, m_cpuMeshIndexes,
			Vec3(worldCoordPos.x, worldCoordPos.y, worldCoordPos.z + 1),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y, worldCoordPos.z + 1),
			Vec3(worldCoordPos.x, worldCoordPos.y + 1, worldCoordPos.z + 1),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y + 1, worldCoordPos.z + 1),
			blockIter.GetFaceTintForLightInfuenceValues(UPWARD), topUvBox);
	}

	//BOTTOM
	if (GetBlockCoord(blockIter.m_blockIndex).z == 0 || (blockIter.GetDownwardNeighbor().GetBlock() && !blockIter.GetDownwardNeighbor().GetBlock()->IsBlockVisible() && !blockIter.GetDownwardNeighbor().GetBlock()->IsBlockOpaque()))
	{
		AddVertsForQuad3D(m_cpuMeshVerts, m_cpuMeshIndexes,
			Vec3(worldCoordPos.x, worldCoordPos.y + 1, worldCoordPos.z),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y + 1, worldCoordPos.z),
			Vec3(worldCoordPos.x, worldCoordPos.y, worldCoordPos.z),
			Vec3(worldCoordPos.x + 1, worldCoordPos.y, worldCoordPos.z),
			blockIter.GetFaceTintForLightInfuenceValues(DOWNWARD), bottomUvBox);
	}
}

World::World()
{
	m_worldTexture = g_theRenderer->CreateOrGetTextureFromFile("Data/Images/BasicSprites_64x64.png");
	m_worldShader = g_theRenderer->CreateShader("Data/Shaders/World");
	m_worldSpriteSheet = new SpriteSheet(*m_worldTexture, IntVec2(64, 64));
	m_chunkActivationRange = g_gameConfigBlackboard.GetValue("chunkActivationDistance", 250);
	m_chunkDeactivationRange = m_chunkActivationRange + CHUNK_SIZE_X + CHUNK_SIZE_Y;
	m_maxChunksRadiusX = 1 + int(m_chunkActivationRange / CHUNK_SIZE_X);
	m_maxChunksRadiusY = 1 + int(m_chunkActivationRange / CHUNK_SIZE_Y);
	m_maxChunks = (2 * m_maxChunksRadiusX) * (2 * m_maxChunksRadiusY);
	m_gameCBO = g_theRenderer->CreateConstantBuffer(sizeof(GameConstants));

	//SEED
	m_worldSeed = (unsigned int)g_gameConfigBlackboard.GetValue("worldSeed", 0);
	if (m_worldSeed == 0)
	{
		m_worldSeed = g_theRNG->RollRandomUnsignedIntInRange(0, 0xFFFFFFFE);
	}
}

World::~World()
{
	FlushEntireWorld();

	if (m_gameCBO)
	{
		delete m_gameCBO;
	}
	m_gameCBO = nullptr;
}

void World::StartUp()
{
	m_player = new Player(this);
	m_player->m_position = Vec3(-165.f, -165.f, 75.f);
	m_player->m_orientationDegrees = EulerAngles(0.f, 20.f, 0.f);

	m_dirtyMeshChunks.reserve(300);
}

void World::Update(float deltaSeconds)
{
	SkyUpdate(deltaSeconds);

	ManagingChunks();

	ProcessDirtyLighting();

	for (const std::pair<IntVec2, Chunk*>& chunk : m_activeChunks)
	{
		chunk.second->Update(deltaSeconds);
	}

	BuildChunkDirtyMeshes();
}

void World::Render() const
{
	m_player->Render();

	Vec4 worldDayColor = Vec4(Vec3(NormalizeByte((unsigned char)m_skyColor.x), NormalizeByte((unsigned char)m_skyColor.y), NormalizeByte((unsigned char)m_skyColor.z)));
	float indoorNoise = Compute1dPerlinNoise(m_worldDay, 0.4f, 9);
	float indoorStrength = RangeMapClamped(indoorNoise, -1.f, 1.f, 0.8f, 1.f);

	GameConstants gameConstant;
	gameConstant.b_camWorldPos = Vec4(m_player->m_position);
	gameConstant.b_skyColor = worldDayColor;
	gameConstant.b_indoorLightColor = Vec4(1.f, 0.9f, 0.8f, 1.f) * indoorStrength;
	gameConstant.b_outdoorLightColor = worldDayColor;
	gameConstant.b_fogStartDist = (m_chunkDeactivationRange - 16.f) * 0.5f;
	gameConstant.b_fogEndDist = (m_chunkDeactivationRange - 16.f);
	gameConstant.b_fogMaxAlpha = 1.0f;
	gameConstant.b_time = m_worldDay;

	g_theRenderer->SetRasterizerMode(RasterizerMode::SOLID_CULL_BACK);
	g_theRenderer->SetDepthStencilMode(DepthMode::ENABLED);
	g_theRenderer->SetSamplerMode(SampleMode::POINT_CLAMP);
	g_theRenderer->SetModelConstants();
	g_theRenderer->BindTexture(&m_worldSpriteSheet->GetTexture());
	g_theRenderer->BindShader(m_worldShader);

	g_theRenderer->CopyCPUToGPU(&gameConstant, sizeof(GameConstants), m_gameCBO);
	g_theRenderer->BindConstantBuffer(8, m_gameCBO);

	for (const std::pair<IntVec2, Chunk*>& chunk : m_activeChunks)
	{
		chunk.second->Render();
	}

	if (g_debugMode)
	{
		std::vector<Vertex_PCU> debugVerts;
		for (const std::pair<IntVec2, Chunk*>& chunk : m_activeChunks)
		{
			AddVertsForWireframeAABB3D(debugVerts, chunk.second->m_bound, Rgba8::COLOR_WHITE, 0.02f);
		}
		g_theRenderer->SetModelConstants();
		g_theRenderer->BindTexture(nullptr);
		g_theRenderer->BindShader(nullptr);
		g_theRenderer->DrawVertexArray((int)debugVerts.size(), debugVerts.data());
	}
}


void World::BuildChunkDirtyMeshes()
{
	IntVec2 playerChunkCoord = m_player->GetCurrentChunkCoord();

	Chunk* closestChunk = nullptr;
	Chunk* secondClosestChunk = nullptr;
	float closestDistance = FLT_MAX;
	float secondClosestDistance = FLT_MAX;

	for (size_t i = 0; i < m_dirtyMeshChunks.size(); i++)
	{
		if (!m_dirtyMeshChunks[i] || !m_dirtyMeshChunks[i]->DoesMeetAllRequirementsForBuildingMesh()) continue;

		IntVec2 coord = m_dirtyMeshChunks[i]->m_coord;

		AABB2 chunkBound = AABB2((float)(coord.x * CHUNK_SIZE_X), (float)(coord.y * CHUNK_SIZE_Y),
			(float)((coord.x + 1) * CHUNK_SIZE_X), (float)((coord.y + 1) * CHUNK_SIZE_Y));

		float distanceToChunkSquared = (chunkBound.GetCenter() - Vec2(m_player->m_position.x, m_player->m_position.y)).GetLengthSquared();


		if (distanceToChunkSquared < secondClosestDistance)
		{
			if (distanceToChunkSquared < closestDistance)
			{
				secondClosestChunk = closestChunk;
				secondClosestDistance = closestDistance;

				closestChunk = m_dirtyMeshChunks[i];
				closestDistance = distanceToChunkSquared;
			}
			else
			{
				secondClosestChunk = m_dirtyMeshChunks[i];
				secondClosestDistance = distanceToChunkSquared;
			}
		}
	}

	if (closestChunk)
	{
		closestChunk->BuildCPUMesh();
	}
	if (secondClosestChunk)
	{
		secondClosestChunk->BuildCPUMesh();
	}

	for (size_t i = 0; i < m_dirtyMeshChunks.size(); i++)
	{
		if (m_dirtyMeshChunks[i] == closestChunk)
		{
			m_dirtyMeshChunks.erase(m_dirtyMeshChunks.begin() + i);
			if (i > 0) i--;
		}
		if (m_dirtyMeshChunks[i] == secondClosestChunk)
		{
			m_dirtyMeshChunks.erase(m_dirtyMeshChunks.begin() + i);
			if (i > 0) i--;
		}
	}
}

void World::RequestToActivateChunk(IntVec2& chunkCoords)
{
	Chunk* newChunk = new Chunk(this, chunkCoords);

	if (HasFile(Stringf("Saves/World_%u/Chunk(%i,%i).chunk", m_worldSeed, chunkCoords.x, chunkCoords.y)))
	{
		ChunkLoadJob* job = new ChunkLoadJob(newChunk);
		g_theJobSystem->QueueJob(job);
		newChunk->m_status = ChunkStatus::ACTIVATING_QUEUE_LOAD;
		m_chunksBeingGeneratedOrLoaded.insert(chunkCoords);
		return;
	}

	ChunkGenerateJob* job = new ChunkGenerateJob(newChunk);
	g_theJobSystem->QueueJob(job);
	newChunk->m_status = ChunkStatus::ACTIVATING_QUEUE_GENERATE;
	m_chunksBeingGeneratedOrLoaded.insert(chunkCoords);
}

void World::ActivateChunk(Chunk* newChunk)
{
	IntVec2 chunkCoords = newChunk->m_coord;

	newChunk->m_northNeighbor = GetChunkAtCoord(chunkCoords + IntVec2(0, 1));
	newChunk->m_southNeighbor = GetChunkAtCoord(chunkCoords + IntVec2(0, -1));
	newChunk->m_eastNeighbor = GetChunkAtCoord(chunkCoords + IntVec2(1, 0));
	newChunk->m_westNeighbor = GetChunkAtCoord(chunkCoords + IntVec2(-1, 0));

	if (newChunk->m_northNeighbor)	newChunk->m_northNeighbor->m_southNeighbor = newChunk;
	if (newChunk->m_southNeighbor)	newChunk->m_southNeighbor->m_northNeighbor = newChunk;
	if (newChunk->m_eastNeighbor)	newChunk->m_eastNeighbor->m_westNeighbor = newChunk;
	if (newChunk->m_westNeighbor)	newChunk->m_westNeighbor->m_eastNeighbor = newChunk;

	newChunk->LightInfluenceInitialization();
	newChunk->m_isActive = true;
	newChunk->m_status = ChunkStatus::ACTIVE;

	m_activeChunks[chunkCoords] = newChunk;

	newChunk->SetMeshDirty();
}

void World::RequestToDeactivateChunk(IntVec2& chunkCoords)
{
	Chunk* chunk = GetChunkAtCoord(chunkCoords);

	if (chunk)
	{
		if (chunk->m_needSaving)
		{
			ChunkSaveJob* job = new ChunkSaveJob(chunk);
			g_theJobSystem->QueueJob(job);
			chunk->m_status = ChunkStatus::DEACTIVATING_QUEUE_SAVE;
			m_chunksBeingDeactivated.insert(chunkCoords);
			return;
		}

		DeactivateChunk(chunk);
	}
}

void World::DeactivateChunk(Chunk* chunk)
{
	chunk->m_status = ChunkStatus::DECONSTRUCTING;
	IntVec2 chunkCoords = chunk->m_coord;
	UndirtyAllBlocksInChunk(chunkCoords);

	delete m_activeChunks[chunkCoords];
	m_activeChunks[chunkCoords] = nullptr;
	m_activeChunks.erase(chunkCoords);
}

bool World::RequestCreationOfNearestMissingChunkInRange()
{
	bool foundMissingChunk = false;

	IntVec2 playerChunkCoord = m_player->GetCurrentChunkCoord();
	IntVec2 closestMissingChunkCoord = IntVec2();
	float closestDistance = FLT_MAX;

	for (int chunkY = playerChunkCoord.y - m_maxChunksRadiusY; chunkY < playerChunkCoord.y + m_maxChunksRadiusY; chunkY++)
	{
		for (int chunkX = playerChunkCoord.x - m_maxChunksRadiusX; chunkX < playerChunkCoord.x + m_maxChunksRadiusX; chunkX++)
		{
			IntVec2 chunkCoords = IntVec2(chunkX, chunkY);

			auto found = m_chunksBeingGeneratedOrLoaded.find(chunkCoords);
			if (found != m_chunksBeingGeneratedOrLoaded.end()) continue;

			AABB2 chunkBound = AABB2((float)(chunkX * CHUNK_SIZE_X), (float)(chunkY * CHUNK_SIZE_Y),
				(float)((chunkX + 1) * CHUNK_SIZE_X), (float)((chunkY + 1) * CHUNK_SIZE_Y));

			Vec2 playerPosXY = Vec2(m_player->m_position.x, m_player->m_position.y);
			float distanceToChunkSquared = (chunkBound.GetCenter() - playerPosXY).GetLengthSquared();

			if (distanceToChunkSquared < m_chunkActivationRange * m_chunkActivationRange && distanceToChunkSquared < closestDistance)
			{
				Chunk* chunk = GetChunkAtCoord(chunkCoords);
				if (chunk) continue;

				closestMissingChunkCoord = IntVec2(chunkX, chunkY);
				closestDistance = distanceToChunkSquared;
				foundMissingChunk = true;
			}
		}
	}

	if (foundMissingChunk)
	{
		RequestToActivateChunk(closestMissingChunkCoord);
	}

	return foundMissingChunk;
}

bool World::RequestDeactivationFarthestChunkOutOfRange()
{
	bool foundOutOfRangeChunk = false;
	IntVec2 farthestChunkCoord = IntVec2();
	float farthestDistance = 0.f;

	for (const std::pair<IntVec2, Chunk*>& chunk : m_activeChunks)
	{
		auto found = m_chunksBeingDeactivated.find(chunk.second->m_coord);
		if (found != m_chunksBeingDeactivated.end()) continue;

		Vec2 playerPosXY = Vec2(m_player->m_position.x, m_player->m_position.y);
		float distanceToChunkSquared = (chunk.second->m_bound.GetCenterXY() - playerPosXY).GetLengthSquared();
		if (distanceToChunkSquared > m_chunkDeactivationRange * m_chunkDeactivationRange && distanceToChunkSquared > farthestDistance)
		{
			farthestChunkCoord = chunk.second->m_coord;
			farthestDistance = distanceToChunkSquared;
			foundOutOfRangeChunk = true;
		}
	}

	if (foundOutOfRangeChunk)
	{
		RequestToDeactivateChunk(farthestChunkCoord);
	}

	return foundOutOfRangeChunk;
}

void World::ManagingChunks()
{
	if (m_activeChunks.size() >= m_maxChunks)
	{
		RequestDeactivationFarthestChunkOutOfRange();
	}
	else
	{
		bool isActivatiing = false;
		do
		{
			isActivatiing = RequestCreationOfNearestMissingChunkInRange();
		} while (g_theJobSystem->GetNumQueuedJobs() < 16 && isActivatiing);

		if (!isActivatiing)
		{
			RequestDeactivationFarthestChunkOutOfRange();
		}
	}

	bool hasLoadOrSaveThisFrame = false;
	for (size_t i = 0; i < g_theJobSystem->GetNumCompletedJobs(); i++)
	{
		Job* completedJob = g_theJobSystem->RetrieveJob();

		ChunkSaveJob* saveJob = dynamic_cast<ChunkSaveJob*>(completedJob);
		if (saveJob && !hasLoadOrSaveThisFrame)
		{
			saveJob->m_chunk->m_status = ChunkStatus::DEACTIVATING_SAVE_COMPLETE;
			m_chunksBeingDeactivated.erase(saveJob->m_chunk->m_coord);
			DeactivateChunk(saveJob->m_chunk);
			hasLoadOrSaveThisFrame = true;
			continue;
		}

		ChunkLoadJob* loadJob = dynamic_cast<ChunkLoadJob*>(completedJob);
		if (loadJob && !hasLoadOrSaveThisFrame)
		{
			loadJob->m_chunk->m_status = ChunkStatus::ACTIVATING_LOAD_COMPLETE;
			m_chunksBeingGeneratedOrLoaded.erase(loadJob->m_chunk->m_coord);
			ActivateChunk(loadJob->m_chunk);
			hasLoadOrSaveThisFrame = true;
			continue;
		}

		ChunkGenerateJob* generateJob = dynamic_cast<ChunkGenerateJob*>(completedJob);
		if (generateJob)
		{
			generateJob->m_chunk->m_status = ChunkStatus::ACTIVATING_GENERATE_COMPLETE;
			m_chunksBeingGeneratedOrLoaded.erase(generateJob->m_chunk->m_coord);
			ActivateChunk(generateJob->m_chunk);
		}
	}
}

void World::FlushEntireWorld()
{
	std::vector<IntVec2> chunkNeedToBeDeletedCoord;

	for (const std::pair<IntVec2, Chunk*>& chunk : m_activeChunks)
	{
		chunkNeedToBeDeletedCoord.emplace_back(chunk.second->m_coord);
	}

	for (size_t i = 0; i < chunkNeedToBeDeletedCoord.size(); i++)
	{
		RequestToDeactivateChunk(chunkNeedToBeDeletedCoord[i]);
	}

	m_activeChunks.clear();
	m_dirtyMeshChunks.clear();
}

void World::ProcessDirtyLighting()
{
	while (!m_dirtyLightBlocks.empty())
	{
		BlockIterator iter = m_dirtyLightBlocks.front();
		m_dirtyLightBlocks.pop_front();
		ProcessNextDirtyLightBlock(iter);
	}
}

void World::ProcessNextDirtyLightBlock(BlockIterator iter)
{
	Block* currentBlock = iter.GetBlock();
	currentBlock->SetLightNotDirty();

	bool isLightInfluenceChanged = false;

	unsigned char highestIndoorLightInfluence = 0;
	unsigned char highestOutdoorLightInfluence = 0;

	// GET THE HIGHEST VALUE FROM NEIGHBOR VALUES
	if (iter.GetEastNeighbor().GetBlock())
	{
		if (iter.GetEastNeighbor().GetBlock()->GetIndoorLightInfluence() > highestIndoorLightInfluence)
		{
			highestIndoorLightInfluence = iter.GetEastNeighbor().GetBlock()->GetIndoorLightInfluence();
		}
		if (iter.GetEastNeighbor().GetBlock()->GetOutdoorLightInfluence() > highestOutdoorLightInfluence)
		{
			highestOutdoorLightInfluence = iter.GetEastNeighbor().GetBlock()->GetOutdoorLightInfluence();
		}
	}
	if (iter.GetWestNeighbor().GetBlock())
	{
		if (iter.GetWestNeighbor().GetBlock()->GetIndoorLightInfluence() > highestIndoorLightInfluence)
		{
			highestIndoorLightInfluence = iter.GetWestNeighbor().GetBlock()->GetIndoorLightInfluence();
		}
		if (iter.GetWestNeighbor().GetBlock()->GetOutdoorLightInfluence() > highestOutdoorLightInfluence)
		{
			highestOutdoorLightInfluence = iter.GetWestNeighbor().GetBlock()->GetOutdoorLightInfluence();
		}
	}
	if (iter.GetNorthNeighbor().GetBlock())
	{
		if (iter.GetNorthNeighbor().GetBlock()->GetIndoorLightInfluence() > highestIndoorLightInfluence)
		{
			highestIndoorLightInfluence = iter.GetNorthNeighbor().GetBlock()->GetIndoorLightInfluence();
		}
		if (iter.GetNorthNeighbor().GetBlock()->GetOutdoorLightInfluence() > highestOutdoorLightInfluence)
		{
			highestOutdoorLightInfluence = iter.GetNorthNeighbor().GetBlock()->GetOutdoorLightInfluence();
		}
	}
	if (iter.GetSouthNeighbor().GetBlock())
	{
		if (iter.GetSouthNeighbor().GetBlock()->GetIndoorLightInfluence() > highestIndoorLightInfluence)
		{
			highestIndoorLightInfluence = iter.GetSouthNeighbor().GetBlock()->GetIndoorLightInfluence();
		}
		if (iter.GetSouthNeighbor().GetBlock()->GetOutdoorLightInfluence() > highestOutdoorLightInfluence)
		{
			highestOutdoorLightInfluence = iter.GetSouthNeighbor().GetBlock()->GetOutdoorLightInfluence();
		}
	}
	if (iter.GetUpwardNeighbor().GetBlock())
	{
		if (iter.GetUpwardNeighbor().GetBlock()->GetIndoorLightInfluence() > highestIndoorLightInfluence)
		{
			highestIndoorLightInfluence = iter.GetUpwardNeighbor().GetBlock()->GetIndoorLightInfluence();
		}
		if (iter.GetUpwardNeighbor().GetBlock()->GetOutdoorLightInfluence() > highestOutdoorLightInfluence)
		{
			highestOutdoorLightInfluence = iter.GetUpwardNeighbor().GetBlock()->GetOutdoorLightInfluence();
		}
	}
	if (iter.GetDownwardNeighbor().GetBlock())
	{
		if (iter.GetDownwardNeighbor().GetBlock()->GetIndoorLightInfluence() > highestIndoorLightInfluence)
		{
			highestIndoorLightInfluence = iter.GetDownwardNeighbor().GetBlock()->GetIndoorLightInfluence();
		}
		if (iter.GetDownwardNeighbor().GetBlock()->GetOutdoorLightInfluence() > highestOutdoorLightInfluence)
		{
			highestOutdoorLightInfluence = iter.GetDownwardNeighbor().GetBlock()->GetOutdoorLightInfluence();
		}
	}

	// CALCULATE THE THEORETICAL VALUE
	unsigned char theoreticalIndoorLightInfluence = 0;
	unsigned char theoreticalOutdoorLightInfluence = 0;

	if (!currentBlock->IsBlockOpaque())
	{
		if (highestIndoorLightInfluence > 0)
		{
			theoreticalIndoorLightInfluence = highestIndoorLightInfluence - 1;
		}
		if (highestOutdoorLightInfluence > 0)
		{
			theoreticalOutdoorLightInfluence = highestOutdoorLightInfluence - 1;
		}
	}
	else
	{
		if (currentBlock->GetIndoorLightInfluenceFromBlockDef() == 0)
		{
			isLightInfluenceChanged = true;
		}
	}
	if (currentBlock->CanSeeSky())
	{
		theoreticalOutdoorLightInfluence = 15;
	}

	// COMPARE TO CURRENT VALUES AND SET IF IT'S DIFFERENT

	if (currentBlock->GetIndoorLightInfluence() != theoreticalIndoorLightInfluence)
	{
		if (currentBlock->GetIndoorLightInfluenceFromBlockDef() > theoreticalIndoorLightInfluence)
		{
			theoreticalIndoorLightInfluence = currentBlock->GetIndoorLightInfluenceFromBlockDef();
		}
		currentBlock->SetIndoorLightInfluence(theoreticalIndoorLightInfluence);
		isLightInfluenceChanged = true;
	}

	if (currentBlock->GetOutdoorLightInfluence() != theoreticalOutdoorLightInfluence)
	{
		currentBlock->SetOutdoorLightInfluence(theoreticalOutdoorLightInfluence);
		isLightInfluenceChanged = true;
	}

	// SPREAD THE LIGHTING IF IT'S DIFFERENT
	if (isLightInfluenceChanged)
	{
		// MARK CHUNK AND NEIGHBOR CHUNKS AS DIRTY
		iter.m_chunk->SetMeshDirty();
		if (iter.GetEastNeighbor().m_chunk) iter.GetEastNeighbor().m_chunk->SetMeshDirty();
		if (iter.GetWestNeighbor().m_chunk) iter.GetWestNeighbor().m_chunk->SetMeshDirty();
		if (iter.GetSouthNeighbor().m_chunk) iter.GetSouthNeighbor().m_chunk->SetMeshDirty();
		if (iter.GetNorthNeighbor().m_chunk) iter.GetNorthNeighbor().m_chunk->SetMeshDirty();

		// MARK NON OPAQUE BLOCK LIGHT DIRTY
		Block* east = iter.GetEastNeighbor().GetBlock();
		if (east && !east->IsBlockOpaque())
		{
			MarkLightingDirty(iter.GetEastNeighbor());
		}

		Block* west = iter.GetWestNeighbor().GetBlock();
		if (west && !west->IsBlockOpaque())
		{
			MarkLightingDirty(iter.GetWestNeighbor());
		}

		Block* north = iter.GetNorthNeighbor().GetBlock();
		if (north && !north->IsBlockOpaque())
		{
			MarkLightingDirty(iter.GetNorthNeighbor());
		}

		Block* south = iter.GetSouthNeighbor().GetBlock();
		if (south && !south->IsBlockOpaque())
		{
			MarkLightingDirty(iter.GetSouthNeighbor());
		}

		Block* upward = iter.GetUpwardNeighbor().GetBlock();
		if (upward && !upward->IsBlockOpaque())
		{
			MarkLightingDirty(iter.GetUpwardNeighbor());
		}

		Block* downward = iter.GetDownwardNeighbor().GetBlock();
		if (downward && !downward->IsBlockOpaque())
		{
			MarkLightingDirty(iter.GetDownwardNeighbor());
		}
	}
}

void World::MarkLightingDirty(BlockIterator iter)
{
	Block* block = iter.GetBlock();
	if (!block)
	{
		return;
	}
	if (block->IsLightDirty())
	{
		return;
	}
	iter.GetBlock()->SetLightDirty();
	m_dirtyLightBlocks.push_back(iter);
}

void World::UndirtyAllBlocksInChunk(IntVec2& chunkCoords)
{
	for (size_t i = 0; i < m_dirtyLightBlocks.size(); i++)
	{
		if (m_dirtyLightBlocks[i].m_chunk == m_activeChunks[chunkCoords])
		{
			m_dirtyLightBlocks.erase(m_dirtyLightBlocks.begin() + i);
			i--;
		}
	}
}

void World::SkyUpdate(float deltaSeconds)
{
	float deltaDay = (deltaSeconds * m_worldTimeScale) / (60.f * 60.f * 24.f);
	m_worldDay += deltaDay;

	if (g_gameConfigBlackboard.GetValue("debugAlwaysDay", false))
	{
		m_skyColor = Vec3(200, 230, 255);
	}
	else
	{
		float timeFraction = 0.f;
		if (IsNightTime())
		{
			m_skyColor = Vec3(20, 20, 40);
		}
		else
		{
			if (GetCurrentTimeOfDay() < 0.5f)
			{
				timeFraction = RangeMap(GetCurrentTimeOfDay(), 0.25f, 0.5f, 0.f, 1.f);
			}
			else
			{
				timeFraction = RangeMap(GetCurrentTimeOfDay(), 0.75f, 0.5f, 0.f, 1.f);
			}
		}
		m_skyColor = Interpolate(Vec3(20, 20, 40), Vec3(200, 230, 255), timeFraction);
	}


	float lightingNoise = Compute1dPerlinNoise(m_worldDay, 1.f, 9);
	float lightingStrength = RangeMapClamped(lightingNoise, 0.6f, 0.9f, 0.f, 1.f);
	m_skyColor = Interpolate(m_skyColor, Vec3(255.f, 255.f, 255.f), lightingStrength);

	if (g_theInput->IsKeyDown('Y'))
	{
		m_worldTimeScale = 10000.f;
	}
	else
	{
		m_worldTimeScale = 200.f;
	}
}

Chunk* World::GetChunkAtCoord(IntVec2 chunkCoord) const
{
	auto found = m_activeChunks.find(chunkCoord);
	if (found != m_activeChunks.end())
	{
		return found->second;
	}

	return nullptr;
}

Chunk* World::GetChunkAtPosition(Vec3 position) const
{
	IntVec2 chunkCoord = IntVec2(RoundDownToInt(position.x / (float)CHUNK_SIZE_X), RoundDownToInt(position.y / (float)CHUNK_SIZE_Y));
	return GetChunkAtCoord(chunkCoord);
}

IntVec3 World::GetBlockLocalCoord(IntVec3 global) const
{
	IntVec2 chunkCoord = IntVec2(RoundDownToInt((float)global.x / (float)CHUNK_SIZE_X), RoundDownToInt((float)global.y / (float)CHUNK_SIZE_Y));
	return global - IntVec3(chunkCoord.x * CHUNK_SIZE_X, chunkCoord.y * CHUNK_SIZE_Y, 0);
}

bool World::IsNightTime()
{
	return GetCurrentTimeOfDay() < 0.25f || GetCurrentTimeOfDay() > 0.75f;
}

float World::GetCurrentTimeOfDay()
{
	return m_worldDay - (float)RoundDownToInt(m_worldDay);
}

GameRaycastResult3D World::RaycastWorld(Vec3 startPos, Vec3 fwdNormal, float maxDist) const
{
	GameRaycastResult3D result;
	result.m_rayStartPos = startPos;
	result.m_rayFwdNormal = fwdNormal;
	result.m_rayMaxLength = maxDist;

	IntVec3 currentBlockGlobalCoord = IntVec3(RoundDownToInt(startPos.x), RoundDownToInt(startPos.y), RoundDownToInt(Clamp(startPos.z, 0, CHUNK_SIZE_Z - 1)));
	BlockIterator currentBlockIterator;
	currentBlockIterator.m_chunk = GetChunkAtPosition(startPos);
	currentBlockIterator.m_blockIndex = GetBlockIndex(GetBlockLocalCoord(currentBlockGlobalCoord));

	// X
	float fwdDistPerXCrossing = 1.f / fabsf(fwdNormal.x);
	int tileStepDirectionX = (fwdNormal.x > 0) ? 1 : -1;
	float xAtFirstXCrossing = currentBlockGlobalCoord.x + (tileStepDirectionX + 1) / 2.f;
	float xDistToFirstXCrossing = xAtFirstXCrossing - startPos.x;
	float fwdDistAtNextXCrossing = fabsf(xDistToFirstXCrossing) * fwdDistPerXCrossing;

	// Y
	float fwdDistPerYCrossing = 1.f / fabsf(fwdNormal.y);
	int tileStepDirectionY = (fwdNormal.y > 0) ? 1 : -1;
	float yAtFirstYCrossing = currentBlockGlobalCoord.y + (tileStepDirectionY + 1) / 2.f;
	float yDistToFirstYCrossing = yAtFirstYCrossing - startPos.y;
	float fwdDistAtNextYCrossing = fabsf(yDistToFirstYCrossing) * fwdDistPerYCrossing;

	// Z
	float fwdDistPerZCrossing = 1.f / fabsf(fwdNormal.z);
	int tileStepDirectionZ = (fwdNormal.z > 0) ? 1 : -1;
	float zAtFirstYCrossing = currentBlockGlobalCoord.z + (tileStepDirectionZ + 1) / 2.f;
	float zDistToFirstYCrossing = zAtFirstYCrossing - startPos.z;
	float fwdDistAtNextZCrossing = fabsf(zDistToFirstYCrossing) * fwdDistPerZCrossing;

	for (;;)
	{
		if (fwdDistAtNextZCrossing < fwdDistAtNextYCrossing && fwdDistAtNextZCrossing < fwdDistAtNextXCrossing)
		{
			if (fwdDistAtNextZCrossing > maxDist)
			{
				result.m_didImpact = false;
				return result;
			}
			if (tileStepDirectionZ > 0)
			{
				currentBlockIterator = currentBlockIterator.GetUpwardNeighbor();
			}
			else
			{
				currentBlockIterator = currentBlockIterator.GetDownwardNeighbor();
			}
			if (!currentBlockIterator.m_chunk)
			{
				result.m_didImpact = false;
				return result;
			}
			if (currentBlockIterator.m_chunk)
			{
				if (currentBlockIterator.GetBlock()->IsBlockSolid())
				{
					result.m_didImpact = true;
					result.m_blockIterator = currentBlockIterator;
					result.m_impactDist = fwdDistAtNextZCrossing;
					result.m_impactPos = startPos + fwdNormal * result.m_impactDist;
					result.m_impactNormal = Vec3(0.f, 0.f, (float)-tileStepDirectionZ);
					return result;
				}
				else
				{
					fwdDistAtNextZCrossing += fwdDistPerZCrossing;
				}
			}
			else
			{
				result.m_didImpact = false;
				return result;
			}

		}
		else
		{
			if (fwdDistAtNextXCrossing < fwdDistAtNextYCrossing)
			{
				if (fwdDistAtNextXCrossing > maxDist)
				{
					result.m_didImpact = false;
					return result;
				}
				if (tileStepDirectionX > 0)
				{
					currentBlockIterator = currentBlockIterator.GetEastNeighbor();
				}
				else
				{
					currentBlockIterator = currentBlockIterator.GetWestNeighbor();
				}
				if (!currentBlockIterator.m_chunk)
				{
					result.m_didImpact = false;
					return result;
				}
				if (currentBlockIterator.GetBlock()->IsBlockSolid())
				{
					result.m_didImpact = true;
					result.m_blockIterator = currentBlockIterator;
					result.m_impactDist = fwdDistAtNextXCrossing;
					result.m_impactPos = startPos + fwdNormal * result.m_impactDist;
					result.m_impactNormal = Vec3((float)-tileStepDirectionX, 0.f, 0.f);
					return result;
				}
				else
				{
					fwdDistAtNextXCrossing += fwdDistPerXCrossing;
				}
			}
			else
			{
				if (fwdDistAtNextYCrossing > maxDist)
				{
					result.m_didImpact = false;
					return result;
				}
				if (tileStepDirectionY > 0)
				{
					currentBlockIterator = currentBlockIterator.GetNorthNeighbor();
				}
				else
				{
					currentBlockIterator = currentBlockIterator.GetSouthNeighbor();
				}
				if (!currentBlockIterator.m_chunk)
				{
					result.m_didImpact = false;
					return result;
				}
				if (currentBlockIterator.GetBlock()->IsBlockSolid())
				{
					result.m_didImpact = true;
					result.m_blockIterator = currentBlockIterator;
					result.m_impactDist = fwdDistAtNextYCrossing;
					result.m_impactPos = startPos + fwdNormal * result.m_impactDist;
					result.m_impactNormal = Vec3(0.f, (float)-tileStepDirectionY, 0.f);
					return result;
				}
				else
				{
					fwdDistAtNextYCrossing += fwdDistPerYCrossing;
				}
			}
		}
	}
}

bool World::RetrievedCompletedGenerateJob()
{
	return false;
}

BlockTemplateEntry::BlockTemplateEntry(unsigned char type, IntVec3 relativeCoord)
	:m_type(type), m_relativeCoord(relativeCoord)
{

}

void BlockTemplate::AddEntry(BlockTemplateEntry entry)
{
	m_blockTemplateEntries.emplace_back(entry);
}

void ChunkGenerateJob::Execute()
{
	m_chunk->GenerateAllBlockData();
}

void ChunkLoadJob::Execute()
{
	m_chunk->LoadData();
}

void ChunkSaveJob::Execute()
{
	m_chunk->SaveData();
}

CaveDiggerMachine::CaveDiggerMachine(Chunk* chunk, IntVec3 startGlobalCoord)
	:m_chunk(chunk)
{
	RandomNumberGenerator rng;
	rng.m_seed = (unsigned int)Compute2dPerlinNoise((float)startGlobalCoord.x, (float)startGlobalCoord.y);
	int z = rng.RollRandomIntInRange(5, 30);
	m_startGlobalPosition = Vec3((float)startGlobalCoord.x, (float)startGlobalCoord.y, (float)z);

	m_totalStep = rng.RollRandomIntInRange(35, 50);

	m_forwardMachine = Capsule3(m_startGlobalPosition, m_startGlobalPosition, m_radius);
	m_backwardMachine = Capsule3(m_startGlobalPosition, m_startGlobalPosition, m_radius);
}

void CaveDiggerMachine::GenerateCave()
{
	RandomNumberGenerator rng;
	rng.m_seed = (unsigned int)Compute2dPerlinNoise((float)m_startGlobalPosition.x, (float)m_startGlobalPosition.y);

	int currentStep = m_totalStep;
	while (currentStep > 0)
	{
		DigOneStepForward(m_forwardMachine.m_end);

		//if (CanThisMachineModifyChunk(m_forwardMachine))
		//{
		//
		//}
		MakeCaveOnCurrentChunk(true);

		DigOneStepBackward(m_backwardMachine.m_end);

		//if (CanThisMachineModifyChunk(m_backwardMachine))
		//{
		//	
		//}
		MakeCaveOnCurrentChunk(false);

		currentStep--;
	}
}

void CaveDiggerMachine::DigOneStepForward(Vec3 startPos)
{
	RandomNumberGenerator rng;
	rng.m_seed = (unsigned int)Compute2dPerlinNoise((float)m_startGlobalPosition.x, (float)m_startGlobalPosition.y);

	m_orientationForward.m_yawDegrees += Compute2dPerlinNoise(m_startGlobalPosition.x, m_startGlobalPosition.y, 50.f, 8, 0.5f, 2.f, true, rng.m_seed + 1) * 120.f;
	m_orientationForward.m_pitchDegrees += Compute2dPerlinNoise(m_startGlobalPosition.x, m_startGlobalPosition.y, 50.f, 3, 0.5f, 2.f, true, rng.m_seed + 2) * 45.f;

	Mat44 matrix = Mat44();
	matrix.AppendXRotation(m_orientationForward.m_yawDegrees);
	matrix.AppendYRotation(m_orientationForward.m_pitchDegrees);

	m_distanceEachStep = rng.RollRandomFloatInRange(10.f, 30.f);
	m_radius = rng.RollRandomFloatInRange(2.f, 10.f);

	Vec3 startPosCapsule = startPos;
	Vec3 endPosCapsule = startPosCapsule + matrix.GetIBasis3D() * m_distanceEachStep;

	m_forwardMachine = Capsule3(startPosCapsule, endPosCapsule, m_radius);
}

void CaveDiggerMachine::DigOneStepBackward(Vec3 startPos)
{
	RandomNumberGenerator rng;
	rng.m_seed = (unsigned int)Compute2dPerlinNoise((float)m_startGlobalPosition.x, (float)m_startGlobalPosition.y);

	m_orientationBackward.m_yawDegrees += Compute2dPerlinNoise(m_startGlobalPosition.x, m_startGlobalPosition.y, 50.f, 8, 0.5f, 2.f, true, rng.m_seed + 11) * 120.f;
	m_orientationBackward.m_pitchDegrees += Compute2dPerlinNoise(m_startGlobalPosition.x, m_startGlobalPosition.y, 50.f, 3, 0.5f, 2.f, true, rng.m_seed + 12) * 45.f;

	Mat44 matrix = Mat44();
	matrix.AppendXRotation(m_orientationBackward.m_yawDegrees);
	matrix.AppendYRotation(m_orientationBackward.m_pitchDegrees);

	m_distanceEachStep = rng.RollRandomFloatInRange(10.f, 30.f);
	m_radius = rng.RollRandomFloatInRange(7.f, 15.f);

	Vec3 startPosCapsule = startPos;
	Vec3 endPosCapsule = startPosCapsule - matrix.GetIBasis3D() * m_distanceEachStep;

	m_backwardMachine = Capsule3(startPosCapsule, endPosCapsule, m_radius);
}

bool CaveDiggerMachine::CanThisMachineModifyChunk(Capsule3 capsule)
{
	int rangeToCheckX = RoundDownToInt(m_distanceEachStep / CHUNK_SIZE_X) + 1;
	int rangeToCheckY = RoundDownToInt(m_distanceEachStep / CHUNK_SIZE_Y) + 1;

	FloatRange xRange = FloatRange((float)((m_chunk->m_coord.x - rangeToCheckX) * CHUNK_SIZE_X), (float)((m_chunk->m_coord.x + rangeToCheckX) * CHUNK_SIZE_X));
	FloatRange yRange = FloatRange((float)((m_chunk->m_coord.y - rangeToCheckY) * CHUNK_SIZE_Y), (float)((m_chunk->m_coord.y + rangeToCheckY) * CHUNK_SIZE_Y));

	bool isStartInRange = xRange.IsOnRange(capsule.m_start.x) && yRange.IsOnRange(capsule.m_start.y);
	bool isEndInRange = xRange.IsOnRange(capsule.m_end.x) && yRange.IsOnRange(capsule.m_end.y);

	return isStartInRange || isEndInRange;
	
}

void CaveDiggerMachine::MakeCaveOnCurrentChunk(bool isForward)
{
	for (int i = 0; i < TOTAL_BLOCKS_SIZE; i++)
	{
		IntVec3 blockLocallCoord = GetBlockCoord(i);
		IntVec3 blockGlobalCoord = m_chunk->GetBlockGlobalCoord(blockLocallCoord);
		Vec3 blockGlobalCenter = Vec3((float)blockGlobalCoord.x + 0.5f, (float)blockGlobalCoord.y + 0.5f, (float)blockGlobalCoord.z + 0.5f);

		if (isForward)
		{
			if (m_forwardMachine.IsPointInside(blockGlobalCenter))
			{
				if (m_chunk->m_blocks[i].IsBlockSolid())
				{
					m_chunk->SetBlockType(i, 0);
				}
			}
		}
		else
		{
			if (m_backwardMachine.IsPointInside(blockGlobalCenter))
			{
				if (m_chunk->m_blocks[i].IsBlockSolid())
				{
					m_chunk->SetBlockType(i, 0);
				}
			}
		}
	
	}
}
