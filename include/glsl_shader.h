#ifndef INCLUDE_SHADER_H_
#define INCLUDE_SHADER_H_

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <map>
#include <vector>

class Shader {
    public:
        Shader();
        Shader(const std::string& name);
        Shader(const std::string& name, const std::string& vname,
               const std::string& fname, const std::string& cname);
        ~Shader();
        void LoadFromString(GLenum shaderType, const std::string& source);
        void LoadFromFile(GLenum shaderType, const std::string& filename);
        void CreateAndLinkProgram();
        void AutoDetectVariables();
        void Enable();
        void Disable();
        void AddAttribute(const std::string& attribute);
        void AddUniform(const std::string& uniform);
        GLuint operator[] (const std::string& name);
        void DeleteShaderProgram();
        GLuint GetProgram() { return program_; }

        std::string& ID() { return id_; }

        // GLuint GetProgram() { return program_; }
        // void SetProgram(GLuint p) { program_ = p; }

    protected:
        std::string id_;
        GLuint program_;
        std::vector<GLuint> shaders_;
        std::map<std::string, GLuint> attributeList_;
        std::map<std::string, GLuint> uniformList_;
};

#endif  // INCLUDE_SHADER_H_
