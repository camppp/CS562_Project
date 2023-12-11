class JavascriptSIMDUint8x16 {
  private:
    uint8_t value;

  public:
    JavascriptSIMDUint8x16(uint8_t value) : value(value) {}

    static JavascriptSIMDUint8x16 New(uint8_t value, RequestContext* context) {
      return JavascriptSIMDUint8x16(value);
    }

    string GetFullBuiltinName(string name, Buffer* buffer) {
      return "SIMD.Uint8x16." + name;
    }

    JavascriptSIMDUint8x16 Copy(RequestContext* context) {
      return JavascriptSIMDUint8x16(value);
    }
};
