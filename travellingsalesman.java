//  Write a program to solve the travelling salesman problem. Print the path and the cost.
//(Branch and Bound).
import java.util.Arrays;

public class TravellingSalesman {
    
    private static final int INF = Integer.MAX_VALUE;

    // Function to solve the TSP using Branch and Bound
    public static void tsp(int[][] graph, int n) {
        // Array to keep the minimum path
        int[] path = new int[n + 1];
        boolean[] visited = new boolean[n];
        
        // Initialize path and visited arrays
        Arrays.fill(path, -1);
        Arrays.fill(visited, false);

        // Start from the first city
        visited[0] = true;
        path[0] = 0;

        // Call recursive function to calculate minimum cost and path
        int minCost = tspRecursive(graph, path, visited, 1, 0, n, 0, INF);

        // Print the result
        System.out.println("Minimum Cost: " + minCost);
        System.out.print("Path: ");
        for (int i = 0; i <= n; i++) {
            System.out.print(path[i] + " ");
        }
        System.out.println();
    }

    // Recursive function for Branch and Bound to solve TSP
    private static int tspRecursive(int[][] graph, int[] path, boolean[] visited, 
                                    int level, int current, int n, int currentCost, int minCost) {
        // Base case: All cities visited, return to the start
        if (level == n) {
            if (graph[current][0] != 0) {
                int finalCost = currentCost + graph[current][0];
                if (finalCost < minCost) {
                    minCost = finalCost;
                    path[level] = 0;
                }
            }
            return minCost;
        }

        // Recursive case: Consider all unvisited cities and minimize the cost
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current][i] != 0) {
                int tempCost = currentCost + graph[current][i];

                // Pruning: Only proceed if tempCost is less than current minCost
                if (tempCost < minCost) {
                    visited[i] = true;
                    path[level] = i;

                    minCost = tspRecursive(graph, path, visited, level + 1, i, n, tempCost, minCost);

                    // Backtracking: Mark the city as unvisited for the next branch
                    visited[i] = false;
                }
            }
        }

        return minCost;
    }

    public static void main(String[] args) {
        int[][] graph = {
            { 0, 20, 42, 35 },
            { 20, 0, 30, 34 },
            { 42, 30, 0, 12 },
            { 35, 34, 12, 0 }
        };
        int n = graph.length;
        tsp(graph, n);
    }
}
