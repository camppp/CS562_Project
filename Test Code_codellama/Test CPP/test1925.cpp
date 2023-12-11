void Pilha::empilhar(int val) {
    No *novo = new No(val);
    novo->setProx(topo);
    topo = novo;
    n++;
}
