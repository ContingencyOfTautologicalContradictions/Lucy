#include <metal_stdlib>

kernel void Render(metal::texture2d<half, metal::access::write> outTexture [[texture(0)]], uint2 gid [[thread_position_in_grid]])
{
    outTexture.write(half4(1, 1, 0, 1), gid);
}