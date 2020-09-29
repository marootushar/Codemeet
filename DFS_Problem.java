import java.util.*;

public class DFS_Problem {
	static long dfs(ArrayList<ArrayList<Integer> > graph, int i, ArrayList<Boolean> visited, ArrayList<Long> costs){
		
		visited.set(i, true);
		long c=costs.get(i), temp;
		
		for(int j=0;j<graph.get(i).size();j++) {
			if(visited.get(graph.get(i).get(j))==false) {
				temp=dfs(graph, graph.get(i).get(j), visited, costs);
				if(c>temp) {
					c=temp;
				}
			}
		}
		return c;
	}
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n, edges, i, x, y; 
		long finalCost=0, c;
		   // Vertices and Edges
		   n=s.nextInt();
		   edges=s.nextInt();
		   ArrayList<Long> costs = new ArrayList<Long>();
		   for(i=0;i<n;i++) {
			   c=s.nextLong();
			   costs.add(c);
		   }
		   ArrayList<Boolean> visited = new ArrayList<Boolean>();
		   
		   for(i=0;i<n;i++) {
			   visited.add(false);
		   }
		   ArrayList<ArrayList<Integer> > graph  = new ArrayList<ArrayList<Integer> >(); 
		   
		   for(i=0;i<n;i++) {
			   graph.add(new ArrayList<Integer>());
		   }
		   
		   for(i=0;i<edges;i++) {
			   x=s.nextInt();
			   y=s.nextInt();
			   x=x-1;
			   y=y-1;
			   graph.get(x).add(y);
			   graph.get(y).add(x);
			   
		   }
		   
		   for(i=0;i<n;i++){
			   	if(visited.get(i)==false) {
			   		finalCost+=dfs(graph, i, visited, costs);
			   	}
		    }
		   System.out.println(finalCost);
	}
}
