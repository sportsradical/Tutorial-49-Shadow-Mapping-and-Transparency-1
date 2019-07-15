////////////////////////////////////////////////////////////////////////////////
// Filename: treeclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TREECLASS_H_
#define _TREEMODELCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <DirectXMath.h>
#include <fstream>
using namespace std;
using namespace DirectX ;

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: TreeClass
////////////////////////////////////////////////////////////////////////////////
class TreeClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
		XMFLOAT3 normal;
	};

	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

public:
	TreeClass();
	TreeClass(const TreeClass&);
	~TreeClass();

	bool Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* trunkModelFilename, 
			char* trunkTextureFilename, char* leafModelFilename, char* leafTextureFilename, float scale);

	void Shutdown();

	void RenderTrunk(ID3D11DeviceContext* deviceContext);
	void RenderLeaves(ID3D11DeviceContext* deviceContext);

	int GetTrunkIndexCount();
	int GetLeafIndexCount();
	
	ID3D11ShaderResourceView* GetTrunkTexture();
	ID3D11ShaderResourceView* GetLeafTexture();
	
	void SetPosition(float x, float y, float z);
	void GetPosition(float& x, float& y, float& z);

private:
	bool InitializeTrunkBuffers(ID3D11Device* device, float scale);
	bool InitializeLeafBuffers(ID3D11Device* device, float scale);

	void ShutdownBuffers();

	void RenderTrunkBuffers(ID3D11DeviceContext*);
	void RenderLeafBuffers(ID3D11DeviceContext*);

	bool LoadTextures(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* trunkFilename, char* leafFilename);
	void ReleaseTextures();

	bool LoadModel(char* filename);
	void ReleaseModel();

private:
	ID3D11Buffer *m_trunkVertexBuffer, *m_trunkIndexBuffer, *m_leafVertexBuffer, *m_leafIndexBuffer;
	int m_vertexCount, m_indexCount, m_trunkIndexCount, m_leafIndexCount;
	TextureClass *m_TrunkTexture, *m_LeafTexture;
	ModelType* m_model;
	float m_positionX, m_positionY, m_positionZ;
};

#endif