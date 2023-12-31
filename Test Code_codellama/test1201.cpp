#include <iostream>
#include <string>

class ConfirmAssetUploadReq {
private:
    int assetId;
    bool isConfirmed;

public:
    ConfirmAssetUploadReq() : assetId(0), isConfirmed(false) {}

    void setAssetId(int assetId) {
        this->assetId = assetId;
    }

    void confirmUpload() {
        // Simulate confirmation process
        isConfirmed = true;
        std::cout << "Asset with ID " << assetId << " has been successfully confirmed for upload." << std::endl;
    }

    bool isConfirmed() {
        return isConfirmed;
    }

    int getAssetId() {
        return assetId;
    }
};

int main() {
    ConfirmAssetUploadReq req;
    req.setAssetId(12345);
    req.confirmUpload();
    std::cout << "Asset ID: " << req.getAssetId() << std::endl;
    std::cout << "Confirmed: " << req.isConfirmed() << std::endl;
    return 0;
}
