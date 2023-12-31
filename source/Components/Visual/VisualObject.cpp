#include "VisualObject.h"

VisualObject::VisualObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Shader::Descriptor _descriptor) {
    position = _position;
    rotation = _rotation;
    scale = _scale;

    shader_descriptor = _descriptor;

    vertex_array_o = 0;
    vertex_buffer_o = 0;
    element_buffer_o = 0;

    shader = Shader::Library::CreateShader(shader_descriptor.vertex_shader_path, shader_descriptor.fragment_shader_path);
}

void VisualObject::SetupGlBuffersVerticesOnly() {
    //generate and bind the circles' vertex array (VAO)
    glGenVertexArrays(1, &vertex_array_o);
    glBindVertexArray(vertex_array_o);

    //generate and bind the grid's VBO
    glGenBuffers(1, &vertex_buffer_o);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_o);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                 &vertices.front(), GL_STATIC_DRAW);

    //generate and bind the circles' EBO
    glGenBuffers(1, &element_buffer_o);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_o);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int),
                 &indices.front(), GL_STATIC_DRAW);

    //set vertex attributes pointers (position & normal)
    //strides are 6 * float-size long, because we are including position + normal data in the VAO (Vertex Attribute Object)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid *) nullptr);
    glEnableVertexAttribArray(0);

    //the following is in this specific order to avoid a dangling EBO
    //more info: https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/2.2.hello_triangle_indexed/hello_triangle_indexed.cpp

    //cleanup buffers
    glBindVertexArray(0);
    glDeleteBuffers(1, &vertex_buffer_o);
    glDeleteBuffers(1, &element_buffer_o);
}

void VisualObject::SetupGlBuffersVerticesAndNormalsOnlyNoIndices() {
    //generate and bind the circles' vertex array (VAO)
    glGenVertexArrays(1, &vertex_array_o);
    glBindVertexArray(vertex_array_o);

    //generate and bind the grid's VBO
    glGenBuffers(1, &vertex_buffer_o);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_o);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                 &vertices.front(), GL_STATIC_DRAW);

    //set vertex attributes pointers (position & normal)
    //strides are 6 * float-size long, because we are including position + normal data in the VAO (Vertex Attribute Object)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid *) nullptr);
    glEnableVertexAttribArray(0);

    //normal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //the following is in this specific order to avoid a dangling EBO
    //more info: https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/2.2.hello_triangle_indexed/hello_triangle_indexed.cpp

    //cleanup buffers
    glBindVertexArray(0);
    glDeleteBuffers(1, &vertex_buffer_o);
}
