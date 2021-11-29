#include "../include/Skybox.hpp"



/* Skybox's Cube Parameters */


const std::vector<ShapeVertexTex> cubeVertex = { ShapeVertexTex(glm::vec3(-1,-1, 1), glm::vec3(0,0,0), glm::vec2(0,1)),
                                                 ShapeVertexTex(glm::vec3( 1,-1, 1), glm::vec3(0,0,0), glm::vec2(1,1)),
                                                 ShapeVertexTex(glm::vec3( 1,-1,-1), glm::vec3(0,0,0), glm::vec2(0,1)),
                                                 ShapeVertexTex(glm::vec3(-1,-1,-1), glm::vec3(0,0,0), glm::vec2(1,1)),
                                                 ShapeVertexTex(glm::vec3(-1, 1, 1), glm::vec3(0,0,0), glm::vec2(0,0)),
                                                 ShapeVertexTex(glm::vec3( 1, 1, 1), glm::vec3(0,0,0), glm::vec2(1,0)),
                                                 ShapeVertexTex(glm::vec3( 1, 1,-1), glm::vec3(0,0,0), glm::vec2(0,0)),
                                                 ShapeVertexTex(glm::vec3(-1, 1,-1), glm::vec3(0,0,0), glm::vec2(1,0))};

const std::vector<GLuint> cubeEBO = {1, 2, 6, 6, 5, 1,
                                     0, 4, 7, 7, 3, 0,
                                     4, 5, 6, 6, 7, 4,
                                     0, 3, 2, 2, 1, 0,
                                     0, 1, 5, 5, 4, 0,
                                     3, 7, 6, 6, 2, 3};


Skybox::Skybox() {

    glGenBuffers(1, &_skyVBO);
    glBindBuffer(GL_ARRAY_BUFFER, _skyVBO);
    glBufferData(GL_ARRAY_BUFFER, cubeVertex.size()*sizeof(ShapeVertexTex), &cubeVertex[0], GL_STATIC_DRAW);

    glGenVertexArrays(1, &_skyVAO);
    glBindVertexArray(_skyVAO);

    glGenBuffers(1, &_skyEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _skyEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, cubeVertex.size()*sizeof(GLuint), &cubeEBO[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 3*sizeof(float), 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 3*sizeof(float), (const void*)sizeof(ShapeVertexTex));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 2*sizeof(float), (const void*)(2*sizeof(ShapeVertexTex)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    _faces.push_back("../ressources/noir.jpg"); //placeholders
    _faces.push_back("../ressources/noir.jpg");
    _faces.push_back("../ressources/noir.jpg");
    _faces.push_back("../ressources/noir.jpg");
    _faces.push_back("../ressources/noir.jpg");
    _faces.push_back("../ressources/noir.jpg");

    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_CUBE_MAP, _texture);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE);

    for(int i=0; i<6; i++){
        const Image* img = ImageManager::loadImage(_faces[i].c_str());

        if(img){
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                         0, GL_RGB, img->getWidth(), img->getHeight(),
                         0, GL_RGB, GL_UNSIGNED_BYTE, img->getPixels());
        } else {
            std::cerr << "Skybox Texture Load Failed" << _faces[i] << std::endl;
        }
    }
}

Skybox::~Skybox() {
    glDeleteBuffers(1, &_skyVBO);
    glDeleteBuffers(1, &_skyEBO);
    glDeleteVertexArrays(1, &_skyVAO);
    glDeleteTextures(1, &_texture);
}

void Skybox::display() const {

    glDepthFunc(GL_EQUAL);

    glBindBuffer(GL_ARRAY_BUFFER, _skyVBO);
    glBindVertexArray(_skyVAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _skyEBO);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, _texture);

    glDrawElements(GL_TRIANGLES, cubeEBO.size(), GL_UNSIGNED_INT, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glDepthFunc(GL_LESS);
}