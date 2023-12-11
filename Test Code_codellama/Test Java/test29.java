import http.client

class ErrorResponseHandler:
    def errorResponse(self, statusCode, message):
        if statusCode == 400:
            return http.client.BadRequest(message)
        elif statusCode == 401:
            return http.client.Unauthorized(message)
        elif statusCode == 403:
            return http.client.Forbidden(message)
        elif statusCode == 404:
            return http.client.NotFound(message)
        else:
            return http.client.InternalServerError(message)