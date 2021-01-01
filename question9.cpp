#include "include/BlockMatrix.hpp"


int main(){
int d; 
cout<<"Entrer un nombre entre 1 et 15 pour la matrice"<<endl;
cin>>d;
string y = to_string(d);
int n,m;
string s,v; 
    std::ifstream o("matrix"+y+".txt");
    o>>s>>n>>m>>v;
    DenseMatrix B(n,m);
    for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                o >> B(i,j) ;
            }
    }
    o.close();
string t = to_string(n); 
cout<< "C'est une matrice de taille N= "+t+"\n";
int k; 
int e; 
cout<<"Entrer 2 nombres pour l et r respectivement dans la construction \n";
cout<<"de la famille de vecteur pour le préconditionneur de Schwartz avec r<l<=N "<<endl;
cin>>k;
cin>>e;
 Vecteur b(n);

   for(int i=0;i<n;i++){
	   b(i)= rand()%1000;  // B TIRÉ AU HASARD
   }
   
   vector<vector<int> >L= Recouvrement(k,e,n); 

 Vecteur x1(m);

 vector<double>rcg,rpcg;

 B.cg(x1,b);
cout<< "et un temps CPU de "<<B.temps()<<endl;;
 rcg=B.residu();

  B.pcg(x1,b,L);
 cout<< "et un temps CPU de "<<B.temps()<<endl; 
  rpcg=B.residu();


     ofstream fichier1("courbe.txt", ios::out);
if(fichier1)
 {
   
   int t1=rpcg.size();
   int t2=rcg.size();
   if(t1<t2) {
     cout<<"PCG plus rapide"<<endl;
     fichier1<<"Niter"<<" "<<"CG"<< " "<<"PCG"<<endl;
   for(int i=0;i<int(rpcg.size());i++){
	   fichier1<<i<<" "<<rcg[i]<<" "<<rpcg[i]<<endl;
   }
   for(int i=rpcg.size();i<int(rcg.size());i++){
	   fichier1<<i<<" "<<rcg[i]<<" "<<" "<<endl;
   }
 fichier1.close();
   }
   else{
     cout<<"CG plus rapide"<<endl;
     fichier1<<"Niter"<<" "<<"PCG"<< " "<<"CG"<<endl;
 for(int i=0;i<int(rcg.size());i++){
	  fichier1<<i<<" "<<rpcg[i]<<" "<<rcg[i]<<endl;
  }
   for(int i=rcg.size();i<int(rpcg.size());i++){
	   fichier1<<i<<" "<<rpcg[i]<<" "<<" "<<endl;
	   }
 fichier1.close();
   }
   
 }
cout<< "Le fichier courbe.txt a été crée: Afficher les courbes sur Gnuplot"<<endl;


return 0;  
}
