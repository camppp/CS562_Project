#include "http/Status.h"
#include <beng-proxy/Headers.hxx>

void processHeaders(Headers& clientToServer, Headers& serverToClient) {
    // Forward all headers from the client to the server, except for the "Host" header
    if (clientToServer.hasHeader("Host")) {
        clientToServer.removeHeader("Host");
    }

    // Forward all headers from the server to the client, except for the "Set-Cookie" header
    if (serverToClient.hasHeader("Set-Cookie")) {
        serverToClient.removeHeader("Set-Cookie");
    }
}
