# 🧬Algoritmo Genético para Ajuste de Reta
> Projeto desenvolvido para aplicar conceitos de algoritmos geneticos na aproximação de uma reta a um conjunto de pontos. 
## 📌Descrição Geral
> Trabalho proposto na disciplina de Algoritmo e Estrutura de Dados I (AEDSI), pelo professor Michel Pires da Silva. Foi proposto a criacao de um código (em C ou C++)
> e uma documentação detalhada sobre o algoritmo. 

Esse projeto implementa um algoritmo genético para encontrar a melhor reta da forma:
<p align="center">
  <b>y = ax + b</b>
</p>

que melhor se ajusta a um conjunto de pontos fornecidos em um arquivo de entrada ("input.dat").

O problema consiste em minimizar o erro entre os valores reais {y} e os valores estimados {ŷ}, utilizando técnicas inpiradas na evolucao natural.

## 🎯Objetivo
Encontrar os valores de {a} e {b} que minimizam o erro entre

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
📁 projeto/
│
├── main.c                        #controle do algoritmo
├── dados.c / dados.h             #leitura dos dados
├── populacao.c / populacao.h     #criação da população
├── erro.c / erro.h               #cálculo do erro e fitness
├── genetica.c / genetica.h       #operadores genéticos
├── input.dat                     #dados de entrada
└── output.dat                    #resultados
</pre>

    
## 💡Implementação
### Funções Implementadas:
#### 1. 📁 populacao.c
* 🔴**Gerar população**🔴
  <pre>
    Individuo* gerarPopulacao(int tamanhoPop);
  </pre>
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
  

* 🔴**Preencher População**🔴
  <pre>
    void preencherPopulacao(Individuo *populacao, int tamanhoPop, float valorMin, float valorMax);
  </pre>
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
  * Nao retorna nada (void)
 
* 🔴**Liberar População**🔴
  <pre>
    void liberarPopulacao(Individuo *populacao);
  </pre>
  📌O que faz:

  Libera a memória alocada para a população.

  ⚙️Funcionamento:
  * usa free() no vetor

  🎯Efeito no Algoritmo:
  * evita vazamento de memória.
 
  🔁Retorno:
  * não retorna nada.
 
#### 2. 📁 dados.c
* 🔴**Ler Dados**🔴
  <pre>
    Dados lerDados(const char *nome);
  </pre>
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

#### 3. 📁 erro.c
* 🔴**Calcular Erro**🔴
  <pre>
    float calcularErro(Individuo ind, int qtdPontos, float *x, float *y);
  </pre>
  📌O que faz:

  Calcula o erro de um individuo.

  ⚙️Funcionamento:

  Para cada ponto:
  1. Calcula
     <pre>
       yPrevisto = a * x + b;
     </pre>
 
  2. Calcula
     <pre>
       erro = yReal - yPrevisto
     </pre>
  3. Soma
     <pre>
       erro²
     </pre>
  4. Divide
     <pre>
       erroTotal/qtdPontos
     </pre>
     Foi usada a fórmula MSE (Erro quadrático médio)

  $$
  MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
  $$
 
  🎯Efeito no Algoritmo:
  * mede o quão boa é a solução
  * serve de base para o fitness

  🔁Retorno:
  
  * retorna um float (erro médio).

* 🔴**Calcular Fitness**🔴
  <pre>
    float calcularFitness(Individuo ind, int qtdPontos, float *x, float *y);
  </pre>
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

#### 4. 📁genetica.c

* 🔴**Ordenar Populacao**🔴
  <pre>
    void ordenarPopulacao(Individuo *populacao, int tamanhoPop, int qtdPontos, float *x, float *y);
  </pre> 
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

* 🔴**Crossover**🔴
  <pre>
    Individuo crossover(Individuo pai1, Individuo pai2);
  </pre>
  📌O que faz:

   Gera um filho combinando dois pais.

  ⚙️Funcionamento:
  <pre>
    filho.a = pai1.a;
    filho.b = pai2.b;
  </pre>

  exemplo
  <pre>
    pai1: a = 2, b = 1
    pai2: a = 3, b = 0

    filho: a = 2, b = 0
  </pre>
  🎯Efeito no Algoritmo:
  * combina caracteristicas boas
 
  🔁Retorno:
  * retorna um novo individuo.

* 🔴**Mutação**🔴
  <pre>
    void mutacao(Individuo *ind);
  </pre>
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

* 🔴**Salvar Resultados**🔴
  <pre>
    void salvarResultados(const char *nome, Individuo melhor, float fitness,float erro );
  </pre>
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


#### 5. 📁Main.c

