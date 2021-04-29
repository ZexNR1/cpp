/*Buturugeanu Iulian-Alexandru
Grupa 1332a
Sortare siruri de caractere
*/
#include<iostream>
#include<cstring>
using namespace std;
int cuv;
char** spargereString(char s[256]){
    int i,j,l=0,k=0,n=strlen(s)+1;
    cuv=1;
    for(int i=0;i<n;i++){
        while(s[i]==' ')
            i++;
        if(s[i]!=' ' && s[i+1]==' ')
            cuv++;
    }
    i=0;
    char**vs=new char*[cuv];
    char *p=strtok(s," ");
    while(p!=NULL){
        vs[i]=new char[strlen(p)+1];
        strcpy(vs[i],p);
        p=strtok(NULL," ");
        i++;
    }
    return vs;
}
bool comparatieCaractere(char s1[256], char s2[256]){
    int i=0,n=strlen(s1),m=strlen(s2),minim;
    if(n<m)
        minim=n;
    else minim=m;
    while(s1[i]==s2[i] && i<minim)
        i++;
    if(s1[i]>s2[i])
        return true;
    return false;
}
void sortareBule(char **s){
    int inv;
    do{
        inv=0;
        for(int i=0;i<cuv-1;i++)
            if(comparatieCaractere(s[i],s[i+1])){
                char *man;
                man=s[i];
                s[i]=s[i+1];
                s[i+1]=man;
                inv=1;
            }
    }while(inv);
}
void sortareSelectie(char **s){
    char *man;
    for(int i=0;i<cuv-1;i++){
        int poz=i;
        for(int j=i+1;j<cuv;j++)
            if(!comparatieCaractere(s[j],s[poz]))
                poz=j;
        man=s[i];
        s[i]=s[poz];
        s[poz]=man;
    }
}
void sortareNumarare(char **a){
    char b[256]={'0'};
    char **c=new char*[cuv];
    for(int i=0;i<cuv;i++)
        b[i]=0;
    for(int i=0;i<cuv-1;i++){
        for(int j=i+1;j<cuv;j++)
            if(comparatieCaractere(a[i],a[j]))
                b[i]++;
            else b[j]++;
    }
    for(int i=0;i<cuv;i++)
        c[b[i]]=a[i];
    for(int i=0;i<cuv;i++)
        a[i]=c[i];
}
void sortareInsertie(char **s){
    char *man;
    for(int i=0;i<cuv;i++){
        for(int j=i;j>0;j--)
            while(!comparatieCaractere(s[j],s[j-1])){
                man=s[j];
                s[j]=s[j-1];
                s[j-1]=man;
            }
    }
}
void citireString(char s[256]){
    cin.get();
    cin.get(s,256);
    cin.get();
}
void afisareString(char **vs){
    for(int i=0;i<cuv;i++){
        for(int j=0;j<strlen(vs[i]);j++)
            cout<<vs[i][j];
        cout<<' ';
    }
}
int main(){
    cout<<endl<<"Proiect ASD - 2021"<<endl;
    cout<<"Alex Buturugeanu"<<endl<<endl;
    int op;
    do
    {
        cout<<endl<<"Algoritmi de sortare pentru siruri de caractere"<<endl;
        cout<<"1. Bubble Sort"<<endl;
        cout<<"2. Selection Sort"<<endl;
        cout<<"3. Counting Sort"<<endl;
        cout<<"4. Insertion Sort"<<endl;
        cout<<"0. Inchide program"<<endl<<endl;
        cout<<"Citeste optiunea: ";cin>>op;
        switch(op){
            case 1:{
                cout<<endl;
                cout<<"1. Bubble Sort"<<endl;
                char s[256];
                char **vs;
                cout<<"Sirul de caractere: "<<endl;
                citireString(s);
                cout<<endl;
                vs=spargereString(s);
                sortareBule(vs);
                cout<<"Sirul de caractere dupa ordonare: "<<endl;
                afisareString(vs);
                cout<<endl;
            }
            break;
            case 2:{
                cout<<endl;
                cout<<"2. Selection Sort"<<endl;
                char s[256];
                char **vs;
                cout<<"Sirul de caractere: "<<endl;
                citireString(s);
                cout<<endl;
                vs=spargereString(s);
                sortareSelectie(vs);
                cout<<"Sirul de caractere dupa ordonare: "<<endl;
                afisareString(vs);
                cout<<endl;
            }
            break;
            case 3:{
                cout<<endl;
                cout<<"3. Counting Sort"<<endl;
                char s[256];
                char **vs;
                cout<<"Sirul de caractere: "<<endl;
                citireString(s);
                cout<<endl;
                vs=spargereString(s);
                sortareNumarare(vs);
                cout<<"Sirul de caractere dupa ordonare: "<<endl;
                afisareString(vs);
                cout<<endl;
            }
            break;
            case 4:{
                cout<<endl;
                cout<<"4. Insertion Sort"<<endl;
                char s[256];
                char **vs;
                cout<<"Sirul de caractere: "<<endl;
                citireString(s);
                cout<<endl;
                vs=spargereString(s);
                sortareInsertie(vs);
                cout<<"Sirul de caractere dupa ordonare: "<<endl;
                afisareString(vs);
                cout<<endl;
            }
            break;
            case 0:
                cout<<"Inchide program"<<endl;
            break;
            default:
                cout<<"Optiune gresita!"<<endl;
            break;
        }
    }while(op!=0);
    return 0;

}
