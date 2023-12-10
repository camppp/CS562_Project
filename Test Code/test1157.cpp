#include <node.h>
#include <nan.h>
#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/obj_mac.h>

using namespace v8;

class Elliptic : public Nan::ObjectWrap {
 public:
  static void Initialize(v8::Local<v8::Object> exports) {
    Nan::HandleScope scope;

    // Prepare the constructor template
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Elliptic").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Prototype methods
    Nan::SetPrototypeMethod(tpl, "generateKeyPair", GenerateKeyPair);
    Nan::SetPrototypeMethod(tpl, "sign", Sign);
    Nan::SetPrototypeMethod(tpl, "verify", Verify);

    // Create the constructor function
    Local<Function> ctor = Nan::GetFunction(tpl).ToLocalChecked();

    // Export the constructor
    exports->Set(Nan::New("Elliptic").ToLocalChecked(), ctor);
  }

 private:
  static NAN_METHOD(New) {
    Elliptic* obj = new Elliptic();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  }

  static NAN_METHOD(GenerateKeyPair) {
    Elliptic* obj = ObjectWrap::Unwrap<Elliptic>(info.This());

    // Generate a new key pair
    EC_KEY* key = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
    if (!key) {
      Nan::ThrowError("Failed to generate key pair");
      return;
    }

    // Extract the private and public keys
    const BIGNUM* privateKey = EC_KEY_get0_private_key(key);
    const EC_POINT* publicKey = EC_KEY_get0_public_key(key);

    // Convert the private key to a string
    char privateKeyStr[100];
    BN_bn2hex(privateKey, privateKeyStr);

    // Convert the public key to a string
    char publicKeyStr[100];
    EC_POINT_point2hex(EC_KEY_get0_group(key), publicKey, POINT_CONVERSION_COMPRESSED, publicKeyStr, 100, NULL);

    // Return the private and public keys as strings
    info.GetReturnValue().Set(Nan::New<v8::String>(privateKeyStr).ToLocalChecked());
    info.GetReturnValue().Set(Nan::New<v8::String>(publicKeyStr).ToLocalChecked());
  }

  static NAN_METHOD(Sign) {
    Elliptic* obj = ObjectWrap::Unwrap<Elliptic>(info.This());

    // Extract the message and private key from the arguments
    const char* message = info[0]->ToString();
    const char* privateKey = info[1]->ToString();

    // Convert the private key to a BIGNUM
    BIGNUM* privateKeyBN = BN_new();
    BN_hex2bn(&privateKeyBN, privateKey);

    // Generate the signature
    EC_KEY* key = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
    if (!key) {
      Nan::ThrowError("Failed to generate key pair");
      return;
    }
    EC_KEY_set_private_key(key, privateKeyBN);
    const BIGNUM* signature = EC_KEY_sign(key, (unsigned char*)message, strlen(message), NULL);

    // Convert the signature to a string
    char signatureStr[100];
    BN_bn2hex(signature, signatureStr);

    // Return the signature as a string
    info.GetReturnValue().Set(Nan::New<v8::String>(signatureStr).ToLocalChecked());
  }

  static NAN_METHOD(Verify) {
    Elliptic* obj = ObjectWrap::Unwrap<Elliptic>(info.This());

    // Extract the message, signature, and public key from the arguments
    const char* message = info[0]->ToString();
    const char* signature = info[1]->ToString();
    const char* publicKey = info[2]->ToString();

    // Convert the public key to a BIGNUM
    BIGNUM* publicKeyBN = BN_new();
    BN_hex2bn(&publicKeyBN, publicKey);

    // Generate the signature
    EC_KEY* key = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
    if (!key) {
      Nan::ThrowError("Failed to generate key pair");
      return;
    }
    EC_KEY_set_public_key(key, publicKeyBN);
    const BIGNUM* signatureBN = BN_new();
    BN_hex2bn(&signatureBN, signature);
    EC_KEY_verify(key, (unsigned char*)message, strlen(message), signatureBN);

    // Return true if the signature is valid, otherwise false
    info.GetReturnValue().Set(Nan::New<v8::Boolean>(EC_KEY_verify(key, (unsigned char*)message, strlen(message), signatureBN)));
  }
};

NODE_MODULE(elliptic, Elliptic::Initialize)
