java
public class TranslationProcessor {
  private Map<String, String> translationMap;

  // Constructor initializes the translation map
  public TranslationProcessor(Map<String, String> translationMap) {
    this.translationMap = translationMap;
  }

  /**
   * Uses the translation file group name to find the input label's PvlKeyword
   * @param groupName the group name from the translation file
   * @return the input label's PvlKeyword or "Not found" if the group name is not found
   */
  public String findPvlKeyword(String groupName) {
    return translationMap.getOrDefault(groupName, "Not found");
  }
}
