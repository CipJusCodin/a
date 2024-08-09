void topology(int n, int a[10][10], int sc[10]) { 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) { 
            if (sc[j] == 0) { 
                printf("%d\t", j); 
                sc[j] = -1; // Mark node as processed 
                for (int k = 1; k <= n; k++) { 
                    if (a[j][k] == 1) 
                        sc[k]--; // Reduce in-degree 
                } 
                break; 
            } 
        } 
    } 
} 
 
int main() { 
    int n, a[10][10], sc[10] = {0}; 
 
    // Input number of nodes 
    printf("Enter the number of nodes: "); 
    scanf("%d", &n); 
 
    // Input adjacency matrix and calculate in-degrees 
    printf("Enter the adjacency matrix:\n"); 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) { 
            scanf("%d", &a[i][j]); 
            if (a[i][j] == 1) 
                sc[j]++; // Increase in-degree 
        } 
    } 
 
    // Print topological order 
    printf("The Topological Order of the graph is:\n"); 
    topology(n, a, sc); 
 
    return 0; 
}