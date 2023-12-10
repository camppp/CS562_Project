template <typename T>
class ErrorClass {
public:
    ErrorClass(T errorCode) : errorCode_(errorCode) {}

    std::string error() {
        switch (errorCode_) {
            case CL_INVALID_COMMAND_QUEUE:
                return "Invalid command queue";
            case CL_INVALID_CONTEXT:
                return "Invalid context";
            case CL_INVALID_DEVICE:
                return "Invalid device";
            case CL_INVALID_VALUE:
                return "Invalid value";
            case CL_INVALID_EVENT:
                return "Invalid event";
            case CL_INVALID_EVENT_WAIT_LIST:
                return "Invalid event wait list";
            case CL_INVALID_GLOBAL_OFFSET:
                return "Invalid global offset";
            case CL_INVALID_MIP_LEVEL:
                return "Invalid mip level";
            case CL_INVALID_BUFFER_SIZE:
                return "Invalid buffer size";
            case CL_INVALID_HOST_PTR:
                return "Invalid host pointer";
            case CL_INVALID_MEM_OBJECT:
                return "Invalid memory object";
            case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR:
                return "Invalid image format descriptor";
            case CL_INVALID_IMAGE_SIZE:
                return "Invalid image size";
            case CL_INVALID_SAMPLER:
                return "Invalid sampler";
            case CL_INVALID_BINARY:
                return "Invalid binary";
            case CL_INVALID_BUILD_OPTIONS:
                return "Invalid build options";
            case CL_INVALID_PROGRAM:
                return "Invalid program";
            case CL_INVALID_PROGRAM_EXECUTABLE:
                return "Invalid program executable";
            case CL_INVALID_KERNEL_NAME:
                return "Invalid kernel name";
            case CL_INVALID_KERNEL_DEFINITION:
                return "Invalid kernel definition";
            case CL_INVALID_KERNEL:
                return "Invalid kernel";
            case CL_INVALID_ARG_INDEX:
                return "Invalid argument index";
            case CL_INVALID_ARG_VALUE:
                return "Invalid argument value";
            case CL_INVALID_ARG_SIZE:
                return "Invalid argument size";
            case CL_INVALID_KERNEL_ARGS:
                return "Invalid kernel arguments";
            case CL_INVALID_WORK_DIMENSION:
                return "Invalid work dimension";
            case CL_INVALID_WORK_GROUP_SIZE:
                return "Invalid work group size";
            case CL_INVALID_WORK_ITEM_SIZE:
                return "Invalid work item size";
            case CL_INVALID_GLOBAL_OFFSET:
                return "Invalid global offset";
            case CL_INVALID_EVENT_WAIT_LIST:
                return "Invalid event wait list";
            case CL_INVALID_EVENT:
                return "Invalid event";
            case CL_INVALID_OPERATION:
                return "Invalid operation";
            case CL_INVALID_GL_OBJECT:
                return "Invalid OpenGL object";
            case CL_INVALID_BUFFER_SIZE:
                return "Invalid buffer size";
            case CL_INVALID_MIP_LEVEL:
                return "Invalid mip level";
            default:
                return "Unknown error";
        }
    }

private:
    T errorCode_;
};
