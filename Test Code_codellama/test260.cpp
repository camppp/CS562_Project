class GraphicsEngine {
public:
	void CreateRenderTarget() {
		// Implement render target creation
	}

	void DestroyRenderTarget() {
		// Implement render target destruction
	}

	void Terminate() {
		DestroyRenderTarget();
		TerminateDevice();
	}

	// Add a function to terminate the device
	void TerminateDevice() {
		// Implement device termination
	}
};
