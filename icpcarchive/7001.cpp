//7001 Bus Problem
//url : https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=5013
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#define endl '\n'
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb emplace_back//faster than push_back. Your choice though

int s = 0;//source vertex
bool visited[100001];//visited array
int dist[100001];//storing shortest distance from source to every vertex
int padres[100001];
vector <pii> a[100001]; //Adjacency List. source vertex->destination vertex,weight

void init(int n)//resets data
{
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
		a[i].clear();
		dist[i]=INT_MAX;
	}
}

void Dijkstra();

class prioritize//Comparator to sort edges. The shortest edge is removed first
{
public:
	bool operator ()(pii&p1 ,pii&p2)
	{
		return p1.s>p2.s;
	}
};

int main()
{
    int casos;
    cin>>casos;
    while(casos--){
        int contador = 0;
	int v1,v2,w,n,m;
	cin>>n>>m;//number of vertics,edges
	init(n);//resetting data
	for(int i=0;i<m;i++){
            
		cin>>v1>>v2>>w;//inputting data
		
		contador += w; //contamos todos los pesos que nos dan
                
		a[v1].pb(mp(v2,w));
                a[v2].pb(mp(v1,w));//bidireccional
	}
	//cin>>s;//inputting source
	Dijkstra();
	/*cout<<"Printing shortest distance from Source "<<s<<" to all other vertices\n";
	for(int i=1;i<n;i++){
            
		cout<<s<<" to "<<i<<" ";
		if(dist[i]!=INT_MAX)
			cout<<dist[i]<<endl;
		else
			cout<<"Unreachable\n";
	}*/
	int aux = 0;
	for(int i = 0; i < n; i++){
            //cout << "padres["<<i<<"] = "<<padres[i]<<endl;
            aux += padres[i];//sumamos los pesos de los padres
            //el camino que se toma, el menor
        }
        /*cout << "contador: " <<contador<<endl;
        cout << "aux: " << aux <<endl;*/
        cout << contador - aux << endl;
    }//cierro while
}

void Dijkstra(){
    
	//Prioriy Queue is a heap based structure which stores only the max element at top. Not in sorted order
	priority_queue<pii, vector<pii> , prioritize> pq;//Datatype, Container, Comparator
	dist[s]=0;
        padres[s]=0;//no tiene papá
	pq.push(mp(s,0));//pushing source,0 as dist from source to itself is 0. Duh
	while(!pq.empty())
	{
		pii cur=pq.top();
		pq.pop();
		int cv=cur.f,cw=cur.s;//This node will be highest priority of all instances of this node
		if(visited[cv])
			continue;
		visited[cv]=true;//Now future instances of this node with higher weight ignored as already visited
		for(pii x:a[cv])//Iterating through vertices of current vertex
		{
                    
			if(!visited[x.f])//Node not visited before.
			{
				int nv=x.f,nw=x.s;//current vertex and its weight
				if(cw+nw<=dist[nv])///New dist is shorter
				{
                                    
					dist[nv]=cw+nw;
                                        
                                        padres[nv]=nw;//costo para llegar nv desde un nodo anterior
                                        
					pq.push(mp(nv,dist[nv]));//Adding to priority queue
				}
			}
		}
	}
}