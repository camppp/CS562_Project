#include <nan.h>

NAN_METHOD(getStringOrEmpty) {
  Local<Object> target = info[0]->ToObject();
  Local<String> key = info[1]->ToString();

  Local<Value> value = target->Get(key);
  if (value->IsUndefined() || value->IsNull()) {
    return Nan::New("").ToLocalChecked();
  }

  return Nan::New(value->ToString()).ToLocalChecked();
}
