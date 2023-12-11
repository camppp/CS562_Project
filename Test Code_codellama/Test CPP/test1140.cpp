string simulateButtonPopup(string popupType, object popupInfo) {
  switch (popupType) {
    case "CONFIRM_MENU":
      return "Launch the confirm menu action";
    case "PYTHON_SCREEN":
      return "Launch the Python screen action";
    case "DEAL_CANCELED":
      return "Launch the cancel deal action";
    default:
      return "Invalid popup type";
  }
}
