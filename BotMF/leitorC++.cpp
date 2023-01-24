#include<bits/stdc++.h>

using namespace std;

vector<string> v[5];//gaps
vector<string> vx[9];//total
vector< int > tempos;//tempo de gap
vector< double> gaps;

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

void gapAlta(double val1, double val2, int x){
    double aux;
    string aux2;
    int min=0;
    for(int i=x;i<(x+20);i++){
        aux2 = vx[2][i];
        aux = stod(aux2);
        min++;
        if( aux < val2){
            tempos.push_back(min);
            break;
        }
        else if(min == 20){
            tempos.push_back(21);
            break;
        }

    }
}

void gapQueda(double val1, double val2, int x){
    double aux;
    string aux2;
    int min=0;
    for(int i=x;i<(x+20);i++){
        aux2 = vx[2][i];
        aux = stod(aux2);
        min++;
        if(aux>val2){
            tempos.push_back(min);
            break;
        }
        else if(min == 20){
            tempos.push_back(21);
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
        busca = v[4][i];
        val2 = stod(busca);//close
        // cout<<val1<<" "<<val2<<"\n";
        if(val1>val2){
            //gapAlta(val1,val2,x);
            capturaMax(x);
        }
        else{
            capturaMin(x);
            //gapQueda(val1,val2,x);
        }
        //cout<<vx[4][x]<<" x\n";
    }
}

void lerArquivos(){
    ifstream fin;
    fin.open("reduzido.csv");
    string line;  
    int aux=0;
    bool nomeColuna = true ;
    while(!fin.eof()){
        fin>>line;
        v[aux].push_back(line);
        aux = (++aux)%5;
    }
    fin.close();
    ifstream fin2;
    fin2.open("WDO$N_M1.csv"); 
    aux=0;
    while(!fin2.eof()){
        fin2>>line;
        vx[aux].push_back(line);
        aux = (++aux)%9;
    }
    fin2.close();

}

void write_csv(std::string filename, std::string colname){
    
    // Create an output filestream object
    std::ofstream myFile(filename);
    
    // Send the column name to the stream
    myFile << colname << "\n";
    
    // Send data to the stream
    for(int i = 0; i < gaps.size(); ++i)
    {
        myFile << gaps.at(i) << "\n";
    }
    
    // Close the file
    myFile.close();
}

void estudaGaps(){
    string s1,s2;
    double d1,d2;
    for(int i = 1; i<v[2].size();i++ ){
        s1 = v[2][i];
        s2 = v[4][i];
        d1 = stod(s1);
        d2 = stod(s2);
        gaps.push_back(d1-d2);
    }
}


int main(){
    lerArquivos();
    pegaMaximo();
    //estudaGaps();
    write_csv("minMaxAnt.csv", "<MIN_MAX>");
    for(int i=0;i<gaps.size();i++){
        cout<<gaps[i]<<" ";
    }
    // for(int i=0;i<9;i++){
        // for(int j=0;j<20;j++){
        //     cout<<vx[i][j]<<" ";
        // }
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