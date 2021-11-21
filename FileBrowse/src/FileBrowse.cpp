#include "../include/FileBrowse.hpp"


std::vector<ShapeVertexTex> testFunc(){

    std::vector<ShapeVertexTex> vec;

    ShapeVertexTex v1;
    v1._position = {1,0,1};
    v1._normal = {0.5,0,0.5};
    v1._texCoords = {1,0};
    ShapeVertexTex v2;
    v2._position = {1,0,-1};
    v2._normal = {0.5,0,-0.5};
    v2._texCoords = {0,1};
    ShapeVertexTex v3;
    v3._position = {-1,0,-1};
    v3._normal = {-0.5,0,-0.5};
    v3._texCoords = {1,1};
    ShapeVertexTex v4;
    v4._position = {-1,0,1};
    v4._normal = {-0.5,0,0.5};
    v4._texCoords = {0,0};
    ShapeVertexTex v5;
    v5._position = {1,1,1};
    v5._normal = {0,1,0};
    v5._texCoords = {0.5,0.25};
    ShapeVertexTex v6;
    v6._position = {1,1,-1};
    v6._normal = {0,1,0};
    v6._texCoords = {0.25,0.5};
    ShapeVertexTex v7;
    v7._position = {-1,1,-1};
    v7._normal = {0,1,0};
    v7._texCoords = {0.5,0.5};
    ShapeVertexTex v8;
    v8._position = {-1,1,1};
    v8._normal = {0,1,0};
    v8._texCoords = {0.25,0.25};

    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    vec.push_back(v4);
    vec.push_back(v5);
    vec.push_back(v6);
    vec.push_back(v7);
    vec.push_back(v8);

    return vec;
}