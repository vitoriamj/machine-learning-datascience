#include<bits/stdc++.h>

using namespace std;

vector<string> v[9];//gaps
vector<string> vx[6];//total
vector<string> finais[12];// tabela de gaps trabalhadas
vector< int > tempos;//tempo de gap
vector< double> gaps;
vector<int > tempoPico;
vector< double> precoX;

vector<int> faixas[6];
vector < double> deltas[6];

void capturaMin(int x){
    double menor,x1;
    string s;
    menor = 1.0*(INT32_MAX);
    for (int i=(x-1);i>=(x-20);i--){
        //cout<<"o";
        s = vx[4][i];
        x1 = stod(s);
        menor = min(menor,x1);
    }
    gaps.push_back(menor);
}

void capturaMax(int x){
    double maior,x1;
    maior = 0.0;
    string s;
    for (int i=(x-1);i>=(x-20);i--){
        s = vx[3][i];
        x1 = stod(s);
        maior = max(maior,x1);
    }
    gaps.push_back(maior);
}

void capturaMinTempo(int posicao,int tempoFecha){
    double menor, x1;
    int tempo=0;
    menor = 1.0*INT32_MAX;
    string s;
    for(int i = (posicao); i<= (posicao + tempoFecha);i++){
        s = vx[5][i];
        x1 = stod(s);
        if(x1<menor){
            menor = x1;
            tempo = i - posicao;
        }
    }
    //tempoPico.push_back(make_pair(menor,tempo));
}

void gapAlta(double val1, double val2, int x){
    double aux,maiorvalor,maiorEfetivo=0;
    string aux2,aux3;
    int cont=0;
    for(int i=x;i<=(x+60);i++){
        aux2 = vx[4][i]; //mudar
        aux = stod(aux2);
        aux3 = vx[3][i]; //mudar
        maiorvalor = stod(aux3);
        cont++;
        maiorEfetivo = max(maiorEfetivo,maiorvalor);
        //cout<< menorEfetivo <<"\n";
        if(aux<=val2){
            tempos.push_back(cont);
            for(int j=x;j<=(x+60);j++){
                
                aux = stod(vx[3][j]);
                if(aux==maiorEfetivo){
                    cont = j-x;
                    tempoPico.push_back(cont);
                    break;
                }
            }
            precoX.push_back(maiorEfetivo - val1);
            break;
        }
        else if(cont == 60){
            tempos.push_back(61);
            for(int j=x;j<=(x+60);j++){
                aux = stod(vx[3][j]);
                if(aux==maiorEfetivo){
                    tempoPico.push_back(j-x);
                    break;
                }
            }
            precoX.push_back(maiorEfetivo - val1);
            break;
        }
    }
}

void gapQueda(double val1, double val2, int x){
    double aux,menorValor,menorEfetivo;
    string aux2,aux3;
    int cont=0;
    menorEfetivo = 1.0*INT32_MAX;
    for(int i=x;i<=(x+60);i++){
        aux2 = vx[3][i];
        aux = stod(aux2);
        aux3 = vx[4][i];
        menorValor = stod(aux3);
        cont++;
        menorEfetivo = min(menorEfetivo,menorValor);
        //cout<< menorEfetivo <<"\n";
        if(aux>=val2){
            tempos.push_back(cont);
            for(int j=x;j<=(x+60);j++){
                
                aux = stod(vx[4][j]);
                if(aux==menorEfetivo){
                    cont = j-x;
                    tempoPico.push_back(cont);
                    break;
                }
            }
            precoX.push_back(val1 - menorEfetivo);
            break;
        }
        else if(cont == 60){
            tempos.push_back(61);
            for(int j=x;j<=(x+60);j++){
                aux = stod(vx[4][j]);
                if(aux==menorEfetivo){
                    tempoPico.push_back(j-x);
                    break;
                }
            }
            precoX.push_back(val1 - menorEfetivo);
            break;
        }

    }
}


