int minNumberOperations(int* alvo, int tamanhoAlvo) {
    if (tamanhoAlvo == 0) return 0;

    int operacoes = alvo[0];

    for (int i = 1; i < tamanhoAlvo; ++i) {
        if (alvo[i] > alvo[i - 1]) operacoes += alvo[i] - alvo[i - 1];
    }

    return operacoes;
}