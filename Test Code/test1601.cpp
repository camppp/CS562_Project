#include <node.h>
#include <string>

std::string getStringOrEmpty(Local<Object> target, std::string key) {
    Local<String> lkey = String::NewFromUtf8(Isolate::GetCurrent(), key.c_str(), NewStringType::kNormal).ToLocalChecked();
    MaybeLocal<Value> mvalue = Nan::Get(target, lkey);
    if (mvalue.IsEmpty() || mvalue.ToLocalChecked()->IsUndefined()) {
        return "";
    } else {
        String::Utf8Value utf8Value(mvalue.ToLocalChecked()->ToString());
        return std::string(*utf8Value);
    }
}
