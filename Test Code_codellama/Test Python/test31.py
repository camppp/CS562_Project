import os
from gensim.scripts.glove2word2vec import glove2word2vec
from gensim.models import KeyedVectors
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