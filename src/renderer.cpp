#include "include/renderer.h"
#include "include/utils.h"

Renderer::Renderer() {
    shader_ = nullptr;
}

Renderer::~Renderer() {
    if (shader_)
        delete shader_;
    glDeleteVertexArrays(vaos_.size(), &vaos_[0]);
    glDeleteBuffers(vbos_.size(), &vbos_[0]);
}

void Renderer::Init() {
    shader_ = new GLSLShader;
    shader_->LoadFromFile(GL_VERTEX_SHADER,   "shaders/regular_phong.vert");
    shader_->LoadFromFile(GL_FRAGMENT_SHADER, "shaders/regular_phong.frag");
    shader_->CreateAndLinkProgram();
    shader_->Enable();
    shader_->AddAttribute("vertex");
    shader_->AddAttribute("normal");
    shader_->AddUniform("modelViewMatrix");
    shader_->AddUniform("normalMatrix");
    shader_->AddUniform("projectionMatrix");
    shader_->AddUniform("ka");
    shader_->AddUniform("kd");
    shader_->AddUniform("ks");
    shader_->AddUniform("Ia");
    shader_->AddUniform("Id");
    shader_->AddUniform("Is");
    shader_->AddUniform("specular");
    shader_->AddUniform("lightInEyeSpace");
}

void Renderer::LoadScene(Scene* scene) {
    std::vector<GameObject*> gameObjects = scene->GameObjects();
    GameObject* obj = gameObjects[0];
    Mesh* mesh = obj->GetMesh();

    int vaoIndex = vaos_.size();
    int vboIndex = vbos_.size();
    vaos_.push_back(0);
    vbos_.push_back(0);
    vbos_.push_back(0);
    vbos_.push_back(0);

    // generate vao + 3 vbos for: verts, norms, indices
    glGenVertexArrays(1, &vaos_[vaoIndex]);
    glBindVertexArray(vaos_[vaoIndex]);
    glGenBuffers(3, &vbos_[vboIndex]);

    // vertices
    glBindBuffer(GL_ARRAY_BUFFER, vbos_[vboIndex + 0]);
    glBufferData(GL_ARRAY_BUFFER, mesh->NumVertices() * sizeof(vec3),
            mesh->Vertices(), GL_STATIC_DRAW);
    glEnableVertexAttribArray((*shader_)["vertex"]);
    glVertexAttribPointer((*shader_)["vertex"], 3, GL_FLOAT, GL_FALSE, 0, 0);

    // normals
    glBindBuffer(GL_ARRAY_BUFFER, vbos_[vboIndex + 1]);
    glBufferData(GL_ARRAY_BUFFER, mesh->NumVertices() * sizeof(vec3),
            mesh->Normals(), GL_STATIC_DRAW);
    glEnableVertexAttribArray((*shader_)["normal"]);
    glVertexAttribPointer((*shader_)["normal"], 3, GL_FLOAT, GL_FALSE, 0, 0);

    // indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos_[vboIndex + 2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->NumTriangles() * sizeof(ivec3),
            mesh->Indices(), GL_STATIC_DRAW);
}

void Renderer::RenderGameObject(GameObject* obj, glm::mat4& V) {
    Mesh* mesh = obj->GetMesh();
    GLuint vao = vaos_[mesh->ModelID()];
    glBindVertexArray(vao);
    Material m = mesh->GetMaterial();
    glUniform4fv((*shader_)["ka"], 1, value_ptr(m.ka));
    glUniform4fv((*shader_)["kd"], 1, value_ptr(m.kd));
    glUniform4fv((*shader_)["ks"], 1, value_ptr(m.ks));
    glUniform1f((*shader_)["specular"], m.specular);

    // glm::mat4 model = obj->ModelMatrix();
    glm::mat4 model = mat4(1);
    glm::mat4 MV = V * model;
    glm::mat4 normalMatrix = glm::transpose(glm::inverse(MV));
    glUniformMatrix4fv((*shader_)["modelViewMatrix"], 1, GL_FALSE, value_ptr(MV));
    glUniformMatrix4fv((*shader_)["normalMatrix"], 1, GL_FALSE, value_ptr(normalMatrix));
    glDrawElements(GL_TRIANGLES, mesh->NumTriangles() * 3, GL_UNSIGNED_INT, 0);
}

// assumes that everything has a vao / whatever already
void Renderer::RenderScene(Scene* scene) {
    shader_->Enable();
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Camera info
    Camera* camera = scene->GetCamera();
    glm::mat4 V = camera->View();
    glm::mat4 P = camera->Proj();
    glUniformMatrix4fv((*shader_)["projectionMatrix"], 1, GL_FALSE, value_ptr(P));

    // Lights
    Light light = scene->GetLight();
    Material m = light.GetMaterial();
    glUniform4fv((*shader_)["Ia"], 1, value_ptr(m.ka));
    glUniform4fv((*shader_)["Id"], 1, value_ptr(m.kd));
    glUniform4fv((*shader_)["Is"], 1, value_ptr(m.ks));
    glUniform4fv((*shader_)["lightInEyeSpace"], 1, value_ptr(V * light.Dir()));
    
    std::vector<GameObject*> gameObjects = scene->GameObjects();
    int i = 0;
    for (std::vector<GameObject*>::iterator obj = gameObjects.begin();
            obj != gameObjects.end();
            ++obj) {
        RenderGameObject(*obj, V);
    }
}
