#include "../include/Skybox.hpp"



/* Skybox's Cube Parameters */


const std::vector<Vertex> cubeVertex = { Vertex(glm::vec3(-1,-1, 1), glm::vec3(0,0,0), glm::vec2(0,1)),
                                         Vertex(glm::vec3( 1,-1, 1), glm::vec3(0,0,0), glm::vec2(1,1)),
                                         Vertex(glm::vec3( 1,-1,-1), glm::vec3(0,0,0), glm::vec2(0,1)),
                                         Vertex(glm::vec3(-1,-1,-1), glm::vec3(0,0,0), glm::vec2(1,1)),
                                         Vertex(glm::vec3(-1, 1, 1), glm::vec3(0,0,0), glm::vec2(0,0)),
                                         Vertex(glm::vec3( 1, 1, 1), glm::vec3(0,0,0), glm::vec2(1,0)),
                                         Vertex(glm::vec3( 1, 1,-1), glm::vec3(0,0,0), glm::vec2(0,0)),
                                         Vertex(glm::vec3(-1, 1,-1), glm::vec3(0,0,0), glm::vec2(1,0))};

const std::vector<GLuint> cubeEBO = {1, 2, 6, 6, 5, 1,
                                     0, 4, 7, 7, 3, 0,
                                     4, 5, 6, 6, 7, 4,
                                     0, 3, 2, 2, 1, 0,
                                     0, 1, 5, 5, 4, 0,
                                     3, 7, 6, 6, 2, 3};


Skybox::Skybox() {

    glGenVertexArrays(1, &_skyVAO);
    glGenBuffers(1, &_skyVBO);
    glGenBuffers(1, &_skyEBO);

    glBindVertexArray(_skyVAO);
    glBindBuffer(GL_ARRAY_BUFFER, _skyVBO);
    glBufferData(GL_ARRAY_BUFFER, cubeVertex.size()*sizeof(Vertex), &cubeVertex[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _skyEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, cubeEBO.size()*sizeof(GLuint), &cubeEBO[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    std::string path = SDL_GetBasePath();
    _faces.push_back(path + "../ressources/Front.png"); //placeholders
    _faces.push_back(path + "../ressources/noir.png");
    _faces.push_back(path + "../ressources/noir.png");
    _faces.push_back(path + "../ressources/noir.png");
    _faces.push_back(path + "../ressources/noir.png");
    _faces.push_back(path + "../ressources/noir.png");

    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_CUBE_MAP, _texture);

    int width, height, nbChannels;
    unsigned char* img;

    for(int i=0; i<6; i++){

        img = stbi_load(_faces[1].c_str(), &width, &height, &nbChannels, 0);

        if(img){
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                         0, GL_RGB, width, height,
                         0, GL_RGB, GL_UNSIGNED_BYTE, img);
            stbi_image_free(img);

        } else {
            std::cout << "Skybox Texture Load Failed" << _faces[i] << std::endl;
            stbi_image_free(img);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE);
}

Skybox::~Skybox() {
    glDeleteBuffers(1, &_skyVBO);
    glDeleteBuffers(1, &_skyEBO);
    glDeleteVertexArrays(1, &_skyVAO);
    glDeleteTextures(1, &_texture);
}

void Skybox::display() const {
    glDepthMask(GL_FALSE);

    glBindVertexArray(_skyVAO);


    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, _texture);
    glDrawElements(GL_TRIANGLES, cubeEBO.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    glDepthMask(GL_TRUE);
}