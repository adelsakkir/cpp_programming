#include <iostream>
#include <vector>
#include "ortools/sat/cp_model.h"

namespace operations_research {
namespace sat {

void CpSolve(int n) {
    // Create the model
    CpModelBuilder model;

    // Define variables: one integer variable per queen's row position
    std::vector<IntVar> queens;
    for (int col = 0; col < n; ++col) {
        queens.push_back(model.NewIntVar(0, n - 1, "queen_" + std::to_string(col)));
    }

    // Add constraints
    // No two queens in the same row
    model.AddAllDifferent(queens);

    // Left-to-right diagonals
    std::vector<IntVar> left_diagonals;
    for (int i = 0; i < n; ++i) {
        left_diagonals.push_back(IntVar(queens[i] + i));
    }
    model.AddAllDifferent(left_diagonals);

    // Right-to-left diagonals
    std::vector<IntVar> right_diagonals;
    for (int i = 0; i < n; ++i) {
        right_diagonals.push_back(IntVar(queens[i] - i));
    }
    model.AddAllDifferent(right_diagonals);

    // Create the solver
    CpSolver solver;

    // Capture solutions
    struct SolutionPrinter : public CpSolverSolutionCallback {
        explicit SolutionPrinter(const std::vector<IntVar>& queens, int n)
            : queens_(queens), n_(n) {}

        void OnSolutionCallback() override {
            std::vector<int64_t> solution;
            for (int col = 0; col < n_; ++col) {
                solution.push_back(Value(queens_[col]));
            }
            solutions_.push_back(solution);
        }

        const std::vector<IntVar>& queens_;
        int n_;
        std::vector<std::vector<int64_t>> solutions_;
    };

    SolutionPrinter solution_printer(queens, n);

    // Solve the model
    solver.SearchAllSolutions(model.Build(), &solution_printer);

    // Output results
    std::cout << "Number of solutions: " << solution_printer.solutions_.size() << std::endl;
}

}  // namespace sat
}  // namespace operations_research

int main() {
    int size = 8;
    operations_research::sat::CpSolve(size);
    return 0;
}
