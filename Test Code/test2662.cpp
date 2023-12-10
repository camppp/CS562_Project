python
def getErrorDescription(error_code: int) -> str:
    error_map = {
        0: "PPMACcontrolNoError",
        -230: "PPMACcontrolNoSSHDriverSet",
        -102: "PPMACcontrolSSHDriverError",
        -104: "PPMACcontrolSSHDriverErrorNoconn",
        -103: "PPMACcontrolSSHDriverErrorNobytes",
        -112: "PPMACcontrolSSHDriverErrorReadTimeout",
        -113: "PPMACcontrolSSHDriverErrorWriteTimeout",
        -231: "PPMACcontrolPMACUnexpectedReplyError",
        -239: "PPMACcontrolSemaphoreTimeoutError",
        -240: "PPMACcontrolSemaphoreError",
        -241: "PPMACcontrolSemaphoreReleaseError"
    }
    return error_map.get(error_code, "Unknown error code")
