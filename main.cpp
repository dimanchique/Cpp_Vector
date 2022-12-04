#include "Vector3D.h"

int main() {
    for(int i = 0; i < 100; i++)
    {
        auto vec = Vector3D::GetRandomRotatedVector();
        const auto m = vec.GetMagnitude();
        printf("Generated vector (%.4f; %.4f; %.4f) with magnitude %.4f\n", vec.X, vec.Y, vec.Z, m);
    }
    return 0;
}
