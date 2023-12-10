class BlocksEngine {
public:
    const char* GetBuffer() const noexcept;
    
    class GraphicsException {
    public:
        GraphicsException(HRESULT hr) noexcept : hr_(hr) {}
        
        HRESULT GetErrorCode() const noexcept {
            return hr_;
        }
        
    private:
        HRESULT hr_;
    };
};
