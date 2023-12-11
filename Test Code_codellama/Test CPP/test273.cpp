public String findPvlKeyword(String groupName) {
    if (translationMap.containsKey(groupName)) {
        return translationMap.get(groupName);
    } else {
        return "Not found";
    }
}