void pegaIndex(){
    int x=1;
    string s1,s2,busca;
    double val1,val2;
    for(int i=1;i<(v[0].size()-1);i++){
        s1 = v[0][i];
        for(int j=x;j<vx[0].size();j++){
            s2 = vx[0][j];
            if(s1==s2){
                x=j;
                break;
            }
        }

        // cout<<"data1 : "<<v[0][i]<<" tempo: "<<v[1][i];
        // cout<<" data2 : "<<vx[0][x]<<" tempo: "<<vx[1][x]<<"\n";
        s2 = v[2][i];//abre
        val1 = stod(s2);
        busca = v[8][i];
        val2 = stod(busca);//close
        gapQueda(val1,val2,x);
        //gapAlta(val1,val2,x);
        // cout<<val1<<" "<<val2<<"\n";
        // if(val1>val2){
        //     gapAlta(val1,val2,x);
        //     capturaMax(x);
        // }
        // else{
        //     capturaMin(x);
        //     gapQueda(val1,val2,x);
        // }
        //cout<<vx[4][x]<<" x\n";
    }
}


void tabelaFrequencia(){
    double aux1, aux2,ans;
    for(int i=1;i<finais[1].size();i++){
        //pegar o tam do gap 2 - 8
        aux1 = stod(finais[2][i]);
        aux2 = stod(finais[8][i]);
        ans = abs(aux1 - aux2);
        if(finais[10][i]!="61"){
        if( (ans)<10.0 ){
            faixas[0].push_back(i);

        }else if( (ans)<15.0 ){
            faixas[1].push_back(i);

        } else if( (ans)<20.0 ){
            faixas[2].push_back(i);


        }else if( (ans)<25.0 ){
            faixas[3].push_back(i);


        }else if( (ans)< 30.0 ){
            faixas[4].push_back(i);

        }
        else{
            faixas[5].push_back(i);
        }
        }
    }
    int index,qtd=0;
    double deltap, deltat, deltat1;
    deltap = deltat = deltat1 = 0.0;
    double d1,d2,d3;
    for(int i=0;i<6;i++){
        cout<<faixas[i].size()<<"\n";
        for(int j=0; j<faixas[i].size();j++){
            qtd++;
            index = faixas[i][j];
            d1 = stod(finais[9][index]);
            d2 = stod(finais[10][index]);
            d3 = stod(finais[11][index]);
            deltap += d1;
            deltat += d2;
            deltat1 += d3;
        }
        if(qtd==0){
            qtd=1;
        }
        deltas[i].push_back( deltap  / (1.0*qtd) );
        deltas[i].push_back( deltat  / (1.0*qtd) );
        deltas[i].push_back( deltat1 / (1.0*qtd) );
        deltap = deltat = deltat1 = 0.0;
        qtd = 0;
    }
}

void arquivosprontos(){
    ifstream fin;
    fin.open("gapsAtualMaiorFinals1hr.csv");
    string line;
    int aux = 0;
    while(!fin.eof()){
        fin>>line;
        finais[aux].push_back(line);
        aux = (++aux)%12;
    }
}

void lerArquivos(){
    ifstream fin;
    fin.open("gapsOntemMaior.csv");
    string line;  
    int aux=0;
    while(!fin.eof()){
        fin>>line;
        v[aux].push_back(line);
        aux = (++aux)%9;
    }
    fin.close();
    ifstream fin2;
    fin2.open("reduzidoTotal.csv"); 
    aux=0;
    while(!fin2.eof()){
        fin2>>line;
        vx[aux].push_back(line);
        aux = (++aux)%6;
    }
    fin2.close();
}

void write_csv(std::string filename, std::string colname){
    
    // Create an output filestream object
    std::ofstream myFile(filename);
    
    // Send the column name to the stream
    myFile << colname << "\n";
    
    // Send data to the stream
    //++i  .at(i)
    for(int i = 0; i < precoX.size(); ++i)
    {
        myFile << precoX.at(i) << "\n";
    }
    
    // Close the file
    myFile.close();
}



int main(){
    // lerArquivos();
    arquivosprontos();
    tabelaFrequencia();
    // for(int i =0;i<12;i++ ){
    //     cout<<finais[i].size()<<" ";
    // }
    for( int i =0;i<6;i++){
        for(int j=0;j<deltas[i].size();j++){
            cout<<deltas[i][j]<<" ";
        }
        cout<<"\n";
    }
    // pegaIndex();
    // write_csv("lowprecolow1hr.csv", "<PRECO_LOW>");
    // for(int i=0;i<tempoPico.size();i++){
    //     cout<<tempoPico[i]<<" ";
    // }
    // for(int i=0;i<vx[1].size();i++){
    //     for(int j=0;j<9;j++){
    //         cout<<vx[j][i]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<v[1].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}