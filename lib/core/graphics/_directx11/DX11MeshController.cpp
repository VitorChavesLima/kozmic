//
// Created by Vitor Chaves on 14/07/2022.
//

#include "DX11MeshController.hpp"

using namespace Kozmic::Core::Graphics;

//<editor-fold desc="Constructors and Destructors">

K_Dx11MeshController::K_Dx11MeshController(const std::string& t_loggerName, ID3D11DeviceContext *t_pContext) : K_MeshController(t_loggerName + "_DX11"){
    this->m_pContext = t_pContext;
}

//</editor-fold>

std::shared_ptr<K_StaticMesh>
K_Dx11MeshController::createStaticMesh(std::vector<std::shared_ptr<K_Vertex>> t_vertices) {
    return std::shared_ptr<K_StaticMesh>();
}
