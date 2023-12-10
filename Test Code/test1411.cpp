#include "graphics/DX12CommandQueue.hpp"

DX12CommandQueue::DX12CommandQueue(ID3D12Device* device, D3D12_COMMAND_LIST_TYPE type)
    : mFenceValue(0), mCommandListType(type)
{
    D3D12_COMMAND_QUEUE_DESC queueDesc = {};
    queueDesc.Type = type;
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.NodeMask = 1;

    ThrowIfFailed(device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&mCommandQueue)));
    ThrowIfFailed(device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&mFence)));
    mFenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
}

DX12CommandQueue::~DX12CommandQueue()
{
    CloseHandle(mFenceEvent);
}

void DX12CommandQueue::ExecuteCommandList(ID3D12CommandList* commandList)
{
    mCommandQueue->ExecuteCommandLists(1, &commandList);
}

void DX12CommandQueue::Signal()
{
    mFenceValue++;
    mCommandQueue->Signal(mFence.Get(), mFenceValue);
}

void DX12CommandQueue::WaitForFenceValue(uint64_t fenceValue)
{
    if (mFence->GetCompletedValue() < fenceValue)
    {
        mFence->SetEventOnCompletion(fenceValue, mFenceEvent);
        WaitForSingleObject(mFenceEvent, INFINITE);
    }
}

void DX12CommandQueue::Flush()
{
    Signal();
    WaitForFenceValue(mFenceValue);
}
