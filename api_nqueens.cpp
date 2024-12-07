#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Declare your functions as C functions
extern "C" {
    
    // Function to check if a solution is valid
    bool is_valid_solution(const vector<int>& sample_sol) {
        int n = sample_sol.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Check for row conflict
                if (sample_sol[i] == sample_sol[j]) {
                    return false;
                }
                // Check for diagonal conflict
                if (abs(sample_sol[i] - sample_sol[j]) == abs(i - j)) {
                    return false;
                }
            }
        }
        return true;
    }

    // Function to print the solution in grid format (this can be done in Python)
    void print_grid_board(const vector<int>& solution) {
        int n = solution.size();
        for (int row = 0; row < n; row++) {
            string line = "|";
            for (int col = 0; col < n; col++) {
                if (solution[col] == n - row - 1) {
                    line += " Q |";  // Place the queen
                } else {
                    line += "   |";  // Empty square
                }
            }
            cout << line << endl;
            cout << string(n * 4 + 1, '-') << endl;  // Draw the horizontal border
        }
    }

    // Function to generate a random solution
    vector<int> generate_random_solution(int n) {
        vector<int> solution(n);
        for (int i = 0; i < n; i++) {
            solution[i] = rand() % n;  // Randomly assign rows for each column
        }
        return solution;
    }

    // DFS function for solving N-Queens without pruning
    void DFS(vector<vector<int>>& master, vector<int>& sol, int idx, vector<int>& branches, int size) {
        for (int i = 0; i < size; i++) {
            sol[idx] = i;
            
            if (idx < size - 1) {
                DFS(master, sol, idx + 1, branches, size);
            } else {
                branches[0]++;
                if (is_valid_solution(sol)) {
                    master.push_back(sol);
                }
            }
        }
    }

    // DFS function with pruning for N-Queens
    void DFS_prune(vector<vector<int>>& master, vector<int>& sol, int idx, vector<int>& branches, int size) {
        for (int i = 0; i < size; i++) {
            sol[idx] = i;
            
            if (idx < size - 1 && idx >= 1 && find(sol.begin(), sol.begin() + idx, sol[idx]) != sol.begin() + idx) {
                continue;
            } else if (idx < size - 1) {
                DFS_prune(master, sol, idx + 1, branches, size);
            } else {
                branches[0]++;
                if (is_valid_solution(sol)) {
                    master.push_back(sol);
                }
            }
        }
    }
    
}
