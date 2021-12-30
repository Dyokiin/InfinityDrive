#include "../include/mesh.hpp"


void Mesh::setupMesh() {

    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ibo);

    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    glBufferData(GL_ARRAY_BUFFER, _vertices.size()*sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), &_indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0); //Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    glEnableVertexAttribArray(1); //Normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, _normal));

    glEnableVertexAttribArray(2); //Texture coordinates
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, _texCoords));

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::Draw() const {
    
    glBindTexture(GL_TEXTURE_2D, _texture._id);
    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

const Mesh texturedPlane( glm::vec3 p1, glm::vec3 p2, std::string pathToText){
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices = {0,2,3,  1,2,3};

    glm::vec3 p3(p2.x, p1.y, p1.z);
    glm::vec3 p4(p1.x, p2.y, p2.z);

    vertices.push_back(Vertex(p1, glm::vec3(0,-1,0), glm::vec2(0,0)));
    vertices.push_back(Vertex(p2, glm::vec3(0,-1,0), glm::vec2(1,1)));
    vertices.push_back(Vertex(p3, glm::vec3(0,-1,0), glm::vec2(1,0)));
    vertices.push_back(Vertex(p4, glm::vec3(0,-1,0), glm::vec2(0,1)));

    Texture texture;
    glGenTextures(1, &texture._id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture._id);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    int width, height, nbChannels;
    unsigned char* img;

    std::string path = SDL_GetBasePath() + pathToText;
    img = stbi_load(path.c_str(), &width, &height, &nbChannels, 0);

    //Different Load depending on Alpha Channel or no
    if(img) {
        if(nbChannels>3){
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
            glGenerateMipmap(GL_TEXTURE_2D);
            stbi_image_free(img);
        } else {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
            glGenerateMipmap(GL_TEXTURE_2D);
            stbi_image_free(img);
        }
    } else {
        std::cerr << "Texture Load Failed : " << pathToText << std::endl;
        stbi_image_free(img);
    }

    glBindTexture(GL_TEXTURE_2D, 0);

    return Mesh(vertices, indices, texture);
}

const Mesh texturedPlane(const glm::vec2 p1, const glm::vec2 p2, SDL_Surface* text) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices = {0,2,3,  1,2,3};

    glm::vec2 p3(p2.x, p1.y);
    glm::vec2 p4(p1.x, p2.y);

    vertices.push_back(Vertex(glm::vec3(p1,1), glm::vec3(0,1,0), glm::vec2(0,0)));
    vertices.push_back(Vertex(glm::vec3(p2,1), glm::vec3(0,1,0), glm::vec2(1,1)));
    vertices.push_back(Vertex(glm::vec3(p3,1), glm::vec3(0,1,0), glm::vec2(1,0)));
    vertices.push_back(Vertex(glm::vec3(p4,1), glm::vec3(0,1,0), glm::vec2(0,1)));

    Texture texture;
    glGenTextures(1, &texture._id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture._id);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, text->w, text->h, 0, GL_RGB, GL_UNSIGNED_BYTE, text->pixels);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    SDL_FreeSurface(text);

    return Mesh(vertices, indices, texture);
}