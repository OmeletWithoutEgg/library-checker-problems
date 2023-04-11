
#include "../params.h"
#include "random.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>

struct Tree {

    int n = 1;
    std::vector<std::pair<int, int>> edges;

    void shuffle_nodes(Random& rng){
        auto perm = rng.perm<int>(n);
        for(auto& e : edges){
            e.first = perm[e.first];
            e.second = perm[e.second];
        }
    }
    void shuffle_edges(Random& rng){
        rng.shuffle(edges.begin(), edges.end());
    }

    void push(int u, int v){
        edges.emplace_back(u, v);
    }

    void join_random_edges(Random& rng, int count){
        int fixn = n;
        for(int i=0; i<count; i++){
            push(rng.uniform(0, fixn-1), n);
            n++;
        }
    }

};


int main(int, char* argv[]) {
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int N = gen.uniform(100, 300);

    Tree tree;
    while(tree.n < N){
        tree.join_random_edges(gen, 1);
    }

    tree.shuffle_edges(gen);
    tree.shuffle_nodes(gen);

    std::vector<int> A(N), B(N-1), C(N-1);
    for(int i=0; i<N; i++) A[i] = gen.uniform(A_MIN, A_MAX);
    for(int i=0; i<N-1; i++) B[i] = gen.uniform(B_MIN, B_MAX);
    for(int i=0; i<N-1; i++) C[i] = gen.uniform(C_MIN, C_MAX);

    printf("%d\n", N);

    for(int i=0; i<N; i++){
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    
    for(int i=0; i<N-1; i++){
        printf("%d %d %d %d\n",
            tree.edges[i].first,
            tree.edges[i].second,
            B[i],
            C[i]
            );
    }

    return 0;
}
