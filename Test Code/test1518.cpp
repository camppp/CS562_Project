#include <QStyle>
#include <QStyleFactory>

const QString g_dark_theme_str = "dark";

QStyle* createStyle() {
  if (theme() == g_dark_theme_str) {
    return QStyleFactory::create("Fusion");
  } else {
    return QStyleFactory::create("Windows");
  }
}
