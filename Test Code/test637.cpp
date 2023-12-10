class VanillaMesh {
private:
    RenderBufferManager* mRenderBufferMgr;
    VertexBuffer* mVertexBuffer;
    IndexBuffer* mIndexBuffer;

public:
    // Existing methods
    void bind() {
        mRenderBufferMgr->bind();
    }

    void unbind() {
        mRenderBufferMgr->unbind();
    }

    // New methods
    void bindVertexBuffer() {
        mVertexBuffer->bind();
    }

    void unbindVertexBuffer() {
        mVertexBuffer->unbind();
    }

    void bindIndexBuffer() {
        mIndexBuffer->bind();
    }

    void unbindIndexBuffer() {
        mIndexBuffer->unbind();
    }
};
