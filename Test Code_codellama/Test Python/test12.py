import sacremoses
from textblob import text_normalizer

class TextProcessor:
    LANG_WITHOUT_ACCENT = ["en", "es", "fr"]

    def __init__(self, lang: str):
        self.lang = lang
        self.moses = sacremoses.MosesTokenizer(lang)
        self.rm_accent = lang in self.LANG_WITHOUT_ACCENT
        self.ready = True

    def do(self, text: str):
        tokens = self.moses.tokenize(text)
        if not self.rm_accent:
            for i, token in enumerate(tokens):
                tokens[i] = token.lower()
        else:
            tokens = [token.lower() for token in tokens]
        normalized_text = ' '.join(tokens)
        text_normalizer.normalize(normalized_text, accent=self.rm_accent, case=False, numbers=False, punct=True)
        return normalized_text