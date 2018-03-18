#include<iostream>
#include<sstream>//convert integer to string.
#include<vector>
using namespace std;

static const int ver = 14;// the number of vertex            //declare it in static const to read only.
static int short_dist[ver];//it takes the shortest result.  // declare it in static to use everywhere.
static int edge[ver][ver];//declare the edged              //declare it in static to use everywhere.

class Graph
{
	private:
		stringstream ss;//convert integer to string
		vector<string> ver1;//for store the shortest vertex from 
		vector<string> ver2;//for store the shortest vertex to
	public:
		void addEdge();
		void process(int, int);
		int shortestDis(bool []);
		void displayGraph(int, int);	 	
};

void Graph::process(int end, int start)
{
	bool check[ver];
	
	for (int i = 0; i < ver; i++)
	{
		short_dist[i] = 999999; //set all element in array to the greatest value.
		check[i] = false; // set check element all false.
	}
	
	short_dist[end] = 0;// Distation it self equal 0.
	
	for (int i = 0; i < ver; i++) // find the shortest Distance form all vertices
	{
		int min_vertex = shortestDis(check);// find the shortest distance. 
		int x = min_vertex;
		check[x] = true; // it's true if the vertice is the shortest distination.
	
		for (int z = 0; z < ver; z++)
		{
	     	if ((short_dist[x]+edge[x][z] < short_dist[z]) && (edge[x][z]>0)) // The value from distance to other will be smaller than current distiance.
			{
				short_dist[z] = edge[x][z] + short_dist[x];// store the shortest distances.	
				ss<<x+1;//convert integer to string
				ver2.push_back(ss.str());//store the vertex to in vector.
				ss.str("");// clear ss string convert
				ss<<z+1;//convert integer to string
				ver1.push_back(ss.str());//store the vertex start in vector.
				ss.str("");// clear ss string convert
			}
		}
	}
	
   displayGraph(end, start);
}

int Graph::shortestDis(bool check[])
{
	int min_ver = 0;
	int max_short = 999999;
	////////find the shortest vertex destination from the vertex that not yat find.
	for (int i = 0; i < ver; i++)
	{
		if (short_dist[i] <= max_short && check[i] == false)
		{
			min_ver = i;
			max_short = short_dist[i];
    	}
	}
	return min_ver;
}
	
void Graph::displayGraph(int end, int start)
{
	////////find and show the shortest path
	string way="";
	ss<<start+1;
	string con= ss.str();
	for(int i = 1;i<ver1.size()+1;i++)
	{   
		if(con == ver1[ver1.size()-i])
		{
			way = way+ ver1[ver1.size()-i] +"-";
			con = ver2[ver2.size()-i];
		}
	}
    cout<<"----------------------------------------------------------------"<<endl;
	cout<<way<<end+1<<" ";
	ss.str("");// clear ss string convert
	ver1.clear();//clear vector 
	ver2.clear();//clear vector 
}
void Graph::addEdge()
{
	///add into edge array 
	for (int i=0; i<ver;i++)
		for (int j=0;j<14;j++)
			edge[i][j] = 0;
			
	edge[0][1]=260, edge[1][0]=260, edge[2][0]=252, edge[3][0]=324,	  edge[4][3]=248, edge[5][2]=416,  edge[6][4]=292, edge[7][1]=869;
	edge[0][2]=252,	edge[1][2]=380, edge[2][1]=380, edge[3][4]=248,   edge[4][5]=272, edge[5][4]=272,  edge[6][7]=212, edge[7][6]=212;
	edge[0][3]=324, edge[1][7]=868, edge[2][5]=416, edge[3][10]=1140, edge[4][6]=292, edge[5][9]=704,                  edge[7][8]=224;
	 																				  edge[5][12]=1036;
	
	edge[8][7]=224,   edge[9][5]=704, edge[10][3]=1140, edge[11][8]=536,  edge[12][5]=1036, edge[13][8]=668;
	edge[8][9]=752,   edge[9][8]=752, edge[10][11]=408, edge[11][10]=408, edge[12][11]=664, edge[13][10]=684;
	edge[8][11]=536,                  edge[10][13]=684, edge[11][12]=664, edge[12][13]=352, edge[13][12]=352;
	edge[8][13]=668; 
		
}

int main()
{
	Graph myGraph;
	myGraph.addEdge();//add edge 
	int i,s;
	while(1)
	{
	cout<<"ENTER A Starting point : ";
	cin>>i;
	cout<<"ENTER A Ending point : ";
	cin>>s;
	
	if((i>ver || s >ver )||( i < 1 || s < 1)){
		cout<<"Sorry! Worng! Input!"<<endl;
	}else
	{
		myGraph.process(s-1,i-1);
    	cout<<"is the shortest way from "<<i<<"-"<<s<<" = "<<short_dist[i-1]<<" miles"<<endl;//show shortest result
    	cout<<"----------------------------------------------------------------"<<endl;
	}
	
	/////////let's user to countinue or end program
	cout<<"Press Y to exit: ";
	string r;
	cin>>r;
	if(r == "y" || r == "Y")break;
	}
	return 0;
}
