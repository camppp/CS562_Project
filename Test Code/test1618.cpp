javascript
function extractCodeContent(htmlString) {
  const parser = new DOMParser();
  const doc = parser.parseFromString(htmlString, 'text/html');
  const codeTags = doc.getElementsByTagName('code');
  const codeContent = [];
  
  for (let i = 0; i < codeTags.length; i++) {
    codeContent.push(codeTags[i].innerText);
  }
  
  return codeContent;
}

// Example usage
const htmlString = `<!DOCTYPE html>
<html>
  <body>
    <p>This is a <code>sample</code> HTML <code>string</code>.</p>
  </body>
</html>`;

console.log(extractCodeContent(htmlString)); // Output: ["sample", "string"]
