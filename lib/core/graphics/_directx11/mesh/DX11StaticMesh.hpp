//
// Created by Vitor Chaves on 14/07/2022.
//

#ifndef KOZMIC_DX11STATICMESH_HPP
#define KOZMIC_DX11STATICMESH_HPP

#include <d3d11.h>

#include <kozmic/core/graphics/MeshController.hpp>

namespace Kozmic::Core::Graphics {
    class K_Dx11StaticMesh : public K_StaticMesh {
        //<editor-fold desc="Properties">

    private:
        ID3D11Buffer* m_pVertexBuffer;
        UINT m_nStride;
        UINT m_nOffset;
        UINT m_nVertexCount;

        friend class K_Dx11MeshController;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_Dx11StaticMesh(ID3D11Buffer* t_pVertexBuffer, UINT t_nStride, UINT t_nOffset, UINT t_nVertexCount);

        //</editor-fold>

        //<editor-fold desc="Getters">

    private:
        ID3D11Buffer* getVertexBuffer() { return this->m_pVertexBuffer; }
        [[nodiscard]] UINT getStride() const { return this->m_nStride; }
        [[nodiscard]] UINT getOffset() const { return this->m_nOffset; }
        [[nodiscard]] UINT getVertexCount() const { return this->m_nVertexCount; }

        //</editor-fold>
    };
}

#endif //KOZMIC_DX11STATICMESH_HPP
