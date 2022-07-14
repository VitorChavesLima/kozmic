//
// Created by Vitor Chaves on 14/07/2022.
//

#include "mesh/DX11StaticMesh.hpp"

#include "DX11MeshController.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Constructors and Destructors">

K_Dx11MeshController::K_Dx11MeshController(const std::string& t_loggerName, ID3D11Device* t_pDevice) : K_MeshController(t_loggerName + "_DX11"){
    this->m_pDevice = t_pDevice;
}

//</editor-fold>

std::shared_ptr<K_StaticMesh>
K_Dx11MeshController::createStaticMesh(std::vector<K_Vertex> t_vertices) {
    this->m_logger->info("Creating a static mesh");

    D3D11_BUFFER_DESC vertexBufferDescription;
    ZeroMemory( &vertexBufferDescription, sizeof(vertexBufferDescription) );

    vertexBufferDescription.Usage = D3D11_USAGE_DEFAULT;
    vertexBufferDescription.ByteWidth = sizeof( t_vertices[0] ) * t_vertices.size();
    vertexBufferDescription.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDescription.CPUAccessFlags = 0;
    vertexBufferDescription.MiscFlags = 0;

    ID3D11Buffer* vertexBuffer;
    UINT stride = sizeof( t_vertices[0] );
    UINT offset = 0;

    D3D11_SUBRESOURCE_DATA vertexBufferData;

    ZeroMemory( &vertexBufferData, sizeof(vertexBufferData) );
    vertexBufferData.pSysMem = &t_vertices[0];
    this->m_pDevice->CreateBuffer( &vertexBufferDescription, &vertexBufferData, &vertexBuffer);

    return std::make_shared<K_Dx11StaticMesh>(vertexBuffer, stride, offset);
}
