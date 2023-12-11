#include <aws/crt/JsonObject.h>
#include <string>

void ErrorResponse::SerializeToObject(Aws::Crt::JsonObject &object) const
{
    object.WithInteger("errorCode", errorCode);
    object.WithString("errorMessage", errorMessage);
}
