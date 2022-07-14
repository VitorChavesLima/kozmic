//
// Created by Vitor Chaves on 14/07/2022.
//

#ifndef KOZMIC_MESHCONTROLLER_HPP
#define KOZMIC_MESHCONTROLLER_HPP

#include <memory>
#include <vector>

#include <kozmic/core/utils/Controller.hpp>

namespace Kozmic::Core::Graphics {
    struct K_Vertex
    {
        K_Vertex(){
           this->pos[0] = 0.0f;
           this->pos[1] = 0.0f;
           this->pos[2] = 0.0f;
        }

        K_Vertex(float t_nX, float t_nY, float t_nZ){
            this->pos[0] = t_nX;
            this->pos[1] = t_nY;
            this->pos[2] = t_nZ;
        }

        float pos[3] = {0.0f, 0.0f, 0.0f};
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
        virtual std::shared_ptr<K_StaticMesh> createStaticMesh(std::vector<K_Vertex> t_vertices) = 0;
    };
}

#endif //KOZMIC_MESHCONTROLLER_HPP
