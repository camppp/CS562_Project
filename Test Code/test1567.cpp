java
for (int i = 0; i < conditions.length; i++) {
  if (/* condition for overlap */) {
    // Handle overlap condition
  } else if (/* condition for offset */) {
    // Handle offset condition
  } else {
    // No overlap, offset OK
    found = true;
    break;
  }
}
