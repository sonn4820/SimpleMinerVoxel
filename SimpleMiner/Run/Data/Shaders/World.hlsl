// World shader for C30 SD SimpleMiner (circa SDST Summer 2021)


//------------------------------------------------------------------------------------------------
// A struct containing the inputs our vertex shader is expecting (from vertex array / VBO vertex struct)
//
struct VertexInputData
{
	// These custom semantic names can be anything, but they must match those referenced in the .CPP
	//	code that defines the vertex layout	information in D3D11_INPUT_ELEMENT_DESC.  Tells D3D11 how
	//	to "hook up" each member variable of the CPP VertexPCU structure to this GPU-internal structure.
	//
	// Just out of personal convention/style I like to use "a_" for the actual Vertex "a"ttributes.
	//
	// [qualifier] type  shaderName : semanticName;
	float3	a_position	: POSITION;		// e.g. in .CPP:  vertexAttribsArray[0].SemanticName = "POSITION";
	float4	a_color		: COLOR;			// e.g. in .CPP:  vertexAttribsArray[1].SemanticName = "TINT";
	float2	a_uv		: TEXCOORD;	// e.g. in .CPP:  vertexAttribsArray[2].SemanticName = "TEXCOORDS";
	
	// Built-in / automatic System Variable (SV) attributes that are NOT part of incoming VBO vertex data
	uint	vertexID	: SV_VertexID; // Which vertex index # in the vertex draw list this is
};


//------------------------------------------------------------------------------------------------
// Vertex shader (VS) OUT to pixel/fragment shader (PS) IN properties.
//
// Each one of these values will (by default) be automatically 3-way interpolated (barycentric varying)
//	across the surface of the triangle, so the position, color, UV, etc. are all lerped at each pixel.
//
// Note: here we use the same struct for both the VS output (return value) and PS input (argument),
//	for convenience.  However, if these were separate structures, their members would be hooked up
//	via their custom semantic names (below).  In our case these semantic names don't matter too much
//	since this structure will automatically perfectlly "hook up with" itself from VS output to PS input.
//
struct VertexToPixelData
{
	float4 v_clipPos	: SV_Position;		// SV_Position is required; marks this member as the clip-space position of the vertex.
	float4 v_color		: VertexColor;		// These custom semantic names can be anything, as long as the struct going
	float2 v_uv			: TextureCoords;	//	into the pixel shader (PS) stage has a semantic that matches the vertex
	float4 v_worldPos	: WorldPos;			//	shader (VS) output semantic name, that variable carries across VS -> PS.
};


//------------------------------------------------------------------------------------------------
// Constant Buffers (CBOs) a.k.a. Uniform Buffers (UBOs) - data which is fixed throughout THIS draw call.
//
// Constant buffers must assign themselves into one of the 16 hard-coded buffer register "slots", b0 through b15.
//
// We stick to certain conventions as it makes using the same engine with multiple games much
//	easier, and allows us to extend the pipeline later with both additional engine and game constants.
//	Here I'm using the conventions suggested by Chris Forseth (which are basically identical to my own).
//
// b0		= system constants (e.g. toggle debug mode) - change rarely (maybe once every many frames)
// b1		= frame constants (e.g. time) - change every frame (once per frame)
// b2		= camera constants (e.g. view/proj matrices) - per camera begin (will differ for each camera)
// b3		= model constants (e.g. model matrix & tint) - per draw call (may differ for each draw call)
// b4-7		= other engine-reserved slots... for future expansion (engine-universal)
// b8-15	= game-specific / free slots... for future expansion (per-game)
//
// CRITICAL NOTE: constant buffers MUST be 16B-aligned (sizeof is multiple of 16B)!
//	Also, member variables may not cross 16B boundaries (unless they are 16B aligned, like Mat44).

//------------------------------------------------------------------------------------------------
// These are set automatically in engine (Camera) code, in Renderer::BeginCamera(), for example:
//
//	UpdateConstantBuffer( *m_cameraCBO, &camGPUData, sizeof(camGPUData) );
//	BindConstantBuffer( 2, m_cameraCBO ); -- the "2" here corresponds with register(b2)
//
cbuffer CameraConstants : register(b2)
{
	float4x4	b_projectionMatrix;		// gameCamera-to-clip (includes gameCamera->screenCamera axis swaps)
	float4x4	b_viewMatrix;			// world-to-gameCamera
	// REMEMBER: CBO structs must have size multiple of 16B, and <16B members cannot straddle 16B boundaries!!
};


//------------------------------------------------------------------------------------------------
// These are set per draw call; I prefer to have them as arguments to DrawVertexArray/DrawVertexBuffer.
//
//	UpdateConstantBuffer( *m_modelCBO, &modelGPUData, sizeof(modelGPUData) );
//	BindConstantBuffer( 3, m_modelCBO ); // bind to constant buffer slot register(b3)
//
cbuffer ModelConstants : register(b3)
{
	float4x4	b_modelMatrix;			// local-to-world
	float4		b_modelTint;			// general diffuse tint to apply to surface colors for this draw
	// REMEMBER: CBO structs must have size multiple of 16B, and <16B members cannot straddle 16B boundaries!!
};


