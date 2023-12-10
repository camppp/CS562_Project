#include <AL/al.h>
#include <AL/alc.h>

class OpenALWrapper {
public:
    void getBuffer3f(ALuint buffer, ALenum param, ALfloat *value1, ALfloat *value2, ALfloat *value3) {
        alGetBuffer3f(buffer, param, value1, value2, value3);
    }

    void getBufferfv(ALuint buffer, ALenum param, ALfloat *values) {
        alGetBufferfv(buffer, param, values);
    }

    void getBufferi(ALuint buffer, ALenum param, ALint *value) {
        alGetBufferi(buffer, param, value);
    }

    void getBuffer3i(ALuint buffer, ALenum param, ALint *value1, ALint *value2, ALint *value3) {
        alGetBuffer3i(buffer, param, value1, value2, value3);
    }

    void getBufferiv(ALuint buffer, ALenum param, ALint *values) {
        alGetBufferiv(buffer, param, values);
    }

    ALCcontext* createContext(ALCdevice *device, const ALCint *attrlist) {
        return alcCreateContext(device, attrlist);
    }

    ALCboolean makeContextCurrent(ALCcontext *context) {
        return alcMakeContextCurrent(context);
    }
};
