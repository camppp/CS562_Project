class GraphicsEngine {
public:
	void CreateRenderTarget() {
		// Implement render target creation
	}

	void DestroyRenderTarget() {
		// Implement render target destruction
	}

	void TerminateDevice() {
		// Implement device termination
	}

	// Complete the Terminate function to destroy the render target and terminate the device
	void Terminate() {
		DestroyRenderTarget();
		TerminateDevice();
	}
};
