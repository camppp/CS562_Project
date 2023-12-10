#include <stdio.h>
#include <efi.h>

const char* efiStrError(EFI_STATUS status) {
    switch (status) {
        case EFI_SUCCESS:
            return "Success";
        case EFI_LOAD_ERROR:
            return "Load error";
        case EFI_INVALID_PARAMETER:
            return "Invalid parameter";
        case EFI_DEVICE_ERROR:
            return "Device error";
        case EFI_WRITE_PROTECTED:
            return "Write protected";
        case EFI_OUT_OF_RESOURCES:
            return "Out of resources";
        case EFI_VOLUME_CORRUPTED:
            return "Volume corrupted";
        case EFI_VOLUME_FULL:
            return "Volume full";
        case EFI_NO_MEDIA:
            return "No media";
        case EFI_MEDIA_CHANGED:
            return "Media changed";
        case EFI_NOT_FOUND:
            return "Not found";
        case EFI_ACCESS_DENIED:
            return "Access denied";
        case EFI_NO_RESPONSE:
            return "No response";
        case EFI_NO_MAPPING:
            return "No mapping";
        case EFI_TIMEOUT:
            return "Timeout";
        case EFI_NOT_STARTED:
            return "Not started";
        case EFI_ALREADY_STARTED:
            return "Already started";
        case EFI_ABORTED:
            return "Aborted";
        case EFI_ICMP_ERROR:
            return "ICMP error";
        case EFI_TFTP_ERROR:
            return "TFTP error";
        case EFI_PROTOCOL_ERROR:
            return "Protocol error";
        case EFI_INCOMPATIBLE_VERSION:
            return "Incompatible version";
        case EFI_SECURITY_VIOLATION:
            return "Security violation";
        case EFI_CRC_ERROR:
            return "CRC error";
        case EFI_END_OF_MEDIA:
            return "End of media";
        case EFI_END_OF_FILE:
            return "End of file";
        case EFI_INVALID_LANGUAGE:
            return "Invalid language";
        case EFI_COMPROMISED_DATA:
            return "Compromised data";
        default:
            return "Unknown error";
    }
}
