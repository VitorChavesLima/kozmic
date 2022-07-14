//
// Created by Vitor Chaves on 14/07/2022.
//

#include "DX11StaticMesh.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Constructors and Destructors">

K_Dx11StaticMesh::K_Dx11StaticMesh(ID3D11Buffer* t_pVertexBuffer, UINT t_nStride, UINT t_nOffset) {
    this->m_pVertexBuffer = t_pVertexBuffer;
    this->m_nStride = t_nStride;
    this->m_nOffset = t_nOffset;
}

//</editor-fold>