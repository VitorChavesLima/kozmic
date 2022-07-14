//
// Created by Vitor Chaves on 14/07/2022.
//

#ifndef KOZMIC_MESHCONTROLLER_HPP
#define KOZMIC_MESHCONTROLLER_HPP

#include <memory>
#include <vector>

namespace Kozmic::Core::Graphics {

    class K_Vertex {

    };

    class K_StaticMesh {

    };

    class K_MeshController {
    public:
        std::shared_ptr<K_StaticMesh> createStaticMesh(std::vector<std::shared_ptr<K_Vertex>> t_vertices);
    };
}

#endif //KOZMIC_MESHCONTROLLER_HPP
