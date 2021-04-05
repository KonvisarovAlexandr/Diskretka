#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
//Функция добавления дуги в граф
//функция пуш бэк для создания просто, а именно edge для их связного применения
void edge(vector<int>Vecttor[],int element1,int element2)//принимает значения вектора и двух интовых переменных 
{
    Vecttor[element1].push_back(element2);//функции вставки переменных
    Vecttor[element2].push_back(element1);
}

//ОБХОД В ШИРИНУ 
void bfs(int s,vector<int>Vecttor[], int V)//принимает значения первого элемента , самого вектора с которым будем работать и одной интовой переменной(размера )
{
    bool visit[V];//Массив Булевых значений для проверки обхода графа
    for(int i=0;i<V;i++) visit[i]=false;// обнуляем весь массив на false чтоб не было нежелательных результатов 
    queue<int>ocheredi;//Очередь
    ocheredi.push(s);// добавляем в очередь первый элемент который мы задали
    visit[s]=true; // меняем его на истинный , чтоб начать делать обход
    while(!ocheredi.empty())// пока стек не пустой
    {
        int u=ocheredi.front(); // записывваем нашу в переменную элемент обход(front возвращает первое значение )
        cout<<u<<" ";// вывод нашего обхода
        ocheredi.pop(); // удаляем этот элемент(pop удаляет это первое значение , таким образом граф проходится )
    //Цикл обхода
        for(int i=0;i<Vecttor[u].size();i++)//цикл от нуля до размера нашего вектора 
        {
            if(!visit[Vecttor[u][i]])//если элемент не был посещён
            {
                ocheredi.push(Vecttor[u][i]);// сохраняем в стек наш элемент
                visit[Vecttor[u][i]]=true; // записываем что мы его прошли
            }
        }
    }
}
//Функция для обхода в глубину
void dfs(int s,vector<int>Vectoor[], int V)//принимает значения первого элемента , самого нашего вектора и размера (количества элементов )
{
    bool visit[V];//Массив Булевых значений для проверки обхода графа
    for(int i=0;i<V;i++) visit[i]=false;//обнуляем массив также на фолс
    stack<int>stk;//создаём стек
    stk.push(s);//добавляем в стек наш первый элемент
    visit[s]=true;//начинаем как и в прошлом случае с него,поэтому ставим будто мы его прошли
    while(!stk.empty())//такой же цикл, пока стек не будем пустым
    {
        int u=stk.top();//записываем в нашу переменную элемент обхода(top)
        cout<<u<<" ";//вывод этого элемента на экран
        stk.pop();//удаление из стэка
        //сам цикл
        for(int i=0;i<Vectoor[u].size();i++)//цикл от нуля до размера вектора
        {
            if(visit[Vectoor[u][i]]==false)//если элемент не был посещён 
            {
                visit[Vectoor[u][i]]=true;//ставим значение на Т 
                stk.push(Vectoor[u][i]);//и вставляем его в наш стек
            }
        }
    }
}
//Наша основная функция 
int main()
{
    int V=0; // Количество вершин
    cout<<"Vvedite kolichestvo vershin v grafe"<<endl;
    cin>>V;
    //в данном случае нам надо ввести 7 ,т.к это вершины {0.1.2.3.4.5.6}
    vector<int>G[V];//Вектор для хранения списка смежности графа
    bool visit[V];//Массив Булевых значений для проверки обхода графа
    //СОЗДАНИЕ ВЕРШИНОК
    edge(G, 0, 3);
    edge(G, 1, 2);
    edge(G, 1, 3);
    edge(G, 1, 4);
    edge(G, 2, 4);
    edge(G, 3, 5);
    edge(G, 3, 6);
    edge(G, 4, 6);
    //Ввод дуг с клавиатуры,но закомментированно потому что выше введено уже
    /*int x=0;
    int y=0;
    int choice=0;
    while(1)//
    {
        choice=0;
        while(1)
        {
            x=0;
            y=0;
            cout<<"Ot kakoi vershini idet duga?"<<endl;
            cin>>x;
            cout<<"V kakuy vershinu ona idet?"<<endl;
            cin>>y;
            if(x==y) cout<<"Oshibka! Vi vveli petliu!"<<endl;
            else break;
        }
        edge(G,x,y);
        cout<<"Hotite eshe dobaviti dugu? 1(Da)/0(Net)"<<endl;
        cin>>choice;
        if(choice==0) break;
    }*/
    cout<<"Obhod v shirinu"<<"  ";
    bfs(0,G,V);//Первый аргумент это значение откуда мы должны начинать обход
    cout<<endl;
    cout<<"Obhod v glubinu"<<"  ";
    dfs(0,G,V);//Первый аргумент это значение откуда мы должны начинать обход
}