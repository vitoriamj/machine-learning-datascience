#include<bits/stdc++.h>

using namespace std;

vector<string> v[9];//gaps
vector<string> vx[6];//total
vector< int > tempos;//tempo de gap
vector< double> gaps;
vector<int > tempoPico;
vector< double> precoX;

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
    for(int i=x;i<=(x+20);i++){
        aux2 = vx[4][i]; //mudar
        aux = stod(aux2);
        aux3 = vx[3][i]; //mudar
        maiorvalor = stod(aux3);
        cont++;
        maiorEfetivo = max(maiorEfetivo,maiorvalor);
        //cout<< menorEfetivo <<"\n";
        if(aux<=val2){
            tempos.push_back(cont);
            for(int j=x;j<=(x+20);j++){
                
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
        else if(cont == 20){
            tempos.push_back(21);
            for(int j=x;j<=(x+20);j++){
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
    for(int i=x;i<=(x+20);i++){
        aux2 = vx[3][i];
        aux = stod(aux2);
        aux3 = vx[4][i];
        menorValor = stod(aux3);
        cont++;
        menorEfetivo = min(menorEfetivo,menorValor);
        //cout<< menorEfetivo <<"\n";
        if(aux>=val2){
            tempos.push_back(cont);
            for(int j=x;j<=(x+20);j++){
                
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
        else if(cont == 20){
            tempos.push_back(21);
            for(int j=x;j<=(x+20);j++){
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

void pegaMaximo(){
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
        //gapQueda(val1,val2,x);
        gapAlta(val1,val2,x);
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

void lerArquivos(){
    ifstream fin;
    fin.open("gapsHjMaior.csv");
    string line;  
    int aux=0;
    bool nomeColuna = true ;
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
    lerArquivos();
    pegaMaximo();
    write_csv("altprecomax.csv", "<PRECO_HIGH>");
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