* 🔴**Main**🔴
  <pre>
  int main();
  </pre>
  📌O que faz:

  Controla TODO o algoritmo.

  ⚙️Funcionamento:

  1. Inicialização
     <pre>
       srand(42);
     </pre>
     * define aleatoriedade
     * com essa seed, sempre vai ser gerado uma mesma sequência, com os mesmos números e os mesmos resultados.

  2. Limpeza do arquivo de saida
     <pre>
       fopen("output.dat", "w");
     </pre>
  3. Lê dados
     <pre>
       Dados d = lerDados("input.dat");
     </pre>
  4. Criação da População
     <pre>
      Individuo *populacao = gerarPopulacao(d.tamanhoPop);
      preencherPopulacao(populacao, d.tamanhoPop, -10, 10);
     </pre>
  5. Loop de gerações
     <pre>
       for(int g = 0; g < d.geracoes; g++){
     </pre>
    * DENTRO DO LOOP:
      * Ordena População:
        <pre>
          ordenarPopulacao(populacao, d.tamanhoPop, d.qtdPontos, d.valorX, d.valorY);
        </pre>
      * Seleciona o melhor:
        <pre>
          Individuo melhor = populacao[0];
        </pre>
      * Calcula o erro e o fitness
        <pre>
          calcularFitness(...)
          calcularErro(...)
        </pre>
      * Divisão da População
        <pre>
          int metade = d.tamanhoPop / 2;
          int qtdNovos = d.tamanhoPop - metade;
        </pre>

        Divide a população em [melhores | piores]
      * Definição das Quantidades
        <pre>
          int qtdMutacao = qtdNovos * 0.6;
          int qtdCrossover = qtdNovos - qtdMutacao;
        </pre>
        📌O que faz:

         É definido que em 60% será feito mutação e em 30% será feito comutação.
      * Crossover
        <pre>
          for(int i = 0; i < qtdCrossover; i++){
        </pre>
        📌O que faz:

        É selecionado dois pais aleatórios, onde é gerado um filho e esse filho é substituido por um dos piores.
      * Mutação
        <pre>
          for(int i =0; i < qtdMutacao; i++){
        </pre>
        📌O que faz:

        É selecionado um dos bons, é feito uma cópia, nessa cópia acontece a mutação. Essa cópia mutada é substituida por um dos piores.
      * Reordenação
        <pre>
          ordenarPopulacao(...)
        </pre>
      * Atualiza o melhor
        <pre>
          melhor = populacao[0];
        </pre>
      * Salvamento dos resultados
        <pre>
          salvarResultados(...)
        </pre>

    6. Liberação de Memória
       <pre>
       liberarPopulacao(populacao);
       </pre>

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

Isso demonstra que o algoritmo conseguiu convergir corretamente para a solução ótima.

## 👩🏽‍🔬Ambiente de Teste
O projeto foi desenvolvido e testado com as seguintes configurações:
- 🖥️ Sistema Operacional: Ubuntu 24.04 (executado via WSL no Windows 11)
- ⚙️ Compilador: GCC (Ubuntu 13.3.0) versão 13.3.0
- 💻 Linguagem: C

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

Em suma, é possível concluir que o algoritmo aplicado (Algoritmo Genético) mostrou-se eficiente para o problema proposto, sendo capaz de aproximar
uma reta a partir de um conjunto de pontos ao longo das gerações. Apesar disso, é importante destacar que, por se tratar de um método estocástico,
os resultados não são exatamente iguais em todas as execuções e nem sempre atingem a solução ótima perfeita, mas sim uma aproximação satisfatória.

Além disso, foi possível observar que as escolhas feitas na implementação, como taxa de mutação, método de crossover e tamanho da população, influenciam
diretamente na qualidade e velocidade de convergência do algoritmo. Dessa forma, futuras melhorias poderiam explorar variações nesses parâmetros ou até
mesmo a utilização de outras abordagens de otimização para comparação de desempenho.

Outro ponto relevante é que este projeto pode ser utilizado como uma ferramenta didática para estudantes da área de programação, permitindo o aprendizado
e reforço de diversos conceitos importantes, como: manipulação de ponteiros, alocação dinâmica de memória, organização modular do código em linguagem C,
leitura e escrita em arquivos, além da implementação prática de técnicas de otimização inspiradas na evolução natural.

Dessa maneira, ao longo do desenvolvimento, foi possível consolidar conhecimentos relacionados à lógica algorítmica, estruturas de dados simples, uso de 
funções e modularização do código, bem como compreender, na prática, o funcionamento e as limitações de algoritmos genéticos em problemas de regressão linear.
       
## 📨Contato
* Email: [lauragoncalves20166@gmail.com]
* instagram: [https://www.instagram.com/lauragoncalves.lopes?igsh=MTFreDVkaW04NTZqNg==]
* GitHub: [https://github.com/lauraglopez6]
  
  

        
      
     




  
    
     
     


  
 
  

  
  

  

  
 
  

  

  
  
