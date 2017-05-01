#include <stdio.h>
#include <stdlib.h>
#include <lzma.h>

int main()
{
    uint32_t preset = 6 | LZMA_PRESET_EXTREME;
    lzma_check check = LZMA_CHECK_CRC64;
    lzma_stream strm = LZMA_STREAM_INIT;
    lzma_ret ret = lzma_easy_encoder (&strm, preset, check);
    printf("lzma_easy_encoder returned: %d\n", ret);
    return 0;
}
