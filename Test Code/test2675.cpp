public String appendPostmodifier(String word, String postmodifier) {
    if (WordConstants.isTensedCopulaTypeVerb(word)) {
        return word + postmodifier;
    } else {
        return word;
    }
}
