//
// Created by Vitor Chaves on 14/07/2022.
//

#define EXCEPT(message) throw Utils::K_Exception(__FILE__, __LINE__, __FUNCTION__, message)

#include "mesh/DX11StaticMesh.hpp"

#include "DX11MeshController.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Constructors and Destructors">

K_Dx11MeshController::K_Dx11MeshController(const std::string& t_loggerName, ID3D11Device* t_pDevice, ID3D11DeviceContext* t_pContext) : K_MeshController(t_loggerName + "_DX11"){
    this->m_pDevice = t_pDevice;
    this->m_pContext = t_pContext;
}

//</editor-fold>

void K_Dx11MeshController::setRenderStyle(std::string t_sRenderStyle) {
    if(t_sRenderStyle == "POINTS") this->m_pContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);
    else if(t_sRenderStyle == "LINES") this->m_pContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
    else if(t_sRenderStyle == "TRIANGLES") this->m_pContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

std::shared_ptr<K_StaticMesh>
K_Dx11MeshController::createStaticMesh(std::vector<K_Vertex> t_vertices) {
    this->m_logger->info("Creating a static mesh");

    HRESULT result;

    D3D11_BUFFER_DESC vertexBufferDescription;
    ZeroMemory( &vertexBufferDescription, sizeof(vertexBufferDescription) );

    vertexBufferDescription.Usage = D3D11_USAGE_DEFAULT;
    vertexBufferDescription.ByteWidth = sizeof( t_vertices[0] ) * static_cast<unsigned int>(t_vertices.size());
    vertexBufferDescription.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDescription.CPUAccessFlags = 0;
    vertexBufferDescription.MiscFlags = 0;

    ID3D11Buffer* vertexBuffer;
    UINT stride = sizeof( t_vertices[0] );
    UINT offset = 0;

    D3D11_SUBRESOURCE_DATA vertexBufferData;

    ZeroMemory( &vertexBufferData, sizeof(vertexBufferData) );
    vertexBufferData.pSysMem = &t_vertices[0];
    result = this->m_pDevice->CreateBuffer( &vertexBufferDescription, &vertexBufferData, &vertexBuffer);
    if(FAILED(result)) EXCEPT("Could not create buffer");

    this->m_pContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    return std::make_shared<K_Dx11StaticMesh>(vertexBuffer, stride, offset, (UINT) t_vertices.size());
}

void K_Dx11MeshController::drawStaticMesh(std::shared_ptr<K_StaticMesh> t_pStaticMesh) {
    std::shared_ptr<K_Dx11StaticMesh> staticMesh = std::reinterpret_pointer_cast<K_Dx11StaticMesh>(t_pStaticMesh);
    ID3D11Buffer* vertexBuffer = staticMesh->getVertexBuffer();
    UINT stride = staticMesh->getStride();
    UINT offset = staticMesh->getOffset();
    UINT vertexCount = staticMesh->getVertexCount();

    this->m_pContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    this->m_pContext->Draw(vertexCount, 0);
}
