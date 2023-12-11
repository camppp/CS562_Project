#include "OpenAPIUserApi.h"
#include "OpenAPIUserApiGetUserByNameResponse.h"

void OpenAPIUserApi::GetUserByNameResponse::SetHttpResponseCode(int InHttpResponseCode)
{
    // Set the HTTP response code based on the input parameter
    switch (InHttpResponseCode)
    {
        case 200:
            // Set the HTTP response code to 200 (OK)
            HttpResponseCode = 200;
            break;
        case 400:
            // Set the HTTP response code to 400 (Bad Request)
            HttpResponseCode = 400;
            break;
        case 404:
            // Set the HTTP response code to 404 (Not Found)
            HttpResponseCode = 404;
            break;
        default:
            // Set the HTTP response code to 500 (Internal Server Error)
            HttpResponseCode = 500;
            break;
    }
}
