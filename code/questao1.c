/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int capacidade_resposta = 10;
    int* resposta = (int*)malloc(capacidade_resposta * sizeof(int));
    *returnSize = 0;

    int ultimo_indice[26];
    int tamanho_string = strlen(s);

    for (int i = 0; i < tamanho_string; ++i) {
        ultimo_indice[s[i] - 'a'] = i;
    }

    int inicio_particao = 0;
    int fim_particao_atual = 0;

    for (int i = 0; i < tamanho_string; ++i) {
        if (ultimo_indice[s[i] - 'a'] > fim_particao_atual)
            fim_particao_atual = ultimo_indice[s[i] - 'a'];
        
        if (fim_particao_atual == i) {
            int tamanho_particao = i - inicio_particao + 1;

            if (*returnSize == capacidade_resposta) {
                capacidade_resposta *= 2;
                resposta = (int*)realloc(resposta, capacidade_resposta * sizeof(int));
                if (resposta == NULL) {
                    *returnSize = 0;
                    return NULL;
                }
            }
            resposta[*returnSize] = tamanho_particao;
            (*returnSize)++;

            inicio_particao = i + 1;
        }
    }

    resposta = (int*)realloc(resposta, (*returnSize) * sizeof(int));
    if (resposta == NULL && *returnSize > 0) {
        *returnSize = 0;
        return NULL;
    }

    return resposta;
}