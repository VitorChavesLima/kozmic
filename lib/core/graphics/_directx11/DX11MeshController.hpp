//
// Created by Vitor Chaves on 14/07/2022.
//

#ifndef KOZMIC_DX11MESHCONTROLLER_HPP
#define KOZMIC_DX11MESHCONTROLLER_HPP

#include <d3d11.h>

#include "kozmic/core/utils/Exception.hpp"
#include <kozmic/core/graphics/MeshController.hpp>

namespace Kozmic::Core::Graphics {
    class K_Dx11MeshController : public K_MeshController {
        //<editor-fold desc="Properties">

    private:
        ID3D11Device* m_pDevice;
        ID3D11DeviceContext* m_pContext;

        //</editor-fold>

        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_Dx11MeshController(const std::string& t_loggerName, ID3D11Device* t_pDevice, ID3D11DeviceContext* t_pContext);

        //</editor-fold>

    public:
        void setRenderStyle(std::string t_sRenderStyle) override;

        std::shared_ptr<K_StaticMesh> createStaticMesh(std::vector<K_Vertex> t_vertices) override;
        void drawStaticMesh(std::shared_ptr<K_StaticMesh> t_pStaticMesh) override;
    };
}

#endif //KOZMIC_DX11MESHCONTROLLER_HPP
