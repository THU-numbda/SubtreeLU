#pragma once
#include <memory>

namespace subtree_lu {
using idx_t = int;     // index type
using val_t = double;  // value type

class SubtreeLUd {
public:
    SubtreeLUd();

    ~SubtreeLUd();

    int analyze(int n, const idx_t *ap, const idx_t *ai, const val_t *ax, int nthreads, idx_t *rp, idx_t *cp) const;

    int factorize(const val_t *ax) const;

    int refactorize(const val_t *ax) const;

    int solve(const val_t *b, val_t *x) const;

    int extract_factors(idx_t *lp, idx_t *li, val_t *lx, idx_t *up, idx_t *ui, val_t *ux, idx_t *rp, idx_t *cp) const;

    long long *parm{};

private:
    struct Impl;

    std::unique_ptr<Impl> impl;
};
}  // namespace subtree_lu
