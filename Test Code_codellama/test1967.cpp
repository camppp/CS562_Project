string handleRequest(CallType callType) {
    if (!taskService) {
        return "Request failed, index task service not found";
    }

    if (callType != FromAPI) {
        if (!taskService->optimizeIndex()) {
            response().addError("failed to optimize index");
            return "failed to optimize index";
        }
        return "Request processed successfully";
    }

    if (!taskService->optimizeIndex()) {
        response().addError("failed to optimize index");
        return "failed to optimize index";
    }
    return "Request processed successfully";
}
