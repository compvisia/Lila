#include "Math/Matrix.h"

int main() {
    /*
     * Matrix Example
     */

     Lila::Matrix4f matrix = Lila::Matrix4f::identity();

     LILA_DEBUG("{} {} {} {}", matrix.get(0,0), matrix.get(1,1), matrix.get(2,2), matrix.get(3,3));

}
