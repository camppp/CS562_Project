#include <nan.h>
#include <gemfire.h>

class GemfireWorker : public Nan::AsyncWorker {
 public:
  GemfireWorker(Nan::Callback *callback) : Nan::AsyncWorker(callback) {}

  void Execute() {
    ExecuteGemfireWork();
  }

  void HandleErrorCallback() {
    SetError("GemfireError", "Error executing Gemfire work");
    v8::Local<v8::Value> error = errorObject();
    callback->Call(1, &error);
  }

  virtual void ExecuteGemfireWork() = 0;

  void SetError(const std::string &name, const std::string &message) {
    error_name = name;
    error_message = message;
  }

  v8::Local<v8::Value> errorObject() {
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope scope(isolate);
    v8::Local<v8::Object> error = v8::Object::New(isolate);
    error->Set(v8::String::NewFromUtf8(isolate, "name"), v8::String::NewFromUtf8(isolate, error_name.c_str()));
    error->Set(v8::String::NewFromUtf8(isolate, "message"), v8::String::NewFromUtf8(isolate, error_message.c_str()));
    return error;
  }

 private:
  std::string error_name;
  std::string error_message;
};
