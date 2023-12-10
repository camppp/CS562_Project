        // TODO(<EMAIL>): must access VAO instead!
        assert(false);
        auto vao = m_color_mesh->get_mesh()->vertex_array().get();

        //auto old_vao =
        static_cast<void>(r.set_buffer(Buffer::Target::array_buffer, vao));

        gr.set_transform(m_hsv_transform);
        gr.set_hsv_matrix(c);
        gr.set_color_scale(vec4(1.0f, 1.0f, 1.0f, 1.0f));
        gr.set_color_add(vec4(0.0f, 0.0f, 0.0f, 1.0f));
        //m_color_mesh->render(m_color_mesh->fill_indices());
