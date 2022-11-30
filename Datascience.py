#!/usr/bin/env python
# coding: utf-8

# <h1>Machine Learning: Algoritmos de Aprendizado Supervisionado e Não Supervisionado</h1>
# 
# <h4>
#     Alexandre Arantes e Vitória Mendonça
#     <br>
#     <i>Universidade Federal de Goiás</i>
# </h4>
# 
# <ol>
#     <li><h3>Introdução</h3></li>
#     Nos últimos anos, houve um crescimento exponencial na geração de dados, os quais vão desde o seu histórico de compras em um site online aos vídeos rápidos que você assiste no TikTok ou no Instagram.
#     <br>
#     Esse enorme volume de dados, fez com que palavras como Data Science, Machine Learning, Big Data e  algoritmos de aprendizado, se tornassem mais presentes e famosas no cotidiano. Mas afinal o que elas significam? De maneira geral, esses termos se referem a como trabalhar com os dados. Ou seja, como podemos usar essas informações para tornar tarefas mais eficientes, automatizar serviços ou recomendar novas compras.
#     <br>
#     Para fazer esses serviços coletamos um volume de dados, colocamos no computador e o treinamos para realizar tarefas. Para isso, precisamos da ajuda dos algoritmos de aprendizado. São eles que, com base na entrada, dizem qual a ação deve ser tomada.
#     <br>
#     Diante do exposto, vamos explorar o estado da arte desses algoritmos, discorrendo sobre a aprendizagem supervisionada e, posteriormente, a aprendizagem não supervisionada.
#     <br>
#     
# 
# <li><h3>Aprendizado Supervisionado</h3>
# 	O aprendizado supervisionado acontece quando se tem conhecimento dos dados e qual o resultado das perguntas. Ou seja, quando já se tem noção da relação entre entrada e saída. Esse aprendizado ocorre normalmente quando temos um problema de Classificação ou de Regressão. Mas qual é a diferença entre esses dois problemas?
#     <br>
# 	Por exemplo, ao analisar um filme ele pode ser de ação, drama, romance, comédia, terror etc. Quando se trata de um problema de classificação a intenção será prever a categoria da entrada. A regressão semelhante a classificação também quer saber a categoria da entrada, porém ela usa um valor numérico como resposta.
#     <br>
# 	Para todas as situações é necessário que se tenham medidas para medir o desempenho de algoritmos. Em problemas de classificação a acurácia e o erro são as principais ferramentas para medir o desempenho. A acurácia é o total de observações classificadas corretamente divida pelo total de previsões e o erro se dá pela subtração da acurácia de um.
#     <br>
# 	Em problemas de regressão o mais usado é o RMSE (Raiz do Erro Quadrado Médio) que na prática consiste na distância entre cada precisão e a linha de regressão, sendo que quanto maior o RMSE, pior a precisão do modelo.
#     <br>
#     É importante lembrar que nem sempre essas duas ferramentas são capazes de dizer a precisão de um modelo de aprendizado supervisionado.
#     <br>
#     <br>
#     
# <ol>
#     <li><h3>K-Nearest Neighbours (KNN)</h3></li>
#         É um algoritmo que utiliza a proximidade para fazer classificações sobre algum tipo de dado, é normalmente usado como um algoritmo para classificar dados, partindo do princípio que dados similares estarão próximos um do outro. Bastante útil no reconhecimento de padrões, por exemplo, visto que os dados com um comportamento parecido não ficarão distantes.
#     <br>
#     Então para determinar essa proximidade, podemos calcular a distância entre esses dados usando alguns fatores e métodos. Entre os mais usados estão:
#     <br>
#     Distância euclidiana: mede a distância em linha reta entre os pontos consultados e os pontos sendo medidos.
#     $$ d(x,y)=\sqrt[]{\sum_{i=1}^{n}(y_i-x_i)^2} $$
#     <br>
#     Distância de Manhattan: Mede o valor absoluto entre dois pontos
#     $$ d(x,y) = \sum_{i=1}^{n}|y_i-x_i| $$
#     <br>
#     Existem outras distâncias como a de Minkowski e a de Hamming, mas não é o intuito explorá-las.
#     <br>
#     O K no nome define quantos vizinhos iremos checar. Definir K é extremamente importante, pois alguns valores podem levar a algo extremamente complexo ou ineficiente. Obviamente a escolha de K vai depender dos dados de entrada. Dados com mais outliers (que fogem da normalidade) precisam de valores de K maiores. É interessante usar sempre valores ímpares de K, independente da entrada para evitar empates na classificação.
#     <br>
#     Entre as vantagens do K-NN temos:
#     <ul/>
#     <li>Implementação fácil;</li>
#     <li>Boa capacidade de adaptação à medida que novos dados são inseridos;</li>
#     <li>poucos hiperparâmetros (apenas um valor para K e uma distância métrica).</li>
#     </ul>
#         <br>
#     As desvantagens acabam sendo:
#     <ul>
#         <li>Requer quantidades significativas de memória e armazenamento, o que aumenta o custo financeiro (mais equipamento) e de processamento;</li>
#         <li>Não consegue apresentar bons resultados com dados com uma grande dimensionalidade, pois após o algoritmo se ater a um número otimizado de resultados, tenta aumentar o erro na classificação dos dados, especialmente se tratando de amostras pequenas.</li>
#     </ul>
#     <br>
#     Normalmente os algoritmos de K-NN, usam uma priority queue para deixar a complexidade em $O(n*log(k))$
#     <br>
#     Os algoritmos de K-NN são usados principalmente em:
#     <ul>
#     <li>Algoritmos de recomendação: algoritmos que com base no que o usuário consumiu, recomenda novos produtos, os quais podem ser de filmes até produtos do dia-a-dia;</li>
#     <li>Finanças: Bancos usam algoritmos para saber o risco de inadimplência de clientes na hora de fornecer um empréstimo, usado previsão de bolsa de valores e até mesmo para analisar possíveis esquemas de lavagem de dinheiro;</li>
#     <li>Saúde: Análise da probabilidade de pacientes desenvolverem alguma doença genética, verificando anomalias no DNA.</li>
#     </ul>
#     <br>
# 
#     
#  <li><h3>Naive-Bayes</h3></li>
#     O algoritmo de Naive-Bayes é um classificador probabilístico que é baseado no teorema de Bayes. Não é um apenas um algoritmo, mas um conjunto desses que compartilham um mesmo princípio, cada par de eventos que está sendo classificado é independente um do outro.
#     <br>
# O teorema de Bayes quer saber a probabilidade de um evento ocorrer, sabendo que outro evento ocorreu:
# $ p(A|B) = \frac{p(B|A)p(A)}{p(B)} $
#     <br>
# Naive assume que os eventos possuem independência entre si.
#     <br>
# O funcionamento do algoritmo em si é simples, os dados são convertidos para uma tabela de frequência. Posteriormente, as probabilidades dos eventos necessários para a classificação dos dados são calculadas e postas em outra tabela. Após, a equação de Naive-Bayes é usada para calcular  a probabilidade para cada classe. A classe com a maior probabilidade será a resposta.
#     <br>
# $$ p(c|X) = \frac{p(X|c)p(c)}{p(X)} $$
# Na fórmula acima, p(c|X) é a probabilidade de c de acordo com o dado X, p(X|c) é a probabilidade do dado c sendo X verdade, p(c) é a probabilidade de c ser verdade e p(x) é  a probabilidade de X ser verdade.
#     <br>
#     <br>
# Entre as vantagens deste algoritmo estão:
#     <ul>
# <li>É fácil e rápido predizer as classificações dos dados de entrada, além de ter boa performance em multiclasses;
# <li>Quando a independência entre os eventos é verdadeira, ele performa melhor que outros algoritmos de classificação, como regressão logística, e  precisa de menos dados para treinar a IA;
# <li>Funciona melhor quando a entrada de dados é categórica e não númerica, isto é, pode ser divida em grupos, como sexo, idade.
#     </ul>
#     <br>
# Já pelo lados das desvantagens destacam-se:
#     <ul>
# <li>Se uma categoria nos dados de entrada não estava nos dados de aprendizado, ela terá frequência zero e não será recomendada;
# <li>Não é um algoritmo muito bom para fazer estimativas;
# <li>O teorema assume que os eventos são 100% independentes, porém no mundo real é bem raro que os eventos sejam completamente independentes.
#     </ul>
#     <br>
# Esse algoritmo acaba por ser muito utilizado para:
#     <ul>
# <li>Realizar predições em tempo real, como o algoritmo é rápido, ele pode ser usado para realizar predições instantâneas;
# <li>Também pode ser usado para predição de múltiplas classes, isto é, dado uma entrada pode calcular as probabilidades de ela pertencer a uma classe;
# <li>Extremamente usado em filtros de spam e análise de sentimentos em redes sociais, visto que pode calcular a probabilidade de um email ser spam, além de conseguir analisar post em redes sociais e tentar predizer a opinião ali exposta;
# <li>Algoritmos de recomendação em geral.
#     </ul>
#     <br>
# 
#     
# <li><h3>Suport Vector Machine (SVM)</h3></li>    
# O SVM (Support Vector Machine) é um algoritmo usado tanto para regressão quanto para classificação. Esse algoritmo busca achar um hiperplano entre pontos de dados, que irá classificar os dados. Se tivermos em 2 dimensões o hiperplano será uma reta, e em 3 dimensões um plano 2D. O algoritmo busca achar entre os hiperplanos existentes aquele com a maior distância possível entre os dados distintos.
#     <br>
#     ![image2.png](attachment:image2.png)
# 	Na figura acima esse hiperplano será o L2. Abaixo, segue um exemplo em 3 dimensões.
# 
# Em algumas situações pode ser complicado separar os pontos em 2 dimensões por uma reta de uma maneira satisfatória. Para isso, pode-se utilizar algumas técnicas, que leva os pontos para 3 dimensões, encontrar o hiperplano e transformar os pontos em 2 dimensões. Por exemplo imagine que temos o seguinte conjunto, porém, inicialmente, não temos a informação de quais pontos são vermelhos e quais são azuis:
# 
# Observe que é impossível traçar uma reta capaz de separar os pontos azuis e vermelhos, porém se colocar os pontos em 3 dimensões, como a figura abaixo:
# 
# agora temos uma nítida separação entre os pontos. Podemos então encontrar o hiperplano e retornar em 2 dimensões, com definição entre pontos azuis e vermelhos encontrada. Essa manobra de usar 3 dimensões para encontrar as diferenças no conjunto dados  é chamada de Truque de Kernel e é responsável por dar uma versatilidade bem maior para os algoritmos de SVM.
# 	Como vantagens destacam-se:
# Uso bastante efetivos em conjunto de dados com múltiplas funcionalidades, como dados financeiros ou médicos.
# Usa um subconjunto de pontos para aprendizado na função de decisão,os quais são chamados de “support vectors”, o qual torna o uso de memória mais eficiente, ou seja, utiliza menos recursos.
# Diferentes funções de Kernel podem ser especificadas para as funções de decisão, pode usar algumas funções específicas também, o que aumenta a versatilidade e a precisão do algoritmo.
# Pelo ponto de vista das desvantagens:
# Funciona melhor quando os dados que serão usados para treinar o algoritmo, não forem muito grandes visto que o tempo de treinamento é alto.
# Não funciona muito bem quando os dados têm mais ruído, isto é, as classes de destino estão mais sobrepostas.
# Os algoritmos de SVM são bastante usados em vários campos:
# Na saúde, são usados para predizer a agressividade de tumores, mapeamento genético.
# Em processamentos de imagens, identificando irregularidades em superfícies, para modelos de reconhecimento facial e de diferenciação de expressão (identificação de sentimentos).
# Na geologia, é usada para fazer mapeamento de camadas do solo.
# No processamento de linguagem usado para classificação de textos por assuntos.
# 
# 
# 
# 
# 
# <li><h3>Referências</h3></li>
# <a href="https://towardsdatascience.com/machine-learning-basics-with-the-k-nearest-neighbors-algorithm-6a6e71d01761">https://towardsdatascience.com/machine-learning-basics-with-the-k-nearest-neighbors-algorithm-6a6e71d01761</a>
# <br>
# <a href="https://www.geeksforgeeks.org/k-nearest-neighbours/">https://www.geeksforgeeks.org/k-nearest-neighbours/</a>
# <br>
# <a href="https://medium.com/brasil-ai/knn-k-nearest-neighbors-1-e140c82e9c4e">https://medium.com/brasil-ai/knn-k-nearest-neighbors-1-e140c82e9c4e</a>
# <br>
# <a href="https://www.ibm.com/topics/knn#:~:text=The%20k%2Dnearest%20neighbors%20algorithm%2C%20also%20known%20as%20KNN%20or,of%20an%20individual%20data%20point">https://www.ibm.com/topics/knn#:~:text=The%20k%2Dnearest%20neighbors%20algorithm%2C%20also%20known%20as%20KNN%20or,of%20an%20individual%20data%20point</a>
# <br>
# <br>
# <a href="https://www.analyticsvidhya.com/blog/2017/09/naive-bayes-explained/#:~:text=Naive%20Bayes%20uses%20a%20similar,with%20problems%20having%20multiple%20classes.">https://www.analyticsvidhya.com/blog/2017/09/naive-bayes-explained/#:~:text=Naive%20Bayes%20uses%20a%20similar,with%20problems%20having%20multiple%20classes.
# <br>
# <a href="https://www.digitalhouse.com/br/blog/naive-bayes/">https://www.digitalhouse.com/br/blog/naive-bayes/
# <br>
# <a href="https://www.javatpoint.com/machine-learning-naive-bayes-classifier">https://www.javatpoint.com/machine-learning-naive-bayes-classifier
# <br>
# <a href="https://www.turing.com/kb/an-introduction-to-naive-bayes-algorithm-for-beginners">https://www.turing.com/kb/an-introduction-to-naive-bayes-algorithm-for-beginners
# <br> 
# 

# In[ ]:




