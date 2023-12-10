#include <string>
#include <l10n_util.h>

std::wstring LocaleWindowCaptionFromPageTitle(const std::wstring& page_title) {
  // Get the text direction for the current locale
  auto text_direction = l10n_util::GetTextDirectionForLocale();

  // Wrap the page title with left-to-right formatting characters if the text direction is right-to-left
  if (text_direction == l10n_util::TextDirection::RIGHT_TO_LEFT) {
    return l10n_util::WrapStringWithLTRFormatting(page_title);
  }

  // Otherwise, return the original page title
  return page_title;
}
