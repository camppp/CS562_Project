#include <getdns/getdns.h>
#include <getdns/getdns_extra.h>
#include <arpa/inet.h>
#include <iostream>

std::string getIPAddress(const std::string& domain) {
    getdns_context *context = NULL;
    getdns_return_t ret;
    getdns_dict *response = NULL;
    getdns_list *replies_tree = NULL;
    getdns_list *just_address_answers = NULL;
    size_t i;
    char *ip_address = NULL;

    ret = getdns_context_create(&context, 1);
    if (ret != GETDNS_RETURN_GOOD) {
        std::cerr << "Error creating context: " << getdns_get_errorstr_by_id(ret) << std::endl;
        return "";
    }

    ret = getdns_address(context, domain.c_str(), NULL, NULL, &response, NULL);
    if (ret != GETDNS_RETURN_GOOD) {
        std::cerr << "Error looking up address: " << getdns_get_errorstr_by_id(ret) << std::endl;
        getdns_context_destroy(context);
        return "";
    }

    ret = getdns_dict_get_list(response, "just_address_answers", &just_address_answers);
    if (ret != GETDNS_RETURN_GOOD) {
        std::cerr << "Error getting just_address_answers: " << getdns_get_errorstr_by_id(ret) << std::endl;
        getdns_context_destroy(context);
        return "";
    }

    size_t answer_count;
    ret = getdns_list_get_length(just_address_answers, &answer_count);
    if (ret != GETDNS_RETURN_GOOD) {
        std::cerr << "Error getting answer count: " << getdns_get_errorstr_by_id(ret) << std::endl;
        getdns_context_destroy(context);
        return "";
    }

    if (answer_count == 0) {
        std::cerr << "No address found for domain: " << domain << std::endl;
        getdns_context_destroy(context);
        return "";
    }

    for (i = 0; i < answer_count; i++) {
        ret = getdns_list_get_string(just_address_answers, i, &ip_address);
        if (ret != GETDNS_RETURN_GOOD) {
            std::cerr << "Error getting IP address: " << getdns_get_errorstr_by_id(ret) << std::endl;
            getdns_context_destroy(context);
            return "";
        }
        std::string ip_str(ip_address);
        free(ip_address);
        getdns_context_destroy(context);
        return ip_str;
    }

    getdns_context_destroy(context);
    return "";
}
