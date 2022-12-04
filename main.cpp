#include "Vector2D.h"
#include "Vector3D.h"

int main() {
    const auto vec1 = Vector3D(3,-2,5);
    const auto vec2 = Vector3D(1,-1, 3);
    const auto vec3 = Vector3D(-2,2, 1);
    printf("Triple product: %.4f\n", Vector3D::GetTripleProduct(vec1, vec2, vec3));
    return 0;
}
