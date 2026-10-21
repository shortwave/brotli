/* Distributed under the MIT license; see LICENSE. */

/* Include the decoder to exercise malformed block switches.
   A one-type stream cannot switch types or consume a block-switch symbol. */
#include "../c/dec/decode.c"

#include <assert.h>
#include <string.h>

int main(void) {
  int safe;
  for (safe = 0; safe <= 1; ++safe) {
    BrotliDecoderState state;
    HuffmanCode type_trees[3 * BROTLI_HUFFMAN_MAX_SIZE_258] = {{0}};
    HuffmanCode length_trees[3 * BROTLI_HUFFMAN_MAX_SIZE_26] = {{0}};
    memset(&state, 0, sizeof(state));
    state.block_type_trees = type_trees;
    state.block_len_trees = length_trees;
    state.num_block_types[0] = 1;
    state.num_block_types[1] = 1;
    state.num_block_types[2] = 1;
    assert(DecodeLiteralBlockSwitchInternal(safe, &state) ==
           BROTLI_DECODER_ERROR_FORMAT_BLOCK_SWITCH);
    assert(DecodeCommandBlockSwitchInternal(safe, &state) ==
           BROTLI_DECODER_ERROR_FORMAT_BLOCK_SWITCH);
    assert(DecodeDistanceBlockSwitchInternal(safe, &state) ==
           BROTLI_DECODER_ERROR_FORMAT_BLOCK_SWITCH);
  }
  return 0;
}
