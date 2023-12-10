#include <string>
#include <locale_util.h>  // Assuming the necessary header for locale-related functions

std::wstring LocaleWindowCaptionFromPageTitle(const std::wstring& expected_title) {
  std::wstring page_title = WindowCaptionFromPageTitle(expected_title);  // Retrieve the actual page title

  // Assuming g_browser_process->GetApplicationLocale() retrieves the locale
  std::string locale = g_browser_process->GetApplicationLocale();

  // Check the text direction for the given locale
  if (l10n_util::GetTextDirectionForLocale(locale.c_str()) == l10n_util::RIGHT_TO_LEFT) {
    l10n_util::WrapStringWithLTRFormatting(&page_title);  // Wrap the page title with left-to-right formatting characters
  }

  return page_title;  // Return the modified page title based on the text direction
}
