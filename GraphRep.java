import java.util.*; 
  
class Graph { 
      
    // A utility function to add an edge in an 
    // undirected graph 
    static void addEdge(ArrayList<ArrayList<Integer> > adj, 
                        int u, int v) 
    { 
        adj.get(u).add(v); 
        adj.get(v).add(u); 
    } 
  
    // A utility function to print the adjacency list 
    // representation of graph 
    static void printAdjList(ArrayList<ArrayList<Integer> > adj) 
    { 
        for (int i = 0; i < adj.size(); i++) { 
            System.out.println("\nAdjacency list of vertex" + i); 
            System.out.print("head"); 
            for (int j = 0; j < adj.get(i).size(); j++) { 
                System.out.print(" -> "+adj.get(i).get(j)); 
            } 
            System.out.println(); 
        } 
    } 
  	static void AdjMatAdd (int adj[][], int x, int y, int wt) {
  		adj[x][y]=wt;
  	}
  	static void AdjMatPrint(int adj[][]) {
  		for(int i=0;i<5;i++) {
  			for(int j=0;j<5;j++) {
  				System.out.print(adj[i][j]+ " ");
  			}
  			System.out.println("");
  		}
  	}
    // Driver Code 
    public static void main(String[] args) 
    { 
        Scanner s=new Scanner(System.in);
        
        int V = s.nextInt();
        int E = s.nextInt();
        ArrayList<ArrayList<Integer> > adj  
                    = new ArrayList<ArrayList<Integer> >(V); 
         
        for (int i = 0; i < V; i++) 
            adj.add(new ArrayList<Integer>()); 
  
        // Adding edges one by one
        int x, y;
        for(int i=0;i<E;i++) {
        	x=s.nextInt();
        	y=s.nextInt();
        	--x;--y;
        	addEdge(adj, x, y);
        }
          
        printAdjList(adj);
        
        int AdjMat[][]= new int[5][5];
        V=s.nextInt();
        E=s.nextInt();
        int wt;
        for(int i=0;i<E;i++) {
        	x=s.nextInt();
        	y=s.nextInt();
        	wt=s.nextInt();
        	--x;
        	--y;
        	AdjMatAdd(AdjMat, x, y, wt);
        }
        
        AdjMatPrint(AdjMat);
        
    } 
} 

/*
5 5
1 2
2 3
3 4
4 5
1 4

5 5
1 2 10
2 3 11
3 4 12
4 5 13
2 1 14

*/