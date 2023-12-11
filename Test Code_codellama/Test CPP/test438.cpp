#include <Windows.h>
#include <d3d12.h>

class FenceManager
{
public:
    FenceManager(ID3D12Device* d3d12Device)
    {
        _d3d12Device = d3d12Device;
        _fenceValues = new UINT[_d3d12Device->GetMaxFrameLatency()];
        _fenceEvents = new HANDLE[_d3d12Device->GetMaxFrameLatency()];
    }

    ~FenceManager()
    {
        delete[] _fenceValues;
        delete[] _fenceEvents;
    }

    void CreateFence(UINT fenceValue)
    {
        ThrowIfFailed(_d3d12Device->CreateFence(fenceValue, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(_fence.GetAddressOf())));
        _fenceValues[fenceValue]++;

        // Create an event handle to use for frame synchronization.
        _fenceEvents[fenceValue] = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (_fenceEvents[fenceValue] == nullptr)
        {
            ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
        }
    }

    void SignalFence(UINT fenceValue)
    {
        _fenceValues[fenceValue]++;
        _fence->Signal(_fenceValues[fenceValue]);

        // Set the event handle to signal that the fence has been signaled.
        SetEvent(_fenceEvents[fenceValue]);
    }

    void WaitForFence(UINT fenceValue)
    {
        // Wait for the fence to be signaled.
        WaitForSingleObject(_fenceEvents[fenceValue], INFINITE);

        // Check if the fence has been signaled.
        if (_fence->GetCompletedValue() >= _fenceValues[fenceValue])
        {
            // The fence has been signaled, so we can continue.
            return;
        }

        // The fence has not been signaled, so we need to wait for it to be signaled.
        WaitForSingleObject(_fenceEvents[fenceValue], INFINITE);
    }

private:
    ID3D12Device* _d3d12Device;
    UINT* _fenceValues;
    HANDLE* _fenceEvents;
    ComPtr<ID3D12Fence> _fence;
};
