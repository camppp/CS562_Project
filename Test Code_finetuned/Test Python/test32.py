import os
from gensim.models import Word2Vec
from glove import Corpus, Glove

_GV_TEXT_FILE = 'input_text.txt'
_GV_MODEL_FILE = 'glove_model.txt'
_GV_W2V_MODEL_FILE = 'word2vec_model.txt'

def create_glove_model():
    # Read the content of the text file and preprocess it
    corpus = Corpus()
    with open(_GV_TEXT_FILE, 'r', encoding='utf-8') as file:
        text = file.read()
    corpus.fit(text, window=10)

    # Train the GloVe model and save it
    glove = Glove(no_components=100, learning_rate=0.05)
    glove.fit(corpus.matrix, epochs=30, no_threads=4, verbose=True)
    glove.add_dictionary(corpus.dictionary)
    glove.save(_GV_MODEL_FILE, binary=False)

    # Convert the GloVe model to word2vec format and save it
    glove.save_word2vec_format(_GV_W2V_MODEL_FILE)

    # Load the word2vec model and print the vector representation of the word 'apple'
    model = Word2Vec.load(_GV_W2V_MODEL_FILE)
    print(model.wv['apple'])

if __name__ == '__main__':
    create_glove_model()