function extractCodeContent(htmlString) {
  const codeTags = htmlString.match(/<code>(.*?)<\/code>/g);
  const codeContent = codeTags.map(tag => tag.replace(/<code>/g, "").replace(/<\/code>/g, ""));
  return codeContent;
}
