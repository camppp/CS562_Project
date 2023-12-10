#include <AL/al.h>
#include <AL/alc.h>

class OpenALWrapper {
public:
    // Constructor
    OpenALWrapper(ALCdevice* device) {
        this->device = device;
    }

    // Destructor
    ~OpenALWrapper() {
        alcMakeContextCurrent(NULL);
    }

    // Get buffer 3f
    void getBuffer3f(ALuint buffer, ALenum param, ALfloat* values) {
        alGetBuffer3f(buffer, param, values);
    }

    // Get buffer fv
    void getBufferfv(ALuint buffer, ALenum param, ALfloat* values) {
        alGetBufferfv(buffer, param, values);
    }

    // Get buffer i
    void getBufferi(ALuint buffer, ALenum param, ALint* value) {
        alGetBufferi(buffer, param, value);
    }

    // Get buffer 3i
    void getBuffer3i(ALuint buffer, ALenum param, ALint* values) {
        alGetBuffer3i(buffer, param, values);
    }

    // Get buffer iv
    void getBufferiv(ALuint buffer, ALenum param, ALint* values) {
        alGetBufferiv(buffer, param, values);
    }

    // Create context
    ALCcontext* createContext(ALCdevice* device, ALCint* attributes) {
        return alcCreateContext(device, attributes);
    }

    // Make context current
    bool makeContextCurrent(ALCcontext* context) {
        return alcMakeContextCurrent(context);
    }

private:
    ALCdevice* device;
};
