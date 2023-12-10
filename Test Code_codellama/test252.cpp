class AAssociateRQ {
public:
    AAssociateRQ() {}
    AAssociateRQ(const std::string& calledApplicationTitle, const std::string& callingApplicationTitle) {
        setCalledApplicationTitle(calledApplicationTitle);
        setCallingApplicationTitle(callingApplicationTitle);
    }

    void setApplicationContext(const std::string& applicationContext) {
        this->applicationContext = applicationContext;
    }

    void setPresentationContexts(const std::vector<PresentationContext>& presentationContexts) {
        this->presentationContexts = presentationContexts;
    }

    void setUserInformation(const std::vector<UserInformation>& userInformation) {
        this->userInformation = userInformation;
    }

private:
    std::string calledApplicationTitle;
    std::string callingApplicationTitle;
    std::string applicationContext;
    std::vector<PresentationContext> presentationContexts;
    std::vector<UserInformation> userInformation;
};
