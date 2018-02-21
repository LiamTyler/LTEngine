#include "include/renderer.h"

Renderer::Renderer() {
}

Renderer::~Renderer() {
    for (auto& shader : shaders_)
        delete shader;
    glDeleteVertexArrays(vaos_.size(), &vaos_[0]);
    glDeleteBuffers(vbos_.size(), &vbos_[0]);
}

Shader* Renderer::GetShader(const std::string& id) {
    assert(shader_mapping_.find(id) != shader_mapping_.end());

    return shaders_[shader_mapping_[id]];
}

Shader* Renderer::AddShader(const std::string& id, const std::string& vShader,
                     const std::string& fShader, const std::string& cShader) {
    Shader* shader = new Shader(id);
    if (vShader != "")
        shader->LoadFromFile(GL_VERTEX_SHADER, vShader);
    if (fShader != "")
        shader->LoadFromFile(GL_FRAGMENT_SHADER, fShader);
    if (cShader != "")
        shader->LoadFromFile(GL_COMPUTE_SHADER, cShader);
    shader->CreateAndLinkProgram();

    // just to test mesh vao
    shader->Enable();
    shader->AddAttribute("vertex");
    shader->AddAttribute("normal");
    shader->AddUniform("modelViewMatrix");
    shader->AddUniform("normalMatrix");
    shader->AddUniform("projectionMatrix");
    shader->AddUniform("ka");
    shader->AddUniform("kd");
    shader->AddUniform("ks");
    shader->AddUniform("Ia");
    shader->AddUniform("Id");
    shader->AddUniform("Is");
    shader->AddUniform("specular");
    shader->AddUniform("lightInEyeSpace");
    // end

    shaders_.push_back(shader);
    shader_mapping_[id] = shaders_.size() - 1;
    ShaderGroup sg;
    sg.shader_index = shaders_.size() - 1;
    shaderGroups_.push_back(sg);

    return shader;
}

bool Renderer::VaoExists(RID r) {
    return vao_mapping_.find(r) != vao_mapping_.end();
}

GLuint Renderer::CreateAndRegisterVao(const std::string& shaderID, RID r, RenderComponent* rc) {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    vaos_.push_back(vao);
    VaoGroup group;
    group.vao_index = vaos_.size() - 1;
    group.objects_.push_back(rc);
    ShaderGroup& sg = shaderGroups_[shader_mapping_[shaderID]];
    sg.vaoGroups_.push_back(group);
    struct Map m;
    m.shaderGroup = shader_mapping_[shaderID];
    m.vaoGroup = sg.vaoGroups_.size() - 1;
    vao_mapping_[r] = m;
    return vao;
}

GLuint* Renderer::CreateVbos(int num) {
    vbos_.resize(vbos_.size() + num);
    glGenBuffers(num, &vbos_[vbos_.size() - num]);

    return &vbos_[vbos_.size() - num];
}

void Renderer::RenderScene(Camera& camera) {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 V = camera.View();
    glm::mat4 P = camera.Proj();

    // hard code the light right now
    glm::vec4 lightDir = glm::normalize(glm::vec4(-1, -.5, -.8, 0));
    glm::vec4 Ia = glm::vec4(.3, .3, .3, 1);
    glm::vec4 Id = glm::vec4(.3, .3, .3, 1);
    glm::vec4 Is = glm::vec4(.3, .3, .3, 1);

    for (auto& sg : shaderGroups_) {
        Shader& shader = *shaders_[sg.shader_index];
        shader.Enable();
        // bind uniforms
        glUniform4fv(shader["Ia"], 1, value_ptr(Ia));
        glUniform4fv(shader["Id"], 1, value_ptr(Id));
        glUniform4fv(shader["Is"], 1, value_ptr(Is));
        glUniform4fv(shader["lightInEyeSpace"], 1, value_ptr(V * lightDir));
        glUniformMatrix4fv(shader["projectionMatrix"], 1, GL_FALSE, value_ptr(P));

        for (auto& vg : sg.vaoGroups_) {
            glBindVertexArray(vaos_[vg.vao_index]);
            for (auto& obj : vg.objects_) {
                obj->Render(shader, V);
            }
        }
    }
}
