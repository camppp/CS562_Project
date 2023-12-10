#include <nan.h>
#include "Elliptic.h"
#include "elliptic-crypto-library.h"  // Replace with the actual elliptic curve cryptography library

class Elliptic : public Nan::ObjectWrap {
public:
    static NAN_MODULE_INIT(Init) {
        v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
        tpl->SetClassName(Nan::New("Elliptic").ToLocalChecked());
        tpl->InstanceTemplate()->SetInternalFieldCount(1);

        Nan::SetPrototypeMethod(tpl, "generateKeyPair", GenerateKeyPair);
        Nan::SetPrototypeMethod(tpl, "sign", Sign);
        Nan::SetPrototypeMethod(tpl, "verify", Verify);

        constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
        Nan::Set(target, Nan::New("Elliptic").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
    }

    static NAN_METHOD(New) {
        if (info.IsConstructCall()) {
            Elliptic* obj = new Elliptic();
            obj->Wrap(info.This());
            info.GetReturnValue().Set(info.This());
        } else {
            const int argc = 0;
            v8::Local<v8::Value> argv[argc] = { };
            v8::Local<v8::Function> cons = Nan::New(constructor());
            info.GetReturnValue().Set(Nan::NewInstance(cons, argc, argv).ToLocalChecked());
        }
    }

    static NAN_METHOD(GenerateKeyPair) {
        Elliptic* obj = ObjectWrap::Unwrap<Elliptic>(info.Holder());
        std::pair<std::string, std::string> keyPair = elliptic_crypto_library::generateKeyPair();
        v8::Local<v8::Object> result = Nan::New<v8::Object>();
        Nan::Set(result, Nan::New("privateKey").ToLocalChecked(), Nan::New(keyPair.first).ToLocalChecked());
        Nan::Set(result, Nan::New("publicKey").ToLocalChecked(), Nan::New(keyPair.second).ToLocalChecked());
        info.GetReturnValue().Set(result);
    }

    static NAN_METHOD(Sign) {
        if (info.Length() < 2 || !info[0]->IsString() || !info[1]->IsString()) {
            return Nan::ThrowTypeError("Invalid arguments. Expected message (string) and privateKey (string).");
        }
        std::string message(*Nan::Utf8String(info[0]));
        std::string privateKey(*Nan::Utf8String(info[1]));
        std::string signature = elliptic_crypto_library::sign(message, privateKey);
        info.GetReturnValue().Set(Nan::New(signature).ToLocalChecked());
    }

    static NAN_METHOD(Verify) {
        if (info.Length() < 3 || !info[0]->IsString() || !info[1]->IsString() || !info[2]->IsString()) {
            return Nan::ThrowTypeError("Invalid arguments. Expected message (string), signature (string), and publicKey (string).");
        }
        std::string message(*Nan::Utf8String(info[0]));
        std::string signature(*Nan::Utf8String(info[1]));
        std::string publicKey(*Nan::Utf8String(info[2]));
        bool isValid = elliptic_crypto_library::verify(message, signature, publicKey);
        info.GetReturnValue().Set(Nan::New(isValid));
    }
};

NAN_MODULE_INIT(Init) {
    Elliptic::Init(target);
}

NODE_MODULE(addon, Init)
