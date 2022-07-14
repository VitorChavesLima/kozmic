//
// Created by Vitor Chaves on 14/07/2022.
//

#ifndef KOZMIC_MESHCONTROLLER_HPP
#define KOZMIC_MESHCONTROLLER_HPP

#include <memory>
#include <vector>

#include <kozmic/core/utils/Controller.hpp>

namespace Kozmic::Core::Graphics {
    class K_Vertex {

    };

    class K_StaticMesh {

    };

    class K_MeshController : public Utils::K_Controller {
        //<editor-fold desc="Constructors and Destructors">

    public:
        explicit K_MeshController(const std::string& t_loggerName) : Utils::K_Controller(t_loggerName + "_GRAPHICS_MESH") {
            this->m_logger->info("Constructing Mesh Controller");
        }

        virtual ~K_MeshController() {
            this->m_logger->info("Cleaning Mesh Controller");
        }

        //</editor-fold>

    public:
        virtual std::shared_ptr<K_StaticMesh> createStaticMesh(std::vector<std::shared_ptr<K_Vertex>> t_vertices) = 0;
    };
}

#endif //KOZMIC_MESHCONTROLLER_HPP
