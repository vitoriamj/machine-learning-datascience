<h1 style="text-align: center">Machine Learning: Algoritmos de Aprendizado <br> Supervisionado e Não Supervisionado</h1>

<h4>
    Alexandre Arantes e Vitória Mendonça
    <br>
    <i>Universidade Federal de Goiás</i>
</h4>
<br>



<ol>
    
   <li><h2>Introdução</h2></li>
    <p>Nos últimos anos, houve um crescimento exponencial na geração de dados, os quais vão desde o seu histórico de compras em um site online aos vídeos rápidos que você assiste no TikTok ou no Instagram.
    <p>Esse enorme volume de dados, fez com que palavras como Data Science, Machine Learning, Big Data e  algoritmos de aprendizado, se tornassem mais presentes e famosas no cotidiano. Mas afinal o que elas significam? De maneira geral, esses termos se referem a como trabalhar com os dados. Ou seja, como podemos usar essas informações para tornar tarefas mais eficientes, automatizar serviços ou recomendar novas compras.
    <p>Para fazer esses serviços coletamos um volume de dados, colocamos no computador e o treinamos para realizar tarefas. Para isso, precisamos da ajuda dos algoritmos de aprendizado. São eles que, com base na entrada, dizem qual a ação deve ser tomada.
<p>Diante do exposto, vamos explorar o estado da arte desses algoritmos, discorrendo sobre a aprendizagem supervisionada e, posteriormente, a aprendizagem não supervisionada.
    <br>
    <br>
     
    

   <li><h2>Aprendizado Supervisionado</h2>
	<p>O aprendizado supervisionado acontece quando se tem conhecimento dos dados e qual o resultado das perguntas. Ou seja, quando já se tem noção da relação entre entrada e saída. Esse aprendizado ocorre normalmente quando temos um problema de Classificação ou de Regressão. Mas qual é a diferença entre esses dois problemas?
	<p>Por exemplo, ao analisar um filme ele pode ser de ação, drama, romance, comédia, terror etc. Quando se trata de um problema de classificação a intenção será prever a categoria da entrada. A regressão semelhante a classificação também quer saber a categoria da entrada, porém ela usa um valor numérico como resposta.
	<p>Para todas as situações é necessário que se tenham medidas para medir o desempenho de algoritmos. Em problemas de classificação a acurácia e o erro são as principais ferramentas para medir o desempenho. A acurácia é o total de observações classificadas corretamente divida pelo total de previsões e o erro se dá pela subtração da acurácia de um.
	<p>Em problemas de regressão o mais usado é o RMSE (Raiz do Erro Quadrado Médio) que na prática consiste na distância entre cada precisão e a linha de regressão, sendo que quanto maior o RMSE, pior a precisão do modelo.
    <p>É importante lembrar que nem sempre essas duas ferramentas são capazes de dizer a precisão de um modelo de aprendizado supervisionado.
    <br>
    <br>
    
        
        
<ol>
    <li><h3>K-Nearest Neighbours (KNN)</h3></li>
    <p>É um algoritmo que utiliza a proximidade para fazer classificações sobre algum tipo de dado, é normalmente usado como um algoritmo para classificar dados, partindo do princípio que dados similares estarão próximos um do outro. Bastante útil no reconhecimento de padrões, por exemplo, visto que os dados com um comportamento parecido não ficarão distantes.
    <p>Então para determinar essa proximidade, podemos calcular a distância entre esses dados usando alguns fatores e métodos. Entre os mais usados estão:
    <p>Distância euclidiana: mede a distância em linha reta entre os pontos consultados e os pontos sendo medidos: $$d(x,y)=\sqrt[]{\sum_{i=1}^{n}(y_i-x_i)^2}$$
    <p>Distância de Manhattan: Mede o valor absoluto entre dois pontos: $$d(x,y) = \sum_{i=1}^{n}|y_i-x_i|$$
    <p>Existem outras distâncias como a de Minkowski e a de Hamming, mas não é o intuito explorá-las.
    <p>O K no nome define quantos vizinhos iremos checar. Definir K é extremamente importante, pois alguns valores podem levar a algo extremamente complexo ou ineficiente. Obviamente a escolha de K vai depender dos dados de entrada. Dados com mais outliers (que fogem da normalidade) precisam de valores de K maiores. É interessante usar sempre valores ímpares de K, independente da entrada para evitar empates na classificação.
    <p>Entre as vantagens do K-NN temos:
    <ul>
        <li>Implementação fácil;
        <li>Boa capacidade de adaptação à medida que novos dados são inseridos;
        <li>poucos hiperparâmetros (apenas um valor para K e uma distância métrica).
    </ul>
    <p>As desvantagens acabam sendo:
    <ul>
        <li>Requer quantidades significativas de memória e armazenamento, o que aumenta o custo financeiro (mais equipamento) e de processamento;
        <li>Não consegue apresentar bons resultados com dados com uma grande dimensionalidade, pois após o algoritmo se ater a um número otimizado de resultados, tenta aumentar o erro na classificação dos dados, especialmente se tratando de amostras pequenas.
    </ul>
    <p>Normalmente os algoritmos de K-NN, usam uma priority queue para deixar a complexidade em $O(n*log(k))$
    Os algoritmos de K-NN são usados principalmente em:
    <ul>
        <li>Algoritmos de recomendação: algoritmos que com base no que o usuário consumiu, recomenda novos produtos, os quais podem ser de filmes até produtos do dia-a-dia;
        <li>Finanças: Bancos usam algoritmos para saber o risco de inadimplência de clientes na hora de fornecer um empréstimo, usado previsão de bolsa de valores e até mesmo para analisar possíveis esquemas de lavagem de dinheiro;
        <li>Saúde: Análise da probabilidade de pacientes desenvolverem alguma doença genética, verificando anomalias no DNA.
    </ul>
    <br>


    
   <li><h3>Naive-Bayes</h3></li>
    <p>O algoritmo de Naive-Bayes é um classificador probabilístico que é baseado no teorema de Bayes. Não é um apenas um algoritmo, mas um conjunto desses que compartilham um mesmo princípio, cada par de eventos que está sendo classificado é independente um do outro.
    <p>O teorema de Bayes quer saber a probabilidade de um evento ocorrer, sabendo que outro evento ocorreu: $p(A|B) = \frac{p(B|A)p(A)}{p(B)}$
Naive assume que os eventos possuem independência entre si.
    <br>
