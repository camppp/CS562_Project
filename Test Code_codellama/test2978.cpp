#include <getdns/getdns.h>
#include <getdns/getdns_extra.h>
#include <iostream>
#include <string>

std::string getIPAddress(const std::string& domain) {
    // Initialize the getdns context
    getdns_context* context = getdns_context_create();

    // Set up the DNS query
    getdns_dict* query = getdns_dict_create();
    getdns_dict_set_str(query, "name", domain.c_str());
    getdns_dict_set_int(query, "type", GETDNS_RRTYPE_A);

    // Perform the DNS lookup
    getdns_dict* response = getdns_general_sync(context, query);

    // Check for errors
    if (getdns_dict_get_int(response, "status") != GETDNS_RESPSTATUS_GOOD) {
        std::cerr << "Error: " << getdns_dict_get_str(response, "status_text") << std::endl;
        return "";
    }

    // Extract the IP address from the response
    getdns_list* answers = getdns_dict_get_list(response, "answer");
    getdns_dict* answer = getdns_list_get_dict(answers, 0);
    getdns_dict_get_str(answer, "address", &ip_address);

    // Clean up
    getdns_dict_destroy(query);
    getdns_dict_destroy(response);
    getdns_context_destroy(context);

    return ip_address;
}
