#include "../include/Model.hpp"

void Model::Draw() const {
    _mesh[0].Draw();
}

void Model::loadModel(const char* path) {
    std::string AbsPath = SDL_GetBasePath();
    AbsPath += path; 
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(AbsPath, aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
        return;
    }

    _textPath = AbsPath.substr(0, AbsPath.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    for(unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        _mesh.push_back(processMesh(mesh, scene));
    }
    for(unsigned int i = 0; i < node->mNumChildren; i++){
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) {

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    Texture tex;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        glm::vec3 vector; 
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z; 
        vertex._position = vector;

        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex._normal = vector;

        if(mesh->mTextureCoords[0]) {
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x; 
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex._texCoords = vec;
        } else {vertex._texCoords = glm::vec2(0.0f, 0.0f);}

        vertices.push_back(vertex);
    }

    // process indices
    for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    } 
    //TODO TEX
    // for(auto i : vertices) {
    //     std::cout << "Position : {" << i._position.x << ", " << i._position.y << ", " <<  i._position.z << "}" << std::endl;
    //     std::cout << "Normal   : {" << i._normal.x << ", " << i._normal.y << ", " <<  i._normal.z << "}" << std::endl;
    // }
    return Mesh(vertices, indices, tex);
}