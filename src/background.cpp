#include "include/background.h"

Background::Background() {
    color = glm::vec4(1);
}

Background::Background(glm::vec3 c) {
    color = glm::vec4(c, 1);
}
