# <h1 align="center">🧬Algoritmo Genético para Ajuste de Reta</h1>
> Projeto desenvolvido para aplicar conceitos de algoritmos geneticos na aproximação de uma reta a um conjunto de pontos. 
## 📌Descrição Geral
> Trabalho proposto na disciplina de Algoritmo e Estrutura de Dados I (AEDSI), pelo professor Michel Pires da Silva. Foi proposto a criacao de um código (em C ou C++)
> e uma documentação detalhada sobre o algoritmo. 

Esse projeto implementa um algoritmo genético para encontrar a melhor reta da forma:
<p align="center">
  <b>y = ax + b</b>
</p>

que melhor se ajusta a um conjunto de pontos fornecidos em um arquivo de entrada ("input.dat").

O problema consiste em minimizar o erro entre os valores reais `y` e os valores estimados `ŷ`, utilizando técnicas inpiradas na evolucao natural.

## 🎯Objetivo
Encontrar os valores de `a` e `b` que minimizam o erro entre

* os dados reais (input)
* a reta gerada pelo algoritmo

## 🖥️Ambiente de criação

* ![C](https://img.shields.io/badge/Linguagem-C-007ACC?style=flat-square&logo=c&logoColor=white)
* ![VS Code](https://img.shields.io/badge/IDE-VS_Code-007ACC?style=flat-square&logo=visual-studio-code&logoColor=white)
* ![Ubuntu](https://img.shields.io/badge/SO-Ubuntu_(WSL)-E95420?style=flat-square&logo=ubuntu&logoColor=white)

Este projeto foi desenvolvido na linguagem C, utilizando o Visual Studio Code como IDE e o ambiente de desenvolvimento WSL Ubuntu 
operando sobre o sistema Windows.

## 📁Estrutura do projeto
<pre> 
📁TrabalhoAquecimentoAEDIS1/
|
├──build/
|
├── include/
|    ├── dados.h
|    ├── erro.h
|    ├── genetica.h
|    ├── populacao.h
|
├──src/
|    ├── dados.c
|    ├── erro.c
|    ├── genetica.c
|    ├── main.c
|    ├── populacao.c
|
├── .gitignore
├── input.dat
├── Makefile
├── output.dat
├── programa
├── readme.md
</pre>

    
## 💡Funções Implementadas
### 1. 📁 populacao.c
### 🔴**Gerar população**🔴
```c
 Individuo* gerarPopulacao(int tamanhoPop);
```
  📌O que faz:

  Aloca dinamicamente memória para armazenar a população.

  ⚙️Funcionamento:
  * cria um vetor de Individuo com tamanho tamanhoPop;
  * cada posição representa uma solução (reta);
 
  🎯Efeito no Algoritmo:
  * cria o "ambiente inicial" onde o algoritmo vai trabalhar;
  * sem isso não existe população;
 
  🔁Retorno:
  *retorna um ponteiro para para o vetor Individuo;
  

### 🔴**Preencher População**🔴
```c
    void preencherPopulacao(Individuo *populacao, int tamanhoPop, float valorMin, float valorMax);
```
  📌O que faz:

  Inicializa os individuos com valores aleatorios

  ⚙️Funcionamento:
  
  Para cada individuo:
  * gera a aleatório;
  * gera b aleatório;
  * valores ficam entre min (-10) e max (10);

  🎯Efeito no Algoritmo:
  * garante uma diversidade inicial;

  🔁Retorno:
  
   Nao retorna nada (void)
 
### 🔴**Liberar População**🔴
```c
    void liberarPopulacao(Individuo *populacao);
```
  📌O que faz:

  Libera a memória alocada para a população.

  ⚙️Funcionamento:
  * usa free() no vetor

  🎯Efeito no Algoritmo:
  * evita vazamento de memória.
 
  🔁Retorno:
  * não retorna nada.
 
### 2. 📁 dados.c
### 🔴**Ler Dados**🔴
```c
    Dados lerDados(const char *nome);
```
  📌O que faz:

  Lê os dados do arquivo de entrada (input.dat).

  ⚙️Funcionamento:
  * abre o arquivo input.dat.
  * Lê:
    * quantidade de pontos.
    * tamanho da população.
    * número de gerações.
  * Aloca memória para:
    * vetor x
    * vetor y
  * Armazena os valores
 
  🎯Efeito no Algoritmo:

  * Define todo o problema do algoritmo, com ele o algoritmo tem o que otimizar
 
  🔁Retorno:
  * Retorna uma struct Dados contendo:
    * qtdPontos
    * tamanhoPop
    * gerações
    * valorX
    * valorY

### 3. 📁 erro.c
### 🔴**Calcular Erro**🔴
```c
    float calcularErro(Individuo ind, int qtdPontos, float *x, float *y);
```
  📌O que faz:

  Calcula o erro de um individuo.

  ⚙️Funcionamento:

  Para cada ponto:
  1. Calcula
```c
       yPrevisto = a * x + b;
```
 
  2. Calcula
```c
       erro = yReal - yPrevisto
```
  3. Soma
```c
       erro²
```
  4. Divide
```c
       erroTotal/qtdPontos
```

  Foi usada a fórmula MSE (Erro quadrático médio)

  $$
  MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
  $$
 
  🎯Efeito no Algoritmo:
  * mede o quão boa é a solução
  * serve de base para o fitness

  🔁Retorno:
  
  * retorna um float (erro médio).

### 🔴**Calcular Fitness**🔴
```c
    float calcularFitness(Individuo ind, int qtdPontos, float *x, float *y);
```
  📌O que faz:

  Convete o erro em fitness.

  ⚙️Funcionamento:
  <pre>
    fitness = 1 / (1 + erro)
  </pre>

  🎯Efeito no Algoritmo:
  * permite comparar individuos
  * quanto melhor -> maior o fitness
 
  🔁Retorno:

  *retorna um float(fitness)

### 4. 📁genetica.c
### 🔴**Ordenar Populacao**🔴
```c
    void ordenarPopulacao(Individuo *populacao, int tamanhoPop, int qtdPontos, float *x, float *y);
```
  📌O que faz:

  Ordena a população pelo valor do fitness.

  ⚙️Funcionamento:
  * é utilizado bubble sort para a ordenacao
  * compara fitness dos individuos
  * coloca o melhor no ínicio
 
  🎯Efeito no Algoritmo:
  * facilita a seleção
  * garante que os melhores estejam no topo, para que a proxima geração os receba.
 
  🔁Retorno:
  * nao retorna nada (void).

 ### 🔴**Crossover**🔴
```c
    Individuo crossover(Individuo pai1, Individuo pai2);
```
  📌O que faz:

   Gera um filho combinando dois pais.

  ⚙️Funcionamento:
  <pre>
    filho.a = pai1.a;
    filho.b = pai2.b;
  </pre>

  exemplo
```c
    pai1: a = 2, b = 1
    pai2: a = 3, b = 0

    filho: a = 2, b = 0
```
  🎯Efeito no Algoritmo:
  * combina caracteristicas boas
 
  🔁Retorno:
  * retorna um novo individuo.

 ### 🔴**Mutação**🔴
```c
    void mutacao(Individuo *ind);
```
  📌O que faz:

  Aplica uma alteração aleatória.

  ⚙️Funcionamento:

  1. Gera
     <pre>
       delta ∈ [-1, +1]
     </pre>
  2. Decide
     <pre>
       mudar a ou b
     </pre>
  3. Aplica
     <pre>
       a += delta ou b += delta
     </pre>
     Observação: nesse algoritmo a mutação apenas muda a ou b, nunca os dois juntos.

     🎯Efeito no Algoritmo:
     * Traz diversidade
     * evita estagnação
    
     🔁Retorno:
     * nao retorna nada (void).
     * modifica o individuo.

### 🔴**Salvar Resultados**🔴
```c
    void salvarResultados(const char *nome, Individuo melhor, float fitness,float erro );
```
  📌O que faz:

  Salva os resultado em um arquivo (output.dat)

  ⚙️Funcionamento:
   * Abre o arquivo em modo append (a)
   * Escreve
     * fitness
     * erro
     * a e b
   * Fecha o arquivo
 
  🎯Efeito no Algoritmo:
  * permite acompanhar a evolução
  * guarda o histórico
 
  🔁Retorno:
  * nao retorna nada.


### 5. 📁Main.c

### 🔴**Main**🔴
```c
  int main();
```
  📌O que faz:

  Controla TODO o algoritmo.

  ⚙️Funcionamento:

  1. Inicialização
```c
srand(42);
```

  * define aleatoriedade
  * com essa seed, sempre vai ser gerado uma mesma sequência, com os mesmos números e os mesmos resultados.

  2. Limpeza do arquivo de saida
```c
       fopen("output.dat", "w");
```
  3. Lê dados
```c
       Dados d = lerDados("input.dat");
```
  4. Criação da População
```c
      Individuo *populacao = gerarPopulacao(d.tamanhoPop);
      preencherPopulacao(populacao, d.tamanhoPop, -10, 10);
```
  5. Loop de gerações
```c
       for(int g = 0; g < d.geracoes; g++){
```

### DENTRO DO LOOP:
  * Ordena População:
```c
          ordenarPopulacao(populacao, d.tamanhoPop, d.qtdPontos, d.valorX, d.valorY);
```
  * Seleciona o melhor:
```c
          Individuo melhor = populacao[0];
```
  * Calcula o erro e o fitness
```c
          calcularFitness(...)
          calcularErro(...)
```
  * Divisão da População
```c
          int metade = d.tamanhoPop / 2;
          int qtdNovos = d.tamanhoPop - metade;
```

  Divide a população em [melhores | piores]
  * Definição das Quantidades
```c
          int qtdMutacao = qtdNovos * 0.6;
          int qtdCrossover = qtdNovos - qtdMutacao;
```
  📌O que faz:

  É definido que em 60% será feito mutação e em 30% será feito comutação.
  * Crossover
```c
          for(int i = 0; i < qtdCrossover; i++){
```
  📌O que faz:

   É selecionado dois pais aleatórios, onde é gerado um filho e esse filho é substituido por um dos piores.
  * Mutação
```c
          for(int i =0; i < qtdMutacao; i++){
```
  📌O que faz:

  É selecionado um dos bons, é feito uma cópia, nessa cópia acontece a mutação. Essa cópia mutada é substituida por um dos piores.
  * Reordenação
```c
          ordenarPopulacao(...)
```
  * Atualiza o melhor
```c
          melhor = populacao[0];
```
  * Salvamento dos resultados
```c
          salvarResultados(...)
```

  6. Liberação de Memória
```c
       liberarPopulacao(populacao);
```

## 📊Análise Assintótica

| Função                | Complexidade     | Descrição |
|----------------------|------------------|----------|
| `lerDados`           | O(n)             | Lê os pontos do arquivo de entrada |
| `gerarPopulacao`     | O(1)             | Aloca memória para a população |
| `preencherPopulacao` | O(m)             | Inicializa os indivíduos da população |
| `liberarPopulacao`   | O(1)             | Libera a memória alocada |
| `calcularErro`       | O(n)             | Calcula o erro percorrendo todos os pontos |
| `calcularFitness`    | O(n)             | Depende do cálculo do erro |
| `ordenarPopulacao`   | O(m² x n)        | Ordena usando Bubble Sort + cálculo de fitness |
| `crossover`          | O(1)             | Combina dois indivíduos |
| `mutacao`            | O(1)             | Modifica um indivíduo |
| `salvarResultados`   | O(1)             | Escreve os resultados no arquivo |
---

## 📊 Complexidade do Algoritmo

A complexidade total do algoritmo é dada por:

O(G x m² x n)

Onde:
- G é o número de gerações
- m é o tamanho da população
- n é a quantidade de pontos

O principal custo computacional está na ordenação da população, que utiliza o algoritmo Bubble Sort, resultando em O(m²). Como o cálculo de fitness depende da avaliação de todos os pontos (O(n)), a complexidade da ordenação torna-se O(m² x n), sendo executada a cada geração.

Dessa forma, o desempenho do algoritmo é fortemente influenciado pelo tamanho da população e pela quantidade de pontos analisados.

## 🧪Casos de Teste

Para validar a funcionalidade do algoritmo, foi utilizado um conjunto de pontos gerados a partir da reta: 
<p align="center"> <b>y = x + 1</b> </p>

## 📥Entrada (input.dat)
<pre>
  10 5 1000
  1 2
  2 3
  3 4
  4 5
  5 6
  6 7
  7 8
  8 9
  9 10
  10 11
</pre>
## 📥Saída (output.dat)
<pre>
  fitness: 0.9902 | erro: 0.01 | a: 1.02 | b: 0.81
</pre>

## 📊Análise
O algoritmo encontrou valores muito próximos da reta original:
 * Valor esperado: a = 1, b = 1
 * Valor encontrado: a = 1.02, b = 0.81

Isso demonstra que o algoritmo conseguiu convergir corretamente para a solução.

## 👩🏽‍🔬Ambiente de Teste
O projeto foi desenvolvido e testado com as seguintes configurações:
- 🖥️ Sistema Operacional: Ubuntu 24.04 (executado via WSL no Windows 11)
- ⚙️ Compilador: GCC (Ubuntu 13.3.0) versão 13.3.0
- 💻 Linguagem: C

**Hardware**

- Notebook: Acer Nitro 5 AN515-54
- CPU: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz (2.40 GHz)
- RAM: 8,00 GB

## 🛠️Modo de compilação
> [!WARNING]
> Antes de compilar, certifique-se de que você possui os seguintes pacotes instalados no Ubuntu (via WSL):
<pre>
sudo apt update
sudo apt install build-essential
</pre>

Para a compilação, será usado o clone do repositório:
<pre>
  git clone (https://github.com/lauraglopez6/TrabalhoAquecimentoAEDIS1.git)
</pre>

Logo depois, usar o comando:
<pre>
  cd TrabalhoAquecimentoAEDIS1
</pre>

Para limpar, compilar e rodar, execute os seguintes comandos:
<pre>
  make clean
</pre>
<pre>
  make
</pre>
<pre>
  make run
</pre>

Dessa forma, você garante que o projeto será limpo, compilado e executado corretamente.


## 📄Considerações Finais
O desenvolvimento deste projeto foi uma experiência importante para a compreensão prática de algoritmos genéticos e manipulação de dados em linguagem C.

Durante a implementação, uma das principais dificuldades encontradas foi a interpretação do que era pra ser feito no trabalho, especialmente na compreensão
da lógica completa do algoritmo genético e da forma como as etapas deveriam ser organizadas. No entanto, com o avanço do desenvolvimento, foi possível
assimilar melhor a estrutura do problema e ganhar confiança na implementação.

Além disso, ferramentas de apoio tiveram um papel fundamental no aprendizado. O uso de inteligência artificial e vídeos no YouTube auxiliaram
bastante na compreensão de conceitos importantes, como:
 * Geração de números pseudoaleatorios (rand e srand)
 * Algoritmos de ordenação (bubble sort)
Esses rescursos ajudaram bastante para o entendimento desses conceitos.

## 📚 Referências
Este projeto faz uso das bibliotecas padrão da linguagem C, que fornecem funcionalidades essenciais para o funcionamento do algoritmo genético.

As principais bibliotecas utilizadas foram:
  * <stdio.h> → operações de entrada e saída (printf, fopen, fprintf)
  * <stdlib.h> → alocação de memória e geração de números aleatórios (malloc, free, rand, srand)
  * <time.h> → controle de seed para geração de números pseudoaleatórios (time)

    Essas bibliotecas fazem parte da Standard Library da linguagem C, sendo fundamentais para:
    * Manipulação de arquivos
    * Controle de memória dinâmica
    * Geração de números aleatorios
    * Entrada e saída de dados

## 📌Conclusão

Em resumo, o algoritmo genético utilizado se mostrou eficiente para o problema proposto, conseguindo aproximar uma reta a partir de um conjunto de pontos ao longo das gerações. No entanto, por ser um método estocástico, os resultados podem variar entre diferentes execuções e nem sempre chegam a uma solução ótima exata, mas sim a uma aproximação satisfatória.

Durante o desenvolvimento, também ficou evidente que algumas escolhas na implementação — como a taxa de mutação, o método de crossover e o tamanho da população — têm impacto direto tanto na qualidade dos resultados quanto na velocidade de convergência. Isso abre espaço para melhorias futuras, seja ajustando esses parâmetros ou até explorando outras técnicas de otimização para comparação.

Além disso, o projeto se mostra bastante útil do ponto de vista didático, especialmente para estudantes de programação. Ele permite praticar conceitos importantes como manipulação de ponteiros, alocação dinâmica de memória, organização modular em C, leitura e escrita de arquivos, além de proporcionar uma aplicação prática de algoritmos inspirados na evolução natural.

Por fim, o desenvolvimento deste trabalho contribuiu para consolidar conhecimentos em lógica algorítmica, uso de funções, modularização e estruturas de dados básicas, além de proporcionar uma compreensão mais concreta sobre o funcionamento e as limitações dos algoritmos genéticos em problemas de regressão linear.

## 💭Créditos

Agradeço o professor Michel Pires Silva por fornecer o Makefile que facilitou na execução e compilação do trabalho e tambem aos meus amigos de turma que me ajudaram na compreensão do projeto.
       
## 📨Contato
* Email: [lauragoncalves20166@gmail.com]
* instagram: [https://www.instagram.com/lauragoncalves.lopes?igsh=MTFreDVkaW04NTZqNg==]
* GitHub: [https://github.com/lauraglopez6]
  
  

        
      
     




  
    
     
     


  
 
  

  
  

  

  
 
  

  

  
  
