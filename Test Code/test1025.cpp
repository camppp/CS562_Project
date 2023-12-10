// Creates a new tab in a browser and initializes its render frame host
content::WebContents* CreateTab() {
  // Assuming the existence of a browser object
  content::WebContents* tab = browser->AddTab();  // AddTab() creates a new tab in the browser
  content::RenderFrameHostTester::For(tab->GetMainFrame())->InitializeRenderFrameIfNeeded();
  return tab;
}

// Retrieves the mock render process host associated with the given web contents
content::MockRenderProcessHost* GetMockRenderProcessHost(content::WebContents* contents) {
  return static_cast<content::MockRenderProcessHost*>(
      contents->GetRenderViewHost()->GetProcess());
}
