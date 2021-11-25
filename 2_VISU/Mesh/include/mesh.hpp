#pragma once

#include "../../../1_CORE/Scene/include/Scene.hpp"
#include <list>

class Mesh {
private :
    std::list<ShapeVertexTex> _vertice;
    std::vector<int> _nbVertexMat;
    std::vector<glm::mat4> _modelMats;

public :

    Mesh();
    Mesh(const Scene &fromScene);
    ~Mesh() = default;

    void extractFromNode(const SceneNode &node);
    void reCompute(const Scene &fromScene);
    void render() const;

    inline void setModelMat(const int wichMat, const glm::mat4 &newModelMat) {_modelMats[wichMat] = newModelMat;}
};