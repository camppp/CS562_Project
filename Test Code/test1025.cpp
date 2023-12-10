#include "content/public/test/browser_test_utils.h"
#include "content/public/test/mock_render_process_host.h"

// Creates a new tab in a browser and initializes its render frame host
content::WebContents* CreateTab() {
  // Create a new tab
  content::WebContents* contents = content::WebContents::Create(
      content::WebContents::CreateParams(browser_context()));

  // Initialize the render frame host
  content::RenderFrameHost* render_frame_host = contents->GetMainFrame();
  render_frame_host->InitializeRenderFrameIfNeeded();

  // Return the created tab
  return contents;
}

// Retrieves the mock render process host associated with the given web contents
content::MockRenderProcessHost* GetMockRenderProcessHost(content::WebContents* contents) {
  // Get the render process host associated with the given web contents
  content::RenderProcessHost* render_process_host = contents->GetRenderProcessHost();

  // Check if the render process host is a mock
  if (render_process_host->IsMock()) {
    // Return the mock render process host
    return static_cast<content::MockRenderProcessHost*>(render_process_host);
  }

  // Return nullptr if the render process host is not a mock
  return nullptr;
}
