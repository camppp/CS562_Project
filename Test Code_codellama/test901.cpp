bool modelExists(const std::vector<std::string>& models, const std::string& modelToCheck) {
    return std::find(models.begin(), models.end(), modelToCheck) != models.end();
}