O funcionamento do algoritmo em si é simples, os dados são convertidos para uma tabela de frequência. Posteriormente, as probabilidades dos eventos necessários para a classificação dos dados são calculadas e postas em outra tabela. Após, a equação de Naive-Bayes é usada para calcular a probabilidade para cada classe. A classe com a maior probabilidade será a resposta.
    <p>$$p(c|X) = \frac{p(X|c)p(c)}{p(X)}$$
    <p>Na fórmula acima, p(c|X) é a probabilidade de c de acordo com o dado X, p(X|c) é a probabilidade do dado c sendo X verdade, p(c) é a probabilidade de c ser verdade e p(x) é  a probabilidade de X ser verdade.
    <p>Entre as vantagens deste algoritmo estão:
    <ul>
        <li>É fácil e rápido predizer as classificações dos dados de entrada, além de ter boa performance em multiclasses;
        <li>Quando a independência entre os eventos é verdadeira, ele performa melhor que outros algoritmos de classificação, como regressão logística, e  precisa de menos dados para treinar a IA;
        <li>Funciona melhor quando a entrada de dados é categórica e não númerica, isto é, pode ser divida em grupos, como sexo, idade.
    </ul>
    <p>Já pelo lados das desvantagens destacam-se:
    <ul>
        <li>Se uma categoria nos dados de entrada não estava nos dados de aprendizado, ela terá frequência zero e não será recomendada;
        <li>Não é um algoritmo muito bom para fazer estimativas;
        <li>O teorema assume que os eventos são 100% independentes, porém no mundo real é bem raro que os eventos sejam completamente independentes.
    </ul>
    <p>Esse algoritmo acaba por ser muito utilizado para:
    <ul>
        <li>Realizar predições em tempo real, como o algoritmo é rápido, ele pode ser usado para realizar predições instantâneas;
        <li>Também pode ser usado para predição de múltiplas classes, isto é, dado uma entrada pode calcular as probabilidades de ela pertencer a uma classe;
        <li>Extremamente usado em filtros de spam e análise de sentimentos em redes sociais, visto que pode calcular a probabilidade de um email ser spam, além de conseguir analisar post em redes sociais e tentar predizer a opinião ali exposta;
        <li>Algoritmos de recomendação em geral.
    </ul>
    <br>

    
    
   <li><h3>Suport Vector Machine (SVM)</h3></li>    
    <p>O SVM (Support Vector Machine) é um algoritmo usado tanto para regressão quanto para classificação. Esse algoritmo busca achar um hiperplano entre pontos de dados, que irá classificar os dados. Se tivermos em 2 dimensões o hiperplano será uma reta, e em 3 dimensões um plano 2D. O algoritmo busca achar entre os hiperplanos existentes aquele com a maior distância possível entre os dados distintos.
	    ![teste](https://static.javatpoint.com/tutorial/machine-learning/images/support-vector-machine-algorithm5.png)
	<p>Em algumas situações pode ser complicado separar os pontos em 2 dimensões por uma reta de uma maneira satisfatória. Para isso, pode-se utilizar algumas técnicas, que leva os pontos para 3 dimensões, encontrar o hiperplano e transformar os pontos em 2 dimensões. Por exemplo imagine que temos um  conjunto, o qual está separados em 2 categorias azul e vermelho, porém, inicialmente, não temos a informação de quais pontos são vermelhos e quais são azuis. Dependendo da configuração deles no plano 2D, é impossível traçar uma reta capaz de separar os pontos azuis e vermelhos, porém se colocar os pontos em 3 dimensões, como a figura abaixo:
    <img src="https://www.researchgate.net/profile/Aldemon-Bonifacio/publication/318598388/figure/fig1/AS:614057111457801@1523414032621/Figura-215-Classicacao-perfeita-pelo-hiperplano-otimo-do-SVM-com-kernel-nao-linear.png" style="width: 300px">
    <p>Terá uma nítida separação entre os pontos. Podemos então encontrar o hiperplano e retornar em 2 dimensões, com definição entre pontos azuis e vermelhos encontrada. Essa manobra de usar 3 dimensões para encontrar as diferenças no conjunto dados  é chamada de Truque de Kernel e é responsável por dar uma versatilidade bem maior para os algoritmos de SVM.
	<p>Como vantagens destacam-se:
    <ul>
        <li>Uso bastante efetivos em conjunto de dados com múltiplas funcionalidades, como dados financeiros ou médicos.
        <li>Usa um subconjunto de pontos para aprendizado na função de decisão,os quais são chamados de “support vectors”, o qual torna o uso de memória mais eficiente, ou seja, utiliza menos recursos.
        <li>Diferentes funções de Kernel podem ser especificadas para as funções de decisão, pode usar algumas funções específicas também, o que aumenta a versatilidade e a precisão do algoritmo.
    </ul>
    <p>Pelo ponto de vista das desvantagens:
    <ul>
        <li>Funciona melhor quando os dados que serão usados para treinar o algoritmo, não forem muito grandes visto que o tempo de treinamento é alto.
        <li>Não funciona muito bem quando os dados têm mais ruído, isto é, as classes de destino estão mais sobrepostas.
    </ul>
    <p>Os algoritmos de SVM são bastante usados em vários campos:
    <ul>
        <li>Na saúde, são usados para predizer a agressividade de tumores, mapeamento genético.
        <li>Em processamentos de imagens, identificando irregularidades em superfícies, para modelos de reconhecimento facial e de diferenciação de expressão (identificação de sentimentos).
        <li>Na geologia, é usada para fazer mapeamento de camadas do solo.
        <li>No processamento de linguagem usado para classificação de textos por assuntos.
    </ul>
    <br>



   <li><h3>Random Forest</h3></li>
    <p>O Random Forest é um algoritmo popular do Machine Learning que pode ser utilizado para resolver problemas tanto de Classificação quanto de Regressão (explicados no tópico de Aprendizado Supervisionado).
    <p>Para melhor compreender essa ferramenta, é preciso entender o que são árvores de definição. Decision trees são uma maneira gráfica de representar todas as possíveis soluções para um problema ou decisão com base em condições.
	<p>Nessas estruturas de classificação, os nós internos, chamados de nós de decisão, atuam como um meio de dividir os dados, os ramos representam as regras de decisão e cada nó folha representa o resultado.
	<p>As árvores de decisão procuram encontrar a melhor divisão para subconjunto dos dados e são normalmente treinadas por meio do algoritmo Classification and Regression Tree (CART). Métricas, como impureza Gini, ganho de informação ou erro quadrático médio (MSE), podem ser usadas para avaliar a qualidade da divisão.
    <p>É baseado no Método Ensemble, que é um processo que combina a saída de várias árvores de decisão para chegar a um único resultado. O maior número de árvores na floresta leva a uma maior precisão e evita o problema de overfitting.
    <br><i>*Overfitting: cenário em que o modelo aprende tão bem as relações existentes no treino, que acabou apenas decorando o que deveria ser feito, e, ao receber as informações das variáveis preditoras nos dados de teste, o modelo tenta aplicar as mesmas regras decoradas, porém com dados diferentes esta regra não tem validade, e o desempenho é afetado.</i>
    <br>
    <img src="https://static.javatpoint.com/tutorial/machine-learning/images/random-forest-algorithm.png" style="width: 300px">
    <p>O processo de funcionamento dos algoritmos de Random Forest, são divididos nas seguintes etapas:
    <ol>
        <li>Selecione uma amostra aleatória de dados de treino no dataset. Aqui, é utilizado o método de reamostragem, em que as amostras selecionadas podem ser repetidas na seleção.
        <li>Construa as árvores de decisão associadas aos dados de treino selecionados (subsets). Para selecionar as variáveis de cada nó:
        <ol>
            <li>O Random Forest irá escolher de maneira aleatória duas ou mais variáveis, e então realizar cálculos com base nas amostras selecionadas, para definir qual dessas variáveis será utilizada no nó raíz.
            <li>O processo é repetido até a construção do último nó, excluindo das escolhas randômicas as variáveis selecionadas anteriormente.
        </ol>
        <li>Escolha o número de árvores de decisão que se deseja construir.
        <li>Os passos 1 e 2 são repetidos na construção das outras árvores de decisão.
        <li>Para cada árvore de decisão, são encontradas previsões, os resultados. Em problemas de regressão será realizada a média dos valores previstos, e esta média informada será o resultado final e em problemas de classificação o resultado com maioria dos votos será o escolhido.
    </ol>
	<p>O algoritmo de Random Forest apresenta diversas vantagens e desvantagens quando usado em problemas de classificação e de regressão. Algumas das vantagens incluem:
    <ul>
        <li>O Random Forest pode ser utilizado para resolver problemas tanto de Classificação quanto de Regressão
        <li>Menor risco de overfitting: Árvores de decisão correm o risco de overfitting, pois tendem a se ajustar perfeitamente a todas as amostras nos dados de treinamento. No Random Forest há um número grande de árvores de decisão, o classificador não fará overfit do modelo, pois a média de árvores não correlacionadas reduz a variância e erros de previsão.
        <li>É capaz de lidar com grande volumes de dados e com alta dimensionalidade.
    </ul>
    <p>Entre as desvantagens desse algoritmo, temos:
    <ul>
        <li>O Random Forest pode lidar com grandes conjuntos de dados e  fornecer previsões mais precisas, mas podem ser lentos para processar dados, pois estão computando dados para cada árvore de decisão individual.
        <li>Como as florestas aleatórias processam conjuntos de dados maiores, elas exigirão mais recursos computacionais para armazenar esses dados.
        <li>Mais complexo: A previsão de uma única árvore de decisão é mais fácil de interpretar quando comparada a uma floresta delas.
    </ul>
    <p>Essa ferramenta do Machine Learning auxilia na melhor tomada de decisões, sendo algumas de suas aplicações:
    <ul>
        <li>Finanças: Reduz o tempo gasto em gerenciamento de dados e tarefas de pré-processamento, em relação a outros algoritmos. Pode ser usado para avaliar clientes com alto risco de crédito, detectar fraudes e problemas de precificação de opções.
        <li>Medicina: Na biologia computacional esse algoritmo permite que os médicos resolvam problemas como classificação de expressão gênica, descoberta de biomarcadores e anotação de sequência. Como resultado, os médicos podem fazer estimativas em torno das respostas dos medicamentos a medicamentos específicos. Além disso, auxilia na identificação de tendências de doenças e os riscos de doenças.
        <li>E-commerce e marketing: Pode ser usado para mecanismos de recomendação para fins de venda cruzada, bem como a identificação de novas tendências.
        <li>Uso do solo: Podemos identificar as áreas de uso do solo semelhantes por este algoritmo.
    </ul>
    <br>

    

   <li><h3>Redes Neurais Artificiais (RNA)</h3></li>
    <p>As redes neurais artificiais são algoritmos que tentam emular o funcionamento de um cérebro. Para isso são utilizados grafos. São constituídos por camadas, sendo uma de entrada, outra de saída e uma ou mais camadas ocultas.
    <p>Os vértices do grafo seriam os neurônios, possuem um valor limite de saída e conectam-se a outros por arestas com peso. Uma RNA possui 5 partes gerais, as conexões entre os neurônios, cada uma possuindo um peso sináptico e um integrador, que realiza a soma dos sinais de entrada sendo ponderado pelos pesos sinápticos. A função de ativação responsável por dar a saída do neurônio, é um bias que será aplicado externamente a cada neurônio, para aumentar ou diminuir a entrada.
    <p  style="text-align: center">Rede Neural com 3 camadas
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/3d/Neural_network.svg/1200px-Neural_network.svg.png" style="width: 250px">
    <br>
    <p style="text-align: center">Rede Neural com 5 camadas
    <img src="https://1.cms.s81c.com/sites/default/files/2021-01-06/ICLH_Diagram_Batch_01_03-DeepNeuralNetwork-WHITEBG.png" style="width: 280px">
    <p>Vamos analisar matematicamente o funcionamento de uma RNA. Observe o grafo com pesos abaixo:
    <img src="https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/figs/iou-graph-10-nodes-and-20-edges.png" style="width: 250px">
    <br>
    <p>Cada vértice seria um neurônio, composto pelos dados de entrada, pesos, um limite e uma saída. Podemos relacionar a saída pela fórmula a seguir, com “m” o número de neurônios que o vértice recebe em um sinal, xi o sinal e um peso sináptico entre o neurônio i e o neurônio que estamos analisando chamado de bias: $$y = \sum{i=1}{m}w_ix_i + bias$$
    <p>Após isso, usa uma função de ativação que será responsável por dar a saída, se o valor de y for maior que um valor, ela manda um sinal para o próximo nível. A função de ativação exerce um papel crucial, pois além de controlar a saída, ele evita que a saída exceda certo valor e assim dispare todos os neurônios da rede.
	<p>Entre os tipos de função de  ativação temos a limiar, que restringe a saída a valores binários (0 ou 1), linear por partes, que permite o valor variar em certo intervalo, sigmoidal, que também assume um valor entre 0 e 1, mas possui um balanceamento adequado entre um comportamento linear e não linear, e tangente hiperbólica, similar a sigmoidal, porém assume valores negativos. O uso de cada uma é determinado caso a caso.
    <p>Limiar: $f(u) = 
      \begin{cases}
          1, &se&u \geq0 \\
          x, &se&u>0 
      \end{cases}$
    <p>Linear por partes: $f(u) = 
      \begin{cases}
          1, &se&u \geq+\frac{1}{2} \\
          u, &se&+\frac{1}{2}>u>-\frac{1}{2} \\
          x, &se&u \leq-\frac{1}{2} 
      \end{cases}$
    <p>Sigmoidal: $f(x) = \frac{1}{1 + e^{-x}}$
    <p>Tangente hiperbólica: $f(u) = tanh(u)$
    <p>Como vantagens das redes neurais tem:
    <ul>
        <li>Capacidade de se adaptar: como as redes neurais podem ter seus pesos sinápticos alterados, se houver pequenas mudanças no ambiente a rede pode ser retreinada para continuar operando no ambiente.
        <li>Como cada neurônio é afetado pela atividade dos neurônios a sua volta, a informação contextual é tratada de maneira natural pela RNA.
        <li>Uma RNA implementada em hardware pode ser considerada tolerante a falhas em casos gerais.
    </ul>
    <p>De desvantagens:
    <ul>
        <li>O treinamento é demorado, levando horas ou dias, além de depender de um grande volume de dados.
        <li>Os dados de treinamento precisam passar por um pré-processamento, como normalização e seleção criteriosa para se obter resultados confiáveis.
        <li>É um funcionamento do tipo caixa-preta, o qual implica não saber como a rede chegou a uma conclusão
        <li>Pode-se obter resultados absurdos, sendo necessário supervisão humana para resolver o problema.
    </ul>
    <p>As RNA’s são usadas em detecção de fraude em cartões de crédito, otimização de logística para redes de transporte, processamento de linguagem natural, marketing direcionado, sistemas de controle, visão computacional para interpretar imagens e vídeos etc.
    <br>
    <br>

        
        
</ol>

   <li><h2>Aprendizado Não Supervisionado</h2></li>
    <p>O aprendizado não supervisionado tem como objetivo buscar características comuns em dados não rotulados e, assim, fazer uma análise complexa nessas informações e usá-las para futuras investigações.
    <p>Essa classificação é feita utilizando o método de clustering, que lida com técnicas para agrupar dados com estruturas e padrões ocultos similares entre si e diferentes dos dados pertencentes a outros grupos (clusters).
    <p>O algoritmo de aprendizado não supervisionado realiza uma análise complexa nos dados, sem ter ideia de seus conceitos.
    <p>É comum a máquina assumir muitos dados redundantes, utilizando a técnica de redução de dimensionalidade, removendo dados repetitivos ou combinando algumas partes de dados, se aplicável. Com esse objetivo, utiliza o modelo generativo, que revisa esses dados e possibilita que novas amostras sejam criadas a partir deles.
    <p>Esses algoritmos são utilizados em processamentos complexos e bancos de dados volumosos, sendo excelentes para identificar oportunidades de marketing, com análises e previsões.
    <br>
    <br>


        
<ol>
    
   <li><h3>Processamento de Linguagem Natural (PLN)</h3></li>
    <p>O Processamento de Linguagem Natural é uma parte poderosa da inteligência artificial  que possibilita o aprendizado das máquinas dos diversos idiomas e dialetos da linguagem humana.
    <p>Com um interesse crescente na comunicação homem-máquina, os algoritmos de PLN viabilizam a interpretação e manipulação da linguagem humana pelos computadores.
    <p>A máquina é capaz de ouvir e entender falas, ler textos, identificar sentimentos e encontrar trechos importantes, independente do idioma que recebeu os comandos e da correta escrita gramatical.
    <p>Em resumo, para a compreensão automática entre homem e máquina, os algoritmos de PLN segmentam a linguagem humana em partes menores e essenciais e tentam compreender relações entre o funcionamento dessas frações, buscando criar um significado.
    <p>A PLN decompõe esse trabalho em etapas:
    <ul>
        <li>Tokenização: quebra uma sequência de caracteres em tokens, identificando o início e o final de palavras e sentenças, que serão processados em sequência.
        <li>Análise Léxica: relacionar variantes morfológicas à forma canônica, ou seja, a forma em que as palavras se encontram no dicionário.
        <li>Análise Sintática: análise fiel de cada frase, determinando e classificando suas estruturas com uso de gramáticas e árvores sintáticas.
        <li>Análise Semântica: traduzir as expressões originais em um tipo de metalinguagem, identificando seus significados no contexto. Uma demanda das análises semânticas em PLN é na resolução de ambiguidade, como diferenciar a fruta manga da manga da camisa.
        <li>Análise Pragmática: busca nas outras frases a compreensão do texto que falta àquela frase em análise, procurando coerência textual e análise do discurso.
    </ul>
    <img src="https://files.passeidireto.com/354091cd-ff8c-4181-a591-a221989a12fb/bg3.png" style="width: 150px">
    <p>A tecnologia de Processamento de Linguagem Natural, alimentada pelo Machine Learning, contém suas vantagens e desvantagens.
    <p>Entre suas vantagens, podemos citar:
    <ul>
        <li>Performar análises de larga escala: As ferramentas de PLN possibilitam uma análise em todos os tipos de documentos, incluindo mídias sociais, e-mails, sistemas internos etc. Além disso, automatiza e processa dados em larga escala em pouco tempo comparado a se essa análise fosse feita manualmente.
        <li>Análise mais precisa e redução de custos: É comum o ser humano cometer erros em atividades repetitivas. O PLN tem a vantagem de estar imune a esses erros, porque são treinados a não cometê-los de acordo com suas regras de negócio. Somado a isso, essa ferramenta trabalha a todo momento, podendo dar feedbacks em tempo real.
        <br>
        Com análises de dados manuais, esse serviço demoraria mais tempo, sem precisar de auxílio, diminuindo o custo de contratação de pessoas para essas tarefas.
        <li>Ajuda a obter insights relevantes: Tarefas como análise de opiniões online e outros tipos de comentários, requerem uma investigação de alto nível, melhor entendida com Machine Learning. As ferramentas de PLN não fazem suposições, mas estão se aprofundando em análises complexas, cenários do mundo real e insights relevantes.
    </ul>
    <br>
	Entretanto, o Processamento de Linguagem Natural ainda apresenta entraves em suas tarefas. As desvantagens desses algoritmos são:
    <ul>
<li>Dificuldade em diferenciar sentenças similares: Algumas palavras e expressões se parecem as mesmas, mas têm diferentes significados. No inglês, um exemplo que podemos dar é ao falar ‘I scream' e ‘ice cream’, expressões com pronúncias semelhantes, mas significados diferentes.
	Humanos são capazes de facilmente diferenciar essas expressões, mas a inteligência artificial ainda não chegou a esse nível. Desse modo, isso pode ser problemático ao responder perguntas de aplicações com reconhecimento de voz, a exemplo da Siri, Alexa, Cortana etc.
<li>Sarcasmo: As máquinas são bem objetivas e processam as informações positivamente ou negativamente.
	Apesar de ser comum ver tecnologias de voz usarem expressões e fazerem piadas que humanos usam como humor e sarcasmo no cotidiano, se você usar essas expressões de forma sarcástica, a máquina não é capaz de processá-las corretamente.
<li>Erros de pronúncia: Apesar das aplicações de escrita sugerirem palavras e correções de gramática, a máquina não consegue interpretar as intenções do escritor. Isso faz com que palavras mal escritas ou mal utilizadas, dificultem a análise das ferramentas de PLN.
	No entanto, à medida que essa tecnologia evolui e é melhor treinada  com expressões que a PNL irá usar, esses erros serão minimizados com o tempo.
<li>Falta de pesquisas: Existem diversos idiomas e dialetos em todo o mundo. Apenas o continente africano tem mais de 2.000 idiomas. Apenas na Nigéria, são 500 idiomas falados!
	Dessa forma, um gargalo encontrado no PLN é que não há dados suficientes disponíveis para essa ferramenta processar e analisar em tantas linguagens existentes pelo mundo.
    </ul>
    <br>
As ferramentas de processamento de linguagem natural possibilitam acesso à informações para análise profunda sobre esses dados.
Os algoritmos de PLN são usados para extrair insights desses dados, tendo várias aplicações tecnológicas. Algumas são:
    <ul>
<li>Aumenta a satisfação dos clientes: A tecnologia de processamento de linguagem natural pode classificar e analisar tickets de serviços do cliente baseado em sentimentos, urgência e outros fatores. Dessa forma, uma empresa preocupada com a satisfação de seus clientes, pode lançar uma pesquisa de satisfação de seus serviços, realizar uma análise de PLN e buscar melhor atender seus clientes.
<li>Análise de Documentos: Sem precisar gastar tempo e dinheiro em análises manuais, a PLN realiza a extração personalizada para identificar entidades específicas de domínios em documentos.
<li>Identificação de tendências: Classifica conteúdos em tópicos significativos e auxilia profissionais de marketing a extrair conteúdo relevante para as marcas, com notícias on-line, artigos e outras fontes de dados.
<li>Descoberta investigativa: Identifica padrões e pistas em e-mails ou relatórios escritos para ajudar na detecção e resolução de crimes;
<li>Análise de mídias sociais: Rastreia a relevância de conteúdos e o sentimento dos usuários sobre tópicos específicos.
    </ul>
    <br>
    <br>
    
    
    
   <li><h3>Redes Neurais Profundas</h3></li>
    <p>As Redes Neurais Profundas, ou Deep Learning, são um tipo de processo de Machine Learning. Essas redes artificiais resolvem problemas complexos usando um sistema adaptativo de aprendizagem com erros e adaptação contínua.
Essa tecnologia ensina os computadores com métodos inspirados no funcionamento do cérebro humano e a interconexão dos neurônios em camadas.
    <p>Os neurônios artificiais são módulos de software chamados de “nós”, e as redes neurais artificiais são programas ou algoritmos de software que, em seu núcleo, usam sistemas de computação para solucionar obstáculos complexos.
    <p>Nas estruturas de Redes Neurais Profundas os dados, que essa irá receber, são introduzidos na camada de entrada, que não participa da contagem de camadas da rede. A última camada é a camada de saída. Todas as demais camadas entre a de entrada e de saída são chamadas de camadas ocultas.
    <p>Na fase de treinamento ocorre o processo de classificação de grandes quantidades de dados e identificação de suas características compartilhadas. O sistema então compara e memoriza essas características para tirar as conclusões apropriadas na próxima vez que encontrar dados de natureza semelhante.
	<p>No algoritmo, os dados de entrada são  comunicados aos demais nós da rede, as camadas ocultas, onde todo o processamento acontece, buscando padrões nos dados e atribuindo pesos de acordo com a relevância da informação.
	<p>Para entender a ideia dos pesos, é preciso levar em conta que no início dos testes, o algoritmo ainda não está treinado e está propenso a gerar saídas erradas. Quando os valores de saída são comparados com os valores reais, essa tecnologia percebe o erro e tenta corrigi-lo atribuindo pesos aos dados de entrada, que determinam a importância dessas informações, e, assim, trabalha de modo a reduzir os erros. Os pesos iniciais são dados aleatoriamente e modificados ao longo das iterações do algoritmo através do backpropagation, até começar a acertar.
	<p>Nas camadas ocultas, o algoritmo toma decisões para passar informações para as demais camadas conectadas, até atingir a última camada oculta, vinculada à camada de saída, que possui um nó para cada saída possível desejada, tornando, assim, possível obter previsões dos dados.
	<p>Essas previsões permitem que as Redes Neurais Profundas “aprendam” as relações complicadas que estão ocultas nos dados e obtenham insights de ações e tomadas de decisões, analisando possíveis cenários futuros. Grandes coleções de dados rotulados são usadas para treinar modelos de aprendizado profundo.
	<p>As redes neurais artificiais profundas são muito utilizadas por várias empresas, estando entre os benefícios do emprego desses algoritmos:
    <ul>
        <li>O Deep Learning é treinado usando vários tipos de dados, sendo capaz de produzir insights pertinentes aos objetivos do treinamento. Por exemplo, pode ser utilizado para encontrar conexões entre pesquisa de mercado, atividade de mídias sociais e muito mais para prever valores futuros de ações de uma empresa específica.
        <li>Uma vez bem treinado, esse modelo pode completar milhares de atividades repetitivas em uma pequena fração de tempo que um humano demoraria para fazer a mesma ação. Ademais, a qualidade de trabalho não decai, a menos que os dados de treinamento incluam dados brutos que não reflitam com precisão o problema que se busca resolver.
        <li>As Redes Neurais Profundas são excelentes em aprender sem regras, sendo muito mais eficaz do que outros tipos de abordagens de Machine Learning.
    </ul>
    <p>Apesar de suas vantagens, as redes neurais profundas têm várias desvantagens:
    <ul>
        <li>Como o Deep Learning é treinado gradualmente, é necessário um grande volume de dados para treiná-lo, o que pode ser inviável para empresas de menor porte. Além disso, em alguns setores a quantidade de dados é limitada, restringindo esse algoritmo para essas áreas.
        <li>As Redes Neurais Profundas demandam grande poder computacional. Hardwares de alto desempenho consistem em unidades de processamento gráfico multi core, que requerem muita eletricidade, tornando-os um investimento caro. Ademais, requer também espaço de memória suficiente para que o modelo tenha um bom desempenho.
        <li>Modelos de Deep Learning com bom desempenho em conjuntos de dados comparados podem ter dificuldades quando aplicados a conjuntos de dados do mundo real. Como exemplo, um algoritmo que aprende que ônibus escolares geralmente são amarelos. Se os ônibus forem pintados de azul, o modelo terá dificuldade em detectar o ônibus. Eles falham em ter um bom desempenho em um ambiente desconhecido.
        <li>Uma caixa preta é um dispositivo ou sistema que permite que você veja a entrada/saída, mas não o funcionamento intermediário. Os algoritmos redes neurais profundas encontram problemas de caixa preta, em que se sabe a entrada/saída, mas não o funcionamento intermediário, tornando-os difíceis de depurar e entender como eles tomam decisões. Isso faz com que os programadores não tenham noção quando tentam entender por que certos aspectos falham. Embora possa não ser um problema na realização de tarefas triviais, em casos como a detecção de tumores, o médico precisa saber por que o modelo marcou algumas áreas e por que não em outras em um relatório de varredura.
    </ul>
	<p>O Deep Learning, além de muito falado atualmente, é uma excelente ferramenta que proporciona diversas aplicações. Entre elas:
    <ul>
        <li>Eficiência na experiência do cliente: Alguns exemplos incluem soluções de auto-atendimento on-line. Existem modelos de redes neurais profundas sendo usados para chatbots, que respondem dúvidas e dão aos clientes um suporte mais rápido e objetivo utilizando programas que simulam a conversação com um ser humano.
        <li>Prever resultados legais: O Deep Learning é capaz de analisar  dados para ajudar a fazer previsões sobre resultados de processos judiciais melhor e mais rápido do que os seres humanos. Com o acesso dessa ferramenta a anos de dados experimentais, os advogados são capazes de responder melhor perguntas que envolvem previsões.
        <li>Previsão do mercado de ações: Esse mercado envolve muitos obstáculos para fazer previsões, com diversos fatores associados (físicos, comportamento  racional e irracional, psicossociais, etc. Todos estes aspectos se combinam para tornar os preços das ações voláteis e muito difíceis de prever com um razoável grau de precisão.
        <li>Veículos autônomos: O algoritmo de redes neurais profundas recebe sinais de sensores, de sistemas de controle e atuadores para sensoriar o ambiente e determina a execução de  ações de forma mais segura e confiável do que poderia ser obtida por um condutor humano comum. 
        <li>Reconhecimento de imagens: O Deep Learning já produziu precisões para classificações de imagens, detecção de objetos, bem como a capacidade de restauração e segmentação de imagens.
    </ul>
    <br>
    <br>
    
    
    
   <li><h3>K-Means Clustering</h3></li>
    <p>O algoritmo de K-Means Clustering agrupa conjuntos de dados não rotulados em diferentes clusters (grupos) com propriedades semelhantes entre si, sem a necessidade de treinar a máquina para isso. Em seu nome, K define o número de clusters predefinidos que precisam ser criados no processo.
    <p>O principal objetivo desse algoritmo é minimizar a soma das distâncias entre o ponto de dados e seus clusters correspondentes.
    <p>Essa ferramenta recebe o conjunto de dados não rotulado como entrada, determina a divisão do conjunto de dados em K-números de clusters com centróides iniciais aleatórios, em um processo iterativo. Depois, atribui a cada ponto de dados o seu K-centro mais próximo.
    <p>O conjunto desses pontos de dados que estão próximos ao K-centro específico cria um cluster. Logo, grupos de dados com diferentes centros e características estão distantes entre si.
	<p>O clustering permite encontrar e analisar os grupos que foram formados. Examinando o centróide de cada cluster, podemos interpretar qualitativamente que tipo de grupo cada cluster representa.
    <img src="https://static.javatpoint.com/tutorial/machine-learning/images/k-means-clustering-algorithm-in-machine-learning.png" style="width:350px">
    <p>Para essa tarefa de clustering, o trabalho é dividido em etapas:
    <ol>
        <li>K é selecionado e predefinido para decidir o número de clusters. Posteriormente, veremos como esse número é definido.
        <li>K pontos aleatórios são escolhidos como centróides.
        <li>Atribuir cada ponto de dados ao seu centróide, o que irá pré-definir os K clusters.
        <li>Calcular a variância e posicionar um novo centróide para cada grupo.
        <li>Repetir a 3ª etapa, reatribuindo cada ponto de dados ao novo centróide mais próximo de cada cluster.
        <li>Se ocorrer alguma reatribuição, é preciso repetir a 4ª etapa, se não, está finalizado o modelo de clustering.
    </ol>
	<p>Escolher um ótimo número K de clusters é uma tarefa difícil. Há algumas maneiras diferentes de escolher o número de grupos, mas iremos discutir o método mais apropriado.
	<p>O Elbow Method, ou Método do Cotovelo é uma dos jeitos mais populares de encontrar um ótimo K-número. Esse método utiliza o conceito de valor WCSS (Within Cluster Sum of Squares), a soma dos quadrados intra-clusters, no português, que define a variação total entre um grupo. É calculado pela fórmula: $$WCSS = ∑P_{i\,no\,Cluster1}\,distância(P_i\,C_1)^2 +  ∑P_{i\,no\,Cluster2}\,distância(P_i\,C_2)^2 + ∑P_{i\,no\,Cluster3}\, distância(P_i\,C_3)^2$$
    <p>$∑P_{i\,no\,Cluster1}\,distância(P_i\,C_1)^2$ : É a soma do quadrado das distâncias entre cada ponto de dados e seus centróides entre o Cluster 1 e o mesmo para os outros termos.
    <p>Para medir a distância entre os pontos de dados e o centróide, usamos métodos como a distância euclidiana ou a distância de Manhattan. Para o Método do Cotovelo, são seguidos os passos:
    <ol>
        <li>Executa o agrupamento K-means em um determinado conjunto de dados para diferentes valores de K (intervalos de 1-10).
        <li>Para cada valor de K, calcula-se o valor WCSS.
        <li>Traça uma curva entre os valores calculados do WCSS e o número de clusters K.
        <li>O ponto agudo da dobra ou um ponto do gráfico se parece com um braço, então esse ponto é considerado o melhor valor de K.
    </ol>
    <p>Como o gráfico mostra a curva acentuada, que se parece com um cotovelo, é conhecido como Método do Cotovelo. O gráfico desse processo se parece com a imagem a seguir:
    <img src="https://static.javatpoint.com/tutorial/machine-learning/images/k-means-clustering-algorithm-in-machine-learning13.png" style="width:300px">
    <p>Entre as vantagens do K-Means, temos:
    <ul>
        <li>Relativamente simples de implementar;
        <li>Escalável para grandes entradas de dados, por sua alta eficiência;
        <li>Garante a convergência dos dados para suas análises, com a inicialização aleatória da posição dos centróides. Uma instância pode mudar o cluster, movendo seus dados quando os centróides são novamente computados;
        <li>Adaptação frequente a novos exemplos, pois é altamente flexível;
        <li>Fácil interpretação dos resultados do clustering;
        <li>Generalização para clusters de diferentes formas e tamanhos.
    </ul>
    <p>As desvantagens são:
    <ul>
        <li>Necessário a escolha do K-número de clusters antes da análise, que fica para escolha do pesquisador, que deve ter conhecimento e domínio das ferramentas estatísticas;
        <li>Os centróides podem ser arrastados por outliers (valores atípicos que fogem da média), ou os outliers podem obter seu próprio cluster em vez de serem ignorados, dificultando a obtenção precisa de resultados.
        <li>Conforme o número de dimensões (características dos dados) aumenta, a escalabilidade da ferramenta diminui.
    </ul>
    <p>O simples e eficiente K-Means Clustering pode ser utilizado para ferramentas de recomendações, como, em serviços de streaming de músicas, agrupar tipos ou gêneros de músicas similares aos do padrão do usuário e recomendar novas escolhas. Além disso, essa tecnologia, tem aplicações que incluem:
    <ul>
        <li>Segmentação de clientes: o clustering ajuda os profissionais de marketing de uma empresa a melhorar a base de clientes, focar o trabalho em áreas-alvo e dividir clientes com base no histórico de compras, interesses ou monitoramento de atividades, o que ajuda no direcionamento de clientes a campanhas específicas.
        <li>Classificação de documentos: Agrupa documentos em diferentes categorias com base em tags, tópicos e conteúdo. No processamento, cada documento é representado como um vetor e utiliza-se a frequência de termos para identificar termos comumente usados que ajudam a classificar o documento. Os vetores de documentos são separados em clusters para ajudar a identificar a similaridade nos grupos de documentos.
        <li>Identificação da localização de crimes: Com a coleção de dados sobre crimes e suas localidades específicas, é possível associar os dois e, com uma análise, coletar informações de qualidade sobre áreas propensas ao crime dentro de uma cidade ou localidade.
        <li>Otimização de entregas: Utilizar uma combinação de K-Means para associar localidades próximas e o número de lançamentos para resolver a rota de entregas, como um problema de caixeiro viajante.
        <li>Análise de dados de viagens: Os dados de viagens disponíveis por empresas, como a Uber, fornecem grande quantidade de informações valiosas sobre tráfego, tempo de trânsito, locais de pico de coleta etc. A análise desses dados é útil para fornecer informações sobre os padrões de tráfego urbano e ajudar no planejamento das cidades do futuro.
        <li>Detecção de fraudes: O Machine Learning desempenha um papel crítico na detecção de fraudes em automóveis, saúde e seguros. Utilizando dados históricos anteriores sobre reclamações fraudulentas, é possível isolar novas reclamações com base em sua proximidade com clusters que indicam padrões fraudulentos. Como a fraude de seguros pode ter um impacto multimilionário em uma empresa, a capacidade de detectar fraudes é de importância crucial.
    </ul>
    <br>
    <br>
    


   <li><h3>Agglomerative Clustering</h3></li>
    <p>Nessa técnica, os dados são agrupados  em clusters pequenos. Seleciona-se alguns desses clusters para criar, assim, um novo cluster, o qual está hierarquizado com os anteriores, e repete-se esse processo até que se obtenha um cluster apenas.
    <p>À medida que se sobe na hierarquia, essas características vão ficando mais genéricas. Para entender melhor essa ideia, imagine que entre os gatos, podemos pegar várias raças, que seriam os clusters iniciais, e agrupá-las no cluster gato. Esse, por sua vez, pode ser agrupado no cluster felinos, que englobaria tigres, leões, entre outros. O qual também pode ser agrupado no cluster mamíferos, que englobaria cães, macacos, marsupiais etc. Então, são agrupados no cluster final, animais, que englobaria, além dos já citados, peixes, aves e insetos.
    <p>A hierarquia seria os relacionamentos que cada clusters possui com outro, exemplo, o gato está no mesmo cluster dos mamíferos junto com o macaco, isso implica que eles possuem características comuns, mas dentro do limite. À medida que descemos na hierarquia essas características vão aumentando. Por exemplo, o gato possui mais características com os mamíferos do que com outros animais, e depois mais características com os felinos do que com o restante dos mamíferos, assim por diante.
    <p>A seguir, segue-se do exemplo acima que os nós na parte de baixo seriam os dados iniciais e, à medida que subimos na hierarquia, elas se juntam a outros clusters e assim sucessivamente até atingir o topo.
    <p>Para usarmos essa técnica não precisamos pré-definir os números de clusters, tal qual a hierarquia entre eles, o algoritmo irá procurar essas relações automaticamente.
    <p>O funcionamento do algoritmo segue os seguintes procedimentos: cada dado inicial será considerado como um cluster, então será calculada a distância entre cada ponto, podendo ser a distância euclidiana ou outras, como a de Minkowski, a depender da situação. Após os cálculos das distâncias, colocaremos essas distância numa matriz, os 2 clusters mais próximos se juntam e criam um nó, e repete-se o processo. Recalcula-se as distâncias e atualiza-se a matriz, até se obter apenas um cluster. O resultado será um dendrograma.
    <p style="text-align: center">Exemplo de matriz distância</p>
    <img src="https://miro.medium.com/max/640/1*W1fEsWccONK6T2cxJ9vJ_g.webp" style="width: 250px">
    <p style="text-align: center">Após juntar os clusters mais próximos</p>
    <img src="https://miro.medium.com/max/640/1*yWU8ooQ_7ayvco3uDPBLeA.webp" style="width: 250px">
    <p style="text-align: center">Processo de construção</p>
    <img src="https://s3.amazonaws.com/higherlogicdownload/IMWUC/UploadedImages/ayiDw9RsRI2yU2MWRbvS_temp.png" style="width: 200px">
    <p style="text-align: center">Dendrograma</p>
    <img src="https://www.edrawsoft.com/images/creatediagram/dendrogram-template.png" style="width: 300px">
    <p>É importante ressaltar que o dendrograma nos fornece o número de clusters dos dados e não um número mais otimizado. Uma das formas de identificar o número de cluster é realizar um corte horizontal no dendrograma. O número de pontos que ele interceptará será a resposta. Interpretar os resultados ainda ficará a cargo do cientista de dados.
	<p>As vantagens:
    <ul>
        <li>Não precisa definir um número prévio de clusters, como no K-Means;
        <li>Implementação fácil;
        <li>Podemos obter classificações bastante significativas.
    </ul>
    <p>Desvantagens:
    <ul>
        <li>Uma vez que 2 clusters são combinados não podem ser desfeitos;
        <li>Ruim para grande quantidade de dados, complexidade O( n2log(n) ).
    </ul>
    <p>Os algoritmos de clustering são bastante usados na biologia, principalmente, para estudos genéticos, visto que estudar a evolução de organismos através do DNA é extremamente facilitado pela forma que o algoritmo funciona naturalmente. Portanto, é usado no estudo de vírus para desenvolver novos tratamentos, no análises de tumores.
    <br>
    <br>
    
    
    
   <li><h3>Density-Based Spatial Clustering of Applications with Noise (DBSCAN)</h3></li>
    <p>Nos algoritmos vistos até o momento, separamos dados mais próximos uns dos outros em grupos. Porém, em algumas situações, os dados estão aninhados, ou seja, muito próximos um dos outros, mesmo sendo diferentes. O DBSCAN é um algoritmo que visa resolver os problemas em que essa situação acontece.
	<p>Este algoritmo aceita qualquer função de distância, ficando a cargo do cientista de dados escolher qual melhor se encaixa no problema. A ideia principal é que cada ponto de um dado cluster, para uma certa distância, possuirá um número mínimo de pontos. Isso implica que a densidade do vizinho precisa exceder um limiar.
    <p>Para entender melhor o algoritmo, vamos antes entender alguns conceitos. A vizinhança do ponto são todos os pontos que estão a uma distância menor que um dado valor, ou seja, esteja interna a um círculo de raio r, e com o centro no ponto.
    <img src="https://i.imgur.com/GHITmzG.png" style="width: 250px">
    <p>Na imagem acima, estão sendo analisados os pontos q e p. Exigem dois tipos de pontos num cluster: pontos centrais e pontos de borda. Se na vizinhança de um ponto possuir no mínimo um número pré-definido de pontos, ele é um ponto central, do contrário, ponto de borda. Um ponto q é alcançado por densidade se estiver na vizinhança de um ponto central. O conjunto de pontos conectado por densidade definirá um cluster.
    <img src="https://i.imgur.com/pLe6WKt.png" style="width: 250px">
    <p style="text-align: center">Conexão por densidade no método DBSCAN</p>
    <br>
    <p>Outra definição importante é a de ruído, que seriam os pontos isolados que não podem ser alcançados por densidade. Na figura acima, observa-se dois pontos de ruído.
    <p>Na hora de implementar o algoritmo precisamos definir dois parâmetros que são: o número mínimo de pontos que um ponto deve ter na sua vizinhança para ser considerado um ponto central e, claro, o raio da círculo que irá definir o limite da vizinhança de um ponto. Isso precisa ser feito com cuidado, visto que, se escolher um raio muito grande, todos os pontos podem ser alcançados por densidade. Existem algumas técnicas para ajudar a definir esses parâmetros.
	<p>O algoritmo em si consiste em encontrar os clusters analisando a vizinhança de cada ponto na base de dados, começando por um ponto p qualquer. Se p for  um ponto central, então um novo cluster é criado.
    <p>O DBSCAN, após verificar os pontos na base e encontrar os clusters, procura, então, pontos alcançáveis por densidade a partir dos pontos centrais, o que pode envolver a união de clusters que são alcançáveis por densidade.
    <p>O algoritmo termina quando nenhum ponto puder ser adicionado a qualquer cluster. Todos os pontos que não puderem ser adicionados a nenhum cluster será considerado como ruído.
	<p>Uma característica interessante e importante do DBSCAN, é que ele possui uma forma de lidar com ruídos, o que o torna uma escolha sempre interessante quando se precisa fazer um tratamento prévio nos dados.
	<p>Como vantagem:
    <ul>
        <li>Pode encontrar clusters de qualquer formato;
        <li>Encontra clusters cercados por outros clusters;
        <li>Eficiente para encontrar ruído.
    </ul>
	<p>Como desvantagem:
    <ul>
        <li>Datasets com densidade de dados variável podem ser problemáticos;
        <li>Falha em identificar cluster se a sua densidade varia, ou se os dados estão muito esparsos;
        <li>Não funciona bem para dados multidimensionais.
    </ul>
	<p>É usado em na literatura científica, em imagens de satélite, cristalografia de raios-x e detecção de anomalias em dados que envolvem temperatura.
    <br>   
    <br> 
        
</ol>
    

    
   <li><h2>Referências</h2></li>
    <a href="https://towardsdatascience.com/machine-learning-basics-with-the-k-nearest-neighbors-algorithm-6a6e71d01761">https://towardsdatascience.com/machine-learning-basics-with-the-k-nearest-neighbors-algorithm-6a6e71d01761</a>
    <br>
    <a href="https://www.geeksforgeeks.org/k-nearest-neighbours/">https://www.geeksforgeeks.org/k-nearest-neighbours/</a>
    <br>
    <a href="https://medium.com/brasil-ai/knn-k-nearest-neighbors-1-e140c82e9c4e">https://medium.com/brasil-ai/knn-k-nearest-neighbors-1-e140c82e9c4e</a>
    <br>
    <a href="https://www.ibm.com/topics/knn#:~:text=The%20k%2Dnearest%20neighbors%20algorithm%2C%20also%20known%20as%20KNN%20or,of%20an%20individual%20data%20point">https://www.ibm.com/topics/knn#:~:text=The%20k%2Dnearest%20neighbors%20algorithm%2C%20also%20known%20as%20KNN%20or,of%20an%20individual%20data%20point</a>
    <br>
    <br>
    <a href="https://www.analyticsvidhya.com/blog/2017/09/naive-bayes-explained/#:~:text=Naive%20Bayes%20uses%20a%20similar,with%20problems%20having%20multiple%20classes.">https://www.analyticsvidhya.com/blog/2017/09/naive-bayes-explained/#:~:text=Naive%20Bayes%20uses%20a%20similar,with%20problems%20having%20multiple%20classes.</a>
    <br>
    <a href="https://www.digitalhouse.com/br/blog/naive-bayes/">https://www.digitalhouse.com/br/blog/naive-bayes/</a>
    <br>
    <a href="https://www.javatpoint.com/machine-learning-naive-bayes-classifier">https://www.javatpoint.com/machine-learning-naive-bayes-classifier</a>
    <br>
    <a href="https://www.turing.com/kb/an-introduction-to-naive-bayes-algorithm-for-beginners">https://www.turing.com/kb/an-introduction-to-naive-bayes-algorithm-for-beginners</a>
    <br>
    <br>
     <a href="https://www.geeksforgeeks.org/introduction-to-support-vector-machines-svm/?ref=rp">https://www.geeksforgeeks.org/introduction-to-support-vector-machines-svm/?ref=rp</a>
    <br>
    <a href="https://www.freecodecamp.org/news/svm-machine-learning-tutorial-what-is-the-support-vector-machine-algorithm-explained-with-code-examples/">https://www.freecodecamp.org/news/svm-machine-learning-tutorial-what-is-the-support-vector-machine-algorithm-explained-with-code-examples/</a>
    <br>
    <a href="https://www.geeksforgeeks.org/predicting-stock-price-direction-using-support-vector-machines/?ref=rp
">https://www.geeksforgeeks.org/predicting-stock-price-direction-using-support-vector-machines/?ref=rp</a>
    <br>
    <a href="https://techvidvan.com/tutorials/svm-applications/">https://techvidvan.com/tutorials/svm-applications/</a>
    <br>
    <br>
    <a href="https://www.javatpoint.com/machine-learning-random-forest-algorithm">https://www.javatpoint.com/machine-learning-random-forest-algorithm</a>
    <br>
    <a href="https://www.ibm.com/cloud/learn/random-forest">https://www.ibm.com/cloud/learn/random-forest</a>
    <br>
    <a href="https://didatica.tech/underfitting-e-overfitting/">https://didatica.tech/underfitting-e-overfitting/</a>
    <br>
    <a href="https://www.javatpoint.com/machine-learning-decision-tree-classification-algorithm">https://www.javatpoint.com/machine-learning-decision-tree-classification-algorithm</a>
    <br>
<a href="https://didatica.tech/o-que-e-e-como-funciona-o-algoritmo-randomforest/">https://didatica.tech/o-que-e-e-como-funciona-o-algoritmo-randomforest/</a>
    <br>
    <br>
    <a href="https://www.tibco.com/pt-br/reference-center/what-is-unsupervised-learning">https://www.tibco.com/pt-br/reference-center/what-is-unsupervised-learning</a>
    <br>
    <a href="https://www.inf.ufpr.br/menotti/am-18b/slides/ML-1112cluster-regression.pdf">https://www.inf.ufpr.br/menotti/am-18b/slides/ML-1112cluster-regression.pdf</a>
    <br>
    <a href="https://www.lume.ufrgs.br/bitstream/handle/10183/2702/000375416.pdf?sequence=1">https://www.lume.ufrgs.br/bitstream/handle/10183/2702/000375416.pdf?sequence=1</a>
    <br>
    <br>
    <a href="https://www.sas.com/pt_br/insights/analytics/processamento-de-linguagem-natural.html">https://www.sas.com/pt_br/insights/analytics/processamento-de-linguagem-natural.html</a>
    <br>
    <a href="https://www.wesuggestsoftware.com/the-pros-and-cons-of-using-natural-language-processing-tools/">https://www.wesuggestsoftware.com/the-pros-and-cons-of-using-natural-language-processing-tools/</a>
    <br>
    <a href="https://www.facom.ufu.br/~wendelmelo/terceiros/tutorial_nltk.pdf">https://www.facom.ufu.br/~wendelmelo/terceiros/tutorial_nltk.pdf</a>
    <br>
    <a href="https://cloud.google.com/learn/what-is-natural-language-processing?hl=pt-br">https://cloud.google.com/learn/what-is-natural-language-processing?hl=pt-br</a>
    <br>
    <a href="https://files.passeidireto.com/354091cd-ff8c-4181-a591-a221989a12fb/bg3.png">https://files.passeidireto.com/354091cd-ff8c-4181-a591-a221989a12fb/bg3.png</a>
    <br>
    <br>
    <a href="https://aws.amazon.com/pt/what-is/neural-network/">https://aws.amazon.com/pt/what-is/neural-network/</a>
    <br>
    <a href="https://ilumeo.com.br/todos-posts/2020/09/13/como-funcionam-as-redes-neurais-de-deep-learning">https://ilumeo.com.br/todos-posts/2020/09/13/como-funcionam-as-redes-neurais-de-deep-learning</a>
    <br>
    <a href="https://www.3dimensoes.com.br/post/deep-learning-conceitos-e-aplicações#:~:text=O%20algoritmo%20de%20Deep%20Learning%20recebe%20sinais%20de%20sensores%2C%20de,por%20um%20condutor%20humano%20comum.">https://www.3dimensoes.com.br/post/deep-learning-conceitos-e-aplicações#:~:text=O%20algoritmo%20de%20Deep%20Learning%20recebe%20sinais%20de%20sensores%2C%20de,por%20um%20condutor%20humano%20comum.</a>
    <br>
    <br>
    <a href="https://towardsdatascience.com/breaking-down-the-agglomerative-clustering-process-1c367f74c7c2">https://towardsdatascience.com/breaking-down-the-agglomerative-clustering-process-1c367f74c7c2</a>
    <br>
    <a href="https://www.educba.com/hierarchical-clustering-agglomerative/?source=leftnav">https://www.educba.com/hierarchical-clustering-agglomerative/?source=leftnav</a>
    <br>
    <a href="https://towardsdatascience.com/machine-learning-algorithms-part-12-hierarchical-agglomerative-clustering-example-in-python-1e18e0075019">https://towardsdatascience.com/machine-learning-algorithms-part-12-hierarchical-agglomerative-clustering-example-in-python-1e18e0075019</a>
    <br>
    <a href="https://community.ibm.com/community/user/datascience/blogs/moloy-de1/2020/07/16/points-to-ponder">https://community.ibm.com/community/user/datascience/blogs/moloy-de1/2020/07/16/points-to-ponder</a>
    <br>
    <a href="https://towardsdatascience.com/hierarchical-clustering-and-its-applications-41c1ad4441a6">https://towardsdatascience.com/hierarchical-clustering-and-its-applications-41c1ad4441a6</a>
    <br>
    <br>
    <a href="https://www.javatpoint.com/k-means-clustering-algorithm-in-machine-learning">https://www.javatpoint.com/k-means-clustering-algorithm-in-machine-learning</a>
    <br>
    <a href="https://www.linkedin.com/pulse/k-means-clustering-aashima-yuthika/">https://www.linkedin.com/pulse/k-means-clustering-aashima-yuthika/</a>
    <br>
    <a href="https://developers.google.com/machine-learning/clustering/algorithm/advantages-disadvantages">https://developers.google.com/machine-learning/clustering/algorithm/advantages-disadvantages</a>
    <br>
    <a href="https://www.linkedin.com/pulse/pros-cons-k-means-clustering-aashima-yuthika/">https://www.linkedin.com/pulse/pros-cons-k-means-clustering-aashima-yuthika/</a>
    <br>
    <a href="https://datapeaker.com/big-data/que-es-big-data-caracteristicas-de-big-data/">https://datapeaker.com/big-data/que-es-big-data-caracteristicas-de-big-data/</a>
    <br>
    <a href="https://www.linkedin.com/pulse/k-means-clustering-its-applications-ritvik-ranjan/">https://www.linkedin.com/pulse/k-means-clustering-its-applications-ritvik-ranjan/</a>
    <br>
    <a href="https://medium.com/programadores-ajudando-programadores/k-means-o-que-é-como-funciona-aplicações-e-exemplo-em-python-6021df6e2572#:~:text=K-Means%20é%20um%20algoritmo,lojas%2Fcentro%20logistico">https://medium.com/programadores-ajudando-programadores/k-means-o-que-é-como-funciona-aplicações-e-exemplo-em-python-6021df6e2572#:~:text=K-Means%20é%20um%20algoritmo,lojas%2Fcentro%20logistico</a>
    <br>
    <br>
    <a href="https://towardsdatascience.com/breaking-down-the-agglomerative-clustering-process-1c367f74c7c2">https://towardsdatascience.com/breaking-down-the-agglomerative-clustering-process-1c367f74c7c2</a>
    <br>
    <a href="https://www.educba.com/hierarchical-clustering-agglomerative/?source=leftnav">https://www.educba.com/hierarchical-clustering-agglomerative/?source=leftnav</a>
    <br>
    <a href="https://towardsdatascience.com/machine-learning-algorithms-part-12-hierarchical-agglomerative-clustering-example-in-python-1e18e0075019">https://towardsdatascience.com/machine-learning-algorithms-part-12-hierarchical-agglomerative-clustering-example-in-python-1e18e0075019</a>
    <br>
    <a href="https://community.ibm.com/community/user/datascience/blogs/moloy-de1/2020/07/16/points-to-ponder">https://community.ibm.com/community/user/datascience/blogs/moloy-de1/2020/07/16/points-to-ponder</a>
    <br>
    <a href="https://towardsdatascience.com/hierarchical-clustering-and-its-applications-41c1ad4441a6">https://towardsdatascience.com/hierarchical-clustering-and-its-applications-41c1ad4441a6</a>
    <br>
    <a href="https://www.datasklr.com/segmentation-clustering/hierarchical-clustering">https://www.datasklr.com/segmentation-clustering/hierarchical-clustering</a>
    <br>
    <br>
    <a href="https://www.maxwell.vrac.puc-rio.br/24787/24787_6.PDF">https://www.maxwell.vrac.puc-rio.br/24787/24787_6.PDF</a>
    <br>
    <a href="https://towardsdatascience.com/how-dbscan-works-and-why-should-i-use-it-443b4a191c80">https://towardsdatascience.com/how-dbscan-works-and-why-should-i-use-it-443b4a191c80</a>


```python

```
