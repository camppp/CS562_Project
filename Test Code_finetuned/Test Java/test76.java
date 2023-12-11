public void processTravisResponse(JSONObject travisResponse) {
    JSONArray buildArray = (JSONArray) travisResponse.get("builds");
    for (Object build : buildArray) {
        builds.add((JSONObject) build);
    }
}

public boolean hasMorePages(JSONObject travisResponse) {
    JSONObject pagination = (JSONObject) travisResponse.get("@pagination");
    if (pagination!= null) {
        int totalPages = pagination.getInt("total_pages");
        int currentPage = pagination.getInt("current_page");
        return currentPage < totalPages;
    }
    return false;
}