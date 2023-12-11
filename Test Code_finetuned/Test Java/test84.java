public class TravisCIAPIProcessor {
    private List<JSONObject> builds = new ArrayList<>();

    public void processTravisResponse(JSONObject travisResponse) {
        JSONArray buildArray = travisResponse.getJSONArray("builds");
        for (int i = 0; i < buildArray.length(); i++) {
            builds.add(buildArray.getJSONObject(i));
        }
    }

    public List<JSONObject> getBuilds() {
        return builds;
    }

    public boolean hasMorePages(JSONObject travisResponse) {
        JSONObject pagination = travisResponse.getJSONObject("@pagination");
        return pagination.getInt("next")!= null;
    }
}