//------------------------------------------------------------------------------------------------
// We can also pass in game-specific constant buffers with any weird custom gamey information we want
//
//	g_theRenderer->UpdateConstantBuffer( *g_gameCBO, &g_gameGPUData, sizeof(GameGPUData) );
//	g_theRenderer->BindConstantBuffer( 8, g_gameCBO ); // bind to constant buffer slot register(b8)
//
cbuffer GameConstants : register(b8)
{
	float4		b_camWorldPos;			// Used for fog thickness calculations, specular lighting, etc.
	float4		b_skyColor;				// Also used as fog color
	float4		b_outdoorLightColor;	// Used for outdoor lighting exposure
	float4		b_indoorLightColor;		// Used for outdoor lighting exposure
	float		b_fogStartDist;			// Fog has zero opacity at or before this distance
	float		b_fogEndDist;			// Fog has maximum opacity at or beyond this distance
	float		b_fogMaxAlpha;			// At and beyond fogEndDist, fog gets this much opacity
	float		b_time;					// CBO structs and members must be 16B-aligned and 16B-sized!!
	// REMEMBER: CBO structs must have size multiple of 16B, and <16B members cannot straddle 16B boundaries!!
};


//------------------------------------------------------------------------------------------------
// Main entry point for the Vertex Stage (VS), which is typically the start of the graphics pipeline.
//
// This runs once per vertex (or index) for each draw call.  It can do anything, but its main critical
//	job is to transform the local-space vertex position attribute (a_position) into clip space.
//
// The input to this function is a vertex; the output is passed on to the pixel shader (PS) stage.
//
VertexToPixelData VertexMain( VertexInputData vertex )
{
	VertexToPixelData outputToPS;
	
	float4 localPos = float4( vertex.a_position, 1.0 );
	float4 worldPos = mul( b_modelMatrix, localPos );
	float4 cameraPos = mul( b_viewMatrix, worldPos );
	float4 clipPos = mul( b_projectionMatrix, cameraPos );

	// We defined the position as a 3 dimensional coordinate, but SV_Position expects a clip/perspective space coordinate (4D).  More on this later.  For now, just pass 1 for w; 
	outputToPS.v_clipPos = clipPos;			// <-- This is the only one D3D11 strictly requires;
	outputToPS.v_worldPos = worldPos;		// ...but we can pass on whatever else we want as well.
	outputToPS.v_color = vertex.a_color * b_modelTint;
	outputToPS.v_uv = vertex.a_uv;

	return outputToPS; // pass it on to the raster stage (RS) and then to the pixel shader (PS) stage
}


//------------------------------------------------------------------------------------------------
// We can bind multiple different textures to multiple different texture constant register slots (t0 through t15).
// e.g. g_theRenderer->BindTexture( mySpritesTexture, 0 ); // the "0" here means texture register(t0)
Texture2D<float4>	t_diffuseTexture : register(t0);	// Texture bound in texture constant slot #0


//------------------------------------------------------------------------------------------------
// We can also support up to 16 different texture samplers; here we're 
// e.g. g_theRenderer->SetSamplerMode( RenderSamplerMode::NEAREST_CLAMP, 0 ); // the "0" here means sampler register(s0)
SamplerState		s_diffuseSampler : register(s0);	// Sampler is bound in sampler constant slot #0



//------------------------------------------------------------------------------------------------
float3 DiminishingAddComponents( float3 a, float3 b )
{
	   return 1.0f - (1.0f - a) * (1.0f - b);
}


//------------------------------------------------------------------------------------------------
// Main entry point for the Pixel Stage (PS), which is near the end of the graphics pipeline.
//
// This runs once per pixel covered by each triangle in the draw call.  It can do anything,
//	but its main critical job is output the final color that will be written (blended) into the screen.
//
// The input to this function is a vertex; the output is an RGBA float4 color, passed on to the
//	output merger (OM) stage, and is blended based on the blend state passed into d3dContext->OMSetBlendState().
//
float4 PixelMain( VertexToPixelData input ) : SV_Target0 // this means "output render target attachment 0" (color)
{
	// Sample the diffuse texture
	float2 uvCoords = input.v_uv;
	float4 diffuseTexel = t_diffuseTexture.Sample( s_diffuseSampler, uvCoords ); // Samples that texture at those UVs
	if( diffuseTexel.a < 0.01 )
    {
		discard; // Skip writing color AND especially depth (if depth-writing is enabled) for transparent pixels
    }

	// Compute lit pixel color
	float outdoorLightExposure = input.v_color.r;
	float indoorLightExposure = input.v_color.g;
	float3 outdoorLight = outdoorLightExposure * b_outdoorLightColor.rgb;
	float3 indoorLight = indoorLightExposure * b_indoorLightColor.rgb;
	float3 diffuseLight = DiminishingAddComponents( outdoorLight, indoorLight );
	float3 diffuseRGB = diffuseLight * diffuseTexel.rgb;
	
	// Compute the fog
	float3 dispCamToPixel = input.v_worldPos.xyz - b_camWorldPos.xyz;
	float distCamToPixel = length( dispCamToPixel );
	float fogDensity = b_fogMaxAlpha * saturate( (distCamToPixel - b_fogStartDist) / (b_fogEndDist - b_fogStartDist) );
	float3 finalRGB = lerp( diffuseRGB, b_skyColor.rgb, fogDensity );
	float finalAlpha = saturate( diffuseTexel.a + fogDensity ); // fog can add opacity

	float4 finalColor = float4( finalRGB, finalAlpha ) ;
	return finalColor;
}

