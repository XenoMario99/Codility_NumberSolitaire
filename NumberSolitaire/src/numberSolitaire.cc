#include "numberSolitaire.h"

int solution(std::vector<int> &A) {
    int throws{6};

    std::vector<int> solutions;
    solutions.reserve(A.size());

    solutions.push_back(A[0]);

    for (int i = 1; i < A.size(); i++) {
        int start{0};
        if (i - throws > 0) {
            start = i - throws;
        }

        int max{A[i] + solutions[start]};
        start++;
        while (start < i) {
            int nextNum{A[i] + solutions[start]};
            if (nextNum > max) {
                max = nextNum;
            }
            start++;
        }

        solutions.push_back(max);
    }

    return solutions[solutions.size() - 1];
}
