#include<bits/stdc++.h>
using namespace std;


struct node{//striktura dlea Spiska smejnosti
	int v;
	node *next;//ssilka na seduiushii
	node(int x=0, node * t=0) {//znacenia dlea vstavki
		v=x;
		next=t;	
	}
};

int MI[100][100]={}, MS[100][100]={},n,m;//n-vershini,m-dugi MS-matr Smej, MI-Matr.intsed
node* adj[100]={};//spisok smejnosti


void FMI()
{
    cout<<"Matritsa Intidentnosti:"<<endl;
    for(int i=0;i<m;i++) {//tsikl po kolicestvu dug
			cout<<"vvedite  stroku "<< i+1<<endl;
			for(int j=0;j<n;j++)//tsikl po kolicestvu vershin
				cin>>MI[i][j];//scitivaem Matritsu intsed.
    }
}


void FMS()
{
    cout<<"Matrita Smejnosti"<<endl;
    for(int i=0;i<n;i++){//tsikl vershin
			cout<<"vvedite stroku"<<endl<<i+1<<":";
			for(int j=0;j<n;j++)//tsikl vershin
				cin>>MS[i][j];
    }
}


void FSS()
{
    int tmp;
		cout<<"Spisok Smejnosti"<<endl;
    for(int i=0;i<n;i++){//tsikl do kolicestva vershin
		cout<<"vvedite vershinu sviazanui s "<<i+1<<endl;
		cout<<"vvedite 0 esli hotite pereiti k sleduiushei vershine"<<endl;
	    cout<<i+1<<":";
		cin>>tmp;
			while(tmp){//poka tmp!=0
				adj[i]=new node(tmp-1,adj[i]);//sozdanie novogo uzla 
			    cin>>tmp;//vvedenie vershin v tsikle
	    	}
   }
}


void FMSvSS()
{
    for(int i=0;i<n;i++)//for po vershinam
		for(int j=0;j<n;j++)//vtoroi for po vershinam
			if(MS[i][j])//esli element !=0
				adj[i]=new node(j,adj[i]);//sozdaietsea novii uzel

}


void FSSvMI()
{
    int m=0;//sozdanie peremennoi, t.k. dalishe tsikl while
	for(int i=0;i<n;i++){//tsikl do vershin
		node * tmp=adj[i];//sozdanie ssilki uzla na adj[100] 
        while(tmp){
				MI[m][i]=-1;//otkuda ishodit uzel
			   MI[m++][tmp->v]=1;//kuda idet uzel
               tmp=tmp->next;//uzel idet v sleduiushii
        }
        
	}
}
void FMIvMS()
{
    int k,l;//scetchiki
		for (int i=0;i<m;i++){//tsikl do kolicestva dug
			for (int j=0;j<n;j++){//tsikl do kolicestva vershin
				if(MI[i][j]==-1) k=j;//esli element v matritse intsidentnosti = -1 , k =-1 
				if(MI[i][j]==1) l=j;//esli element v matritse =1 ,l=1
			}
        MS[k][l]=1;//stavit element ot k ,l =1
    }
}
void printm()//vivod na ekran
{
    cout<<"\tMatritsa Intidentnosti"<<endl;
    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
				cout<<MI[i][j]<<" ";
			cout<<endl;
    }
    cout<<"\tMatritsa Smejnosti"<<endl;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
				cout<<MS[i][j]<<" ";
		    cout<<endl;
    }
	cout<<"\tspisok smeznosti"<<endl;
	for(int i=1;i<=n;i++){
		cout<<i<<":";
		node* tmp=adj[i-1];
		while(tmp){
		   cout<<tmp->v+1;
		   tmp=tmp->next;
		}
		cout<<endl;
	}
}
int main()
{
int k;
cout<<"Vvedite kol-vo vershin"<<endl;
cin>>n;
cout<<"Vvedite kol-vo Dug"<<endl;
cin>>m;
cout<<"Sposob vvoda\n1.Matritsa Intidentnosti\n2.Matritsa Smejnosti\n3.Spisok Smejnosti\n";
cin>>k;
if(k){
	if(k==1){	FMI() ; 	FMIvMS();	FMSvSS();}
	else if(k==2){	FMS();	FMSvSS();	FSSvMI();}
	else if(k==3){	FSS();	FSSvMI();	FMIvMS();}
}
printm();
}