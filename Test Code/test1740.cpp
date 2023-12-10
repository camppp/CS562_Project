void setDrawColorBasedOnCondition(Color* nc, Filler filler) {
  if (nc != nullptr) {
    Application.renderer()->setDrawColor(*nc);
  } else {
    Application.renderer()->setDrawColor(filler.color2);
  }
}
