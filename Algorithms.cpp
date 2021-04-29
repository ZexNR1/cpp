#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct numar{
    int v;
    numar* urm;
};
struct numar2{
    int v;
    numar2 *urm;
    numar2 *prec;
};
struct lista2{
    numar2 *prim;
    numar2 *ultim;
};
void ecuatieGrad2(float a, float b,float c){
    float d=0,x1=0,x2=0,x=0,pi=0,pr=0;
    if(a!=0){
        d=pow(b,2)-(4*a*c);
        if(d>0){
            x1=(-b+sqrt(d))/(2*a);
            x2=(-b-sqrt(d))/(2*a);
            cout<<"x1="<<x1<<endl;
            cout<<"x2="<<x2<<endl;
        }
        else if(d<0){
            cout<<"Ecuatia are radacini complexe"<<endl;
            d=abs(d);
            pr=-b/(2*a);
            pi=sqrt(d)/(2*abs(a));
            cout<<"x1="<<pr<<"+"<<pi<<"i"<<endl;
            cout<<"x2="<<pr<<"-"<<pi<<"i"<<endl;
            }
        else if(d==0){
            x=-b/(2*a);
            cout<<"x="<<x<<endl;
        }
    }
    else {
        if(b!=0){
            x=-c/b;
            cout<<"x="<<x<<endl;
        }
        else {
            if(c!=0)
                cout<<"Solutia e multimea vida"<<endl;
            else cout<<"Ecuatia are o infinitate de solutii"<<endl;
        }
    }
}
void citireMatrice(int **a,int n,int m){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
}
void afisareMatrice(int **a,int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}
void inmultireMatrice(int **a,int **b, int n1, int n2,int m1,int m2){
    if(m1==n2){
        int **c=new int*[n1];
        for(int i=1;i<=n1;i++)
            c[i]=new int[m2];
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=m2;j++){
                c[i][j]=0;
                for(int k=1;k<=m1;k++)
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
        cout<<"Matricea A*B="<<endl;
        afisareMatrice(c,n1,m2);
        delete[]c;
    }
    else cout<<"Inmultirea celor doua matrice nu se poate realiza"<<endl;
}
int prim(int n){
    if(n==2 || n==3)
        return 1;
    for(int i=2;i<sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}
void schimbareBaza(int n,int b){
    int cpn=n,k=0;
    int *v=new int[k];
    while(n>0){
        v[k++]=n%b;
        n=n/b;
    }
    for(int i=k-1;i>=0;i--)
        cout<<v[i];
    cout<<endl;
    delete[]v;
}
int numarMaxim(int *v,int n){
    int maxim=v[0];
    for(int i=1;i<n;i++)
        if(v[i]>maxim)
            maxim=v[i];
    return maxim;
}
void afisareVector(int *v,int n){
    for(int i=0;i<n;i++)
        cout<<v[i]<<' ';
    cout<<endl;
}
void citireVector(int *v,int n){
    for(int i=0;i<n;i++)
        cin>>v[i];
}
void bule(int *v,int n){
    int inv=0,man;
    do{
        inv=0;
        for(int i=0;i<n-1;i++)
            if(v[i]>v[i+1]){
                man=v[i];
                v[i]=v[i+1];
                v[i+1]=man;
                inv=1;
        }
    }while(inv);
}
void sortareSelectie(int *v,int n){
    int man;
    for(int i=0;i<n-1;i++){
        int poz=i;
        for(int j=i+1;j<n;j++)
            if(v[j]<v[poz])
                poz=j;
        man=v[i];
        v[i]=v[poz];
        v[poz]=man;
    }
}
void sortareNumarare(int *a,int n){
    int *b=new int[n];
    int *c=new int[n];
    for(int i=0;i<n;i++)
        b[i]=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j])
                b[i]++;
            else b[j]++;
    }
    for(int i=0;i<n;i++)
        c[b[i]]=a[i];
    for(int i=0;i<n;i++)
        a[i]=c[i];
    delete[]b;
    delete[]c;
}
void interclasare(int *v,int n, int p, int q,int r){
    int k=0,i=p,j=q+1,l;
    int *a=new int[n];
    while((i<=q) && (j<=r)){
        if(v[i]<v[j]){
            a[k]=v[i];
            k++;
            i++;
        }
        else{
            a[k]=v[j];
            j++;
            k++;
        }
    }
    if(i>q)
    for(l=j;l<=r;l++){
       a[k]=v[l];
       k++;
    }
    else
    for(l=i;l<=q;l++){
        a[k]=v[l];
        k++;
    }
    j=p;
    for(i=0;i<(r-p+1);i++){
        v[j]=a[i];
        j++;
    }
    delete[]a;
}
void sortareInterclasare(int *v,int n,int p,int r){
    int m;
    if(p<r){
        m=(p+r)/2;
        sortareInterclasare(v,n,p,m);
        sortareInterclasare(v,n,m+1,r);
        interclasare(v,n,p,m,r);
    }
}
void pozitie(int *v,int s,int d,int &k){
    int i=s,j=d,man=0,inv=0;
    while(i<j){
        if(v[i]>v[j]){
            man=v[i];
            v[i]=v[j];
            v[j]=man;
            inv=1;
        }
        if(inv)j--;
            else i++;
    }
    k=i;
}
void quickSort(int *v,int li,int ls){
    int k=0;
    if(li<ls){
        pozitie(v,li,ls,k);
        quickSort(v,li,k-1);
        quickSort(v,k+1,ls);
    }
}
void sortareInsertie(int *v,int n){
    int man,j;
    for(int i=0;i<n;i++){
        for(j=i;j>0 && v[j]<v[j-1];j--){
            man=v[j];
            v[j]=v[j-1];
            v[j-1]=man;
        }
    }
}
void shellSort(int *v,int n){
    int pas=n/2,aux=0,j=0;
    while(pas>0){
        for(int i=pas;i<n;i++){
            aux=v[i];
            j=i;
            while(j>=pas && v[j-pas]>aux){
                v[j]=v[j-pas];
                j=j-pas;
            }
            v[j]=aux;
        }
        pas=pas/2;
    }
}
void countSort(int *v,int n,int exp){
    int *a=new int[n];
    int b[10]={0};
    for(int i=0;i<n;i++)
        b[(v[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        b[i]=b[i]+b[i-1];
    for(int i=n-1;i>=0;i--){
        a[b[(v[i]/exp)%10]-1]=v[i];
        b[(v[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
        v[i]=a[i];
}
void radixSort(int *v,int n){
    int maxim=numarMaxim(v,n);
    for(int exp=1;maxim/exp>0;exp=exp*10)
        countSort(v,n,exp);
}
void cautareSecventiala(int *v, int n){
    int x,c=0;
    cout<<"Elementul cautat: ";cin>>x;
    for(int i=0;i<n;i++)
        if(x==v[i])
            c++;
    if(c==0)
        cout<<"Elementul "<<x<<" nu se gaseste in sir"<<endl;
    else cout<<"Elementul "<<x<<" apare in sir de "<<c<<" ori"<<endl;
}
int cautareBinara(int *v,int x,int s,int d){
    int m=0;
    if(s>d) return -1;
    else{
        m=(s+d)/2;
        if(x==v[m])
            return m;
        if(x<v[m])
            return cautareBinara(v,x,s,m-1);
        else return cautareBinara(v,x,m+1,d);
    }
}
numar *creareLista(){
    numar *cap, *u, *p;
    int x,n;
    cap=new numar;
    cout<<"Cap Lista: ";cin>>x;
    cap->v=x;
    cap->urm=NULL;
    u=cap;
    cout<<"Numarul de elemente pe care vreau sa il adaug in lista: ";cin>>n;
    while(n){
        p=new numar;
        cout<<"Adaug: ";cin>>x;
        p->v=x;
        p->urm=NULL;
        u->urm=p;
        u=p;
        n--;
    }
    return cap;
}
void parcurgereLista(numar *cap){
    numar *p;
    if(cap==NULL)
        cout<<"Lista este vida!"<<endl;
    else{
            p=cap;
            while(p!=NULL){
                cout<<p->v<<' ';
                p=p->urm;
        }
    }
}
numar* inserareInceput(numar *cap,int val){
    numar *element=new numar;
    element->v=val;
    element->urm=cap;
    cap=element;
    return cap;
}
numar* inserareSfarsit(numar *cap,int val){
    numar *element=new numar;
    element->v=val;
    element->urm=NULL;
    if(cap==NULL)
        cap=element;
    else{
        numar *nod=cap;
        while(nod->urm!=NULL)
            nod=nod->urm;
        nod->urm=element;
    }
    return cap;
}
numar* inserareInterior(numar *cap,int x,int val){
    numar *p, *c;
    c=cap;
    while(c!=NULL){
        if(c->v==val){
            p=new numar;
            p->v=x;
            p->urm=c->urm;
            c->urm=p;
            c=p;
        }
        c=c->urm;
    }
    return cap;
}
numar *stergeElement(numar *cap,int s){
    numar *p, *r;
    int c=0;
    while(cap->v==s){
        if(cap->urm!=NULL)
            cap=cap->urm;
        else{
            cap=cap->urm;
            break;
        }
    }
    p=cap->urm;
    r=cap;
    while(p!=NULL){
        if(p->v==s){
            r->urm=p->urm;
            p=p->urm;

        }
        else{
            r=p;
            p=p->urm;
        }
    }
    return cap;
}
numar *modificaValoare(numar *cap,int x,int val){
    numar *p;
    p=cap;
    while(p!=NULL){
        if(p->v==x)
            p->v=val;
        p=p->urm;
    }
    return cap;
}
numar *stergereLista(numar *cap){
    numar *s;
    while(cap!=NULL){
        s=cap;
        cap=cap->urm;
        delete s;
    }
    return cap;
}
lista2 *creareListaLD(){
    int x,n;
    lista2 *cap;
    numar2 *c;
    cout<<"Primul element: "; cin>>x;
    c=new numar2;
    c->v=x;
    c->prec=NULL;
    c->urm=NULL;
    cap=new lista2;
    cap->prim=c;
    cap->ultim=c;
    cout<<"Cate elemente adaugam: "; cin>>n;
    while(n){
        cout<<"Adaug: ";cin>>x;
        c=new numar2;
        c->v=x;
        c->prec=cap->ultim;
        c->urm=NULL;
        (cap->ultim)->urm=c;
        cap->ultim=c;
        n--;
    }
    return cap;
}
void parcurgereInainte(lista2 *cap){
    numar2 *c;
    c=cap->prim;
    while(c!=NULL){
        cout<<c->v<<' ';
        c=c->urm;
    }
    cout<<endl;
}
void parcurgereInapoi(lista2 *cap){
    numar2 *c;
    c=cap->ultim;
    while(c!=NULL){
        cout<<c->v<<' ';
        c=c->prec;
    }
    cout<<endl;
}
lista2* adaugareInceputLD(lista2 *cap, int x){
    numar2 *c;
    c=new numar2;
    c->v=x;
    c->prec=NULL;
    c->urm=cap->prim;
    cap->prim->prec=c;
    cap->prim=c;
    return cap;
}
lista2* adaugareInteriorLD(lista2 *cap,int x,int y){
    numar2 *p,*c;
    p=cap->prim;
    while(p!=NULL){
        if(p->v==y){
            c=new numar2;
            c->v=x;
            c->urm=NULL;
            if(p->urm!=NULL){
                c->urm=p->urm;
                (p->urm)->prec=c;
            }
            c->prec=p;
            p->urm=c;
            p=c->urm;
        }
        else p=p->urm;
    }
    return cap;
}
lista2* adaugareSfarsitLD(lista2 *cap,int x){
    numar2 *c;
    c=new numar2;
    c->v=x;
    c->urm=NULL;
    c->prec=cap->ultim;
    cap->ultim->urm=c;
    cap->ultim=c;
    return cap;
}
lista2 *stergeElementLD(lista2 *cap, int x){
    numar2 *c, *s;
    while(cap->prim->v==x){
        s=cap->prim;
        cap->prim->urm->prec=NULL;
        cap->prim=cap->prim->urm;
        delete s;
    }
    c=cap->prim;
    while(c!=NULL){
        if(c->v==x){
            s=c;
            if(c->urm!=NULL){
                c->prec->urm=c->urm;
                c->urm->prec=c->prec;
            }
            else{
                c->prec->urm=NULL;
                cap->ultim=c->prec;
            }
            delete s;
        }
        c=c->urm;
    }
    return cap;
}
lista2 *modificaValoareLD(lista2 *cap,int x,int val){
    numar2 *p;
    p=cap->prim;
    while(p!=NULL){
        if(p->v==x)
            p->v=val;
        p=p->urm;
    }
    return cap;
}
numar *creareStiva(){
    numar *s, *c;
    int x, n;
    cout<<"Primul element este: "; cin>>x;
    s=new numar;
    s->v=x;
    s->urm=NULL;
    cout<<"Cate elemente adaugam in stiva: "; cin>>n;
    while(n){
        cout<<"Adaug: "; cin>>x;
        c=new numar;
        c->v=x;
        c->urm=s;
        s=c;
        n--;
    }
    return s;
}
void parcurgereStiva(numar *s){
    numar *c;
    c=s;
    while(c!=NULL){
        cout<<c->v<<endl;
        c=c->urm;
    }
}
numar *stergereDinStiva(numar *s){
    numar *desters;
    desters=s;
    s=s->urm;
    delete desters;
    return s;
}
numar *adaugareInStiva(numar *s,int x){
    numar *a;
    a=new numar;
    a->v=x;
    a->urm=s;
    s=a;
    return s;
}
lista2 *creareCoada(){
    int x,n;
    lista2 *cap;
    numar2 *c;
    cout<<"Primul element: "; cin>>x;
    c=new numar2;
    c->v=x;
    c->prec=NULL;
    c->urm=NULL;
    cap=new lista2;
    cap->prim=c;
    cap->ultim=c;
    cout<<"Cate elemente adaugam: "; cin>>n;
    while(n){
        cout<<"Adaug: ";cin>>x;
        c=new numar2;
        c->v=x;
        c->prec=cap->ultim;
        c->urm=NULL;
        (cap->ultim)->urm=c;
        cap->ultim=c;
        n--;
    }
    return cap;
}
void parcurgereCoada(lista2 *cap){
    numar2 *c;
    c=cap->prim;
    while(c!=NULL){
        cout<<c->v<<' ';
        c=c->urm;
    }
    cout<<endl;
}
lista2 *adaugareInCoada(lista2 *cap,int x){
    numar2 *c;
    c=new numar2;
    c->v=x;
    c->urm=NULL;
    c->prec=cap->ultim;
    cap->ultim->urm=c;
    cap->ultim=c;
    return cap;
}
lista2 *stergereDinCoada(lista2 *s){
    numar2 *desters;
    desters=s->prim;
    s->prim=s->prim->urm;
    delete desters;
    return s;
}
void sortareLista(numar *c){
    int inv,man;
    do{
        inv=0;
        while(c!=NULL && c->urm!=NULL){
            if(c->v>c->urm->v){
                man=c->v;
                c->v=c->urm->v;
                c->urm->v=man;
                inv=1;
            }
        c=c->urm;
        }
    }while(inv);
}
int main(){
    int op,op1,op2,op3;
    do{
    cout<<endl<<"Programe ASD - 2020"<<endl;
    cout<<"Alex Buturugeanu"<<endl<<"*********************************";
    cout<<endl;
    cout<<"1. Probleme simple de programare "<<endl;
    cout<<"2. Algoritmi de sortare"<<endl;
    cout<<"3. Liste, stive, cozi. Aplicatii"<<endl;
    cout<<"0. Iesire din program "<<endl;
    cout<<"Citeste optiune: ";cin>>op;
    switch(op){
       case 1:
        do {
           cout<<endl;
           cout<<"Probleme simple de programare"<<endl;
           cout<<endl;
           cout<<"1.1. Rezolvarea completa a ecuatiei de gradul al doilea"<<endl;
           cout<<"1.2. Inmultirea a doua matrice"<<endl;
           cout<<"1.3. Verificare numar prim"<<endl;
           cout<<"1.4. Schimbarea bazei (din baza 10 in baza b=2,...9)"<<endl;
           cout<<"1.5. Numar maxim"<<endl;
           cout<<"1.0. Iesire din meniu 1"<<endl;
           cout<<"Optiune meniu 1: ";cin>>op1;
           switch(op1){
                   case 1:{
                       cout<<"Rezolvare ecuatie de gradul al doilea"<<endl;
                       float a,b,c,d=0,x=0,x1=0,x2=0,pi=0,pr=0;
                       cout<<"a=";cin>>a;
                       cout<<"b=";cin>>b;
                       cout<<"c=";cin>>c;
                       ecuatieGrad2(a,b,c);
                       break;
                   }
                   case 2:{
                        cout<<"Inmultirea a doua matrice"<<endl;
                        int n1,m1,n2,m2;
                        cout<<"Numar de linii pentru Matricea A=";cin>>n1;
                        cout<<"Numar de coloane pentru Matricea B=";cin>>m1;
                        cout<<"Prima Matrice"<<endl;
                        int **a=new int*[n1];
                        for(int i=1;i<=n1;i++)
                            a[i]=new int[m1];
                        citireMatrice(a,n1,m1);
                        cout<<"Numar de linii pentru Matricea B=";cin>>n2;
                        cout<<"Numar de coloane pentru Matricea B=";cin>>m2;
                        cout<<"A doua Matrice"<<endl;
                        int **b=new int*[n2];
                        for(int i=1;i<=n2;i++)
                            b[i]=new int[m2];
                        citireMatrice(b,n2,m2);
                        inmultireMatrice(a,b,n1,n2,m1,m2);
                        delete[]a;
                        delete[]b;
                        break;
                   }
                   case 3:{
                        cout<<"Verificare numar prim"<<endl;
                        int n,gasit=0;
                        cout<<"Numar=";cin>>n;
                        if(prim(n)==1)
                            cout<<"Numarul este prim"<<endl;
                        else cout<<"Numarul nu este prim"<<endl;
                        break;
                   }
                   case 4:{
                        cout<<"Schimbarea bazei"<<endl;
                        int n,b;
                        cout<<"Numar in baza 10=";cin>>n;
                        cout<<"Baza=";cin>>b;
                        cout<<n<<" in baza "<<b<<" este: "<<endl;
                        schimbareBaza(n,b);
                        break;
                   }
                   case 5:{
                        cout<<"Numar maxim"<<endl;
                        int n;
                        cout<<"n=";cin>>n;
                        int *v=new int[n];
                        for(int i=0;i<n;i++)
                            cin>>v[i];
                        cout<<numarMaxim(v,n);
                        delete[]v;
                        break;
                   }
                   case 0:
                        cout<<"Iesire meniu 1"<<endl;
                        break;
                   default:
                        cout<<"Optiune gresita!"<<endl;
                        break;
                }
            }while(op1!=0);
        break;
        case 2:do{
            cout<<endl;
            cout<<"Algoritmi de sortare"<<endl;
            cout<<endl;
            cout<<"2.1. Bubble Sort"<<endl;
            cout<<"2.2. Selection Sort"<<endl;
            cout<<"2.3. Counting Sort"<<endl;
            cout<<"2.4. Merge Sort"<<endl;
            cout<<"2.5. Quick Sort"<<endl;
            cout<<"2.6. Insertion Sort"<<endl;
            cout<<"2.7. Shell Sort"<<endl;
            cout<<"2.8. Radix Sort"<<endl;
            cout<<"2.9. Cautare Secventiala"<<endl;
            cout<<"2.10. Cautare Binara"<<endl;
            cout<<"2.0. Iesire meniu 2"<<endl;
            cout<<"Optiune meniu 2: ";cin>>op2;
            switch(op2){
                case 1:{
                    cout<<"Bubble Sort"<<endl;
                    int n;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    bule(v,n);
                    afisareVector(v,n);
                    delete[]v;
                    break;
                }
                case 2:{
                    cout<<"Selection Sort"<<endl;
                    int n;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    sortareSelectie(v,n);
                    afisareVector(v,n);
                    delete[]v;
                    break;
                }
                case 3:{
                    cout<<"Counting Sort"<<endl;
                    int n;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    sortareNumarare(v,n);
                    afisareVector(v,n);
                    delete[]v;
                    break;
                }
                case 4:{
                    cout<<"Merge Sort"<<endl;
                    int n;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    sortareInterclasare(v,n,0,n-1);
                    afisareVector(v,n);
                    delete[]v;
                    break;
                }
                case 5:{
                    cout<<"Quick Sort"<<endl;
                    int n;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    quickSort(v,0,n-1);
                    afisareVector(v,n);
                    delete[]v;
                    break;
                }
                case 6:{
                    cout<<"Insertion Sort"<<endl;
                    int n;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    sortareInsertie(v,n);
                    afisareVector(v,n);
                    delete[]v;
                    break;
                }
                case 7:{
                    cout<<"Shell Sort"<<endl;
                    int n;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    shellSort(v,n);
                    afisareVector(v,n);
                    delete[]v;
                    break;
                }
                case 8:{
                    cout<<"Radix Sort"<<endl;
                    int n;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    radixSort(v,n);
                    afisareVector(v,n);
                    delete[]v;
                    break;
                }
                case 9:{
                    cout<<"Cautare Secventiala"<<endl;
                    int n;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    cautareSecventiala(v,n);
                    delete[]v;
                    break;
                }
                case 10:{
                    cout<<"Cautare Binara"<<endl;
                    int n,x;
                    cout<<"n=";cin>>n;
                    int *v=new int[n];
                    citireVector(v,n);
                    cout<<"x=";cin>>x;
                    cout<<"Elementul "<<x<<" a fost gasit pe pozitia "<<cautareBinara(v,x,0,n-1)+1<<endl;
                    delete[]v;
                    break;
                }
                case 0:
                    cout<<"Iesire meniu 2"<<endl;
                    break;
                default:
                    cout<<"Optiune gresita!"<<endl;
                    break;
            }
        }while(op2!=0);
        break;
        case 3:do{
            cout<<endl;
            cout<<"Liste, stive, cozi. Aplicatii"<<endl;
            cout<<endl;
            cout<<"3.1. Operatii cu liste simplu inlantuite."<<endl;
            cout<<"3.2. Operatii cu liste dublu inlantuite."<<endl;
            cout<<"3.3. Operatii cu stive."<<endl;
            cout<<"3.4. Operatii cu cozi."<<endl;
            cout<<"3.5. Crearea unuei liste ordonate"<<endl;
            cout<<"3.6. Interclasarea a doua liste"<<endl;
            cout<<"3.7. Adunarea a doua polinoame"<<endl;
            cout<<"3.8. Inmultirea a doua polinoame"<<endl;
            cout<<"3.0. Iesire  meniu 3"<<endl;
            cout<<"Optiune meniu 3: ";cin>>op3;
            switch(op3){
                case 1:{
                    cout<<"3.1. Operatii cu liste simplu inlantuite."<<endl;
                    numar *cap;
                    int val,val2,mod1,mod2,vals;
                    char opt1[14];
                    cap=creareLista();
                    cout<<"Lista dupa creare este: "<<endl;
                    parcurgereLista(cap);
                    cout<<endl;
                    cout<<"Valoarea pe care vrem sa o adaugam: ";cin>>val;
                    cout<<"Unde vrei sa adaugi numarul [Inceput/Sfarsit/Interior]: ";cin>>opt1;
                    if(strcmp(opt1,"Inceput")==0)
                        cap=inserareInceput(cap,val);
                    if(strcmp(opt1,"Sfarsit")==0)
                        cap=inserareSfarsit(cap,val);
                    if(strcmp(opt1,"Interior")==0){
                        cout<<"Valoare dupa care vrem sa adaugam: ";cin>>val2;
                        cap=inserareInterior(cap,val,val2);
                    }
                    parcurgereLista(cap);
                    cout<<endl;
                    cout<<"Modificam valoarea: ";cin>>mod1;
                    cout<<"Cu valoarea: ";cin>>mod2;
                    cap=modificaValoare(cap,mod1,mod2);
                    parcurgereLista(cap);
                    cout<<endl;
                    cout<<"Elementul pe care il sterg: ";cin>>vals;
                    cap=stergeElement(cap,vals);
                    parcurgereLista(cap);
                    delete cap;
                    break;
                }
                case 2:{
                    cout<<"3.1. Operatii cu liste dublu inlantuite."<<endl;
                    lista2 *cap;
                    int val,val2,mod1,mod2,vals;
                    char opt1[14];
                    cap=creareListaLD();
                    cout<<"Lista parcursa inainte: "<<endl;
                    parcurgereInainte(cap);
                    cout<<"Lista parcursa inapoi: "<<endl;
                    parcurgereInapoi(cap);
                    cout<<endl;
                    cout<<"Valoarea pe care vrem sa o adaugam: ";cin>>val;
                    cout<<"Unde vrei sa adaugi numarul [Inceput/Sfarsit/Interior]: ";cin>>opt1;
                    if(strcmp(opt1,"Inceput")==0)
                        cap=adaugareInceputLD(cap,val);
                    if(strcmp(opt1,"Sfarsit")==0)
                        cap=adaugareSfarsitLD(cap,val);
                    if(strcmp(opt1,"Interior")==0){
                        cout<<"Valoare dupa care vrem sa adaugam: ";cin>>val2;
                        cap=adaugareInteriorLD(cap,val,val2);
                    }
                    parcurgereInainte(cap);
                    cout<<endl;
                    cout<<"Modificam valoarea: ";cin>>mod1;
                    cout<<"Cu valoarea: ";cin>>mod2;
                    cap=modificaValoareLD(cap,mod1,mod2);
                    parcurgereInainte(cap);
                    cout<<endl;
                    cout<<"Elementul pe care il sterg: ";cin>>vals;
                    cap=stergeElementLD(cap,vals);
                    parcurgereInainte(cap);
                    delete cap;
                    break;
                }
                case 3:{
                    cout<<"3.3. Operatii cu stive."<<endl;
                    numar *s;
                    int x,n;
                    s=creareStiva();
                    cout<<"Stiva: "<<endl;
                    parcurgereStiva(s);
                    cout<<"Cate elemente adaugam: ";cin>>n;
                    while(n){
                        cout<<"Adaug: ";cin>>x;
                        s=adaugareInStiva(s,x);
                        cout<<"Stiva dupa adaugarea unui element: "<<endl;
                        parcurgereStiva(s);
                        n--;
                    }
                    s=stergereDinStiva(s);
                    cout<<"Siva dupa stergerea unui element: "<<endl;
                    parcurgereStiva(s);
                    break;
                }
                case 4:{
                    cout<<"3.4. Operatii cu cozi."<<endl;
                    lista2* s;
                    int n,x;
                    s=creareCoada();
                    cout<<"Coada: "<<endl;
                    parcurgereCoada(s);
                    cout<<"Cate elemente adaugam: ";cin>>n;
                    while(n){
                        cout<<"Adaug: ";cin>>x;
                        s=adaugareInCoada(s,x);
                        cout<<"Coada dupa adaugarea unui element: "<<endl;
                        parcurgereCoada(s);
                        n--;
                    }
                    cout<<"Coada dupa stergerea unui element: "<<endl;
                    s=stergereDinCoada(s);
                    parcurgereCoada(s);
                    break;
                }
                case 5:{
                    cout<<"3.5. Crearea unuei liste ordonate"<<endl;
                    numar*s;
                    int n;
                    s=creareLista();
                    cout<<"Lista inainte de sortare: ";
                    parcurgereLista(s);
                    cout<<endl;
                    sortareLista(s);
                    cout<<"Lista dupa sortare: ";
                    parcurgereLista(s);
                    cout<<endl;
                    delete s;
                    break;
                }
                case 0:
                    cout<<"Iesire meniu 3"<<endl;
                    break;
                default:
                    cout<<"Optiune gresita!"<<endl;
                    break;
            }
        }while(op3!=0);
        break;
        case 0:
            cout<<"Terminare program! La revedere!"<<endl;
            break;
        default:
            cout<<"Optiune gresita!"<<endl;
            break;
        }
    }while(op!=0);
}
