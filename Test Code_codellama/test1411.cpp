#include <d3d12.h>
#include <wrl.h>

class DX12CommandQueue : public ICommandQueue {
public:
    DX12CommandQueue(ID3D12Device* device) : device_(device) {}

    void Initialize() {
        // Create the command queue
        D3D12_COMMAND_QUEUE_DESC queueDesc = {};
        queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
        queueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
        queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
        device_->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&commandQueue_));

        // Create the command allocator
        device_->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&commandAllocator_));

        // Create the command list
        device_->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, commandAllocator_, nullptr, IID_PPV_ARGS(&commandList_));
    }

    void SubmitCommands(ID3D12CommandList* commandList) {
        // Add the command list to the queue
        commandQueue_->ExecuteCommandLists(1, &commandList);
    }

    void ExecuteCommands() {
        // Execute the command list
        commandQueue_->ExecuteCommandLists(1, &commandList_);
    }

private:
    Microsoft::WRL::ComPtr<ID3D12Device> device_;
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue_;
    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator_;
    Microsoft::WRL::ComPtr<ID3D12CommandList> commandList_;
};
