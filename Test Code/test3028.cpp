#include <nan.h>
#include <string>

class GemfireWorker : public Nan::AsyncWorker {
public:
  explicit GemfireWorker(Nan::Callback * callback) :
    Nan::AsyncWorker(callback),
    errorName() {}

  void Execute() {
    try {
      ExecuteGemfireWork();
    } catch (const std::exception& e) {
      SetError("GemfireError", e.what());
      HandleErrorCallback();
    }
  }

  virtual void ExecuteGemfireWork() = 0;

  void HandleErrorCallback() {
    v8::Local<v8::Value> argv[] = { errorObject() };
    callback->Call(1, argv, async_resource);
  }

  void SetError(const char * name, const char * message) {
    errorName = name;
    SetErrorMessage(message);
  }

protected:
  v8::Local<v8::Value> errorObject() {
    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    Nan::Set(obj, Nan::New("name").ToLocalChecked(), Nan::New(errorName).ToLocalChecked());
    Nan::Set(obj, Nan::New("message").ToLocalChecked(), Nan::New(ErrorMessage()).ToLocalChecked());
    return obj;
  }

  std::string errorName;
};
