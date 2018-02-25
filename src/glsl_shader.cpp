#include "include/glsl_shader.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Shader::Shader() : Shader("Null Shader") {}

Shader::Shader(const std::string& name) {
    id_ = name;
    program_ = 0;
}

Shader::~Shader() {
    DeleteShaderProgram();
}

void Shader::LoadFromString(GLenum shaderType, const std::string& source) {
    GLuint newShader = glCreateShader(shaderType);
    char const * sourcePointer = source.c_str();
    glShaderSource(newShader, 1, &sourcePointer, NULL);
    glCompileShader(newShader);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    glGetShaderiv(newShader, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(newShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(newShader, InfoLogLength, NULL, &ErrorMessage[0]);
        printf("Error while loading shader:\n%s\n\n", &ErrorMessage[0]);
    }

    shaders_.push_back(newShader);
}

void Shader::LoadFromFile(GLenum shaderType, const std::string& filename) {
    std::ifstream in(filename);
    if (in.fail()) {
        std::cerr << "Failed to open the shader file: " << filename << std::endl;
        return;
    }
    std::string file, line;
    while (std::getline(in, line))
        file += line + '\n';
    in.close();
    LoadFromString(shaderType, file);
}

void Shader::CreateAndLinkProgram() {
    program_ = glCreateProgram();
    for (int i = 0; i < shaders_.size(); i++)
        glAttachShader(program_, shaders_[i]);

    glLinkProgram(program_);

    GLint Result = GL_FALSE;
    int InfoLogLength;
    glGetProgramiv(program_, GL_LINK_STATUS, &Result);
    glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(program_, InfoLogLength, NULL, &ErrorMessage[0]);
        printf("Error while compiling and linking program:\n%s\n\n", &ErrorMessage[0]);
        return;
    }

    for (int i = 0; i < shaders_.size(); i++) {
        glDetachShader(program_, shaders_[i]);
        glDeleteShader(shaders_[i]);
    }
    shaders_.clear();
}

void Shader::Enable() {
    glUseProgram(program_);
}

void Shader::Disable() {
    glUseProgram(0);
}

void Shader::AddAttribute(const std::string& attribute) {
    attributeList_[attribute] = glGetAttribLocation(program_, attribute.c_str());
}

void Shader::AddUniform(const std::string& uniform) {
    uniformList_[uniform] = glGetUniformLocation(program_, uniform.c_str());
}

GLuint Shader::operator[] (const std::string& name) {
    std::map<std::string, GLuint>::iterator it;
    it = uniformList_.find(name);
    if (it != uniformList_.end())
        return it->second;
    it = attributeList_.find(name);
    if (it != attributeList_.end())
        return it->second;

    return -1;
}

void Shader::DeleteShaderProgram() {
    glDeleteProgram(program_);
}
