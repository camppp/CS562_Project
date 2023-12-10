        // TODO(<EMAIL>): must access VAO instead!
        assert(false);
        auto vao = m_color_mesh->get_mesh()->vertex_array_object().get();  // Accessing the Vertex Array Object (VAO)

        static_cast<void>(r.set_vertex_array(vao));  // Setting the Vertex Array Object (VAO)

        gr.set_transform(m_hsv_transform);
        gr.set_hsv_matrix(c);
        gr.set_color_scale(vec4(1.0f, 1.0f, 1.0f, 1.0f));
        gr.set_color_add(vec4(0.0f, 0.0f, 0.0f, 1.0f));
        //m_color_mesh->render(m_color_mesh->fill_indices());
