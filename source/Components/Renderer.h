#pragma once

#include <map>
#include "Camera.h"
#include "Shader.h"
#include "Visual/VisualGrid.h"
#include "GLFW/glfw3.h"
#include "Components/Visual/VisualLine.h"
#include "Components/Visual/VisualCube.h"

class Renderer {
private:
    std::shared_ptr<Camera> main_camera;
    std::shared_ptr<Shader> default_shader;

    std::unique_ptr<VisualGrid> main_grid;

    std::unique_ptr<VisualLine> main_x_line;
    std::unique_ptr<VisualLine> main_y_line;
    std::unique_ptr<VisualLine> main_z_line;

    std::unique_ptr<VisualCube> world_cube;

    std::vector<VisualCube> racket_cubes;

    glm::vec3 racket_one_position;
    glm::vec3 racket_one_rotation;
    glm::vec3 racket_one_scale;

    glm::vec3 racket_two_position;
    glm::vec3 racket_two_rotation;
    glm::vec3 racket_two_scale;

    glm::vec3 racket_three_position;
    glm::vec3 racket_three_rotation;
    glm::vec3 racket_three_scale;

    glm::vec3 racket_four_position;
    glm::vec3 racket_four_rotation;
    glm::vec3 racket_four_scale;

    int racket_render_mode = GL_TRIANGLES;
    int selected_player = 0;

public:
    Renderer(int _initialWidth, int _initialHeight);

    void Render(GLFWwindow* _window, double _deltaTime);
    void ResizeCallback(GLFWwindow* _window, int _displayWidth, int _displayHeight);
    void InputCallback(GLFWwindow* _window, double _deltaTime);

    void DrawOneRacket(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale);
};

