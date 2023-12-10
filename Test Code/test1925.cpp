void Pilha::empilhar(int val) {
    if (this->topo == NULL) {
        this->topo = new No(val);
        this->n++;
    } else {
        No *p = this->topo;
        this->topo = new No(val);
        this->topo->setProx(p);
        this->n++;
    }
}
