std::string getIDSecure(const ShadowLane& shadowLane, const std::string& additionalParameter) {
    // Generate a unique ID based on the shadow lane's information
    std::string id = shadowLane.getID() + additionalParameter;

    // Use a secure hash function to generate a unique and secure ID
    id = hash(id);

    // Return the generated ID
    return id;
}
