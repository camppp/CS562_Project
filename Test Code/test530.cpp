#include "mtao/types.hpp"

namespace mtao { namespace geometry { namespace mesh {

    template <typename VDerived, typename FDerived>
    auto face_normals(const Eigen::MatrixBase<VDerived>& V, const Eigen::MatrixBase<FDerived>& F) {
        constexpr static int CRows = VDerived::RowsAtCompileTime;
        auto N = VDerived::Zero(V.rows(), F.cols()).eval();
        using T = typename VDerived::Scalar;

        for (int i = 0; i < F.cols(); ++i) {
            auto v0 = V.col(F(0, i));
            auto v1 = V.col(F(1, i));
            auto v2 = V.col(F(2, i));

            auto edge1 = v1 - v0;
            auto edge2 = v2 - v0;

            auto normal = edge1.cross(edge2);
            normal.normalize();

            N.col(i) = normal;
        }

        return N;
    }
}}}
